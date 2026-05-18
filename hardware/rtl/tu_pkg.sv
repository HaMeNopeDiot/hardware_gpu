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

    typedef struct packed {
        logic [DW - 1: 0] value;
        logic             valid;
    } dw_value_t;

    /*==========================================================================//
    region TU
    //==========================================================================*/
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

    /*==========================================================================//
    region OP
    //==========================================================================*/

    parameter int unsigned LSU_OP_W = 4 + 1;

    typedef enum logic[LSU_OP_W - 1: 0] {
        LOP_LW     = 0,
        LOP_SW     = 1
    } lsu_op_e;

    // DEC INSTR
    typedef enum logic {
        LSU_CMD = 0,
        FPU_CMD = 1
    } dec_op_type_e;

    typedef struct packed {
        operation_e t;
        logic       mod;
    } fpu_op_t;

    typedef union packed {
        lsu_op_e    lsu_op;
        fpu_op_t    fpu_op;
    } op_union_t;

    /*==========================================================================//
    region LSU
    //==========================================================================*/

    typedef struct packed {
        lsu_op_e        op;
        regfile_addr_t  rd, rs1, rs2;
    } lsu_cmd_t;

    /*==========================================================================//
    region ALU
    //==========================================================================*/

    // ALU
    typedef enum logic [1: 0] {
        AOP_ADD         = 0,
        AOP_IMM_LSHIFT  = 1
    } alu_op_e;

    typedef struct packed {
        logic [DW - 1: 0] o1, o2;
        alu_op_e          op;
        logic             valid;
    } tu_alu_t;

    /*==========================================================================//
    region TYPE OF COMMANDS FROM DECODER
    //==========================================================================*/

    localparam int unsigned F_IMM_W = DW - (REGFILE_AW * 4 + LSU_OP_W + 3);
    // fpu
    typedef struct packed {
        op_union_t              operand;         // 5
        regfile_addr_t          a1, a2, a3, ar;  // 3 * 4 = 12
        logic [2:0]             extra;           // 3
        logic [F_IMM_W - 1: 0]  imm;
    } f_cmd_t;


    localparam int unsigned L_IMM_W = DW - (REGFILE_AW * 3 + LSU_OP_W);
    // lsu
    typedef struct packed {
        regfile_addr_t          rs1_addr, rs2_addr, rd_addr;
        op_union_t              operand;
        logic [L_IMM_W - 1: 0]  imm;
    } l_cmd_t;

    /*==========================================================================//
    region DECODER COMMAND MAIN
    //==========================================================================*/
    typedef union packed {
        f_cmd_t f;
        l_cmd_t l;
    } cmd_union_t;

    typedef struct packed {
        dec_op_type_e  op_type;
        cmd_union_t    cmd;
    } cmd_t;

    // ======================================================================== //
endpackage
