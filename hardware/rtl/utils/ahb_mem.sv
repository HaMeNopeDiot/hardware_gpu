
//-------------------------------------------------------------------------------//
// Author:                Cherkasov V. V.
// ------------------------------------------------------------------------------//
// Purpose: AHB Slave Memory
// Date: 2026/06
//-------------------------------------------------------------------------------//


module ahb_mem #(
    parameter int DEPTH = 1024,
    parameter int AW = 32,
    parameter int DW = 32
)(
    input  logic                HCLK,
    input  logic                HRESETn,
    input  logic [AW-1:0]       HADDR,
    input  logic [1:0]          HTRANS,
    input  logic [DW-1:0]       HWDATA,
    input  logic                HWRITE,

    output logic [DW-1:0]       HRDATA
);

logic [DW-1:0] mem[DEPTH];

always_ff @(posedge HCLK) begin: always_read_blk
    HRDATA <= mem[HADDR];
end

logic [AW-1:0] address;
logic          do_write;
always_ff @(posedge HCLK or negedge HRESETn) begin
    if (!HRESETn) begin
        address <= '0;
        do_write <= '0;
    end
    else begin
        address <= HADDR;
        do_write <= (HWRITE == '1) && (HTRANS != '0);
    end
end

always_ff @(posedge HCLK) begin
    if (do_write) begin
        mem[address] <= HWDATA;
    end
end

endmodule
