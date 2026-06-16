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


    import handshake_fpu_pkg::tags_t;
    import tu_pkg::cmd_union_t;
    import tu_pkg::cmd_t;
    import tu_pkg::dec_op_type_e;
    import tu_pkg::thread_command_t;
    import tu_pkg::tags_t;


    import tu_pkg::SOP_SW;
    import tu_pkg::LOP_LW;
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
    output logic                decoder_ready_o
    //========================================================================//
);

/*============================================================================//
region LOGIC
//============================================================================*/

logic instr_valid_ff;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        instr_valid_ff <= '0;
    else
        instr_valid_ff <= instr_valid;
end

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
                if (threads_valid_i)
                    next_state = DEC_GIVE;
                else
                    next_state = DEC_WAIT;
            else
                next_state = DEC_IDLE;
        end
        DEC_WAIT: begin
            if (threads_valid_i)
                next_state = DEC_GIVE;
            else
                next_state = DEC_WAIT;
        end
        DEC_GIVE: begin
            if (instr_valid_ff)
                if (threads_valid_i)
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

logic  can_latch_for_wait;
assign can_latch_for_wait = ~prepare_wait;

logic  l_cmd_valid, u_cmd_valid, s_cmd_valid, f_cmd_valid;
assign l_cmd_valid      = instr_valid && (instr_i.op_type == L_CMD);
assign u_cmd_valid      = instr_valid && (instr_i.op_type == U_CMD);
assign f_cmd_valid      = instr_valid && (instr_i.op_type == F_CMD);
assign s_cmd_valid      = instr_valid && (instr_i.op_type == S_CMD);

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

logic  is_lsu_load, is_lsu_store;
assign is_lsu_load  = l_cmd_valid? (instr_i.cmd.l.operand == LOP_LW? 1: 0): 0;
assign is_lsu_store = s_cmd_valid? (instr_i.cmd.s.operand == SOP_SW? 1: 0): 0;

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
assign cmd              = prepare_give? cmd_ff              : '0;
assign cmd_op_type      = prepare_give? cmd_op_type_ff      : U_CMD;
// lsu
assign lsu_cmd          = prepare_give? lsu_cmd_ff          : LSU_L;
assign lsu_cmd_valid    = prepare_give? lsu_cmd_valid_ff    : '0;
// fpu
assign fpu_cmd          = prepare_give? fpu_cmd_ff          : '0;
assign fpu_cmd_valid    = prepare_give? fpu_cmd_valid_ff    : '0;

//============================================================================*/
endmodule
