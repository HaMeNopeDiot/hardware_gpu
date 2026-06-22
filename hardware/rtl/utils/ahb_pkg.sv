//-------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// ------------------------------------------------------------------------------//
// Purpose: Thread unit package
// Date: 2026/06
//-------------------------------------------------------------------------------//

package ahb_pkg;
    import base_pkg::AW;
    import base_pkg::DW;
    // ========================= ### COMMON ENUMS ### ========================= //

    typedef enum logic [2: 0] {
        HBURST_SINGLE   = 3'b000,
        HBURST_INCR     = 3'b001,
        HBURST_WRAP4    = 3'b010,
        HBURST_INCR4    = 3'b011,
        HBURST_WRAP8    = 3'b100,
        HBURST_INCR8    = 3'b101,
        HBURST_WRAP16   = 3'b110,
        HBURST_INCR16   = 3'b111
    } hburst_e;

    typedef enum logic [2: 0] {
        HSIZE_BYTE     = 3'b000,    // 8
        HSIZE_HWORD    = 3'b001,    // 16
        HSIZE_WORD     = 3'b010,    // 32
        HSIZE_DWORD    = 3'b011,    // 64
        HSIZE_4WORD    = 3'b100,    // 128
        HSIZE_8WORD    = 3'b101,    // 256
        HSIZE_16WORD   = 3'b110,    // 512
        HSIZE_32WORD   = 3'b111     // 1024
    } hsize_e;

    typedef enum logic [1: 0] {
        HTRANS_IDLE     = 2'b00,
        HTRANS_BUSY     = 2'b01,
        HTRANS_NONSEQ   = 2'b10,
        HTRANS_SEQ      = 2'b11
    } htrans_e;

    typedef enum logic {
        HTRANS_DORO_OPCODE   = 1'b0,
        HTRANS_DORO_DATA     = 1'b1
    } hprot_doro_e;

    typedef enum logic {
        HTRANS_ACCS_USER     = 1'b0,
        HTRANS_ACCS_PRIV     = 1'b1
    } hprot_accs_e; // access type

    typedef enum logic {
        HTRANS_BUFE_ON      = 1'b0,
        HTRANS_BUFE_OFF     = 1'b1
    } hprot_bufe_e; // bufferable

    typedef enum logic {
        HTRANS_CACH_ON      = 1'b0,
        HTRANS_CACH_OFF     = 1'b1
    } hprot_cach_e; // cacheable

    typedef struct packed {
        hprot_cach_e cache;
        hprot_bufe_e buffer;
        hprot_accs_e access_type;
        hprot_doro_e txn_type;
    } hprot_t;

    typedef enum logic[1: 0] {
        AHB_IDLE    = 2'b00,
        AHB_STALL   = 2'b01,
        AHB_ACTIVE  = 2'b10,
        AHB_ERROR   = 2'b11
    } ahb_txn_e;

    typedef enum logic [2:0] {
        AHB_FSM_IDLE    = 3'b000,
        AHB_FSM_SADDR   = 3'b001,
        AHB_FSM_SDATA   = 3'b010,
        AHB_FSM_BOTH    = 3'b011,
        AHB_FSM_ERROR   = 3'b100
    } ahb_fsm_e;

    // - structs
    // ======================================================================== //

    typedef struct packed {
        logic [AW - 1: 0]   haddr;
        logic               hwrite;
        hsize_e             hsize;
        hburst_e            hburst;
        hprot_t             hprot;
        htrans_e            htrans;
        logic               hmastlock;
        logic [DW - 1: 0]   hwdata;
    } ahb_mports_t;

    typedef struct packed {
        logic               hready;
        logic               hresp;
        logic [DW - 1: 0]   hrdata;
    } ahb_sports_t;

    // ======================================================================== //
endpackage
