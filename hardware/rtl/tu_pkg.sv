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
    import fpnew_pkg::OP_BITS;

    // ========================= ### COMMON ENUMS ### ========================= //
    localparam int unsigned REGFILE_SIZE    = 8;
    localparam int unsigned REGFILE_AW      = $clog2(REGFILE_SIZE);
    localparam int unsigned DW              = 64;

    typedef logic [REGFILE_AW - 1 : 0] regfile_addr_t;

    /* Danya, take a notice please:
    typedef struct packed {
        logic a; <- high bit
        logic b;
        ...
        logic z; <- low bit
    } aboba_t;
    */

    // TU

    typedef struct packed {
        operation_e     op;
        logic           op_mod;
        regfile_addr_t  a1, a2, a3, ar;
        tags_t          tag;
        roundmode_e     rnd;
    } thread_command_t;

    typedef struct packed {
        tags_t            tag;
        status_t          status;
        logic             is_busy;
        logic             early_valid;
    } thread_info_t;

    typedef struct packed {
        logic [DW - 1: 0] result_data;
        thread_info_t     info;
    } thread_result_t;

    // ALU

    typedef enum logic [1: 0] {
        AOP_ADD         = 0,
        AOP_IMM_LSHIFT  = 1
    } alu_op_e;


    // LSU

    parameter int unsigned LSU_OP_W = 4;
    parameter int unsigned IMM_W = DW - (REGFILE_AW * 3 + LSU_OP_W);

    typedef logic [IMM_W - 1: 0] imm_t;

    typedef enum logic[LSU_OP_W - 1: 0] {
        LOP_LW     = 0,
        LOP_SW     = 1
    } lsu_op_e;

    typedef struct packed {
        lsu_op_e        op;
        regfile_addr_t  rd, rs1, rs2;
        imm_t           imm;
    } lsu_cmd_t;

    typedef struct packed {
        logic                     rw;
        regfile_addr_t            addr;
        logic [DW - 1        : 0] data_w;
    } lsu2tu_txn_t;

    // DEC INSTR
    typedef enum logic {
        LSU_CMD = 0,
        FPU_CMD = 1
    } dec_op_type_e;

    typedef union packed {
        lsu_op_e    lsu_op;
        operation_e fpu_op;
    } op_union_t;

    /*==========================================================================//
    region TYPE OF COMMANDS FROM DECODER
    //==========================================================================*/

    // fpu
    typedef struct packed {
        dec_op_type_e  op_type;
        op_union_t     operand;
        regfile_addr_t a1, a2, a3, ar;
        logic [2:0]    extra;
        logic [10:0]   imm;
    } f_cmd_t;

    // lsu
    typedef struct packed {
        regfile_addr_t rs1_addr;
        regfile_addr_t rs2_addr;
        regfile_addr_t rd_addr;
    } dec2tu_bus_t;

    typedef struct packed {
        dec_op_type_e   op_type;
        op_union_t      operand;
        logic [16:0]    imm;
    } dec2lsu_bus_t;

    typedef struct packed {
        dec2lsu_bus_t   to_lsu;
        dec2tu_bus_t    to_tu;
    } l_cmd_t;
    /*==========================================================================//
    region DECODER COMMAND MAIN
    //==========================================================================*/
    typedef union packed {
        f_cmd_t fcmd;
        l_cmd_t lcmd;
    } cmd_union_t;

    // ======================================================================== //
endpackage
