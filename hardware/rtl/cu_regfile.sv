//------------------------------------------------------------------------------
// Department:            Software Laboratory
// Author:                Starukhin Danila M.
// Author's e-mail:       starukhin.d@milandr.ru
// -----------------------------------------------------------------------------
// Purpose: Regfile for CU
//------------------------------------------------------------------------------
// Copyright (c) 2026 JSC "ICC Milandr", all rights reserved.
//
// This file contains confidential, proprietary information and trade
// secrets of JSC "ICC Milandr". The information contained in this file
// may only be used by a person authorised under and to the extent
// permitted by a subsisting license agreement or design service
// agreement from JSC "ICC Milandr".
//
// This entire notice must be reproduced on all copies of this file
// and copies of this file may only be made by a person if such person
// is permitted to do so under the terms of a subsisting license
// agreement or design service agreement from JSC "ICC Milandr".
//------------------------------------------------------------------------------

module cu_regfile #(
    parameter int unsigned  DW = 64,
    parameter int unsigned  REG_NUM = 32,
    localparam int unsigned AW = $clog2(REG_NUM)
) (
    /*============================### COMMON SIGNALS ###=============================*/
    input  logic                clk,
    /*=============================### WRITE SIGNALS ###=============================*/
    input  logic                wr_en,                      // Write enable
    input  logic [AW - 1: 0]    addr_w,                     // Write address
    input  logic [DW - 1: 0]    data_w,                     // Write data
    /*========================### READ SIGNALS FOR ALU ###===========================*/
    input  logic [AW - 1: 0]    addr_r1, addr_r2, addr_r3,  // Read address ports
    output logic [DW - 1: 0]    data_r1, data_r2, data_r3,  // Read data ports
    /*==========================### READ SIGNALS ###=================================*/
    input logic  [AW - 1: 0]    addr_r,
    output logic [DW - 1: 0]    data_r
    //===============================================================================//
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

    assign data_r  = addr_r != '0? rd[addr_r]: '0;
endmodule
