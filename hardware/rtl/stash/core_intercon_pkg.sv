//------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// -----------------------------------------------------------------------------//
// Purpose: Package for core interconnect
// Date: 2026/06
//------------------------------------------------------------------------------//

package core_intercon_pkg;
    // ======================= ### COMMON STRUCTS ### ========================= //
    typedef enum logic [1:0] {
        HNDSHK_IDLE = 2'd0,
        HNDSHK_REQ  = 2'd1,
        HNDSHK_BUSY = 2'd2,
        HNDSHK_DONE = 2'd3
    } fsm_hndshk_e;

    // ======================================================================== //
endpackage
