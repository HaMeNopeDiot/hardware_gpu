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

    import base_pkg::DW;

    // ========================= ### COMMON ENUMS ### ========================= //
    localparam int unsigned REGFILE_SIZE    = 8;
    localparam int unsigned REGFILE_AW      = $clog2(REGFILE_SIZE);

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
    region LSU
    //==========================================================================*/

    parameter int unsigned LSU_OP_W = 4 + 1;
    typedef enum logic[LSU_OP_W - 1: 0] {
        LOP_LW     = 0, // rd = M[rs1 + imm]
        LOP_SW     = 1, // M[rs1 + imm] = rs2
        LOP_ADDI   = 2, // rd = r1 + imm
        LOP_ADD    = 3, // rd = r1 + r2
        LOP_MUL    = 4  // rd = r1 * r2
    } lsu_op_e;

    typedef struct packed {
        lsu_op_e        op;
        regfile_addr_t  rd, rs1, rs2;
    } lsu_cmd_t;

    /*==========================================================================//
    region UPPER
    //==========================================================================*/

    parameter int unsigned U_OP_W = 4 + 1;
    typedef enum logic[U_OP_W - 1: 0] {
        UOP_IMM = 0,    // rd = rs1 << 20
        UOP_APC = 1     // PC = PC + 4
    } u_op_e;


    /*==========================================================================//
    region OP
    //==========================================================================*/

    typedef struct packed {
        operation_e t;
        logic       mod;
    } fpu_op_t;

    typedef union packed {
        lsu_op_e    lsu_op;
        fpu_op_t    fpu_op;
        u_op_e      upp_op;
    } op_union_t;


    /*==========================================================================//
    region ALU
    //==========================================================================*/

    // ALU
    typedef enum logic [1: 0] {
        AOP_ADD         = 0,    // r = s1 + s2
        AOP_IMM_LSHIFT  = 1,    // r = s1 << s2
        AOP_MUL         = 2     // r = s1 * s2
    } alu_op_e;

    typedef struct packed {
        logic [DW - 1: 0] o1, o2;
        alu_op_e          op;
        logic             valid;
    } tu_alu_t;

    /*==========================================================================//
    region TYPE OF COMMANDS FROM DECODER
    //==========================================================================*/
    localparam int unsigned  DEC_OP_W = 2;

    localparam int unsigned F_IMM_W = DW - (REGFILE_AW * 4 + LSU_OP_W + DEC_OP_W + 3);
    // fpu
    typedef struct packed {
        op_union_t              operand;         // 5
        regfile_addr_t          a1, a2, a3, ar;  // 3 * 4 = 12
        logic [2:0]             extra;           // 3
        logic [F_IMM_W - 1: 0]  imm;             //
    } f_cmd_t;


    localparam int unsigned L_IMM_W = DW - (REGFILE_AW * 3 + LSU_OP_W + DEC_OP_W);
    // lsu
    typedef struct packed {
        op_union_t              operand;                        // 5
        regfile_addr_t          rs1_addr, rs2_addr, rd_addr;    // 3 * 3 = 9
        logic [L_IMM_W - 1: 0]  imm;                            //
    } l_cmd_t;

    localparam int unsigned U_OFS_IMM_W = REGFILE_AW + LSU_OP_W + DEC_OP_W;
    localparam int unsigned U_IMM_W     = DW - U_OFS_IMM_W;
    // upper imid
    typedef struct packed {
        op_union_t              operand; // 5
        regfile_addr_t          rd_addr; // 3
        logic [U_IMM_W - 1: 0]  imm;
    } u_cmd_t;

    /*==========================================================================//
    region DECODER COMMAND MAIN
    //==========================================================================*/
    typedef union packed {
        f_cmd_t f;
        l_cmd_t l;
        u_cmd_t u;
    } cmd_union_t;

    // DEC INSTR
    typedef enum logic [DEC_OP_W - 1: 0] {
        NO_CMD  = 0,
        LSU_CMD = 1,
        FPU_CMD = 2,
        UPP_CMD = 3
    } dec_op_type_e;


    typedef struct packed {
        dec_op_type_e  op_type;
        cmd_union_t    cmd;
    } cmd_t;

    /*==========================================================================//
    region CORE
    //==========================================================================*/

    localparam int unsigned CORE_STATE_W = 3;
    typedef enum logic [CORE_STATE_W - 1: 0] {
        CORE_STATE_FETCH   = 0,
        CORE_STATE_DECODE  = 1,
        CORE_STATE_LOAD    = 2,
        CORE_STATE_EXECUTE = 3,
        CORE_STATE_STORE   = 4
    } core_state_e;

    localparam int unsigned TU_STATE_W = 2;
    typedef enum logic [TU_STATE_W - 1: 0] {
        TU_STATE_IDLE    = 0,
        TU_STATE_REQUEST = 1,
        TU_STATE_WAIT    = 2,
        TU_STATE_DONE    = 3
    } tu_state_e;

    // ======================================================================== //
endpackage
