//------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// -----------------------------------------------------------------------------//
// Purpose: Core Reg Structure
// Date: 2026/06
//------------------------------------------------------------------------------//

package core_reg_structure_pkg;
    import base_pkg::DW;
    import core_regblk_pkg::*;
    // ============================ ### COMMON PARAMS ### ===================== //
    localparam int unsigned F_PARAM_W               = $clog2(DW) + 1;

    // Package with access types. Add only needed acces types in enum
    parameter int unsigned F_ACCESS_TYPE_W = 2;
    typedef enum logic [F_ACCESS_TYPE_W - 1: 0] {
        F_ACCESS_RW     = (F_ACCESS_TYPE_W)'(0),
        F_ACCESS_RO     = (F_ACCESS_TYPE_W)'(1),
        F_ACCESS_WO     = (F_ACCESS_TYPE_W)'(2),
        F_ACCESS_W1S    = (F_ACCESS_TYPE_W)'(3)
    } f_access_type_e;

    /*==========================================================================//
    region CORE CONTROL
    //==========================================================================*/

    // =========================== ### CORE CONTROL ### ======================= //

    localparam int unsigned CORE_CTRL_F_NUM = 1;
    localparam int unsigned CORE_CTRL_ARR_W = CORE_CTRL_F_NUM * F_PARAM_W;

    // WIDTH
    localparam logic [CORE_CTRL_ARR_W - 1: 0] CORE_CTRL_F_W = {
        (F_PARAM_W)'(F_CORE_EN_SZ )
    };
    // OFFSETS
    localparam logic [CORE_CTRL_ARR_W - 1: 0] CORE_CTRL_F_OFS = {
        (F_PARAM_W)'(F_CORE_EN_OFS )
    };
    // ACCESS TYPES
    // localparam logic [CORE_CTRL_ARR_W - 1: 0] CORE_CTRL_F_AT = {
    //     (F_PARAM_W)'(F_ACCESS_RW)
    // };


    /*==========================================================================//
    region VID
    //==========================================================================*/

    // =============================== ### VID ### ============================ //
    localparam int unsigned VID_F_NUM = 1;
    localparam int unsigned VID_ARR_W = VID_F_NUM * F_PARAM_W;

    // WIDTH
    localparam logic [VID_ARR_W - 1: 0] VID_F_W = {
        (F_PARAM_W)'(F_VID_SZ )
    };
    // OFFSETS
    localparam logic [VID_ARR_W - 1: 0] VID_F_OFS = {
        (F_PARAM_W)'(F_VID_OFS )
    };
    // ACCESS TYPES
    // localparam logic [VID_ARR_W - 1: 0] VID_F_AT = {
    //     (F_PARAM_W)'(F_ACCESS_RW)
    // };


    /*==========================================================================//
    region PC
    //==========================================================================*/

    // ================================ ### PC ### ============================ //
    localparam int unsigned PC_F_NUM = 1;
    localparam int unsigned PC_ARR_W = PC_F_NUM * F_PARAM_W;

    // WIDTH
    localparam logic [PC_ARR_W - 1: 0] PC_F_W = {
        (F_PARAM_W)'(F_PC_SZ )
    };
    // OFFSETS
    localparam logic [PC_ARR_W - 1: 0] PC_F_OFS = {
        (F_PARAM_W)'(F_PC_OFS )
    };
    // ACCESS TYPES
    // localparam logic [PC_ARR_W - 1: 0] PC_F_AT = {
    //     (F_PARAM_W)'(F_ACCESS_RW)
    // };



    // ======================================================================== //
endpackage
