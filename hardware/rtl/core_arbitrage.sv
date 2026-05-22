//-------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// ------------------------------------------------------------------------------//
// Purpose: GPU Core decoder
// Date: 2026/05
//-------------------------------------------------------------------------------//

/*===================================================================================//
region MODULE DEFINITION
//===================================================================================*/
module core_arbitrage
    import tu_pkg::tu_state_e;
    import tu_pkg::core_state_e;
    import tu_pkg::TU_STATE_REQUEST;
    import tu_pkg::CORE_STATE_WAIT;
#(
    parameter  int unsigned THREAD_CNT       = 4,
    localparam int unsigned THREAD_W         = $clog2(THREAD_CNT)
) (
    /*=======================### COMMON SIGNALS ###===========================*/
    input  logic                            clk,
    input  logic                            rst_n,

    input  core_state_e                     core_state,
    input  tu_state_e   [THREAD_CNT - 1: 0] treads_state,

    output logic        [THREAD_W - 1: 0]   thread_sel
    //========================================================================//
);
    /*========================================================================//
    region LOGIC
    //========================================================================*/

    logic [THREAD_W - 1: 0] thread_ptr;

    // selected thread is requesting right now
    logic  thread_req;
    assign thread_req = thread_state[thread_ptr] == TU_STATE_REQUEST;

    // whole core wait requested threads
    logic  core_wait;
    assign core_wait = core_state == CORE_STATE_WAIT;

    // is selected last thread in thread list
    logic  is_sel_last_thread;
    assign is_sel_last_thread = thread_ptr == THREAD_CNT - 1;

    always_ff @(posedge clk or negedge rst_n) begin
        if (~rst_n)
            thread_ptr <= '0;
        else if (core_wait && ~thread_req)
            if (~is_sel_last_thread)
                thread_ptr <= thread_ptr + (THREAD_W)'(1);
            else
                thread_ptr <= '0;
    end

    // On next cycle thread ptr is go back to zero
    logic  thread_cycle_done;
    assign thread_cycle_done = core_wait && ~tread_rq && ~is_sel_last_thread;

    /*========================================================================//
    region OUT
    //========================================================================*/

    assign thread_sel = thread_ptr;

    //========================================================================*/
endmodule
