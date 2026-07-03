//------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// -----------------------------------------------------------------------------//
// Purpose: Core Reg Structure Package
// Date: 2026/07
//------------------------------------------------------------------------------//

package core_csrm_pkg;
    // ============================ ### COMMON PARAMS ### ===================== //

    class core_csrm_pkg #(
        parameter int unsigned DW         = 32,
        parameter int unsigned THREAD_CNT = 4
    );
        typedef struct packed {
            logic                                   en_o;
            logic [THREAD_CNT - 1: 0][DW - 1: 0]    vid_o;
            logic [DW - 1: 0]                       cur_pc_o;
            logic [THREAD_CNT - 1: 0]               thread_en_o;
        } csrm_sig_out_t;

        typedef struct packed {
            logic   ret_i;
            logic   pc_readed_i;
        } csrm_req_sig_t;
    endclass

    // ======================================================================== //
endpackage
