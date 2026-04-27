//------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// -----------------------------------------------------------------------------//
// Purpose: Regfile for thread unit
//------------------------------------------------------------------------------//

module tu_regfile #(
    parameter int unsigned  DW = 64,
    parameter int unsigned  REG_NUM = 32,
    localparam int unsigned AW = $clog2(REG_NUM)
) (
    /*============================### COMMON SIGNALS ###========================*/
    input  logic                clk,
    /*=============================### WRITE SIGNALS ###========================*/
    input  logic                wr_en,                      // Write enable
    input  logic [AW - 1: 0]    addr_w,                     // Write address
    input  logic [DW - 1: 0]    data_w,                     // Write data
    /*==========================### SIGNALS FOR ALU ###=========================*/
    input  logic [AW - 1: 0]    addr_r1, addr_r2, addr_r3,  // Read address ports
    output logic [DW - 1: 0]    data_r1, data_r2, data_r3,  // Read data ports
    /*==========================### READ SIGNALS ###============================*/
    input logic  [AW - 1: 0]    addr_r,
    output logic [DW - 1: 0]    data_r
    //==========================================================================//
);
    logic [DW - 1:0] rf [REG_NUM];

    // Synchronous Write
    always_ff @(posedge clk) begin
        if (wr_en)
            rf[addr_w] <= data_w;
    end

    // Asynchronous Read (Combinational)
    assign data_r1 = addr_r1 != '0? rf[addr_r1]: '0;
    assign data_r2 = addr_r2 != '0? rf[addr_r2]: '0;
    assign data_r3 = addr_r3 != '0? rf[addr_r3]: '0;

    assign data_r  = addr_r  != '0? rf[addr_r]: '0;
endmodule
