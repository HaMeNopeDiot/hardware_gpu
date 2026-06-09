//----------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// ---------------------------------------------------------------------------//
// Purpose: GPU Core LSU
// Date: 2026/06
//----------------------------------------------------------------------------//

/*============================================================================//
region MODULE DEFINITION
//============================================================================*/
module core_lsu
    import tu_pkg::dw_value_t;
    // LSU
    import lsu_pkg::lsu_cmd_e;
    import lsu_pkg::LSU_L;
    import lsu_pkg::LSU_S;

    // LSU FSM
    import core_lsu_fsm_pkg::lsu_fsm_t;
    import core_lsu_fsm_pkg::LSU_IDLE;
    import core_lsu_fsm_pkg::LSU_SEND;
    import core_lsu_fsm_pkg::LSU_RQ  ;
    import core_lsu_fsm_pkg::LSU_DONE;

    import ahb_pkg::ahb_mports_t;
    import ahb_pkg::ahb_sports_t;
#(
    parameter int unsigned DW = 64,
    parameter int unsigned MEM_AW = 32
) (
    /*============================### COMMON SIGNALS ###======================*/
    input  logic                    clk,
    input  logic                    rst_n,

    /*=========================### SIGNALS FROM DECODER ###===================*/
    input  lsu_cmd_e                lsu_op,
    input  logic                    lsu_op_valid,
    /*=======================### SIGNALS FROM MEMORY BUS ###==================*/
    input  ahb_sports_t             ahb_i,
    output ahb_mports_t             ahb_o,

    /*=======================### SIGNALS FROM THREAD UNIT ###=================*/
    reg_if.lsu                      r_if,

    /*=========================### SIGNALS HANDSHAKE ###======================*/
    output logic                    lsu_ready_o,
    input  logic                    lsu_valid_i

    //========================================================================//
);

/*============================================================================//
region LOGIC
//============================================================================*/

// Register interface
logic [DW - 1: 0] rs1,       rs2,       rd;
logic             rs1_valid, rs2_valid, rd_valid;
assign rs1              = r_if.rs1.value;
assign rs1_valid        = r_if.rs1.valid;
assign rs2              = r_if.rs2.value;
assign rs2_valid        = r_if.rs2.valid;

assign r_if.rd.value    = rd;
assign r_if.rd.valid    = rd_valid;

/*============================================================================//
region FSM
//============================================================================*/
logic mem_ans_valid;
logic [DW - 1: 0] mem_data;

lsu_fsm_t state, next_state;

always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        state <= LSU_IDLE;
    else
        state <= next_state;
end

always_comb begin
    case (state)
        LSU_IDLE: begin // Get command
            if (lsu_op_valid)
                next_state = LSU_SEND;
            else
                next_state = LSU_IDLE;
        end
        LSU_SEND: begin // Wait info from TU and send it to SRAM
            if (req_valid)
                next_state = LSU_RQ;
            else
                next_state = LSU_SEND;
        end
        LSU_RQ: begin // Wait answer from SRAM
            if (mem_ans_valid)
                next_state = LSU_DONE;
            else
                next_state = LSU_RQ;
        end
        LSU_DONE: begin // Hold result
            if (lsu_valid_i)
                next_state = LSU_IDLE;
            else
                next_state = LSU_DONE;
        end
        default:
            next_state = LSU_IDLE;
    endcase
end

logic   send_rq;
assign  send_rq = next_state == LSU_SEND;

logic   get_res;
assign  get_res = next_state == LSU_DONE;

/*============================================================================//
region COMMON
//============================================================================*/
logic  op_is_load, op_is_store;
assign op_is_load   = lsu_op == LSU_L;
assign op_is_store  = lsu_op == LSU_S;

logic  rw_req;
assign rw_req = op_is_load? '0: '1;

logic [MEM_AW - 1: 0] mem_addr;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        mem_addr <= '0;
    else if (rs1_valid && op_is_store)
        mem_addr <= (MEM_AW)'(rs1);
    else if (rs1_valid && op_is_load && send_rq)
        mem_addr <= (MEM_AW)'(rs1);
    else
        mem_addr <= '0;
end

/*============================================================================//
region READ
//============================================================================*/

always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        rd <= '0;
    else if (get_res && op_is_load)
        rd <= mem_data;
    else
        rd <= '0;
end

always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        rd_valid <= '0;
    else if (get_res && op_is_load)
        rd_valid <= mem_ans_valid;
    else
        rd_valid <= '0;
end


/*============================================================================//
region WRITE
//============================================================================*/

logic [DW -1 : 0] wdata;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        wdata <= '0;
    else if (send_rq && op_is_store && rs2_valid)
        wdata <= rs2;
    else
        wdata <= '0;
end

logic req_valid;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        req_valid <= '0;
    else if (send_rq && op_is_store)
        req_valid <= rs1_valid && rs2_valid;
    else if (send_rq && op_is_load)
        req_valid <= rs1_valid;
    else
        req_valid <= '0;
end
/*============================================================================//
region INSTANCE
//============================================================================*/

// ///////////////////////////////////////////////////////// //
//                    *** AHB MASTER ***                     //
// NOTE: Master AHB to memory for LSU
ahb_master #(
    .DW (DW),
    .AW (MEM_AW),
    .TW (2)
) ahb_master_u (
    //================### COMMON SIGNALS ###=================//
    .clk          (clk          ),  // <-
    .rst_n        (rst_n        ),  // <-
    //==================### AHB SIGNALS ###==================//
    .ahb_i        (ahb_i        ),  // <-
    .ahb_o        (ahb_o        ),  // ->
    //================### CONTROL SIGNALS ###================//
    .req_txn_i    (req_valid    ),  // <-
    .rw_i         (rw_req       ),  // <-
    .txn_amount_i (2'b01        ),  // <-
    //==================### IN SIGNALS ###===================//
    .addr_i       (mem_addr     ),  // <-
    .data_i       (wdata        ),  // <-
    //==================### OUT SIGNALS ###==================//
    .data_o       (mem_data     ),  // ->
    .data_valid_o (mem_ans_valid)   // ->
    //=======================================================//
);
// ///////////////////////////////////////////////////////// //

/*============================================================================//
region OUT
//============================================================================*/

assign lsu_ready_o = next_state == LSU_DONE;

//============================================================================*/
endmodule
