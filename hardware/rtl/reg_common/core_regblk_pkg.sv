//------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// -----------------------------------------------------------------------------//
// Purpose: Core Regblock package
// Date: 2026/06
//------------------------------------------------------------------------------//

package core_regblk_pkg;
    import base_pkg::DW;

    localparam int unsigned  BYTES_IN_REG  = int'(DW / 8);
    // [REGISTERS]
    //----------------------- REGISTER ADDR OFFSET PARAMETERS ------------------//
    localparam int unsigned  R_CORE_CTRL_OFS               = 'h0 * BYTES_IN_REG;
    // localparam int unsigned  R_CORE_STATUS_OFS             = 'h1 * BYTES_IN_REG;
    localparam int unsigned  R_PC_OFS                      = 'h2 * BYTES_IN_REG;
    //                       [RESERVED]                    = 'h3 * BYTES_IN_REG;
    localparam int unsigned  RS_VID_OFS                    = 'h4 * BYTES_IN_REG;

    // [FIELDS]
    // - [CORE CONTROL]
    //------------------ REGISTER CORE CONTROL OFFSETS PARAMETERS --------------//
    localparam int unsigned  F_CORE_EN_OFS                      = 'h0;  // RW

    //------------------- REGISTER CORE CONTROL SIZE PARAMETERS ----------------//
    localparam int unsigned  F_CORE_EN_SZ                       = 'h1;

    //----------------------- REGISTER VID OFFSETS PARAMETERS ------------------//
    localparam int unsigned  F_VID_OFS                          = 'h0; // RW

    //------------------------ REGISTER VID SIZE PARAMETERS --------------------//
    localparam int unsigned  F_VID_SZ                           = DW;

    //----------------------- REGISTER PC OFFSETS PARAMETERS -------------------//
    localparam int unsigned  F_PC_OFS                           = 'h0; // RW

    //------------------------ REGISTER PC SIZE PARAMETERS ---------------------//
    localparam int unsigned  F_PC_SZ                            = DW;


    //--------------------------------------------------------------------------//
endpackage
