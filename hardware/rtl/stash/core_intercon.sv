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
module core_intercon
    import core_lsu_pkg::lsu_load_q_elem_t;
    import core_lsu_pkg::lsu_store_q_elem_t;
    import core_lsu_pkg::lsu_q_elem_t;

    import core_intercon_pkg::fsm_hndshk_e;
    import core_intercon_pkg::HNDSHK_IDLE;
    import core_intercon_pkg::HNDSHK_REQ;
    import core_intercon_pkg::HNDSHK_BUSY;
    import core_intercon_pkg::HNDSHK_DONE;
#(
    parameter  int unsigned DW               = 32,
    parameter  int unsigned THREAD_CNT       = 4,
    localparam int unsigned THREAD_W         = $clog2(THREADS_CNT) == 0? 1: $clog2(THREADS_CNT)
) (
    /*=======================### COMMON SIGNALS ###===========================*/
    input  logic                            clk,
    input  logic                            rst_n,

    /*==========================### LSU SIGNALS ###===========================*/
    reg_if.tu                               r_if_from_lsu,
    input  logic                            lsu_valid_i,
    input  logic                            lsu_ready_i,
    output logic                            lsu_ready_o,
    output logic                            lsu_valid_o,

    /*===========================### TU SIGNALS ###===========================*/
    reg_if.lsu                              r_if_from_tu[THREAD_CNT],
    input  logic                            tu_valid_i  [THREAD_CNT],
    output logic                            tu_valid_o  [THREAD_CNT],
    input  logic                            tu_ready_i  [THREAD_CNT],

    input  thread_info_t                    tu_info     [THREAD_CNT],
    input  tu_state_e                       tu_state    [THREAD_CNT]

    //========================================================================//
);
    /*========================================================================//
    region MAIN CONCEPT
    //========================================================================*/
    logic [THREAD_W - 1: 0]      tu_sel;
    lsu_q_elem_t                 tu_q[THREAD_CNT];

    /*========================================================================//
    region INSTANCE
    //========================================================================*/

    // ///////////////////////////////////////////////////////// //
    //                  *** CORE ARBITRAGE ***                   //
    core_arbiter #(
        .THREAD_CNT (THREAD_CNT)
    ) core_arbitrage_u (
        //================### COMMON SIGNALS ###=================//
        .clk          (clk),                    // <-
        .rst_n        (rst_n),                  // <-
        .threads_state(tu_state),               // <-
        .thread_sel   (tu_sel)                  // ->
        //=======================================================//
    );
    // ///////////////////////////////////////////////////////// //



    //========================================================================*/
endmodule
