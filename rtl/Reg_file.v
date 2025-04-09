module Reg_file(
    input          clk,
    input          we3,
    input    [4:0] a1,
    input    [4:0] a2,
    input    [4:0] a3,
    input    [31:0] wd3,
    output  [7:0] a0_r,
    output   [31:0] rd1,
    output   [31:0] rd2
);
    (* verilator public *)
    reg [31:0] rf [0:31];
    integer i;
    initial begin
    for (i = 0; i < 32; i = i + 1) begin
        rf[i] = 32'b0;
    end
    end
    // Sequential logic - register writes
    always @(posedge clk) begin
        if (we3 == 1 && (a3 != 0)) begin
        rf[a3] <= wd3;
        end
    end
    
    // Combinational logic - register reads
    assign rd1 = (a1 == 0) ? 32'b0 : rf[a1];
    assign rd2 = (a2 == 0) ? 32'b0 : rf[a2];
    assign a0_r = rf[10][7:0];  // This reads bit 0 of register a0 (x10)
endmodule
