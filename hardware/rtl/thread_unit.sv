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
    import fpnew_pkg::FP32;
    import fpnew_pkg::INT64;
    import fpnew_pkg::INT32;

    import fpnew_pkg::RV64D_Xsflt;
    import fpnew_pkg::RV32F_Xsflt;
    import fpnew_pkg::DEFAULT_NOREGS;
    import fpnew_pkg::THMULTI;

    import fpnew_pkg::fp_format_e;
    import fpnew_pkg::int_format_e;
    import fpnew_pkg::fpu_features_t;

    // Operation
    import tu_pkg::cmd_union_t;
    import tu_pkg::dec_op_type_e;

    import tu_pkg::thread_command_t;
    import tu_pkg::thread_result_t;
    import tu_pkg::thread_info_t;
    import tu_pkg::tu_alu_t;

    // FSM STATE
    import tu_pkg::tu_state_e;
    import tu_pkg::TU_STATE_IDLE   ;
    import tu_pkg::TU_STATE_REQUEST;
    import tu_pkg::TU_STATE_WAIT   ;
    import tu_pkg::TU_STATE_DONE   ;

    import tu_pkg::U_OFS_IMM_W;


    // INSTR TYPES
    import tu_pkg::L_CMD;
    import tu_pkg::U_CMD;
    import tu_pkg::S_CMD;

    import tu_pkg::l_cmd_t;
    import tu_pkg::u_cmd_t;
    import tu_pkg::s_cmd_t;


    import tu_pkg::LOP_LW;
    import tu_pkg::SOP_SW;
    import tu_pkg::AOP_ADD;


    import tu_pkg::dw_value_t;
#(
    parameter  int unsigned DW = 64,
    parameter  int unsigned REGFILE_SIZE = 8,
    localparam int unsigned AW = $clog2(REGFILE_SIZE),
    parameter  bit          LATCH_R_ADDR = 1,
    parameter  bit          ONLY_LINT = `ifdef LINT 1 `else 0 `endif,


    localparam fpu_features_t FPU_FEATURES = DW == 64? RV64D_Xsflt: RV32F_Xsflt
) (
    /*=========================### COMMON SIGNALS ###=========================*/
    input  logic                clk,
    input  logic                rst_n,

    /*===========================### CMD SIGNALS ###==========================*/
    input  cmd_union_t          cmd,
    input  dec_op_type_e        cmd_op_type,

    /*======================### REGISTER SIGNALS (LSU) ###====================*/
    reg_if.tu                   r_if,
    input logic                 lsu_ready_i,

    /*===========================### DEC SIGNALS ###==========================*/
    input  thread_command_t     dec_cmd,
    input  logic                dec_cmd_valid,

    /*===========================### OUT SIGNALS ###==========================*/
    output thread_info_t        thread_info,
    output tu_state_e           thread_state
    //========================================================================//
);

/*============================================================================//
region ASSIGNES
//============================================================================*/

// Register interface
logic [DW - 1: 0] rs1,       rs2,       rd;
logic             rs1_valid, rs2_valid, rd_valid;

assign r_if.rs1.value   = rs1;
assign r_if.rs1.valid   = rs1_valid;
assign r_if.rs2.value   = rs2;
assign r_if.rs2.valid   = rs2_valid;

assign rd               = r_if.rd.value;
assign rd_valid         = r_if.rd.valid;

// Dec
logic  l_cmd_valid, u_cmd_valid, s_cmd_valid;
assign l_cmd_valid = cmd_op_type == L_CMD;
assign u_cmd_valid = cmd_op_type == U_CMD;
assign s_cmd_valid = cmd_op_type == S_CMD;

l_cmd_t l_cmd;
assign  l_cmd = l_cmd_valid? cmd.l: '0;

u_cmd_t u_cmd;
assign  u_cmd = u_cmd_valid? cmd.u: '0;

s_cmd_t s_cmd;
assign  s_cmd = s_cmd_valid? cmd.s: '0;

/*============================================================================//
region FSM
//============================================================================*/
tu_state_e next_thread_state;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        thread_state <= TU_STATE_IDLE;
    else
        thread_state <= next_thread_state;
end

always_comb begin
    case (thread_state)
        TU_STATE_IDLE:
            if (l_cmd_valid || s_cmd_valid) // TU wants request to LSU
                next_thread_state   = TU_STATE_REQUEST;
            else
                next_thread_state   = TU_STATE_IDLE;
        TU_STATE_REQUEST:
            if (lsu_ready_i)
                next_thread_state   = TU_STATE_DONE;
            else
                next_thread_state   = TU_STATE_REQUEST;
        TU_STATE_DONE:
            next_thread_state       = TU_STATE_IDLE;
        default:
            next_thread_state       = TU_STATE_IDLE;
    endcase
end


/*============================================================================//
region LOGIC
//============================================================================*/

thread_result_t fpu_result;

logic [DW - 1: 0]       op_1, op_2, op_3;
logic [2: 0][DW - 1: 0] operands;

assign operands = {op_1, op_2, op_3};

fsm_fpu_state_e state;

logic  busy_o;
assign busy_o          = state != FPU_IDLE;

logic wr_en;
logic [AW - 1: 0] addr_w;
logic [DW - 1: 0] data_w;

logic [AW - 1: 0] addr_result;
if (LATCH_R_ADDR) begin: gen_latch_r_addr
    logic [AW - 1: 0] ff_addr_r;
    always_ff @(posedge clk or negedge rst_n) begin
        if (~rst_n)
            ff_addr_r <= '0;
        else if (dec_cmd_valid)
            ff_addr_r <= dec_cmd.ar;
        else if (~busy_o)
            ff_addr_r <= '0;
    end

    assign addr_result = dec_cmd_valid? dec_cmd.ar: ff_addr_r;
end
else begin: gen_no_latch_r_addr
    assign addr_result = dec_cmd.ar;
end

// write
always_comb begin
    if (rd_valid && (l_cmd_valid || s_cmd_valid)) begin
        if (l_cmd_valid)
            addr_w = l_cmd.rd_addr;
        else
            addr_w = s_cmd.rd_addr;
        data_w = rd;
        wr_en  = '1;
    end
    else if (u_cmd_valid && u_cmd.operand == '0) begin
        addr_w = u_cmd.rd_addr;
        data_w = (DW)'(u_cmd.imm << U_OFS_IMM_W);
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
    if (s_cmd_valid)
        addr_rs1 = s_cmd.rs1_addr;
    else if (l_cmd_valid)
        addr_rs1 = l_cmd.rs1_addr;
    else
        addr_rs1 = '0;
end

assign addr_rs2 = s_cmd_valid? s_cmd.rs2_addr: '0;

// handshake sig
logic out_ready_i;
logic out_valid_o;
logic in_valid_i;
logic in_ready_o;

logic [DW - 1: 0] data_rs1, data_rs2;

/*============================================================================//
region ALU
//============================================================================*/

tu_alu_t alu_struct;
always_comb begin
    case (cmd_op_type)
        L_CMD: begin
            case (l_cmd.operand)
                LOP_LW: begin
                    alu_struct.o1       = data_rs1;
                    alu_struct.o2       = (DW)'(l_cmd.imm);
                    alu_struct.op       = AOP_ADD;
                    alu_struct.valid    = '1;
                end
                default: begin
                    alu_struct = '0;
                end
            endcase
        end
        S_CMD: begin
            case (s_cmd.operand)
                SOP_SW: begin
                    alu_struct.o1       = data_rs1;
                    alu_struct.o2       = (DW)'(s_cmd.imm);
                    alu_struct.op       = AOP_ADD;
                    alu_struct.valid    = '1;
                end
                default: begin
                    alu_struct = '0;
                end
            endcase
        end
        default:
            alu_struct = '0;
    endcase
end

logic [DW - 1: 0]   alu_or; // operation result
logic               alu_rr; // result ready

/*============================================================================//
region OUT
//============================================================================*/
assign  thread_info     = fpu_result.info;


always_comb begin
    if(l_cmd_valid || s_cmd_valid) begin
        rs1         = alu_or;
        rs1_valid   = alu_rr;
    end
    else begin
        rs1         = data_rs1;
        rs1_valid   = '1;
    end
end

assign rs2          = data_rs2;
assign rs2_valid    = '1;


/*============================================================================//
region INSTANCES HELPERS
//============================================================================*/

fp_format_e  fp_format_data;
int_format_e int_format_data;

if (DW == 32) begin: gen_32_dw_format
    assign fp_format_data   = FP32;
    assign int_format_data  = INT32;
end
else if (DW == 64) begin: gen_64_dw_format
    assign fp_format_data   = FP64;
    assign int_format_data  = INT64;
end

/*============================================================================//
region INSTANCES
//============================================================================*/

// ///////////////////////////////////////////////////////// //
//                     *** CORE ALU ***                      //
// NOTE: alu for calc addressing
tu_alu #(
    .DW        (DW)
) tu_alu_u (
    //================### COMMON SIGNALS ###=================//
    .op_i    (alu_struct.op),       // <-
    .a1_i    (alu_struct.o1),       // <-
    .a2_i    (alu_struct.o2),       // <-
    .valid_i (alu_struct.valid),    // <-
    .r_o     (alu_or),              // ->
    .ready_o (alu_rr)               // ->
    //=======================================================//
);
// ///////////////////////////////////////////////////////// //

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
    .data_rs1  (data_rs1),          // ->
    .data_rs2  (data_rs2)           // ->
    //=======================================================//
);
// ///////////////////////////////////////////////////////// //

// ///////////////////////////////////////////////////////// //
//                      *** CU FSM ***                       //
// NOTE: write a purpose here
tu_fpu_fsm tu_fpu_fsm_u (
    //================### COMMON SIGNALS ###=================//
    .clk         (clk),             // <-
    .rst_n       (rst_n),           // <-
    /*================### COMMON SIGNALS ###=================*/
    .ready       (dec_cmd_valid),   // <-
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
        .src_fmt_i      (fp_format_data),               // <- (type of incoming data)
        .dst_fmt_i      (fp_format_data),               // <- (type of outcoming data)
        .int_fmt_i      (int_format_data),              // <- (type of data, if it int)
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
        .Features       (FPU_FEATURES),
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
        .src_fmt_i      (fp_format_data),               // <- (type of incoming data)
        .dst_fmt_i      (fp_format_data),               // <- (type of outcoming data)
        .int_fmt_i      (int_format_data),              // <- (type of data, if it int)
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
