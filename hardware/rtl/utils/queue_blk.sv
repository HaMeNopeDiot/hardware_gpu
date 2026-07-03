//-------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// ------------------------------------------------------------------------------//
// Purpose: Queue blk
// Date: 2026/07
//-------------------------------------------------------------------------------//

/*===================================================================================//
region MODULE DEFINITION
//===================================================================================*/
module queue_blk
#(
    parameter   int unsigned DW           = 32,
    parameter   int unsigned INST_Q_SZ    = 8,
    parameter   int unsigned LD_DELAY     = 2, // give a save load to queue, when getter data is
    // dumb
    localparam  int unsigned INST_Q_W     = $clog2(INST_Q_SZ)
) (
    /*=======================### COMMON SIGNALS ###===========================*/
    input  logic                clk,
    input  logic                rst_n,
    input  logic                clr,
    /*======================### IN DATA SIGNALS ###===========================*/
    input  logic [DW    - 1: 0] data_i,
    input  logic                data_valid_i,
    output logic                data_ready_o,
    /*======================### OUT DATA SIGNALS ###==========================*/
    output logic [DW    - 1: 0] data_o,
    output logic                data_valid_o,
    input  logic                data_ready_i
    //========================================================================//
);

/*============================================================================//
region DEFINITIONS
//============================================================================*/
logic [DW - 1       : 0]    inst_q [INST_Q_SZ];
logic [INST_Q_W - 1 : 0]    inst_ptr_q;
logic [INST_Q_W - 1 : 0]    next_inst_ptr_q;

logic [INST_Q_W     : 0]    inst_buf_len;
logic [INST_Q_W     : 0]    free_buf_space;
assign free_buf_space = (INST_Q_W + 1)'(INST_Q_SZ) - inst_buf_len;


logic  stop_load_pc;
assign stop_load_pc = free_buf_space <= (INST_Q_W + 1)'(LD_DELAY);


logic  stop_load_pc_ff;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        stop_load_pc_ff <= '0;
    else
        stop_load_pc_ff <= stop_load_pc;
end

/*============================================================================//
region LOGIC
//============================================================================*/

logic  q_data_get;
assign q_data_get  = data_valid_i && data_ready_o;

logic  q_data_give;
assign q_data_give = data_valid_o && data_ready_i;

logic  inst_q_empty;
logic  inst_q_full;

assign inst_q_empty = inst_buf_len   == '0;
assign inst_q_full  = free_buf_space == '0;

logic  store_inst;
assign store_inst   = q_data_get  && ~inst_q_full;

logic  deploy_inst;
assign deploy_inst  = q_data_give && ~inst_q_empty;

always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        inst_ptr_q <= '0;
    else if (store_inst)
        if (inst_ptr_q == (INST_Q_W)'(INST_Q_SZ - 1))
            inst_ptr_q <= '0;
        else
            inst_ptr_q <= inst_ptr_q + (INST_Q_W)'(1);
end

always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        next_inst_ptr_q <= '0;
    else if (clr)
        next_inst_ptr_q <= inst_ptr_q;
    else if (deploy_inst)
        if (next_inst_ptr_q == (INST_Q_W)'(INST_Q_SZ - 1))
            next_inst_ptr_q <= '0;
        else
            next_inst_ptr_q <= next_inst_ptr_q + (INST_Q_W)'(1);
end

// Counter buf length
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        inst_buf_len <= '0;
    else if (clr)
        inst_buf_len <= '0;
    else if (store_inst && deploy_inst)
        inst_buf_len <= inst_buf_len;
    else if (store_inst)
        inst_buf_len <= inst_buf_len + (INST_Q_W + 1)'(1);
    else if (deploy_inst)
        inst_buf_len <= inst_buf_len - (INST_Q_W + 1)'(1);
end

always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        for (int unsigned i = 0; i < INST_Q_SZ; i++) begin: gen_reset_inst_q
            inst_q[i] <= '0;
        end
    else if (store_inst)
        inst_q[inst_ptr_q] <= data_i;
end

/*============================================================================//
region OUT
//============================================================================*/

assign data_o       = inst_q[next_inst_ptr_q];
assign data_valid_o = ~inst_q_empty;


assign data_ready_o = ~stop_load_pc;

//============================================================================*/

endmodule
