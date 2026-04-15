//-------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// ------------------------------------------------------------------------------//
// Purpose: GPU Thread unit
//-------------------------------------------------------------------------------//


/*===================================================================================//
region MODULE DEFINITION
//===================================================================================*/
module thread_unit
    import handshake_fpu_pkg::tags_t;
    import handshake_fpu_pkg::TAGS_NUM;
    import handshake_fpu_pkg::fsm_fpu_state_e;
    import handshake_fpu_pkg::FPU_RESULT;

    // FSM states
    import handshake_fpu_pkg::FPU_IDLE;
    import handshake_fpu_pkg::FPU_PRELOAD;
    import handshake_fpu_pkg::FPU_LOAD;
    import handshake_fpu_pkg::FPU_PROCESS;
    import handshake_fpu_pkg::FPU_RESULT;

    // Types for src/dst/int
    import fpnew_pkg::FP64;
    import fpnew_pkg::INT64;

    // Operation
    import tu_pkg::thread_command_t;
    import tu_pkg::lsu2tu_txn_t;
#(
    parameter int unsigned DW = 64,
    parameter int unsigned REGFILE_SIZE = 6,
    parameter int unsigned AW = $clog2(REGFILE_SIZE)
) (
    input  logic            clk,
    input  logic            rst_n,

    output logic            ready_out,

    input  lsu2tu_txn_t     lsu_cmd,
    input                   lsu_cmd_active,

    input  thread_command_t dec_cmd,
    input  logic            dec_cmd_active,

    output thread_result_t  result
);

/*===================================================================================//
region LOGIC
//===================================================================================*/

logic [DW - 1: 0] operands [3];
logic [DW - 1: 0] op_1;
logic [DW - 1: 0] op_2;
logic [DW - 1: 0] op_3;

assign operands = {op_1, op_2, op_3};

fsm_fpu_state_e state;
logic  fpu_result_active;
assign fpu_result_active = state == FPU_RESULT;

logic wr_en;
logic [AW - 1: 0] addr_w;
logic [DW - 1: 0] data_w;

// write
always_comb begin
    if (lsu_cmd_active && lsu_cmd.rw) begin
        addr_w = lsu_cmd.addr;
        data_w = lsu_cmd.data_w;
        wr_en  = '1;
    end
    else if (fpu_result_active) begin
        addr_w = dec_cmd.ar;
        data_w = result.result_data;
        wr_en = '1;
    end
    else begin
        addr_w = '0;
        data_w = '0;
        wr_en  = '0;
    end
end

// read
always_comb begin
    if (lsu_cmd_active && ~lsu_cmd.rw)
        addr_r = lsu_cmd.addr;
    else
        addr_r = dec_cmd_ar;
end

/*===================================================================================//
region INSTANCES
//===================================================================================*/

// ///////////////////////////////////////////////////////// //
//                    *** CU REGFILE ***                     //
// NOTE: write a purpose here
tu_regfile #(
    .DW      (DW),
    .REG_NUM (REGFILE_SIZE)
) tu_regfile_u (
    //================### COMMON SIGNALS ###=================//
    .clk     (clk),                 // <-
    //=================### WRITE SIGNALS ###=================//
    .wr_en   (wr_en),               // <-
    .addr_w  (addr_w),              // <-
    .data_w  (data_w),              // <-
    //=============### READ SIGNALS FOR ALU ###==============//
    .addr_r1 (dec_cmd.a1),          // <-
    .addr_r2 (dec_cmd.a2),          // <-
    .addr_r3 (dec_cmd.a3),          // <-
    .data_r1 (op_1),                // ->
    .data_r2 (op_2),                // ->
    .data_r3 (op_3),                // ->
    /*================### READ SIGNALS ###===================*/
    .addr_r  (dec_cmd.ar),          // <-
    .data_r  (result.result_data)   // ->
    //=======================================================//
);
// ///////////////////////////////////////////////////////// //

// ///////////////////////////////////////////////////////// //
//                      *** CU FSM ***                       //
// NOTE: write a purpose here
tu_fsm tu_fsm_u (
    //================### COMMON SIGNALS ###=================//
    .clk         (clk),             // <-
    .rst_n       (rst_n),           // <-
    /*================### COMMON SIGNALS ###=================*/
    .ready       (dec_cmd_active),  // <-
    //===============### HANDSHAKE SIGNALS ###===============//
    .in_ready_o  (in_ready_o),      // <-
    .out_valid_o (out_valid_o),     // <-
    .out_ready_i (out_ready_i),     // ->
    .in_valid_i  (in_valid_i),      // ->
    /*================### STATUS SIGNALS ###=================*/
    .state       (state)            // ->
    //=======================================================//
);
// ///////////////////////////////////////////////////////// //

// ///////////////////////////////////////////////////////// //
//                     *** FPNEW TOP ***                     //
// NOTE: write a purpose here
fpnew_top #(
    // ----------------- GLOBAL PARAMETERS ----------------- //
    // Type of FPU configuration. Do not touch
    .Features       (fpnew_pkg::RV64D_Xsflt),
    .Implementation (fpnew_pkg::DEFAULT_NOREGS),
    .DivSqrtSel     (fpnew_pkg::THMULTI),
    .TrueSIMDClass  ('0),
    .EnableSIMDMask ('0),
    .TagType        (logic [3: 0])
) fpnew_top_u (
    /*================### COMMON SIGNALS ###=================*/
    .clk_i          (clk),                  // <-
    .rst_ni         (rst_n),                // <-
    /*=================### MAIN SIGNALS ###==================*/
    .operands_i     (operands),             // <- (operands like a, b, c in a + b * c)
    .rnd_mode_i     (dec_cmd.rnd),          // <- (type of round after calc)
    .op_i           (dec_cmd.op),           // <- (type of operation in expression)
    .op_mod_i       (dec_cmd.op_mod),       // <- (alt option for operation type)
    /*==============### SET FORMAT SIGNALS ###===============*/
    .src_fmt_i      (FP64),                 // <- (type of incoming data)
    .dst_fmt_i      (FP64),                 // <- (type of outcoming data)
    .int_fmt_i      (INT64),                // <- (type of data, if it int)
    /*==============### PROPERTIES SIGNALS ###===============*/
    .vectorial_op_i ('0),                   // <- (vectorial mode)
    .simd_mask_i    ('0),                   // <-
    .flush_i        ('0),                   // <-
    .tag_i          (dec_cmd.tag),          // <- (tag of operation set)
    .tag_o          (result.tag),           // -> (tag of operation get)
    /*===============### HANDSHAKE SIGNALS ###===============*/
    .in_valid_i     (in_valid_i),           // <-
    .out_ready_i    (out_ready_i),          // <-
    .out_valid_o    (out_valid_o),          // ->
    .in_ready_o     (in_ready_o),           // ->
    /*================### RESULT SIGNALS ###=================*/
    .result_o       (result.result_data),   // ->
    .status_o       (result.status),        // ->
    .busy_o         (result.is_busy),       // ->
    .early_valid_o  (result.early_valid)    // ->
    //=======================================================//
);
// ///////////////////////////////////////////////////////// //

endmodule
