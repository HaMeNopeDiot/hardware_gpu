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
    import tu_pkg::l_cmd_t;
    import tu_pkg::lsu_op_e;
#(
    parameter int unsigned DW               = 64,
    parameter int unsigned MEM_AW           = 64,
    parameter int unsigned TU_REGILE_SZ     = 8,
    parameter int unsigned TU_LATCH_R_ADDR  = 1,
    parameter bit          ONLY_LINT        = `ifdef LINT 1 `else 0 `endif
) (
    /*============================### COMMON SIGNALS ###======================*/
    input  logic                    clk,
    input  logic                    rst_n,

    input  cmd_t                    instr_i,
    input  logic                    instr_valid_i,

    simple_bus_if.lsu               m_if,
    simple_hq_if.slave              fpu_hq_if,
    simple_hq_if.slave              lsu_hq_if,
    output thread_info_t            thread_unit_info


    //========================================================================//
);

/*============================================================================//
region LOGIC
//============================================================================*/
l_cmd_t             lsu_cmd;
logic               lsu_cmd_valid;


thread_command_t    fpu_cmd;
logic               fpu_cmd_valid;

lsu_op_e            lsu_op;
logic               lsu_op_valid;
assign              lsu_op       = lsu_cmd.operand.lsu_op;
assign              lsu_op_valid = lsu_cmd_valid;

reg_if              r_if();

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
    .lsu_cmd        (lsu_cmd      ),    // ->
    .lsu_cmd_valid  (lsu_cmd_valid),    // ->
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
    .r_if              (r_if.lsu       ),   // <->
    //============### SIGNALS FROM MEMORY BUS ###============//
    .m_if              (m_if           ),   // <->
    //================### HANDSHAKE SIGNALS ###==============//
    .lsu_ready_o       (lsu_hq_if.ready),   // ->
    .lsu_valid_i       (lsu_hq_if.valid)    // <-
    //=======================================================//
);
// ///////////////////////////////////////////////////////// //

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
    .lsu_cmd        (lsu_cmd         ),  // <-
    .lsu_cmd_valid  (lsu_cmd_valid   ),  // <-
    //===============### REGISTER SIGNALS ###================//
    .r_if           (r_if.tu         ),  // <->
    //==================### DEC SIGNALS ###==================//
    .dec_cmd        (fpu_cmd         ),  // <-
    .dec_cmd_valid  (fpu_cmd_valid   ),  // <-
    //================### HANDSHAKE SIGNALS ###==============//
    .fpu_valid_i    (fpu_hq_if.valid ),  // <-
    .fpu_ready_o    (fpu_hq_if.ready ),  // ->
    //==================### OUT SIGNALS ###==================//
    .thread_info    (thread_unit_info)   // ->
    //=======================================================//
);
// ///////////////////////////////////////////////////////// //

endmodule
