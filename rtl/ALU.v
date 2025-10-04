module ALU
(
  input  [31:0] in_a,
  input  [31:0] in_b,
  input  [2:0]  select,
  output        zero,
  output reg [31:0] aluOut
);

    // Extend select[0] to 32 bits: if select[0] is 1, add 32'd1; otherwise add 32'd0.
    wire [31:0] condinvb = select[0] ? ~in_b : in_b;
    wire [31:0] sum = in_a + condinvb + (select[0] ? 32'd1 : 32'd0);
    wire isAddSub = (~select[2] & ~select[1]) | (~select[1] & ~select[0]);
    wire v; // Overflow flag
   
    // Compute overflow flag
    assign v = ~(select[0] ^ in_a[31] ^ in_b[31]) & (in_a[31] ^ sum[31]) & isAddSub;

    always @(*) begin      
        case (select)
            3'b000: aluOut = sum;                           // ADD
            3'b001: aluOut = sum;                           // SUB
            3'b010: aluOut = in_a & in_b;                     // AND
            3'b011: aluOut = in_a | in_b;                     // OR
            3'b100: aluOut = in_a ^ in_b;                     // XOR
            3'b101: aluOut = {31'b0, (sum[31] ^ v)};          // SLT
            3'b110: aluOut = in_a << in_b[4:0];               // SLL
            3'b111: aluOut = in_a >> in_b[4:0];               // SRL
            default: aluOut = 32'bx;
        endcase
    end
    
    assign zero = (aluOut == 32'b0);
endmodule

