module instrmemory 
#(
    parameter SIZE = 2048,
    parameter MEMFILE = "/home/almas/MultiCycleLast/rtl/instructions.hex"  // Parameterized file path
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
    reg [31:0] RAM [SIZE - 1:0];  // Memory storage
    
    initial begin
        $readmemh(MEMFILE, RAM);
    end
    
    // Read operation (combinational)
    assign rd = RAM[a[12:2]];  // Word-aligned addressing (divide by 4)
    
    // Write operation (sequential)
    always @(posedge clk) begin
        if (we) RAM[a[12:2]] <= wd;
    end
endmodule
