//-------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// ------------------------------------------------------------------------------//
// Purpose: Thread unit package
//-------------------------------------------------------------------------------//

package tu_pkg;
    import handshake_fpu_pkg::tags_t;
    import fpnew_pkg::roundmode_e;
    import fpnew_pkg::status_t;
    import fpnew_pkg::operation_e;
    // ========================= ### COMMON ENUMS ### ========================= //
    localparam int unsigned REGFILE_SIZE    = 6;
    localparam int unsigned REGFILE_AW      = $clog2(REGFILE_SIZE);
    localparam int unsigned DW              = 64;

    typedef struct packed {
        operation_e                 op;
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

    typedef struct packed {
        logic                     rw;
        logic [REGFILE_AW - 1: 0] addr;
        logic [DW - 1        : 0] data_w;
    } lsu2tu_txn_t;
    // ======================================================================== //
endpackage
