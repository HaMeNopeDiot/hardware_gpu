//-------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// ------------------------------------------------------------------------------//
// Purpose: GPU Core decoder
// Date: 2026/06
//-------------------------------------------------------------------------------//

/*===================================================================================//
region MODULE DEFINITION
//===================================================================================*/
module core_arbiter
    import tu_pkg::tu_state_e;
    import tu_pkg::core_state_e;
    import tu_pkg::TU_STATE_REQUEST;
#(
    parameter  int unsigned THREAD_CNT       = 4,
    localparam int unsigned THREAD_W         = $clog2(THREAD_CNT) == 0? 1: $clog2(THREAD_CNT)
) (
    /*=======================### COMMON SIGNALS ###===========================*/
    input  logic                            clk,
    input  logic                            rst_n,

    input  tu_state_e                       threads_state [THREAD_CNT],

    output logic        [THREAD_W - 1: 0]   thread_sel,
    output logic                            no_req_from_threads
    //========================================================================//
);
    /*========================================================================//
    region LOGIC
    //========================================================================*/

    logic [THREAD_W - 1: 0] thread_ptr;

    // selected thread is requesting right now
    logic  thread_req;
    assign thread_req = threads_state[thread_ptr] == TU_STATE_REQUEST;

    // is selected last thread in thread list
    logic  is_sel_last_thread;
    assign is_sel_last_thread = thread_ptr == (THREAD_W)'(THREAD_CNT - 1);

    always_ff @(posedge clk or negedge rst_n) begin
        if (~rst_n)
            thread_ptr <= '0;
        else if (~thread_req)
            if (~is_sel_last_thread)
                thread_ptr <= thread_ptr + (THREAD_W)'(1);
            else
                thread_ptr <= '0;
        else
            thread_ptr <= thread_ptr;
    end


    logic [THREAD_CNT - 1: 0] is_req_from_tu;
    for (genvar i = 0; i < THREAD_CNT; i++) begin: gen_status_tu_req
        assign is_req_from_tu[i] = threads_state[i] == TU_STATE_REQUEST;
    end

    assign no_req_from_threads = is_req_from_tu == '0;


    /*========================================================================//
    region OUT
    //========================================================================*/

    assign thread_sel = thread_ptr;

    //========================================================================*/
endmodule
