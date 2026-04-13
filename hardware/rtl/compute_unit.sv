//------------------------------------------------------------------------------
// Department:            Software Laboratory
// Author:                Starukhin Danila M.
// Author's e-mail:       starukhin.d@milandr.ru
// -----------------------------------------------------------------------------
// Purpose: GPU Compute unit
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


/*===================================================================================//
region MODULE DEFINITION
//===================================================================================*/
module compute_unit
    import handshake_fpu_pkg::tags_t;
    import handshake_fpu_pkg::TAGS_NUM;
    import handshake_fpu_pkg::proccess_t;

    // FSM states
    import handshake_fpu_pkg::FPU_IDLE;
    import handshake_fpu_pkg::FPU_PRELOAD;
    import handshake_fpu_pkg::FPU_LOAD;
    import handshake_fpu_pkg::FPU_PROCESS;
    import handshake_fpu_pkg::FPU_RESULT;

    // Types for src/dst/int
    import fpnew_pkg::FP64;
    import fpnew_pkg::INT64;

    // Operation
    import cu_pkg::cu_command_t;
#(
    parameter int unsigned DW = 64,
    parameter int unsigned REGFILE_SIZE = 6
) (
    input logic         clk,
    input logic         rst_n,

    input cu_command_t  command,
    input logic         ready
);

/*===================================================================================//
region LOGIC
//===================================================================================*/

logic [DW - 1: 0] operands [3];
logic [DW - 1: 0] op_1;
logic [DW - 1: 0] op_2;
logic [DW - 1: 0] op_3;

assign operands = {op_1, op_2, op_3};

/*===================================================================================//
region HANDSHAKE FSM
//===================================================================================*/


/*===================================================================================//
region INSTANCES
//===================================================================================*/

// ///////////////////////////////////////////////////////// //
//                    *** CU REGFILE ***                     //
// NOTE: write a purpose here
cu_regfile #(
    .DW      (DW),
    .REG_NUM (REGFILE_SIZE)
) cu_regfile_u (
    //================### COMMON SIGNALS ###=================//
    .clk     (clk),         // <-
    //=================### WRITE SIGNALS ###=================//
    .wr_en   (), // <-
    .addr_w  (), // <-
    .data_w  (), // <-
    //=================### READ SIGNALS ###==================//
    .addr_r1 (command.a1),  // <-
    .addr_r2 (command.a2),  // <-
    .addr_r3 (command.a3),  // <-
    .data_r1 (op_1),        // ->
    .data_r2 (op_2),        // ->
    .data_r3 (op_3)         // ->
    //=======================================================//
);
// ///////////////////////////////////////////////////////// //

// ///////////////////////////////////////////////////////// //
//                      *** CU FSM ***                       //
// NOTE: write a purpose here
cu_fsm cu_fsm_u (
    //================### COMMON SIGNALS ###=================//
    .clk         (clk),         // <-
    .rst_n       (rst_n),       // <-
    //===============### HANDSHAKE SIGNALS ###===============//
    .in_ready_o  (in_ready_o),  // <-
    .out_valid_o (out_valid_o), // <-
    .out_ready_i (out_ready_i), // ->
    .in_valid_i  (in_valid_i)   // ->
    //=======================================================//
);
// ///////////////////////////////////////////////////////// //

// ///////////////////////////////////////////////////////// //
//                     *** FPNEW TOP ***                     //
// NOTE: write a purpose here
fpnew_top #(
    // ----------------- GLOBAL PARAMETERS ----------------- //
    // Type of FPU configuration. Do not touch
    .Features       (fpnew_pkg::RV64D_Xsflt),
    .Implementation (fpnew_pkg::DEFAULT_NOREGS),
    .DivSqrtSel     (fpnew_pkg::THMULTI),
    .TrueSIMDClass  (0),
    .EnableSIMDMask (0),
    .TagType        (logic [3: 0])
) fpnew_top_u (
    /*================### COMMON SIGNALS ###=================*/
    .clk_i          (clk),              // <-
    .rst_ni         (rst_n),            // <-
    /*=================### MAIN SIGNALS ###==================*/
    .operands_i     (operands),         // <- (operands like a, b, c in a + b * c)
    .rnd_mode_i     (command.rnd),      // <- (type of round after calc)
    .op_i           (command.op),       // <- (type of operation in expression)
    .op_mod_i       (command.op_mod),   // <- (alt option for operation type)
    /*==============### SET FORMAT SIGNALS ###===============*/
    .src_fmt_i      (FP64),             // <- (type of incoming data)
    .dst_fmt_i      (FP64),             // <- (type of outcoming data)
    .int_fmt_i      (INT64),            // <- (type of data, if it int)
    /*==============### PROPERTIES SIGNALS ###===============*/
    .vectorial_op_i (),                 // <- (vectorial mode)
    .simd_mask_i    (),                 // <-
    .flush_i        (),                 // <-
    .tag_i          (),                 // <- (tag of operation set)
    .tag_o          (),                 // -> (tag of operation get)
    /*===============### HANDSHAKE SIGNALS ###===============*/
    .in_valid_i     (in_valid_i),   // <-
    .out_ready_i    (out_ready_i),  // <-
    .out_valid_o    (out_valid_o),  // ->
    .in_ready_o     (in_ready_o),   // ->
    /*================### RESULT SIGNALS ###=================*/
    .result_o       (), // ->
    .status_o       (), // ->
    .busy_o         (), // ->
    .early_valid_o  ()  // ->
    //=======================================================//
);
// ///////////////////////////////////////////////////////// //

endmodule
