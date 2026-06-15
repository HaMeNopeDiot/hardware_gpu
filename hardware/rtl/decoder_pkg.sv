//----------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// ---------------------------------------------------------------------------//
// Purpose: Core Decoder package
// Date:    26/06
//----------------------------------------------------------------------------//

package decoder_pkg;
    // ========================= ### COMMON ENUMS ### ======================= //
    parameter int unsigned DEC_FSM_W = 2;
    typedef enum logic [DEC_FSM_W - 1:0] {
        DEC_IDLE    = (DEC_FSM_W)'(0),
        DEC_WAIT    = (DEC_FSM_W)'(1),
        DEC_GIVE    = (DEC_FSM_W)'(2)
    } dec_fsm_t;

    // ====================================================================== //
endpackage
