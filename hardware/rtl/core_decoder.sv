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


    import handshake_fpu_pkg::tags_t;
    import tu_pkg::cmd_union_t;
    import tu_pkg::cmd_t;
    import tu_pkg::dec_op_type_e;
    import tu_pkg::thread_command_t;
    import tu_pkg::tags_t;


    import tu_pkg::SOP_SW;
    import tu_pkg::LOP_LW;
    import tu_pkg::UOP_RET;
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

#() (
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
    output logic                ret_inst_o
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
            if (instr_valid)
                if (threads_free)
                    next_state = DEC_GIVE;
                else
                    next_state = DEC_WAIT;
            else
                next_state = DEC_IDLE;
        end
        DEC_WAIT: begin
            if (threads_free)
                next_state = DEC_GIVE;
            else
                next_state = DEC_WAIT;
        end
        DEC_GIVE: begin
            if (instr_valid)
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
