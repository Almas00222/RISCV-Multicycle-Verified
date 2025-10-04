module CSR (
    input clk,
    input rst,
    input we,                      // Write enable
    input [11:0] addr,             // CSR address
    input [31:0] wdata,            // Write data
    output reg [31:0] rdata,       // Read data
    
    // Trap handling inputs
    input trap_entry,              // Signal trap entry
    input [31:0] trap_pc,          // PC to save on trap
    input [3:0] trap_cause,        // Exception cause
    input mret,                    // Machine return signal
    
    // CSR outputs
    output [31:0] mtvec_out,       // Trap vector base address
    output [31:0] mepc_out         // Exception PC for return
);

    // CSR addresses (Machine-mode)
    localparam CSR_MSTATUS  = 12'h300;
    localparam CSR_MTVEC    = 12'h305;
    localparam CSR_MEPC     = 12'h341;
    localparam CSR_MCAUSE   = 12'h342;

    // CSR registers
    reg [31:0] mstatus;   // Machine status
    reg [31:0] mtvec;     // Trap vector base address
    reg [31:0] mepc;      // Exception PC
    reg [31:0] mcause;    // Exception cause

    // Initialize CSRs
    initial begin
        mstatus = 32'h0000_1800;  // MPP=11 (machine mode)
        mtvec   = 32'h8000_0004;  // Default trap handler address
        mepc    = 32'h0;
        mcause  = 32'h0;
    end

    // CSR outputs
    assign mtvec_out = mtvec;
    assign mepc_out = mepc;

    // CSR read
    always @(*) begin
        case (addr)
            CSR_MSTATUS:  rdata = mstatus;
            CSR_MTVEC:    rdata = mtvec;
            CSR_MEPC:     rdata = mepc;
            CSR_MCAUSE:   rdata = mcause;
            default:      rdata = 32'h0;
        endcase
    end

    // CSR write and trap handling
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            mstatus <= 32'h0000_1800;
            mtvec   <= 32'h8000_0004;
            mepc    <= 32'h0;
            mcause  <= 32'h0;
        end else begin
            // Trap entry: save PC and cause
            if (trap_entry) begin
                mepc   <= trap_pc;
                mcause <= {28'h0, trap_cause};
            end
            // MRET: restore status (if needed)
            else if (mret) begin
                // Could restore privilege level here if implementing user mode
            end
            // Normal CSR write
            else if (we) begin
                case (addr)
                    CSR_MSTATUS:  mstatus <= wdata;
                    CSR_MTVEC:    mtvec   <= wdata;
                    CSR_MEPC:     mepc    <= wdata;
                    CSR_MCAUSE:   mcause  <= wdata;
                    default: ;
                endcase
            end
        end
    end

endmodule

