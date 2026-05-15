//-------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// ------------------------------------------------------------------------------//
// Purpose: GPU Core LSU
// Date: 2026/05
//-------------------------------------------------------------------------------//

/*===================================================================================//
region MODULE DEFINITION
//===================================================================================*/
module core_lsu
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
    parameter int unsigned DW = 64,
    parameter int unsigned MEM_AW = 32
) (
    /*============================### COMMON SIGNALS ###========================*/
    input  logic                    clk,
    input  logic                    rst_n,

    /*=========================### SIGNALS FROM DECODER ###=====================*/
    input  lsu_cmd_t                lsu_cmd,
    input  logic                    lsu_valid,

    /*=======================### SIGNALS FROM THREAD UNIT ###===================*/
    input  logic [DW - 1: 0]        rs1,
    input  logic [DW - 1: 0]        rs2,

    output logic [DW - 1: 0]        rd,
    output logic                    rd_active,
    /*=======================### SIGNALS FROM MEMORY BUS ###====================*/
    input  logic [DW - 1: 0]        mem_read_data,
    output logic [MEM_AW - 1: 0]    mem_read_address,
    input  logic                    mem_read_ready,
    output logic                    mem_read_valid,

    input  logic [DW - 1: 0]        mem_write_data,
    input  logic [MEM_AW - 1: 0]    mem_write_address,
    input  logic                    mem_write_ready,
    output logic                    mem_write_valid
    //==========================================================================//
);

endmodule

