//------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// -----------------------------------------------------------------------------//
// Purpose: Package for LSU
// Date: 2026/06
//------------------------------------------------------------------------------//

package core_lsu_pkg;
    import base_pkg::DW;
    import base_pkg::THREADS_W;
    // ======================= ### COMMON STRUCTS ### ========================= //

    typedef struct {
        logic [DW - 1: 0]           rs1, rs2;
        logic [THREADS_W - 1: 0]    vid;
    } lsu_load_q_elem_t;

    typedef struct {
        logic                       done;
        logic [DW - 1: 0]           rd;
        logic [THREADS_W - 1: 0]    vid;
    } lsu_store_q_elem_t;


    typedef struct {
        logic                       done;
        logic [DW - 1: 0]           rs1, rs2, rd;
        logic [THREADS_W - 1: 0]    vid;
    } lsu_q_elem_t;
    // ======================================================================== //
endpackage
