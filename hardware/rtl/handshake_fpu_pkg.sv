//-------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// ------------------------------------------------------------------------------//
// Purpose: Structs for in/out ports in modules
//-------------------------------------------------------------------------------//

package handshake_fpu_pkg;
    localparam int unsigned TAGS_NUM = 8;
    localparam int unsigned TAGS_W = $clog2(TAGS_NUM);

    typedef logic [TAGS_W - 1: 0] tags_t;
    // ========================= ### COMMON ENUMS ### ========================= //
    localparam int unsigned FSM_FPU_STATE_NUM = 5;
    localparam int unsigned FSM_FPU_STATE_W = $clog2(FSM_FPU_STATE_NUM);
    typedef enum logic [FSM_FPU_STATE_W - 1:0] {
        FPU_IDLE    = (FSM_FPU_STATE_W)'(0),
        FPU_PRELOAD = (FSM_FPU_STATE_W)'(1),
        FPU_LOAD    = (FSM_FPU_STATE_W)'(2), // in_ready_o = 1
        FPU_PROCESS = (FSM_FPU_STATE_W)'(3), // out_valid_o != 1
        FPU_RESULT  = (FSM_FPU_STATE_W)'(4)  // out_valid_o = 1
    } fsm_fpu_state_e;

    typedef struct packed {
        fsm_fpu_state_e prev_state;
        fsm_fpu_state_e state;
    } proccess_t;
    // ======================================================================== //
endpackage
