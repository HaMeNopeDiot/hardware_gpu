//----------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// ---------------------------------------------------------------------------//
// Purpose: GPU Core decoder
// Date: 2026/06
//----------------------------------------------------------------------------//

/*============================================================================//
region MODULE DEFINITION
//============================================================================*/
module core_decoder
    import fpnew_pkg::roundmode_e;
    import fpnew_pkg::operation_e;
    import fpnew_pkg::MINMAX;
    import fpnew_pkg::SGNJ;
    import fpnew_pkg::RTZ;


    import fpnew_pkg::ADD;
    import fpnew_pkg::MUL;
    import fpnew_pkg::SQRT;
    import fpnew_pkg::DIV;



    import handshake_fpu_pkg::tags_t;
    import tu_pkg::cmd_union_t;
    import tu_pkg::cmd_t;
    import tu_pkg::dec_op_type_e;
    import tu_pkg::thread_command_t;
    import tu_pkg::tags_t;


    import tu_pkg::SOP_SW;
    import tu_pkg::SOP_ADD;
    import tu_pkg::SOP_MUL;

    import tu_pkg::LOP_LW;
    import tu_pkg::LOP_ADDI;

    import tu_pkg::UOP_IMM;
    import tu_pkg::UOP_RET;

    import tu_pkg::U_IMM_W;
    // type cmd
    import tu_pkg::S_CMD;
    import tu_pkg::L_CMD;
    import tu_pkg::F_CMD;
    import tu_pkg::U_CMD;
    // LSU
    import lsu_pkg::LSU_L;
    import lsu_pkg::LSU_S;
    import lsu_pkg::lsu_cmd_e;

    import decoder_pkg::dec_fsm_t;
    import decoder_pkg::DEC_IDLE;
    import decoder_pkg::DEC_WAIT;
    import decoder_pkg::DEC_GIVE;

    // dbg
    import tu_pkg::dbg_cmd_t;
    import tu_pkg::cmd_op_t;
    import tu_pkg::CMD_UNKN ;
    import tu_pkg::CMD_RET  ;
    import tu_pkg::CMD_LW   ;
    import tu_pkg::CMD_SW   ;
    import tu_pkg::CMD_LUI  ;
    import tu_pkg::CMD_ADDI ;
    import tu_pkg::CMD_ADD  ;
    import tu_pkg::CMD_MUL  ;
    import tu_pkg::CMD_FADD ;
    import tu_pkg::CMD_FMUL ;
    import tu_pkg::CMD_FDIV ;
    import tu_pkg::CMD_FSQRT;
    import tu_pkg::CMD_FNEG ;
    import tu_pkg::CMD_FMAX ;

#(
    parameter logic DEBUG_MODE = 1
) (
    /*=======================### COMMON SIGNALS ###===========================*/
    input  logic                clk,
    input  logic                rst_n,

    /*===================### SIGNALS FROM CONTROL UNIT ###====================*/
    input  cmd_t                instr_i,
    input  logic                instr_valid,

    /*=======================### CMD SIGNALS ###==============================*/
    output cmd_union_t          cmd,
    output dec_op_type_e        cmd_op_type,

    /*=========================### SIGNALS TO LSU ###=========================*/
    output lsu_cmd_e            lsu_cmd,
    output logic                lsu_cmd_valid,

    /*=========================### SIGNALS TO FPU ###=========================*/
    output thread_command_t     fpu_cmd,
    output logic                fpu_cmd_valid,

    /*========================### SIGNALS FROM FPU ###========================*/
    input  logic                threads_valid_i,
    output logic                decoder_ready_o,
    output logic                ret_inst_o,
    input  logic                en_i
    //========================================================================//
);

/*============================================================================//
region LOGIC
//============================================================================*/

logic  l_cmd_valid, u_cmd_valid, s_cmd_valid, f_cmd_valid;
assign l_cmd_valid      = instr_valid && (instr_i.op_type == L_CMD);
assign u_cmd_valid      = instr_valid && (instr_i.op_type == U_CMD);
assign f_cmd_valid      = instr_valid && (instr_i.op_type == F_CMD);
assign s_cmd_valid      = instr_valid && (instr_i.op_type == S_CMD);

logic  is_lsu_load, is_lsu_store;
assign is_lsu_load  = l_cmd_valid? (instr_i.cmd.l.operand == LOP_LW? 1: 0): 0;
assign is_lsu_store = s_cmd_valid? (instr_i.cmd.s.operand == SOP_SW? 1: 0): 0;

logic  i_with_delay;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        i_with_delay <= '0;
    else
        i_with_delay <= is_lsu_load || is_lsu_store || f_cmd_valid;
end

logic threads_valid_prev;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        threads_valid_prev <= '0;
    else
        threads_valid_prev <= threads_valid_i;
end

logic  tu_valid_re;
assign tu_valid_re = ~threads_valid_prev && threads_valid_i;


logic  threads_free;
assign threads_free = (~(i_with_delay && ~tu_valid_re)) && threads_valid_i;

logic  decoder_activate;
assign decoder_activate = en_i && (~ret_inst_o);

/*============================================================================//
region FSM
//============================================================================*/

dec_fsm_t state, next_state;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        state <= DEC_IDLE;
    else
        state <= next_state;
end

always_comb begin
    case (state)
        DEC_IDLE: begin
            if (instr_valid && decoder_activate)
                if (threads_free)
                    next_state = DEC_GIVE;
                else
                    next_state = DEC_WAIT;
            else
                next_state = DEC_IDLE;
        end
        DEC_WAIT: begin
            if (~decoder_activate)
                next_state = DEC_IDLE;
            if (threads_free)
                next_state = DEC_GIVE;
            else
                next_state = DEC_WAIT;
        end
        DEC_GIVE: begin
            if (instr_valid && decoder_activate)
                if (threads_free)
                    next_state = DEC_GIVE;
                else
                    next_state = DEC_WAIT;
            else
                next_state = DEC_IDLE;
        end
        default: begin
            next_state = DEC_IDLE;
        end
    endcase
end

logic prepare_give;
logic prepare_wait;
logic prepare_idle;

assign prepare_give = next_state == DEC_GIVE;
assign prepare_wait = next_state == DEC_WAIT;
assign prepare_idle = next_state == DEC_IDLE;

logic  give_rn;
assign give_rn = state == DEC_GIVE;

logic  can_latch_for_wait;
assign can_latch_for_wait = ~prepare_wait;


/*============================================================================//
region FPU
//============================================================================*/

thread_command_t fpu_cmd_ff;
logic            fpu_cmd_valid_ff;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n) begin
        fpu_cmd_ff              <= '0;
        fpu_cmd_valid_ff        <= '0;
    end
    else if (prepare_give || can_latch_for_wait) begin
        if (f_cmd_valid) begin
            fpu_cmd_ff.op       <= instr_i.cmd.f.operand.t;
            fpu_cmd_ff.op_mod   <= instr_i.cmd.f.operand.mod;
            fpu_cmd_ff.a1       <= instr_i.cmd.f.a1;
            fpu_cmd_ff.a2       <= instr_i.cmd.f.a2;
            fpu_cmd_ff.a3       <= instr_i.cmd.f.a3;
            fpu_cmd_ff.ar       <= instr_i.cmd.f.ar;
            fpu_cmd_ff.tag      <= (tags_t)'(instr_i.cmd.f.imm);
            // Yeah, i know that minmax is not only max and sgnj is not only
            // negate, but for this case I need only MAX and negate the number.
            // So, in cvfpu this works only with RTZ round mode
            if (instr_i.cmd.f.operand.t == MINMAX || instr_i.cmd.f.operand.t == SGNJ)
                fpu_cmd_ff.rnd      <= (roundmode_e)'(RTZ);
            else
                fpu_cmd_ff.rnd      <= (roundmode_e)'(instr_i.cmd.f.extra);
            fpu_cmd_valid_ff    <= '1;
        end
        else begin
            fpu_cmd_ff          <= '0;
            fpu_cmd_valid_ff    <= '0;
        end
    end
    else if (prepare_idle) begin
        fpu_cmd_ff              <= '0;
        fpu_cmd_valid_ff        <= '0;
    end
end

/*============================================================================//
region LSU
//============================================================================*/

lsu_cmd_e   lsu_cmd_ff;
logic       lsu_cmd_valid_ff;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n) begin
        lsu_cmd_ff              <= LSU_L;
        lsu_cmd_valid_ff        <= '0;
    end
    else if (prepare_give || can_latch_for_wait) begin
        if (is_lsu_load) begin
            lsu_cmd_ff          <= LSU_L;
            lsu_cmd_valid_ff    <= '1;
        end
        else if (is_lsu_store) begin
            lsu_cmd_ff          <= LSU_S;
            lsu_cmd_valid_ff    <= '1;
        end
        else begin
            lsu_cmd_ff          <= LSU_L;
            lsu_cmd_valid_ff    <= '0;
        end
    end
    else if (prepare_idle) begin
        lsu_cmd_ff              <= LSU_L;
        lsu_cmd_valid_ff        <= '0;
    end
end

/*============================================================================//
region MAIN CMD
//============================================================================*/


cmd_union_t     cmd_ff;
dec_op_type_e   cmd_op_type_ff;

logic  no_fpu_cmd_valid;
assign no_fpu_cmd_valid = l_cmd_valid || u_cmd_valid || s_cmd_valid; // maked it dumb.

always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n) begin
        cmd_ff              <= '0;
        cmd_op_type_ff      <= U_CMD; // so it's write in zero address zero, that prohibited.
    end
    else if ((prepare_give || can_latch_for_wait)) begin
        if (no_fpu_cmd_valid) begin
            cmd_ff          <= instr_i.cmd;
            cmd_op_type_ff  <= instr_i.op_type;
        end
        else begin
            cmd_ff          <= '0;
            cmd_op_type_ff  <= U_CMD;
        end
    end
    else if (prepare_idle) begin
        cmd_ff              <= '0;
        cmd_op_type_ff      <= U_CMD;
    end
end

/*============================================================================//
region DEBUG MODE
//============================================================================*/

if (DEBUG_MODE) begin: gen_debug_info
    /* verilator lint_off UNUSEDSIGNAL */
    int unsigned cmd_idx, cmd_idx_ff;
    always_ff @(posedge clk or negedge rst_n) begin
        if (~rst_n)
            cmd_idx_ff <= '0;
        else if (give_rn)
            cmd_idx_ff <= cmd_idx_ff + 1;
        else
            cmd_idx_ff <= cmd_idx_ff;
    end

    assign cmd_idx = give_rn? cmd_idx_ff: '0;

    /* verilator lint_off UNUSEDSIGNAL */
    dbg_cmd_t command;
    always_comb begin
        if (give_rn) begin
            if (fpu_cmd_valid) begin
                case (fpu_cmd.op)
                    ADD:
                        command.op = CMD_FADD;
                    MUL:
                        command.op = CMD_FMUL;
                    DIV:
                        command.op = CMD_FDIV;
                    SQRT:
                        command.op = CMD_FSQRT;
                    SGNJ:
                        command.op = CMD_FNEG; // bad idea
                    MINMAX:
                        command.op = CMD_FMAX; // bad idea
                    default:
                        command.op = CMD_UNKN;
                endcase
                command.rs1_a   = fpu_cmd.a1;
                command.rs2_a   = fpu_cmd.a2;
                command.rs3_a   = fpu_cmd.a3;
                command.rd_a    = fpu_cmd.ar;
                command.imm     = (U_IMM_W)'(fpu_cmd.tag);
                command.extra   = fpu_cmd.rnd;
            end
            else begin
                case (cmd_op_type)
                    U_CMD: begin
                        case (cmd.u.operand)
                            UOP_IMM: command.op = CMD_LUI;
                            UOP_RET: command.op = CMD_RET;
                            default: command.op = CMD_UNKN;
                        endcase
                        command.rs1_a   = '0;
                        command.rs2_a   = '0;
                        command.rs3_a   = '0;
                        command.rd_a    = cmd.u.rd_addr;
                        command.extra   = '0;
                        command.imm     = cmd.u.imm;
                    end
                    L_CMD: begin
                        case (cmd.l.operand)
                            LOP_LW:     command.op = CMD_LW;
                            LOP_ADDI:   command.op = CMD_ADDI;
                            default:    command.op = CMD_UNKN;
                        endcase
                        command.rs1_a   = cmd.l.rs1_addr;
                        command.rs2_a   = '0;
                        command.rs3_a   = '0;
                        command.rd_a    = cmd.l.rd_addr;
                        command.extra   = '0;
                        command.imm     = (U_IMM_W)'(cmd.l.imm);
                    end
                    S_CMD: begin
                        case (cmd.s.operand)
                            SOP_SW:     command.op = CMD_SW;
                            SOP_ADD:    command.op = CMD_ADD;
                            SOP_MUL:    command.op = CMD_MUL;
                            default:    command.op = CMD_UNKN;
                        endcase
                        command.rs1_a   = cmd.s.rs1_addr;
                        command.rs2_a   = cmd.s.rs2_addr;
                        command.rs3_a   = '0;
                        command.rd_a    = cmd.s.rd_addr;
                        command.extra   = '0;
                        command.imm     = (U_IMM_W)'(cmd.s.imm);
                    end
                    F_CMD:
                        command.op = CMD_UNKN;
                    default:
                        command.op = CMD_UNKN;
                endcase
            end
        end
        else begin
            command = '0;
        end
    end
end

/*============================================================================//
region OUT
//============================================================================*/

assign decoder_ready_o = next_state != DEC_WAIT;

// cmd for threads
assign cmd              = give_rn? cmd_ff              : '0;
assign cmd_op_type      = give_rn? cmd_op_type_ff      : U_CMD;
// lsu
assign lsu_cmd          = give_rn? lsu_cmd_ff          : LSU_L;
assign lsu_cmd_valid    = give_rn? lsu_cmd_valid_ff    : '0;
// fpu
assign fpu_cmd          = give_rn? fpu_cmd_ff          : '0;
assign fpu_cmd_valid    = give_rn? fpu_cmd_valid_ff    : '0;

// ret
assign ret_inst_o       =   give_rn
                        && (cmd_op_type_ff == U_CMD)
                        && (cmd_ff.u.operand == UOP_RET)? 1: '0;

//============================================================================*/
endmodule
