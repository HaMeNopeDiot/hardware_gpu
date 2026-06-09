//-------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// ------------------------------------------------------------------------------//
// Purpose: GPU Core decoder
// Date: 2026/05
//-------------------------------------------------------------------------------//

/*===================================================================================//
region MODULE DEFINITION
//===================================================================================*/
module core_decoder
    import fpnew_pkg::roundmode_e;
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

#() (
    /*=======================### COMMON SIGNALS ###===========================*/
    input  logic                clk,
    input  logic                rst_n,

    /*===================### SIGNALS FROM CONTROL UNIT ###====================*/
    input  cmd_t                instr_i,
    input  logic                instr_valid,

    /*=======================### CMD SIGNALS ###==============================*/
    output cmd_union_t          cmd,
    output dec_op_type_e        cmd_op_type, // by this you can get type and valid

    /*=========================### SIGNALS TO LSU ###=========================*/
    output lsu_cmd_e            lsu_cmd,
    output logic                lsu_cmd_valid,

    /*=========================### SIGNALS TO FPU ###=========================*/
    output thread_command_t     fpu_cmd,
    output logic                fpu_cmd_valid

    //========================================================================//
);

/*============================================================================//
region LOGIC
//============================================================================*/

always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        cmd_op_type <= U_CMD;
    else if (instr_valid)
        cmd_op_type <= instr_i.op_type;
    else
        cmd_op_type <= U_CMD;
end


logic  l_cmd_valid, u_cmd_valid, s_cmd_valid, f_cmd_valid;
assign l_cmd_valid      = (instr_valid && instr_i.op_type == L_CMD);
assign u_cmd_valid      = (instr_valid && instr_i.op_type == U_CMD);
assign f_cmd_valid      = (instr_valid && instr_i.op_type == F_CMD);
assign s_cmd_valid      = (instr_valid && instr_i.op_type == S_CMD);

always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        cmd <= '0;
    else if (l_cmd_valid || u_cmd_valid || s_cmd_valid)
        cmd <= instr_i.cmd;
    else
        cmd <= '0;
end

logic is_lsu_load;
logic is_lsu_store;

assign is_lsu_load  = l_cmd_valid? (instr_i.cmd.l.operand == LOP_LW? 1: 0): 0;
assign is_lsu_store = s_cmd_valid? (instr_i.cmd.s.operand == SOP_SW? 1: 0): 0;

always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        lsu_cmd <= LSU_L;
    else if (is_lsu_load)
        lsu_cmd <= LSU_L;
    else if (is_lsu_store)
        lsu_cmd <= LSU_S;
    else
        lsu_cmd <= LSU_L;
end

always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        lsu_cmd_valid <= '0;
    else if (is_lsu_load || is_lsu_store)
        lsu_cmd_valid <= '1;
    else
        lsu_cmd_valid <= '0;
end


always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        fpu_cmd <= '0;
    else if (f_cmd_valid) begin
        fpu_cmd.op      <= instr_i.cmd.f.operand.t;
        fpu_cmd.op_mod  <= instr_i.cmd.f.operand.mod;
        fpu_cmd.a1      <= instr_i.cmd.f.a1;
        fpu_cmd.a2      <= instr_i.cmd.f.a2;
        fpu_cmd.a3      <= instr_i.cmd.f.a3;
        fpu_cmd.ar      <= instr_i.cmd.f.ar;
        fpu_cmd.tag     <= (tags_t)'(instr_i.cmd.f.imm);
        fpu_cmd.rnd     <= (roundmode_e)'(instr_i.cmd.f.extra);
    end
    else
        fpu_cmd <= '0;
end

/*============================================================================//
region OUT
//============================================================================*/

assign fpu_cmd_valid = f_cmd_valid;

//============================================================================*/
endmodule
