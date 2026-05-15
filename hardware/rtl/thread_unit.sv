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

    // FSM states
    import handshake_fpu_pkg::FPU_IDLE;
    import handshake_fpu_pkg::FPU_PRELOAD;
    import handshake_fpu_pkg::FPU_LOAD;
    import handshake_fpu_pkg::FPU_PROCESS;
    import handshake_fpu_pkg::FPU_RESULT;

    // Types for src/dst/int

    import fpnew_pkg::FP64;
    import fpnew_pkg::INT64;

    import fpnew_pkg::RV64D_Xsflt;
    import fpnew_pkg::DEFAULT_NOREGS;
    import fpnew_pkg::THMULTI;


    // Operation
    import tu_pkg::thread_command_t;
    import tu_pkg::thread_result_t;
    import tu_pkg::dec2tu_bus_t;
    import tu_pkg::thread_info_t;
#(
    parameter int unsigned DW = 64,
    parameter int unsigned REGFILE_SIZE = 8,
    parameter int unsigned AW = $clog2(REGFILE_SIZE),

    parameter bit          LATCH_R_ADDR = 1,

    parameter bit          ONLY_LINT = `ifdef LINT 1 `else 0 `endif
) (
    input  logic                clk,
    input  logic                rst_n,

    input  dec2tu_bus_t         lsu_cmd,
    input  logic                lsu_cmd_active,

    input  logic [DW - 1: 0]    rd,
    input  logic                rd_active,
    output logic [DW - 1: 0]    rs1,
    output logic [DW - 1: 0]    rs2,

    input  thread_command_t     dec_cmd,
    input  logic                dec_cmd_active,

    output logic                busy_o,

    output thread_info_t        thread_info
);

/*===================================================================================//
region LOGIC
//===================================================================================*/

thread_result_t fpu_result;

logic [2: 0][DW - 1: 0] operands;
logic [DW - 1: 0] op_1;
logic [DW - 1: 0] op_2;
logic [DW - 1: 0] op_3;

assign operands = {op_1, op_2, op_3};

fsm_fpu_state_e state;

logic wr_en;
logic [AW - 1: 0] addr_w;
logic [DW - 1: 0] data_w;

logic [AW - 1: 0] addr_result;
if (LATCH_R_ADDR) begin: gen_latch_r_addr
    logic [AW - 1: 0] ff_addr_r;
    always_ff @(posedge clk or negedge rst_n) begin
        if (~rst_n)
            ff_addr_r <= '0;
        else if (dec_cmd_active)
            ff_addr_r <= dec_cmd.ar;
        else if (~busy_o)
            ff_addr_r <= '0;
    end

    assign addr_result = dec_cmd_active? dec_cmd.ar: ff_addr_r;
end
else begin: gen_no_latch_r_addr
    assign addr_result = dec_cmd.ar;
end

// write
always_comb begin
    if (rd_active && lsu_cmd_active) begin
        addr_w = lsu_cmd.rd_addr;
        data_w = rd;
        wr_en  = '1;
    end
    else if (state == FPU_RESULT) begin
        addr_w = addr_result;
        data_w = fpu_result.result_data;
        wr_en = '1;
    end
    else begin
        addr_w = '0;
        data_w = '0;
        wr_en  = '0;
    end
end

// read
logic [AW - 1: 0] addr_rs1, addr_rs2;

always_comb begin
    addr_rs1 = lsu_cmd_active? lsu_cmd.rs1_addr: '0;
    addr_rs2 = lsu_cmd_active? lsu_cmd.rs2_addr: '0;
end

// hshk sig
logic out_ready_i;
logic out_valid_o;
logic in_valid_i;
logic in_ready_o;


/*===================================================================================//
region OUT
//===================================================================================*/
assign  thread_info     = fpu_result.info;
assign  busy_o          = state != FPU_IDLE;

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
    .addr_rs1  (addr_rs1),          // <-
    .addr_rs2  (addr_rs2),          // <-
    .data_rs1  (rs1),               // ->
    .data_rs2  (rs2)                // ->
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
// NOTE: Instance fpu dummy need to change in simulation to fpnew_top
if (ONLY_LINT == 0) begin: gen_real_fpu
    fpnew_top #(
        // ----------------- GLOBAL PARAMETERS ----------------- //
        // Type of FPU configuration. Do not touch
        .Features       (RV64D_Xsflt),
        .Implementation (DEFAULT_NOREGS),
        .DivSqrtSel     (THMULTI),
        .TagType        (tags_t),
        .TrueSIMDClass  ('0),
        .EnableSIMDMask ('0)
    ) fpnew_top_u (
        /*================### COMMON SIGNALS ###=================*/
        .clk_i          (clk),                          // <-
        .rst_ni         (rst_n),                        // <-
        /*=================### MAIN SIGNALS ###==================*/
        .operands_i     (operands),                     // <- (operands like a, b, c in a + b * c)
        .rnd_mode_i     (dec_cmd.rnd),                  // <- (type of round after calc)
        .op_i           (dec_cmd.op),                   // <- (type of operation in expression)
        .op_mod_i       (dec_cmd.op_mod),               // <- (alt option for operation type)
        /*==============### SET FORMAT SIGNALS ###===============*/
        .src_fmt_i      (FP64),                         // <- (type of incoming data)
        .dst_fmt_i      (FP64),                         // <- (type of outcoming data)
        .int_fmt_i      (INT64),                        // <- (type of data, if it int)
        /*==============### PROPERTIES SIGNALS ###===============*/
        .vectorial_op_i ('0),                           // <- (vectorial mode)
        .simd_mask_i    ('0),                           // <-
        .flush_i        ('0),                           // <-
        .tag_i          (dec_cmd.tag),                  // <- (tag of operation set)
        .tag_o          (fpu_result.info.tag),          // -> (tag of operation get)
        /*===============### HANDSHAKE SIGNALS ###===============*/
        .in_valid_i     (in_valid_i),                   // <-
        .out_ready_i    (out_ready_i),                  // <-
        .out_valid_o    (out_valid_o),                  // ->
        .in_ready_o     (in_ready_o),                   // ->
        /*================### RESULT SIGNALS ###=================*/
        .result_o       (fpu_result.result_data),       // ->
        .status_o       (fpu_result.info.status),       // ->
        .busy_o         (fpu_result.info.is_busy),      // ->
        .early_valid_o  (fpu_result.info.early_valid)   // ->
        //=======================================================//
    );
    // ///////////////////////////////////////////////////////// //
end
else begin: gen_dummy_fpu
        fpu_dummy #(
        // ----------------- GLOBAL PARAMETERS ----------------- //
        // Type of FPU configuration. Do not touch
        .Features       (RV64D_Xsflt),
        .Implementation (DEFAULT_NOREGS),
        .DivSqrtSel     (THMULTI),
        .TagType        (tags_t),
        .TrueSIMDClass  ('0),
        .EnableSIMDMask ('0)
    ) fpnew_top_u (
        /*================### COMMON SIGNALS ###=================*/
        .clk_i          (clk),                          // <-
        .rst_ni         (rst_n),                        // <-
        /*=================### MAIN SIGNALS ###==================*/
        .operands_i     (operands),                     // <- (operands like a, b, c in a + b * c)
        .rnd_mode_i     (dec_cmd.rnd),                  // <- (type of round after calc)
        .op_i           (dec_cmd.op),                   // <- (type of operation in expression)
        .op_mod_i       (dec_cmd.op_mod),               // <- (alt option for operation type)
        /*==============### SET FORMAT SIGNALS ###===============*/
        .src_fmt_i      (FP64),                         // <- (type of incoming data)
        .dst_fmt_i      (FP64),                         // <- (type of outcoming data)
        .int_fmt_i      (INT64),                        // <- (type of data, if it int)
        /*==============### PROPERTIES SIGNALS ###===============*/
        .vectorial_op_i ('0),                           // <- (vectorial mode)
        .simd_mask_i    ('0),                           // <-
        .flush_i        ('0),                           // <-
        .tag_i          (dec_cmd.tag),                  // <- (tag of operation set)
        .tag_o          (fpu_result.info.tag),          // -> (tag of operation get)
        /*===============### HANDSHAKE SIGNALS ###===============*/
        .in_valid_i     (in_valid_i),                   // <-
        .out_ready_i    (out_ready_i),                  // <-
        .out_valid_o    (out_valid_o),                  // ->
        .in_ready_o     (in_ready_o),                   // ->
        /*================### RESULT SIGNALS ###=================*/
        .result_o       (fpu_result.result_data),       // ->
        .status_o       (fpu_result.info.status),       // ->
        .busy_o         (fpu_result.info.is_busy),      // ->
        .early_valid_o  (fpu_result.info.early_valid)   // ->
        //=======================================================//
    );
    // ///////////////////////////////////////////////////////// //
end
endmodule
