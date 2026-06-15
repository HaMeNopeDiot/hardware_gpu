//----------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// ---------------------------------------------------------------------------//
// Purpose: GPU Core
// Date: 2026/06
//----------------------------------------------------------------------------//

/*============================================================================//
region MODULE DEFINITION
//============================================================================*/
module core
    import tu_pkg::thread_command_t;
    import tu_pkg::thread_info_t;
    import tu_pkg::cmd_t;
    import tu_pkg::dec_op_type_e;
    import tu_pkg::cmd_union_t;
    import tu_pkg::l_op_e;
    import tu_pkg::L_CMD;
    import tu_pkg::dw_value_t;
    import tu_pkg::TU_STATE_REQUEST;
    import tu_pkg::TU_STATE_IDLE;
    import tu_pkg::tu_state_e;

    // AHB
    import ahb_pkg::ahb_mports_t;
    import ahb_pkg::ahb_sports_t;

    import ahb_pkg::hsize_e;
    import ahb_pkg::hburst_e;
    import ahb_pkg::hprot_t;
    import ahb_pkg::htrans_e;

    // LSU
    import lsu_pkg::lsu_cmd_e;
#(
    parameter  int unsigned DW               = 32,
    parameter  int unsigned MEM_AW           = 32,
    parameter  int unsigned TU_REGILE_SZ     = 32,
    parameter  int unsigned TU_LATCH_R_ADDR  = 1,
    parameter  bit          ONLY_LINT        = `ifdef LINT 1 `else 0 `endif,
    parameter  int unsigned THREAD_CNT       = 4,
    localparam int unsigned THREAD_W         = $clog2(THREAD_CNT)
) (
    /*==========================### COMMON SIGNALS ###========================*/
    input   logic                       clk,
    input   logic                       rst_n,
    /*=========================### INSTRUCTION SIGNALS ###====================*/
    input   cmd_t                       instr_i,
    input   logic                       instr_valid_i,
    /*============================### AHB SIGNALS ###=========================*/
    // input   ahb_sports_t                lsu_ahb_i,
    output   logic [MEM_AW - 1: 0]       lsu_haddr,
    output   logic                       lsu_hwrite,
    output   hsize_e                     lsu_hsize,
    output   hburst_e                    lsu_hburst,
    output   hprot_t                     lsu_hprot,
    output   htrans_e                    lsu_htrans,
    output   logic                       lsu_hmastlock,
    output   logic [DW - 1: 0]           lsu_hwdata,
    // output  ahb_mports_t                lsu_ahb_o,
    input   logic                       lsu_hready,
    input   logic                       lsu_hresp,
    input   logic [DW - 1: 0]           lsu_hrdata,
    /*=============================### TU SIGNALS ###=========================*/
    output  thread_info_t               thread_info,
    output  logic                       decoder_ready_o
    //========================================================================//
);
/*============================================================================//
region AHB
//============================================================================*/
ahb_sports_t lsu_ahb_i;
ahb_mports_t lsu_ahb_o;

always_comb begin
    lsu_haddr     = lsu_ahb_o.haddr    ;
    lsu_hwrite    = lsu_ahb_o.hwrite   ;
    lsu_hsize     = lsu_ahb_o.hsize    ;
    lsu_hburst    = lsu_ahb_o.hburst   ;
    lsu_hprot     = lsu_ahb_o.hprot    ;
    lsu_htrans    = lsu_ahb_o.htrans   ;
    lsu_hmastlock = lsu_ahb_o.hmastlock;
    lsu_hwdata    = lsu_ahb_o.hwdata   ;
end

always_comb begin
    lsu_ahb_i.hready = lsu_hready;
    lsu_ahb_i.hresp  = lsu_hresp ;
    lsu_ahb_i.hrdata = lsu_hrdata;
end

/*============================================================================//
region LOGIC
//============================================================================*/
cmd_union_t         cmd;
dec_op_type_e       cmd_op_type;

thread_command_t    fpu_cmd;
logic               fpu_cmd_valid;

lsu_cmd_e           lsu_cmd;
logic               lsu_cmd_valid;

logic               no_req_from_threads;

/*============================================================================//
region THREAD INTERCONNECT
//============================================================================*/

logic [THREAD_W - 1: 0]      thread_sel, thread_sel_d1;

always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        thread_sel_d1 <= '0;
    else
        thread_sel_d1 <= thread_sel;
end

logic  thread_change;
assign thread_change = thread_sel_d1 != thread_sel;


reg_if              rt_if [THREAD_CNT](); // registers thread interface
reg_if              rl_if ();             // registers lsu interface

dw_value_t          rs1_arr[THREAD_CNT];
dw_value_t          rs2_arr[THREAD_CNT];

thread_info_t        thread_unit_info   [THREAD_CNT];
tu_state_e           thread_states      [THREAD_CNT];
assign thread_info = thread_unit_info   [thread_sel];


logic lsu_r2_thread [THREAD_CNT];
for (genvar i = 0; i < THREAD_CNT; i++) begin: gen_lsu_ready_demux
    assign lsu_r2_thread[i] = lsu_done && (i == thread_sel);
end

logic  thread_req, lsu_done;
assign thread_req = thread_states[thread_sel] != TU_STATE_IDLE;

for (genvar i = 0; i < THREAD_CNT; i++) begin: gen_rd_if_interpretator
    assign rs1_arr[i] = rt_if[i].rs1;
    assign rs2_arr[i] = rt_if[i].rs2;
end

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
    .clk                    (clk),                    // <-
    .rst_n                  (rst_n),                  // <-
    .threads_state          (thread_states),          // <-
    .thread_sel             (thread_sel),             // ->
    .no_req_from_threads    (no_req_from_threads)     // ->
    //=======================================================//
);
// ///////////////////////////////////////////////////////// //


// ///////////////////////////////////////////////////////// //
//                   *** CORE DECODER ***                    //
core_decoder #() core_decoder_u (
    //================### COMMON SIGNALS ###=================//
    .clk            (clk          ),    // <-
    .rst_n          (rst_n        ),    // <-
    //===========### SIGNALS FROM CONTROL UNIT ###===========//
    .instr_i        (instr_i      ),    // <-
    .instr_valid    (instr_valid_i),    // <-
    //==================### CMD SIGNALS ###==================//
    .cmd            (cmd          ),    // ->
    .cmd_op_type    (cmd_op_type  ),    // ->
    //================### SIGNALS TO LSU ###=================//
    .lsu_cmd        (lsu_cmd      ),    // ->
    .lsu_cmd_valid  (lsu_cmd_valid),    // ->
    //================### SIGNALS TO FPU ###=================//
    .fpu_cmd        (fpu_cmd      ),    // ->
    .fpu_cmd_valid  (fpu_cmd_valid),     // ->
    //===============### SIGNALS FROM FPU ###================//
    .threads_valid_i(no_req_from_threads), // <-
    .decoder_ready_o(decoder_ready_o    )  // ->
    //=======================================================//
);
// ///////////////////////////////////////////////////////// //

// ///////////////////////////////////////////////////////// //
//                     *** CORE LSU ***                      //
core_lsu #(
    .DW         (DW),
    .MEM_AW     (MEM_AW),
    .THREAD_CNT (THREAD_CNT)
) core_lsu_u (
    //================### COMMON SIGNALS ###=================//
    .clk               (clk                ),   // <-
    .rst_n             (rst_n              ),   // <-
    //=============### SIGNALS FROM DECODER ###==============//
    .lsu_op            (lsu_cmd            ),   // <-
    .lsu_op_valid      (lsu_cmd_valid      ),   // <-
    .thread_req_start  (thread_change      ),   // <-
    .threads_req_done  (no_req_from_threads),   // <-
    //===========### SIGNALS FROM THREAD UNIT ###============//
    .r_if              (rl_if.lsu          ),   // <->
    //============### SIGNALS FROM MEMORY BUS ###============//
    .ahb_i             (lsu_ahb_i          ),   // <-
    .ahb_o             (lsu_ahb_o          ),   // ->
    //================### HANDSHAKE SIGNALS ###==============//
    .lsu_ready_o       (lsu_done           ),   // ->
    .lsu_valid_i       (thread_req         )    // <-
    //=======================================================//
);
// ///////////////////////////////////////////////////////// //

for (genvar i = 0; i < THREAD_CNT; i++) begin: gen_threads
    // ///////////////////////////////////////////////////////// //
    //                    *** THREAD UNIT ***                    //
    thread_unit #(
        .DW           (DW),
        .REGFILE_SIZE (TU_REGILE_SZ),
        .LATCH_R_ADDR (TU_LATCH_R_ADDR),
        .ONLY_LINT    (ONLY_LINT)
    ) thread_unit_u (
        //================### COMMON SIGNALS ###=================//
        .clk            (clk                ),  // <-
        .rst_n          (rst_n              ),  // <-
        //==================### LSU SIGNALS ###==================//
        .cmd            (cmd                ),  // <-
        .cmd_op_type    (cmd_op_type        ),  // <-
        //===============### REGISTER SIGNALS ###================//
        .r_if           (rt_if[i].tu        ),  // <->
        .lsu_ready_i    (lsu_r2_thread[i]   ),  // <-
        //==================### DEC SIGNALS ###==================//
        .dec_cmd        (fpu_cmd            ),  // <-
        .dec_cmd_valid  (fpu_cmd_valid      ),  // <-
        //==================### VID SIGNALS ###==================//
        .vid_i          ((DW)'(i)           ),  // <- fixme later
        //==================### OUT SIGNALS ###==================//
        .thread_info    (thread_unit_info[i]),  // ->
        .thread_state   (thread_states[i]   )   // ->
        //=======================================================//
    );
    // ///////////////////////////////////////////////////////// //
end

endmodule
