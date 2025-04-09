module Control_Unit (
    input aluZero,
    input clk,
    input rst,
    input [6:0] cmdOp,
    input cmdF7,
    input [7:0] a0_r,
    input [4:0] einstr,
    input [2:0] cmdF3,
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
    output reg [2:0] aluControl,
    output reg [1:0] ALUSrcB, //mux
    output reg [1:0] ALUSrcA, //mux
    output reg [1:0] ResultSrc, // from Control Unit
    output reg regWrite, //feds into Reg_file
    output reg [3:0] state_out,
    output reg PCUpdate  //enable pcnext
);
	
	import "DPI-C" function void check(byte a0, byte mcause);
	
    reg [1:0] AluOp;
    reg branch;
    assign PCWrite = (branch & aluZero) | PCUpdate;

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
    
    reg [3:0] current_state, next_state;
    
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
    
    always @(posedge clk or posedge rst) begin
    	if (rst) begin
    		current_state <= s0;
    		end else begin
    		current_state <= next_state;
    		end
    end
    
    always @(*) begin
    next_state = s0;
    case(current_state)
    s0: begin
    next_state = s1;
    end
    s1: begin
    if ((cmdOp == 7'b0000011) || (cmdOp == 7'b0100011)) begin // lw sw
    next_state = s2; // memadr
    end else if (cmdOp == 7'b0110011) begin // R-type
    next_state = s6;
    end else if (cmdOp == 7'b1100011) begin // beq
    next_state = s10;
    end else if (cmdOp == 7'b0010011) begin //immediate addi slti ori
    next_state = s8;
    end else if (cmdOp == 7'b1101111) begin // JAL
    next_state = s9;
    end 
    end
    s2: begin
    if (cmdOp == 7'b0000011) begin 
    next_state = s3; //memread
    end else if (cmdOp == 7'b0100011) begin
    next_state = s5; //memwrite
    end
    end
    s3: begin
    next_state = s4; //memwb
    end
    s4: begin
    next_state = s0;
    end
    s5: begin
    next_state = s0; //memwrite and done
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
    mcause = 4'd0;
    aluControl = 3'b000;
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
        if (cmdOp == 7'b1110011 && einstr == 5'b00000) begin //Ecall
    	mcause = 4'd11;
    	done_ecall = 1;
    	end else if (cmdOp == 7'b1110011 && einstr == 5'b00001) begin //Ebreak
    	mcause = 4'd3;
    	done_ebreak = 1;
    	end
    	/* verilator lint_off WIDTHEXPAND */
		check(a0_r, mcause);
	/* verilator lint_on WIDTHEXPAND */
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
        MemWrite = 1;
        done_SW = 1;
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
        default: begin
        mcause = 4'dx;
        branch = 1'bx;
    IRWrite = 1'bx;
    MemWrite = 1'bx;
    PCWrite = 1'bx;
    AdrSrc = 1'bx;
    aluControl = 3'bx;
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
    
    
    
    ALUdec aludecode(
    	.funct3(cmdF3),
	.opb5(cmdOp[5]),
	.funct7b5(cmdF7),
	.aluop(AluOp),
	.aluselect(aluControl)
    );
    
endmodule

