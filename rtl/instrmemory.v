module instrmemory 
#(
    parameter SIZE = 32768,
    `ifndef SYNTHESIS
    parameter MEMFILE = "instructions/rv32mi-p-ma_addr.hex"
    `endif
)
(
    input [31:0] wd,      // Write data
    /* verilator lint_off UNUSEDSIGNAL */
    input [31:0] a,       // Address input
    /* verilator lint_on UNUSEDSIGNAL */
    input clk,            // Clock
    input we,             // Write enable
    output [31:0] rd      // Instruction output
);
    localparam ADDR_WIDTH = $clog2(SIZE);
    wire [ADDR_WIDTH-1:0] word_addr = a[ADDR_WIDTH+1:2];

    reg [31:0] RAM [0:SIZE - 1];  // Memory storage
    integer i;
    
    `ifndef SYNTHESIS
    initial begin
        for (i = 0; i < SIZE; i = i + 1) begin
            RAM[i] = 32'h0000_0000;
        end
        `ifndef SYNTHESIS
        $readmemh(MEMFILE, RAM);
        `endif
    end
    `endif
    // Read operation (combinational)
    assign rd = RAM[word_addr];  // Word-aligned addressing (divide by 4)
    
    // Write operation (sequential)
    always @(posedge clk) begin
    if (we) RAM[word_addr] <= wd;
    end
endmodule

