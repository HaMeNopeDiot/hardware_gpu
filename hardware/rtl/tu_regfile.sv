//------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// -----------------------------------------------------------------------------//
// Purpose: Regfile for thread unit
//------------------------------------------------------------------------------//

module tu_regfile #(
    parameter int unsigned  DW              = 64,
    parameter int unsigned  REG_NUM         = 32,

    localparam int unsigned AW              = $clog2(REG_NUM),
    localparam logic [AW - 1: 0] ZERO_ADDR  = 0,
    localparam logic [AW - 1: 0] VID_ADDR   = (AW)'(REG_NUM - 1)
) (
    /*============================### COMMON SIGNALS ###========================*/
    input  logic                clk,
    input  logic [DW - 1: 0]    vid_i,
    /*=============================### WRITE SIGNALS ###========================*/
    input  logic                wr_en,                      // Write enable
    input  logic [AW - 1: 0]    addr_w,                     // Write address
    input  logic [DW - 1: 0]    data_w,                     // Write data
    /*==========================### SIGNALS FOR ALU ###=========================*/
    input  logic [AW - 1: 0]    addr_r1, addr_r2, addr_r3,  // Read address ports
    output logic [DW - 1: 0]    data_r1, data_r2, data_r3,  // Read data ports
    /*==========================### READ SIGNALS ###============================*/
    input logic  [AW - 1: 0]    addr_rs1, addr_rs2,
    output logic [DW - 1: 0]    data_rs1, data_rs2
    //==========================================================================//
);
    logic [DW - 1:0] rf [REG_NUM];

    logic  is_zero_addr, is_vid_add;
    assign is_zero_addr = addr_w == ZERO_ADDR;
    assign is_vid_add   = addr_w == VID_ADDR;

    logic  is_write_prohibited;
    assign is_write_prohibited = is_zero_addr || is_vid_add;

    // Synchronous Write
    always_ff @(posedge clk) begin
        if (~is_write_prohibited && wr_en)
            rf[addr_w]  <= data_w;
        rf[ZERO_ADDR]   <= '0;
        rf[VID_ADDR]    <= vid_i;
    end

    // Asynchronous Read (Combinational)
    assign data_r1   = rf[addr_r1];
    assign data_r2   = rf[addr_r2];
    assign data_r3   = rf[addr_r3];

    assign data_rs1  = rf[addr_rs1];
    assign data_rs2  = rf[addr_rs2];
endmodule
