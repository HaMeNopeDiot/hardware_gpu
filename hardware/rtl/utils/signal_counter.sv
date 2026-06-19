//------------------------------------------------------------------------------//
// Department:            Software Laboratory
// Author:                Starukhin Danila M.
// Author's e-mail:       starukhin.d@milandr.ru
// -----------------------------------------------------------------------------//
// Purpose: Signal counter
//------------------------------------------------------------------------------//
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


/*==============================================================================//
region MODULE DEFINITION
//==============================================================================*/
module signal_counter #(
    /*-------------------------### COMMON PARAMETERS ###------------------------*/
    parameter int unsigned          CNT_W    = 8,
    parameter logic [CNT_W - 1: 0]  CNT2DONE = (CNT_W)'((1 << 8) - 1),
    parameter logic                 AUTO_DISABLE_AFTER_DONE = '1
    /*--------------------------------------------------------------------------*/
) (
    /*==========================### COMMON SIGNALS ###==========================*/
    input  logic                clk,
    input  logic                rst_n,

    input  logic [CNT_W - 1: 0] start_value,
    input  logic                start,
    input  logic                inc,

    output logic [CNT_W - 1: 0] value_out,
    output logic                done
    //==========================================================================//
);
/*==============================================================================//
region LOGIC
//==============================================================================*/

logic [CNT_W - 1: 0] value;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        value <= '0;
    else if (start)
        value <= start_value;
    else if (inc && ~done)
        value <= value + (CNT_W)'('h1);
end

assign done = value == (CNT_W)'(CNT2DONE);

if (AUTO_DISABLE_AFTER_DONE) begin: gen_auto_disable_after_done
    assign value_out =  done? '0: value;
end
else begin: gen_no_disable
    assign value_out = value;
end


endmodule
