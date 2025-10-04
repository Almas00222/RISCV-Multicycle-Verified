module ALU
(
  input  [31:0] in_a,
  input  [31:0] in_b,
  input  [3:0]  select,
  output        zero,
  output reg [31:0] aluOut
);

    localparam [3:0] ALU_ADD  = 4'b0000;
    localparam [3:0] ALU_SUB  = 4'b0001;
    localparam [3:0] ALU_AND  = 4'b0010;
    localparam [3:0] ALU_OR   = 4'b0011;
    localparam [3:0] ALU_XOR  = 4'b0100;
    localparam [3:0] ALU_SLT  = 4'b0101;
    localparam [3:0] ALU_SLTU = 4'b0110;
    localparam [3:0] ALU_SLL  = 4'b0111;
    localparam [3:0] ALU_SRL  = 4'b1000;
    localparam [3:0] ALU_SRA  = 4'b1001;

    always @(*) begin
        case (select)
            ALU_ADD:  aluOut = in_a + in_b;
            ALU_SUB:  aluOut = in_a - in_b;
            ALU_AND:  aluOut = in_a & in_b;
            ALU_OR:   aluOut = in_a | in_b;
            ALU_XOR:  aluOut = in_a ^ in_b;
            ALU_SLT:  aluOut = {31'b0, ($signed(in_a) < $signed(in_b))};
            ALU_SLTU: aluOut = {31'b0, (in_a < in_b)};
            ALU_SLL:  aluOut = in_a << in_b[4:0];
            ALU_SRL:  aluOut = in_a >> in_b[4:0];
            ALU_SRA:  aluOut = $signed(in_a) >>> in_b[4:0];
            default:  aluOut = 32'b0;
        endcase
    end
    
    assign zero = (aluOut == 32'b0);
endmodule


