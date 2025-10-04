module instrmemory 
#(
    parameter SIZE = 32768,
    `ifndef SYNTHESIS
    parameter MEMFILE = "instructions/rv32mi-p-ma_addr.hex"
    `endif
)
(
    input [31:0] wd,      
    /* verilator lint_off UNUSEDSIGNAL */
    input [31:0] a,       // Address input
    /* verilator lint_on UNUSEDSIGNAL */
    input clk,            
    input we,             
    output [31:0] rd      
);
    localparam ADDR_WIDTH = $clog2(SIZE);
    wire [ADDR_WIDTH-1:0] word_addr = a[ADDR_WIDTH+1:2];

    reg [31:0] RAM [0:SIZE - 1];  // Memory storage
    integer i;
    `ifndef SYNTHESIS
    reg [1023:0] memfile_path;
    `endif

    initial begin
        for (i = 0; i < SIZE; i = i + 1) begin
            RAM[i] = 32'h0000_0000;
        end
        `ifndef SYNTHESIS
        if ($value$plusargs("MEMFILE=%s", memfile_path)) begin
            $display("instrmemory: Loading instructions from %0s", memfile_path);
            $readmemh(memfile_path, RAM);
        end else begin
            $display("instrmemory: Using default instruction image %0s", MEMFILE);
            $readmemh(MEMFILE, RAM);
        end
        `endif
    end
    // Read operation (combinational)
    assign rd = RAM[word_addr];  // Word-aligned addressing (divide by 4)
    
    // Write operation (sequential)
    always @(posedge clk) begin
    if (we) RAM[word_addr] <= wd;
    end
endmodule

