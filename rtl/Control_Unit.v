module Control_Unit (
    input aluZero,
    input clk,
    input rst,
    input [6:0] cmdOp,
    input cmdF7,
    input [7:0] a0_r,
    input [4:0] einstr,
    input [2:0] cmdF3,
    /* verilator lint_off UNUSEDSIGNAL */
    input [31:0] aluResult,  // For misalignment checking (only use [1:0])
    /* verilator lint_on UNUSEDSIGNAL */
    input [31:0] current_pc,   // Current PC for saving on trap
    output reg done_LW,
    output reg done_SW,
    output reg done_ALUWB,
    output reg done_beq,
    output reg done_ecall,
    output reg done_ebreak,
    output reg IRWrite,
    output reg MemWrite,
    output reg PCWrite, // from Control Unit
    output reg AdrSrc,
    output reg [3:0] mcause,
    output reg [1:0] immSrc,
    output wire [3:0] aluControl,
    output reg [1:0] ALUSrcB, //mux
    output reg [1:0] ALUSrcA, //mux
    output reg [1:0] ResultSrc, // from Control Unit
    output reg regWrite, //feds into Reg_file
    output reg [3:0] state_out,
    output reg PCUpdate,       //enable pcnext
    output reg trap_entry,     // Signal CSR to save trap context
    output reg [31:0] trap_pc, // PC to save on trap
    output reg mret_sig,       // MRET instruction signal
    output reg csr_we,         // CSR write enable
    output reg [1:0] PCSrc     // PC source: 00=PC+4, 01=ALU, 10=mtvec, 11=mepc
);
	
	`ifndef SYNTHESIS
	import "DPI-C" function void check(byte a0, byte mcause);
	`endif
	
    reg [1:0] AluOp;
    reg branch;
    reg [3:0] mcause_next;
    

    parameter s0 = 4'b0000; 
    parameter s1 = 4'b0001;
    parameter s2 = 4'b0010;
    parameter s3 = 4'b0011;
    parameter s4 = 4'b0100;
    parameter s5 = 4'b0101;
    parameter s6 = 4'b0110;
    parameter s7 = 4'b0111;
    parameter s8 = 4'b1000;
    parameter s9 = 4'b1001;
    parameter s10 = 4'b1010;
    parameter s11 = 4'b1011;  // Trap entry state
    parameter s12 = 4'b1100;  // MRET state
    
    reg [3:0] current_state, next_state;
    reg [31:0] saved_pc;  // Save PC for trap entry
    
    always @(*) begin
    	case (cmdOp)
    		7'b0000011: immSrc = 2'b00;
		7'b0100011: immSrc = 2'b01;
		7'b0110011: immSrc = 2'bxx;
		7'b1100011: immSrc = 2'b10;
		7'b0010011: immSrc = 2'b00;
		7'b1101111: immSrc = 2'b11;
		default: begin
		immSrc = 2'b00;
		end
    	endcase
    end
    
    // Save PC when entering trap handler and register mcause
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            current_state <= s0;
            saved_pc <= 32'h0;
            mcause <= 4'd0;
        end else begin
            current_state <= next_state;
            mcause <= mcause_next;
            // Save PC when in decode (s1) for potential trap
            if (current_state == s1) begin
                saved_pc <= current_pc;
            end
        end
    end

    // Determine next mcause value
    always @(*) begin
        mcause_next = mcause;
        case (current_state)
            s0: begin
                mcause_next = 4'd0;
            end
            s1: begin
                if (cmdOp == 7'b1110011 && einstr == 5'b00000) begin
                    mcause_next = 4'd11;  // ECALL
                end else if (cmdOp == 7'b1110011 && einstr == 5'b00001) begin
                    mcause_next = 4'd3;   // EBREAK
                end
            end
            s3: begin
                if (cmdOp == 7'b0000011 && aluResult[1:0] != 2'b00) begin
                    mcause_next = 4'd4;   // Load misaligned
                end
            end
            s5: begin
                if (cmdOp == 7'b0100011 && aluResult[1:0] != 2'b00) begin
                    mcause_next = 4'd6;   // Store misaligned
                end
            end
            default: begin
                // Hold mcause for other states (e.g., trap handling)
            end
        endcase
    end
    
    always @(*) begin
    next_state = s0;
    case(current_state)
    s0: begin
    next_state = s1;
    end
    s1: begin
    // Check for ECALL/EBREAK/MRET first
    if (cmdOp == 7'b1110011 && (einstr == 5'b00000 || einstr == 5'b00001)) begin
        next_state = s11;  // Trap entry for ecall/ebreak
    end else if (cmdOp == 7'b1110011 && einstr == 5'b00010) begin  // MRET
        next_state = s12;  // MRET state
    end else if ((cmdOp == 7'b0000011) || (cmdOp == 7'b0100011)) begin // lw sw
        next_state = s2; // memadr
    end else if (cmdOp == 7'b0110011) begin // R-type
        next_state = s6;
    end else if (cmdOp == 7'b1100011) begin // beq
        next_state = s10;
    end else if (cmdOp == 7'b0010011) begin //immediate addi slti ori
        next_state = s8;
    end else if (cmdOp == 7'b1101111) begin // JAL
        next_state = s9;
    end else begin
        next_state = s0;
    end
    end
    s2: begin
    // Check for misalignment after ALU computation (address in aluOut, not yet registered)
    // We need to check here for stores since they skip s3
    if (cmdOp == 7'b0000011) begin  // LW
        next_state = s3; //memread
    end else if (cmdOp == 7'b0100011) begin  // SW
        // For stores, check misalignment here and skip s5 if misaligned
        // Note: aluResult is from previous cycle, we need current aluOut
        // So we'll defer the actual check to the output logic
        next_state = s5; //memwrite (check will happen in s5 output logic)
    end
    end
    s3: begin
    // Check for misalignment - if detected, go to trap entry
    if (aluResult[1:0] != 2'b00) begin
        next_state = s11;  // Trap entry on misalignment
    end else begin
        next_state = s4; //memwb (only if aligned)
    end
    end
    s4: begin
    next_state = s0;
    end
    s5: begin
        if (aluResult[1:0] != 2'b00) begin
            next_state = s11;  // Trap entry on misaligned store
        end else begin
            next_state = s0; //memwrite and done
        end
    end
    s6: begin
    next_state = s7; //executeR type
    end
    s7: begin
    next_state = s0; //aluwb
    end
    s8: begin 
    next_state = s7; //aluwb
    end
    s9: begin
    next_state = s7; //aluwb
    end
    s10: begin
    next_state = s0;
    end
    s11: begin  // Trap entry
    next_state = s0;  // Jump to handler, then fetch
    end
    s12: begin  // MRET
    next_state = s0;  // Return from trap
    end
    default: begin next_state = s0;
    end
    endcase
    end

    always @(*) begin
    branch = 0;
    IRWrite = 0;
    MemWrite = 0;
    PCWrite = 0;
    AdrSrc = 0;
    ALUSrcB = 2'b00;
    ALUSrcA = 2'b00;
    ResultSrc = 2'b00;
    regWrite = 0;
    PCUpdate = 0;
    AluOp = 2'b00;
    done_LW = 0;
    done_SW = 0;
    done_ALUWB = 0;
    done_beq = 0;
    done_ecall = 0;
    done_ebreak = 0;
    trap_entry = 0;
    trap_pc = 32'h0;
    mret_sig = 0;
    csr_we = 0;
    PCSrc = 2'b00;

        case (current_state)
	s0: begin
	AdrSrc = 0;
	IRWrite = 1;
	ALUSrcA = 2'b00;
	ALUSrcB = 2'b10;
	AluOp = 2'b00;
        ResultSrc = 2'b10;
        PCUpdate = 1;
        end
        s1: begin   
        ALUSrcA = 2'b01; 
        ALUSrcB = 2'b01;
        // Exception detection - mcause will be set in s11
        end
        s2: begin
        ALUSrcA = 2'b10;
        ALUSrcB = 2'b01;
        end
        s3: begin
        AdrSrc = 1;
        end
        s4: begin
        ResultSrc = 2'b01;
        regWrite = 1;
        done_LW = 1;
        end
        s5: begin
        AdrSrc = 1;
        // Check for misaligned store address before writing
        if (aluResult[1:0] != 2'b00) begin
            // Misaligned store - do not perform write, trap handled in s11
        end else begin
            // Aligned - perform the store
            MemWrite = 1;
            done_SW = 1;
        end
        end
        s6: begin
        ALUSrcA = 2'b10;
        AluOp = 2'b10;
        end
        s7: begin
        regWrite = 1;
        done_ALUWB = 1;
        end
        s8: begin
        ALUSrcA = 2'b10;
        ALUSrcB = 2'b01;
        AluOp = 2'b10;
        end
        s9: begin
        ALUSrcA = 2'b01;
        ALUSrcB = 2'b10;
        PCUpdate = 1;
        end
        s10: begin
        ALUSrcA = 2'b10;
        ALUSrcB = 2'b00;
        ResultSrc = 2'b00;
        AluOp = 2'b01;
        branch = 1;
        done_beq = 1;
        end
        s11: begin  // Trap entry
        trap_entry = 1;      // Signal CSR to save context
        trap_pc = saved_pc;  // PC to save
        PCSrc = 2'b10;       // Jump to mtvec
        PCUpdate = 1;        // Update PC
        // Set appropriate done flags and call DPI check
        if (mcause == 4'd11 || mcause == 4'd3) begin  // ecall/ebreak
            done_ecall = (mcause == 4'd11);
            done_ebreak = (mcause == 4'd3);
        end
        /* verilator lint_off WIDTHEXPAND */
        `ifndef SYNTHESIS
        check(a0_r, mcause);  // DPI call - simulation only
        `endif
        /* verilator lint_on WIDTHEXPAND */
        end
        s12: begin  // MRET - return from trap
        mret_sig = 1;        // Signal CSR
        PCSrc = 2'b11;       // Jump to mepc
        PCUpdate = 1;        // Update PC
        end
        default: begin
        branch = 1'bx;
    IRWrite = 1'bx;
    MemWrite = 1'bx;
    PCWrite = 1'bx;
    AdrSrc = 1'bx;
    ALUSrcB = 2'bx;
    ALUSrcA = 2'bx;
    ResultSrc = 2'bx;
    regWrite = 1'bx;
    PCUpdate = 1'bx;
    AluOp = 2'bx;
    done_LW = 1'bx;
    done_SW = 1'bx;
    done_ALUWB = 1'bx;
    done_beq = 1'bx;
    done_ecall = 1'bx;
    done_ebreak = 1'bx;
    end
        endcase
    end
    
    // Output the current state for debugging
    always @(*) begin
        state_out = current_state;
    end
    
    
    
    // compute PCWrite combinationally from branch, aluZero and PCUpdate
    always @(*) begin
        PCWrite = (branch & aluZero) | PCUpdate;
    end

    ALUdec aludecode(
    	.funct3(cmdF3),
	.opb5(cmdOp[5]),
	.funct7b5(cmdF7),
	.aluop(AluOp),
	.aluselect(aluControl)
    );
    
endmodule


