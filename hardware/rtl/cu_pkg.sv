//------------------------------------------------------------------------------
// Department:            Software Laboratory
// Author:                Starukhin Danila M.
// Author's e-mail:       starukhin.d@milandr.ru
// -----------------------------------------------------------------------------
// Purpose: Compute unit package
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


package cu_pkg;
    import handshake_fpu_pkg::tags_t;
    import fpnew_pkg::roundmode_e;
    import fpnew_pkg::status_t;
    // ========================= ### COMMON ENUMS ### ========================= //
    localparam int unsigned REGFILE_SIZE    = 6;
    localparam int unsigned REGFILE_AW      = $clog2(REGFILE_SIZE);
    localparam int unsigned DW              = 64;

    typedef struct packed {
        operation_t                 op;
        logic                       op_mod;
        logic [REGFILE_AW - 1: 0]   a1, a2, a3, ar;
        tags_t                      tag;
        roundmode_e                 rnd;
    } thread_command_t;

    typedef struct packed {
        tags_t            tag;
        logic [DW - 1: 0] result_data;
        status_t          status;
        logic             is_busy;
        logic             early_valid;
    } thread_result_t;
    // ======================================================================== //
endpackage
