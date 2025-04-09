module dff_en (
	input clk,
	input rst,
	input  [31:0] d,
	input en,
	output reg [31:0] q
);

always @(posedge clk or posedge rst) begin
	if (rst) begin
	q <= 32'b0;
	end else if (en) begin
	q <= d;
	end
	end
endmodule

