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
    // DEC
    import tu_pkg::cmd_union_t;
    // LSU
    import tu_pkg::lsu_cmd_t;
    import tu_pkg::LSU_CMD;
    // FPU
    import tu_pkg::thread_command_t;
    import tu_pkg::tags_t;
    import tu_pkg::FPU_CMD;
#(
    parameter int unsigned DW = 64
) (
    input  logic                clk,
    input  logic                rst_n,

    input  cmd_union_t          instr_i,
    input                       instr_valid,

    output lsu_cmd_t            lsu_cmd,
    output logic                lsu_valid,

    output thread_command_t     fpu_cmd,
    output                      fpu_valid,


    input  logic                ready_i,
    output logic                ready_o
);

assign lsu_valid = (instr_valid && instr_i.op_type == LSU_CMD);

assign fpu_valid = (instr_valid && instr_i.op_type == FPU_CMD);

always_comb begin
    if (lsu_valid) begin
        lsu_cmd.op  = instr_i.lcmd.operand;
        lsu_cmd.rd  = instr_i.lcmd.a1;
        lsu_cmd.r1  = instr_i.lcmd.a2;
        lsu_cmd.r2  = instr_i.lcmd.a3;
        lsu_cmd.imm = instr_i.lcmd.imm;
    end
    else begin
        lsu_cmd = '0;
    end
end

always_comb begin
    if (fpu_valid) begin
        fpu_cmd.op      = instr_i.fcmd.operand[4: 1];
        fpu_cmd.op_mod  = instr_i.fcmd.operand[0];
        fpu_cmd.a1      = instr_i.fcmd.a1;
        fpu_cmd.a2      = instr_i.fcmd.a2;
        fpu_cmd.a3      = instr_i.fcmd.a3;
        fpu_cmd.ar      = intsr_i.fcmd.ar;
        fpu_cmd.tag     = (tags_t)'(imm);
        fpu_cmd.rnd     = instr_i.fcmd.extra;
    end
    else begin
        fpu_cmd = '0;
    end
end

assign ready_i = ready_o;

endmodule
