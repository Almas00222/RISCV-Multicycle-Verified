module top 
(
	input clk,
	input rst,
	output wire [7:0] a0_r,
	output wire [4:0] einstr,
	//Fetch output wires
	output wire [31:0] meminstr, //feds into instruction memory block
	output wire [4:0] rs1,
	output wire [4:0] rs2,
	output wire [31:0] aluOut,
	output wire done_LW,
    	output wire done_SW,
    	output wire done_ALUWB,
    	output wire done_ecall,
    	output wire done_ebreak,
    	output wire [3:0] mcause,
    	output wire done_beq,
	output reg [31:0] SrcBout,
	output reg [31:0] SrcAout,
	output wire IRWrite,
	output wire PCWrite,
	output wire zero,
	output wire [2:0] aluControl,
	//Reg_File
	output wire [31:0] rd1,
	output wire [1:0] ALUSrcB, //mux
	output wire [31:0] rd2,
	output wire [3:0] state_out,
	output reg [31:0] ResultOut, // goes to wd3 and AdrSrc to A instr/data memory
	
	output wire [31:0] out_A,
	//Control_Unit output wires

	
	output wire MemWrite,
    	 // from Control Unit
    	output wire AdrSrc,
    	
    	output wire [1:0] immSrc,
    	

	output wire [1:0] ALUSrcA, //mux
	output wire [1:0] ResultSrc, // from Control Unit
	output wire regWrite, //feds into Reg_file
	
	//
	output wire [31:0] WriteData,
	
    	output wire  [31:0] immext,
    	output wire [31:0] instr, 
    	output wire [31:0] pcdata_out,
    	output wire [31:0] pcout,
    	output wire [31:0] oldpcout,
    	output wire [31:0] alupcOut,
    	output reg [31:0] Adr,
	
	output wire PCUpdate,
	// ALU SrcA mux
	output wire [4:0] rd    //feds into reg_files
);
	assign Adr = AdrSrc ? ResultOut : pcout; // fed into input of instrmem
	
	

	
always @(*) begin
	case (ALUSrcA)
		2'b00: begin
		SrcAout = pcout;
		end
		2'b01: begin
		SrcAout = instr;
		end
		2'b10: begin
		SrcAout = out_A;
		end
		default: SrcAout = 32'bx;
		endcase
	end
	
	
	// ALU SrcB mux
	
	

	
always @(*) begin
	case (ALUSrcB)
		2'b00: begin
		SrcBout = WriteData;
		end
		2'b01: begin
		SrcBout = immext;
		end
		2'b10: begin
		SrcBout = 4;
		end
		default: SrcBout = 32'bx;
		endcase
	end
	
	// ALUOut ResultSrc
	
	
	
always @(*) begin
	case (ResultSrc)
		2'b00: begin
		ResultOut = alupcOut;
		end
		2'b01: begin
		ResultOut = pcdata_out;
		end
		2'b10: begin
		ResultOut = aluOut;
		end
		default: ResultOut = 32'bx;
		endcase
	end
	
    dff_en pcnext(
    	.clk(clk),
	.rst(rst),
	.d(ResultOut),
	.en(PCWrite),
	.q(pcout)
    );
    
    // this is right
    instrmemory mem(
        .rd(meminstr),
        .wd(WriteData), //coming from dffA
        .we(MemWrite),  //cu
        .clk(clk),
        .a(Adr)
    );
    
    // this is right
    dff_clk pcdata(
    	.clk(clk),
	.rst(rst),
	.d(meminstr),
	.q(pcdata_out)
    );
    
    // this is right
    dff_clk oldpcinstr(
    	.clk(clk),
	.rst(rst),
	.d(pcout),
	.q(instr)
	);
	
	// this is right
	dff_en oldpc(
    	.clk(clk),
	.rst(rst),
	.d(meminstr),
	.en(IRWrite),
	.q(oldpcout)
	);
	
	// this is right
	Reg_file regfile(
	.clk(clk),
	.we3(regWrite),
	.a1(rs1),
	.a2(rs2),
	.a3(rd),
	.a0_r(a0_r),
	.wd3(ResultOut),
	.rd1(rd1),
	.rd2(rd2)
	);
	
	// this is right
	dff_clk dffA(
	.clk(clk),
	.rst(rst),
	.d(rd1),
	.q(out_A) //goes where -- ALU
	);
	
	// this is right
	dff_clk dffBwd(
	.clk(clk),
	.rst(rst),
	.d(rd2),
	.q(WriteData) //goes where -- Instr/Data memory
	);
	
	// this is right
	decoder dec
	(
	.instruction(oldpcout[31:7]),
	.immSrc(immSrc),
	.einstr(einstr),
	.rs1(rs1),
	.rs2(rs2),
	.rd(rd),
	.immext(immext)
	);
	
	// this is no
	Control_Unit ctrl
	(
	.state_out(state_out),
	.aluZero(zero),
	.einstr(einstr),
        .clk(clk),
        .mcause(mcause),
        .a0_r(a0_r),
    	.rst(rst),
	.cmdOp(oldpcout[6:0]),
	.cmdF3(oldpcout[14:12]),
	.cmdF7(oldpcout[30]),
    	.IRWrite(IRWrite),
    	.MemWrite(MemWrite),
    .PCWrite(PCWrite), // from Control Unit
    .AdrSrc(AdrSrc),
    .immSrc(immSrc),
    .aluControl(aluControl),
    .done_LW(done_LW),
    .done_SW(done_SW),
    .done_ALUWB(done_ALUWB),
    .done_ecall(done_ecall),
    .done_ebreak(done_ebreak),
    .done_beq(done_beq),
    .ALUSrcB(ALUSrcB), //muxs
    .ALUSrcA(ALUSrcA), //mux
    .ResultSrc(ResultSrc), // from Control Unit
    .regWrite(regWrite), //feds into Reg_file
    .PCUpdate(PCUpdate)  //enable pcnext
	);
	
	// this is right
	ALU alutrans
	(
	.in_a(SrcAout),
	.in_b(SrcBout),
	.select(aluControl),
	.zero(zero),
	.aluOut(aluOut)
	);
	
	// this is right
	dff_clk alupc(
	.clk(clk),
	.rst(rst),
	.d(aluOut),
	.q(alupcOut)
	);
endmodule
