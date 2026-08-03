//----------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
//----------------------------------------------------------------------------//
// Purpose: GPU Thread unit
// Date: 2026/06
//----------------------------------------------------------------------------//

/*============================================================================//
region MODULE DEFINITION
//============================================================================*/
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
    import fpnew_pkg::ADD;

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
    import tu_pkg::TU_STATE_BUSY   ;
    import tu_pkg::TU_STATE_DONE   ;

    import tu_pkg::U_OFS_IMM_W;


    // INSTR TYPES
    import tu_pkg::L_CMD;
    import tu_pkg::U_CMD;
    import tu_pkg::S_CMD;

    import tu_pkg::l_cmd_t;
    import tu_pkg::u_cmd_t;
    import tu_pkg::s_cmd_t;


    import tu_pkg::UOP_IMM;
    import tu_pkg::LOP_LW, tu_pkg::LOP_ADDI, tu_pkg::LOP_JALR;
    import tu_pkg::SOP_SW, tu_pkg::SOP_ADD, tu_pkg::SOP_MUL;
    import tu_pkg::AOP_ADD, tu_pkg::AOP_MUL;


    import tu_pkg::dw_value_t;
#(
    parameter  int unsigned     DW                  = 64,
    localparam int unsigned     STRB_W              = int'(DW / 8),
    parameter  int unsigned     REGFILE_SIZE        = 8,
    localparam int unsigned     AW                  = $clog2(REGFILE_SIZE),
    parameter  bit              LATCH_R_ADDR        = 1,
    parameter  bit              ONLY_LINT           = `ifdef LINT 1 `else 0 `endif,

    parameter  fpu_features_t   FPU_CONFIGURATION   = RV32F_Xsflt, // RV32F_Xsflt or RV64D_Xsflt
    parameter  int unsigned     FDW                 = FPU_CONFIGURATION == RV64D_Xsflt? 64: 32

) (
    /*=========================### COMMON SIGNALS ###=========================*/
    input  logic                clk,
    input  logic                rst_n,
    input  logic                en,
    /*===========================### CMD SIGNALS ###==========================*/
    input  cmd_union_t          cmd,
    input  dec_op_type_e        cmd_op_type,

    /*======================### REGISTER SIGNALS (LSU) ###====================*/
    reg_if.tu                   r_if,
    input logic                 lsu_ready_i,

    /*===========================### DEC SIGNALS ###==========================*/
    input  thread_command_t     dec_cmd,        // fpu
    input  logic                dec_cmd_valid,  // fpu valid

    /*===========================### VID SIGNALS ###==========================*/
    input logic [DW - 1: 0]     csr_pc_i,
    input logic [DW - 1: 0]     vid_i,
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
logic  l_cmd_valid, u_cmd_valid, s_cmd_valid, f_cmd_valid;
assign l_cmd_valid = en && (cmd_op_type == L_CMD);
assign u_cmd_valid = en && (cmd_op_type == U_CMD);
assign s_cmd_valid = en && (cmd_op_type == S_CMD);
assign f_cmd_valid = en && dec_cmd_valid;

l_cmd_t l_cmd;
assign  l_cmd = en & l_cmd_valid? cmd.l: '0;

u_cmd_t u_cmd;
assign  u_cmd = en & u_cmd_valid? cmd.u: '0;

s_cmd_t s_cmd;
assign  s_cmd = en & s_cmd_valid? cmd.s: '0;

logic  store_op, load_op;
assign store_op = en && s_cmd_valid? cmd.s.operand == SOP_SW: '0;
assign load_op  = en && l_cmd_valid? cmd.l.operand == LOP_LW: '0;

/*============================================================================//
region FSM
//============================================================================*/

fsm_fpu_state_e fpu_state; // fpu
logic  fpu_is_idle;
assign fpu_is_idle = fpu_state == FPU_IDLE;

tu_state_e next_thread_state, cur_thread_state;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        cur_thread_state <= TU_STATE_IDLE;
    else
        cur_thread_state <= next_thread_state;
end

always_comb begin
    if (~en)
        next_thread_state   = TU_STATE_IDLE;
    else
        case (cur_thread_state)
            TU_STATE_IDLE:
                if (~fpu_is_idle)
                    next_thread_state   = TU_STATE_BUSY;
                else if (load_op || store_op) // TU wants request to LSU
                    next_thread_state   = TU_STATE_REQUEST;
                else
                    next_thread_state   = TU_STATE_IDLE;
            TU_STATE_REQUEST:
                if (lsu_ready_i)
                    next_thread_state   = TU_STATE_DONE;
                else
                    next_thread_state   = TU_STATE_REQUEST;
            TU_STATE_DONE:
                if (load_op || store_op) // In some case need instant be prepaired to next cmd
                    next_thread_state   = TU_STATE_REQUEST;
                else
                    next_thread_state   = TU_STATE_IDLE;
            TU_STATE_BUSY:
                if (fpu_is_idle)
                    next_thread_state   = TU_STATE_IDLE;
                else
                    next_thread_state   = TU_STATE_BUSY;
            default:
                next_thread_state       = TU_STATE_IDLE;
        endcase
end

assign thread_state = cur_thread_state;

// logic  tu_idle;
logic  tu_req;
// logic  tu_done;
// assign tu_idle = thread_state == TU_STATE_IDLE;
assign tu_req  = cur_thread_state == TU_STATE_REQUEST;
// assign tu_done = thread_state == TU_STATE_DONE;

/*============================================================================//
region LOGIC
//============================================================================*/

logic               load_stall;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        load_stall <= '0;
    else if (load_op)
        load_stall <= '1;
    else if (rd_valid)
        load_stall <= '0;
    else
        load_stall <= load_stall;
end

logic [AW - 1: 0]   load_rd_addr;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        load_rd_addr <= '0;
    else if (load_op)
        load_rd_addr <= cmd.l.rd_addr;
    else
        load_rd_addr <= load_rd_addr;
end


logic [DW - 1: 0]           alu_or; // operation result
logic                       alu_rr; // result ready


thread_result_t             fpu_result;

logic [DW - 1: 0]           op_1, op_2, op_3;


logic [2: 0][FDW - 1: 0] operands;

// assign operands = {op_1, op_2, op_3};
if (FDW == DW) begin: gen_fdw_eq_dw
    always_comb begin
        if (f_cmd_valid)
            case (dec_cmd.op)
                ADD:        operands = {op_1, op_2, op_3};
                default:    operands = {op_3, op_2, op_1};
            endcase
        else
            operands = {op_1, op_2, op_3};
    end
end
else begin: gen_fdw_bigger_dw
    logic [FDW - 1: 0] fop_1, fop_2, fop_3;
    assign fop_1 = {(FDW - DW)'(1'b1), op_1};
    assign fop_2 = {(FDW - DW)'(1'b1), op_2};
    assign fop_3 = {(FDW - DW)'(1'b1), op_3};

    always_comb begin
        if (f_cmd_valid)
            case (dec_cmd.op)
                ADD:        operands = { fop_1,
                                         fop_2,
                                         fop_3 };
                default:    operands = { fop_3,
                                         fop_2,
                                         fop_1 };
            endcase
        else
            operands = {fop_1, fop_2, fop_3};
    end
end


logic  busy_o;
assign busy_o = fpu_state != FPU_IDLE;

logic wr_en;
logic [AW - 1: 0] addr_w;
logic [DW - 1: 0] data_w;

logic [AW - 1: 0] addr_result;
if (LATCH_R_ADDR) begin: gen_latch_r_addr
    logic [AW - 1: 0] ff_addr_r;
    always_ff @(posedge clk or negedge rst_n) begin
        if (~rst_n)
            ff_addr_r <= '0;
        else if (f_cmd_valid)
            ff_addr_r <= dec_cmd.ar;
        else if (~busy_o)
            ff_addr_r <= '0;
    end

    assign addr_result = f_cmd_valid? dec_cmd.ar: ff_addr_r;
end
else begin: gen_no_latch_r_addr
    assign addr_result = dec_cmd.ar;
end

// write
always_comb begin
    if (rd_valid && load_stall) begin
        addr_w = load_rd_addr;
        data_w = rd;
        wr_en  = '1;
    end
    else if (l_cmd_valid && ~(load_op || store_op)) begin
        addr_w = l_cmd.rd_addr;
        data_w = alu_or;
        wr_en  = alu_rr;
    end
    else if (s_cmd_valid) begin
        addr_w = s_cmd.rd_addr;
        data_w = alu_or;
        wr_en  = alu_rr;
    end
    else if (fpu_state == FPU_RESULT) begin
        addr_w = addr_result;
        data_w = fpu_result.result_data[DW - 1: 0];
        wr_en = '1;
    end
    else if (u_cmd_valid && u_cmd.operand != UOP_RET && thread_state != TU_STATE_REQUEST) begin
        addr_w = u_cmd.rd_addr;
        if (u_cmd.operand == UOP_IMM) begin
            data_w = (DW)'(u_cmd.imm << U_OFS_IMM_W);
            wr_en  = '1;
        end
        else begin
            data_w = alu_or;
            wr_en  = alu_rr;
        end
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
                LOP_LW, LOP_ADDI: begin
                    alu_struct.o1       = data_rs1;
                    alu_struct.o2       = (DW)'(l_cmd.imm);
                    alu_struct.op       = AOP_ADD;
                    alu_struct.valid    = '1;
                end
                LOP_JALR: begin
                    alu_struct.o1       = csr_pc_i;
                    alu_struct.o2       = STRB_W;
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
                SOP_ADD: begin
                    alu_struct.o1       = data_rs1;
                    alu_struct.o2       = data_rs2;
                    alu_struct.op       = AOP_ADD;
                    alu_struct.valid    = '1;
                end
                SOP_MUL: begin
                    alu_struct.o1       = data_rs1;
                    alu_struct.o2       = data_rs2;
                    alu_struct.op       = AOP_MUL;
                    alu_struct.valid    = '1;
                end
                default: begin
                    alu_struct = '0;
                end
            endcase
        end
        U_CMD: begin
            case (u_cmd.operand)
                UOP_JAL: begin
                    alu_struct.o1       = csr_pc_i;
                    alu_struct.o2       = STRB_W;
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


/*============================================================================//
region OUT
//============================================================================*/
assign  thread_info     = fpu_result.info;

always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n) begin
        rs1         <= '0;
        rs1_valid   <= '0;
    end
    else if (~tu_req) begin
        if (l_cmd_valid || s_cmd_valid) begin
            rs1         <= alu_or;
            rs1_valid   <= alu_rr;
        end
        else begin
            rs1         <= data_rs1;
            rs1_valid   <= '1;
        end
    end
    else begin
        rs1         <= rs1;
        rs1_valid   <= rs1_valid;
    end
end

// assign rs2          = data_rs2;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        rs2 <= '0;
    else if (~tu_req)
        rs2 <= data_rs2;
end

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
    .vid_i   (vid_i),               // <-
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
//                      *** TU FSM ***                       //
// NOTE: TU FSM model to check FPU state
tu_fpu_fsm tu_fpu_fsm_u (
    //================### COMMON SIGNALS ###=================//
    .clk         (clk),             // <-
    .rst_n       (rst_n),           // <-
    /*================### COMMON SIGNALS ###=================*/
    .ready       (f_cmd_valid),     // <-
    //===============### HANDSHAKE SIGNALS ###===============//
    .in_ready_o  (in_ready_o),      // <-
    .out_valid_o (out_valid_o),     // <-
    .out_ready_i (out_ready_i),     // ->
    .in_valid_i  (in_valid_i),      // ->
    /*================### STATUS SIGNALS ###=================*/
    .state       (fpu_state)        // ->
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
        .Features       (FPU_CONFIGURATION),
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
        .Features       (FPU_CONFIGURATION),
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
        .vectorial_op_i ('1),                           // <- (vectorial mode)
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
