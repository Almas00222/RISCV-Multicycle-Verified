module decoder 
(
	input [31:7] instruction,
	input [1:0] immSrc,
	output [4:0] einstr,
	output [4:0] rs1,
	output [4:0] rs2,
	output [4:0] rd,
	output reg [31:0] immext
);	
	assign einstr = instruction [24:20];
	assign rs1 = instruction [19:15];
	assign rs2 = instruction [24:20]; 
	assign rd = instruction [11:7];
	
	// extend block

	always @(*) begin 
	case (immSrc)
	2'b00 : immext = {{20{instruction[31]}}, instruction[31:20]};
	2'b01: immext  = {{20{instruction[31]}}, instruction[31:25], instruction[11:7]};
	2'b10: immext  = {{20{instruction[31]}} , instruction[7], instruction[30:25], instruction[11:8], 1'b0};
	2'b11: immext = {{12{instruction[31]}}, instruction[19:12], instruction[20], instruction[30:21], 1'b0};
	default: immext = 32'b00;
	
		// U-type
		// immU [11:0] = 12'b0;
		// immU [31:12] = instruction [31:12];
		
	endcase
	end
endmodule
