//----------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// ---------------------------------------------------------------------------//
// Purpose: GPU Core Interconnect
// Date: 2026/07
//----------------------------------------------------------------------------//

/*============================================================================//
region MODULE DEFINITION
//============================================================================*/

module core_interconnect
    import tu_pkg::TU_STATE_BUSY;
    import tu_pkg::TU_STATE_REQUEST;
    import tu_pkg::tu_state_e;
    import tu_pkg::dw_value_t;
    import tu_pkg::thread_info_t;
#(
    parameter  int unsigned THREAD_CNT       = 4,
    localparam int unsigned THREAD_W         = $clog2(THREAD_CNT)
) (
    /*=======================### COMMON SIGNALS ###===========================*/
    input    logic                      clk,
    input    logic                      rst_n,
    //========================================================================//
    input    logic                      lsu_done,
    //========================================================================//
    input    thread_info_t              thread_sel_info  [THREAD_CNT],
    input    tu_state_e                 thread_states    [THREAD_CNT],
    //========================================================================//
    output   thread_info_t              thread_info,
    output   logic                      next_cmd_ready,
    output   logic                      lsu_ready_mask   [THREAD_CNT],
    output   logic                      thread_sel_valid,
    output   logic                      no_req_from_threads,
    output   logic                      thread_req,
    //========================================================================//
    reg_if.lsu                          rt_if            [THREAD_CNT],
    reg_if.tu                           rl_if
    //========================================================================//
);
/*============================================================================//
region DEFINITIONS
//============================================================================*/

logic [THREAD_W - 1: 0]      thread_sel;
logic [THREAD_CNT - 1: 0]    is_busy_tu;

/*============================================================================//
region LOGIC
//============================================================================*/
assign thread_info = thread_sel_info   [thread_sel];

// lsu ready signal for each thread. LSU must signal READY only to sel thread
for (genvar i = 0; i < THREAD_CNT; i++) begin: gen_lsu_ready_demux
    assign lsu_ready_mask[i] = lsu_done && (i == thread_sel);
end

for (genvar i = 0; i < THREAD_CNT; i++) begin: gen_status_tu_req
    assign is_busy_tu[i] = thread_states[i] == TU_STATE_BUSY;
end

/*============================================================================//
region OUT
//============================================================================*/

// All threads are idle and waiting next cmd
assign next_cmd_ready = (is_busy_tu == '0) && no_req_from_threads;

// Thread req LSU
assign thread_req = thread_states[thread_sel] != TU_STATE_REQUEST;

/*============================================================================//
region RF INTERFACE CONNECTIONS
//============================================================================*/


// This needed to avoid verilator. If verilator don't blame me when i write less
// code construction to attach interfaces, this code generation don't needed
dw_value_t                   rs1_arr[THREAD_CNT];
dw_value_t                   rs2_arr[THREAD_CNT];
for (genvar i = 0; i < THREAD_CNT; i++) begin: gen_rd_if_interpretator
    assign rs1_arr[i] = rt_if[i].rs1;
    assign rs2_arr[i] = rt_if[i].rs2;
end

// Just connect 1 of all interfaces to 1 LSU interface
always_comb begin
    rl_if.rs1 = rs1_arr[thread_sel];
    rl_if.rs2 = rs2_arr[thread_sel];
end

for (genvar i = 0; i < THREAD_CNT; i++) begin: gen_rd_demux
    assign rt_if[i].rd = (THREAD_W)'(i) == thread_sel? rl_if.rd: '0;
end

/*============================================================================//
region INSTANCES
//============================================================================*/

// ///////////////////////////////////////////////////////// //
//                  *** CORE ARBITRAGE ***                   //
core_arbiter #(
    .THREAD_CNT (THREAD_CNT)
) core_arbitrage_u (
    //================### COMMON SIGNALS ###=================//
    .clk                    (clk                ),    // <-
    .rst_n                  (rst_n              ),    // <-
    .threads_state          (thread_states      ),    // <-
    .thread_sel             (thread_sel         ),    // ->
    .no_req_from_threads    (no_req_from_threads),    // ->
    .thread_sel_valid       (thread_sel_valid   )     // ->
    //=======================================================//
);
// ///////////////////////////////////////////////////////// //

//============================================================================//
endmodule
