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
    // DEC
    import tu_pkg::cmd_union_t;
    import tu_pkg::cmd_t;
    // LSU
    import tu_pkg::l_cmd_t;
    import tu_pkg::lsu_cmd_t;
    import tu_pkg::LSU_CMD;
    // FPU
    import tu_pkg::thread_command_t;
    import tu_pkg::tags_t;
    import tu_pkg::FPU_CMD;

#() (
    /*=======================### COMMON SIGNALS ###===========================*/
    // input  logic                clk,
    // input  logic                rst_n,

    /*===================### SIGNALS FROM CONTROL UNIT ###====================*/
    input  cmd_t                instr_i,
    input                       instr_valid,

    /*=======================### CMD SIGNALS ###==============================*/
    output l_cmd_t              lsu_cmd,
    output logic                lsu_cmd_valid,

    /*=========================### SIGNALS TO FPU ###=========================*/
    output thread_command_t     fpu_cmd,
    output logic                fpu_valid

    //========================================================================//
);

assign lsu_cmd_valid    = (instr_valid && instr_i.op_type == LSU_CMD);
assign fpu_valid        = (instr_valid && instr_i.op_type == FPU_CMD);

assign lsu_cmd          = lsu_cmd_valid? instr_i.cmd.l: '0;

always_comb begin
    if (fpu_valid) begin
        fpu_cmd.op      = instr_i.cmd.f.operand.fpu_op.t;
        fpu_cmd.op_mod  = instr_i.cmd.f.operand.fpu_op.mod;
        fpu_cmd.a1      = instr_i.cmd.f.a1;
        fpu_cmd.a2      = instr_i.cmd.f.a2;
        fpu_cmd.a3      = instr_i.cmd.f.a3;
        fpu_cmd.ar      = instr_i.cmd.f.ar;
        fpu_cmd.tag     = (tags_t)'(instr_i.cmd.f.imm);
        fpu_cmd.rnd     = (roundmode_e)'(instr_i.cmd.f.extra);
    end
    else begin
        fpu_cmd = '0;
    end
end

endmodule
