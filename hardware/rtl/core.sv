//-------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// ------------------------------------------------------------------------------//
// Purpose: GPU Core
// Date: 2026/05
//-------------------------------------------------------------------------------//

/*===================================================================================//
region MODULE DEFINITION
//===================================================================================*/
module core
    import tu_pkg::thread_command_t;
    import tu_pkg::thread_info_t;
    import tu_pkg::cmd_t;
    import tu_pkg::dec_op_type_e;
    import tu_pkg::cmd_union_t;
    import tu_pkg::lsu_op_e;
    import tu_pkg::LSU_CMD;
#(
    parameter  int unsigned DW               = 64,
    parameter  int unsigned MEM_AW           = 64,
    parameter  int unsigned TU_REGILE_SZ     = 8,
    parameter  int unsigned TU_LATCH_R_ADDR  = 1,
    parameter  bit          ONLY_LINT        = `ifdef LINT 1 `else 0 `endif,
    parameter  int unsigned THREAD_CNT       = 4,
    localparam int unsigned THREAD_W         = $clog2(THREAD_CNT)
) (
    /*============================### COMMON SIGNALS ###======================*/
    input   logic                       clk,
    input   logic                       rst_n,

    input   cmd_t                       instr_i,
    input   logic                       instr_valid_i,

    simple_bus_if.lsu                   m_if,

    input  logic [THREAD_CNT - 1: 0]    fpu_valid_m,
    output logic [THREAD_CNT - 1: 0]    fpu_ready_m,
    // simple_hndh_if.slave             fpu_hndh_if,
    simple_hndh_if.slave                lsu_hndh_if,
    output thread_info_t                thread_unit_info,

    input  logic [THREAD_W - 1: 0]      thread_sel
    //========================================================================//
);

/*============================================================================//
region LOGIC
//============================================================================*/
cmd_union_t         cmd;
dec_op_type_e       cmd_op_type;
logic               lsu_cmd_valid;
assign              lsu_cmd_valid = cmd_op_type == LSU_CMD;

thread_command_t    fpu_cmd;
logic               fpu_cmd_valid;

lsu_op_e            lsu_op;
logic               lsu_op_valid;
assign              lsu_op       = cmd.l.operand.lsu_op;
assign              lsu_op_valid = lsu_cmd_valid;

/*============================================================================//
region REGISTER INTERFACE
//============================================================================*/

reg_if              rt_if [THREAD_CNT](); // registers thread interface
reg_if              rl_if ();             // registers lsu interface

always_comb begin
    rl_if.rd = rt_if[thread_sel].rd;
end

for (genvar i = 0; i < THREAD_CNT; i++) begin: gen_demux
    assign rt_if[i].rs1 = (THREAD_W)'(i) == thread_sel? rl_if.rs1: '0;
    assign rt_if[i].rs2 = (THREAD_W)'(i) == thread_sel? rl_if.rs2: '0;
end

/*============================================================================//
region INSTANCES
//============================================================================*/

// ///////////////////////////////////////////////////////// //
//                   *** CORE DECODER ***                    //
core_decoder #() core_decoder_u (
    //================### COMMON SIGNALS ###=================//
    // .clk            (clk          ),    // <-
    // .rst_n          (rst_n        ),    // <-
    //===========### SIGNALS FROM CONTROL UNIT ###===========//
    .instr_i        (instr_i      ),    // <-
    .instr_valid    (instr_valid_i),    // <-
    //==================### CMD SIGNALS ###==================//
    .cmd            (cmd          ),    // ->
    .cmd_op_type    (cmd_op_type  ),    // ->
    //================### SIGNALS TO FPU ###=================//
    .fpu_cmd        (fpu_cmd      ),    // ->
    .fpu_valid      (fpu_cmd_valid)     // ->
    //=======================================================//
);
// ///////////////////////////////////////////////////////// //

// ///////////////////////////////////////////////////////// //
//                     *** CORE LSU ***                      //
core_lsu #(
    .DW     (DW),
    .MEM_AW (MEM_AW)
) core_lsu_u (
    //================### COMMON SIGNALS ###=================//
    .clk               (clk            ),   // <-
    .rst_n             (rst_n          ),   // <-
    //=============### SIGNALS FROM DECODER ###==============//
    .lsu_op            (lsu_op         ),   // <-
    .lsu_op_valid      (lsu_op_valid   ),   // <-
    //===========### SIGNALS FROM THREAD UNIT ###============//
    .r_if              (rl_if.lsu      ),   // <->
    //============### SIGNALS FROM MEMORY BUS ###============//
    .m_if              (m_if           ),   // <->
    //================### HANDSHAKE SIGNALS ###==============//
    .lsu_ready_o       (lsu_hndh_if.ready), // ->
    .lsu_valid_i       (lsu_hndh_if.valid)  // <-
    //=======================================================//
);
// ///////////////////////////////////////////////////////// //

for (genvar i = 0; i < THREAD_CNT; i++) begin: gen_threads
    // ///////////////////////////////////////////////////////// //
    //                    *** THREAD UNIT ***                    //
    thread_unit #(
        .DW           (DW),
        .REGFILE_SIZE (TU_REGILE_SZ),
        .LATCH_R_ADDR (TU_LATCH_R_ADDR),
        .ONLY_LINT    (ONLY_LINT)
    ) thread_unit_u (
        //================### COMMON SIGNALS ###=================//
        .clk            (clk             ),  // <-
        .rst_n          (rst_n           ),  // <-
        //==================### LSU SIGNALS ###==================//
        .cmd            (cmd             ),  // <-
        .cmd_op_type    (cmd_op_type     ),  // <-
        //===============### REGISTER SIGNALS ###================//
        .r_if           (rt_if[i].tu     ),  // <->
        //==================### DEC SIGNALS ###==================//
        .dec_cmd        (fpu_cmd         ),  // <-
        .dec_cmd_valid  (fpu_cmd_valid   ),  // <-
        //================### HANDSHAKE SIGNALS ###==============//
        .fpu_valid_i    (fpu_valid_m[i]  ),  // <-
        .fpu_ready_o    (fpu_ready_m[i]  ),  // ->
        //==================### OUT SIGNALS ###==================//
        .thread_info    (thread_unit_info)   // ->
        //=======================================================//
    );
    // ///////////////////////////////////////////////////////// //
end

endmodule
