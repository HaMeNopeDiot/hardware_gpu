
//-------------------------------------------------------------------------------//
// Author:                Cherkasov V. V.
// ------------------------------------------------------------------------------//
// Purpose: AHB Slave Memory
// Date: 2026/06
//-------------------------------------------------------------------------------//


module ahb_mem #(
    parameter  int DEPTH             = 1024,
    parameter  int AW                = 32,
    parameter  int DW                = 32,
    localparam int STRB              = DW / 8,
    localparam int UNALIGNED_BITS    = $clog2(STRB),
    parameter  bit DEBUG_MODE        = 0,
    parameter  int DEBUG_REGS_TRACE  = 10,
    parameter  int DEBUG_TRACE_OFS   = 0
)(
    input  logic                HCLK,
    input  logic                HRESETn,
    input  logic [AW    - 1: 0] HADDR,
    input  logic [1        : 0] HTRANS,
    input  logic [DW    - 1: 0] HWDATA,
    input  logic                HWRITE,

    output logic [DW    - 1: 0] HRDATA
);

logic [DW - 1: 0] mem[DEPTH];

always_ff @(posedge HCLK) begin: always_read_blk
    HRDATA <= mem[HADDR >> UNALIGNED_BITS];
end

logic [AW - 1: 0] address;
logic          do_write;
always_ff @(posedge HCLK or negedge HRESETn) begin
    if (!HRESETn) begin
        address <= '0;
        do_write <= '0;
    end
    else begin
        address  <= HADDR >> UNALIGNED_BITS;
        do_write <= (HWRITE == '1) && (HTRANS != '0);
    end
end

always_ff @(posedge HCLK) begin
    if (do_write) begin
        mem[address] <= HWDATA;
    end
end

if (DEBUG_MODE) begin: gen_debug_reg_trace
    logic [DW - 1: 0] trace_regs [DEBUG_REGS_TRACE];
    for (genvar i = 0; i < DEBUG_REGS_TRACE; i++) begin: gen_trace_reg
        logic [DW - 1: 0] trace_reg;
        assign trace_reg        = mem[i + DEBUG_TRACE_OFS];
        assign trace_regs[i]    = trace_reg;
    end
end

endmodule
