//----------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// ---------------------------------------------------------------------------//
// Purpose: CORE LSU FSM
// Date:    26/05
//----------------------------------------------------------------------------//

package core_lsu_fsm_pkg;
    // ========================= ### COMMON ENUMS ### ======================= //
    parameter int unsigned LSU_FSM_W = 2;
    typedef enum logic [LSU_FSM_W - 1:0] {
        LSU_IDLE  = (LSU_FSM_W)'(0),
        LSU_SEND  = (LSU_FSM_W)'(1),
        LSU_RQ    = (LSU_FSM_W)'(2),
        LSU_DONE  = (LSU_FSM_W)'(3)
    } lsu_fsm_t;

    // ====================================================================== //
endpackage
