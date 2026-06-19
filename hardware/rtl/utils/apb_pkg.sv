//------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// -----------------------------------------------------------------------------//
// Purpose: APB slave package
// Date: 2026/06
//------------------------------------------------------------------------------//

package apb_pkg;
    import base_pkg::*;

    localparam int unsigned STROBE = DW / 8;

    typedef struct packed {
        logic [AW     - 1: 0] paddr;
        logic [DW     - 1: 0] pwdata;
        logic [STROBE - 1: 0] pstrb;
        logic                 psel;
        logic                 pwrite;
        logic                 penable;
        logic [2: 0]          pprot;
    } apb4_mports_t;

    typedef struct packed {
        logic [DW     - 1: 0] prdata;
        logic                 pready;
        logic                 pslverr;
    } apb4_sports_t;

    localparam int unsigned APB_SLV_FSM_W = 3;
    typedef enum logic [APB_SLV_FSM_W - 1: 0] {
        APB_SLV_IDLE        = (APB_SLV_FSM_W)'(0),
        APB_SLV_SETUP       = (APB_SLV_FSM_W)'(1),
        APB_SLV_STALL       = (APB_SLV_FSM_W)'(2),
        APB_SLV_ACCESS      = (APB_SLV_FSM_W)'(3)
    } apb_slv_fsm_e;
endpackage
