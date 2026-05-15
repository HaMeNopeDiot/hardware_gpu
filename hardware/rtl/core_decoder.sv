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

    // unsorted
    import tu_pkg::dec2lsu_bus_t;
    import tu_pkg::dec2tu_bus_t;
#(
    parameter int unsigned DW = 64
) (
    /*=========================### COMMON SIGNALS ###===========================*/
    input  logic                clk,
    input  logic                rst_n,

    /*====================### SIGNALS FROM CONTROL UNIT ###=====================*/
    input  cmd_union_t          instr_i,
    input                       instr_valid,

    /*=========================### SIGNALS TO LSU ###===========================*/
    output dec2lsu_bus_t        lsu_cmd,
    output logic                lsu_valid,

    /*=====================### SIGNALS TO REGFILE ###===========================*/
    output dec2tu_bus_t         regfile_cmd,
    output logic                regfile_valid,

    /*=========================### SIGNALS TO FPU ###===========================*/
    output thread_command_t     fpu_cmd,
    output                      fpu_valid,

    /*======================### HANDSHAKE SINGALS ###===========================*/
    input  logic                ready_i,
    output logic                ready_o
    //==========================================================================//
);

assign lsu_valid        = (instr_valid && instr_i.op_type == LSU_CMD);
assign regfile_valid    = (instr_valid && instr_i.op_type == LSU_CMD);
assign fpu_valid        = (instr_valid && instr_i.op_type == FPU_CMD);

assign lsu_cmd      = lsu_valid? intsr_i.lcmd.to_lsu: '0;
assign regfile_cmd  = lsu_valid? instr_i.lcmd.to_rf : '0;

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
