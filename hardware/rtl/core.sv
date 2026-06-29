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
    import tu_pkg::TU_STATE_BUSY;
    import tu_pkg::TU_STATE_IDLE;
    import tu_pkg::tu_state_e;

    // AHB
    import ahb_pkg::ahb_mports_t;
    import ahb_pkg::ahb_sports_t;

    import ahb_pkg::hsize_e;
    import ahb_pkg::hburst_e;
    import ahb_pkg::hprot_t;
    import ahb_pkg::htrans_e;

    // APB
    import apb_pkg::apb4_mports_t;
    import apb_pkg::apb4_sports_t;
    import apb_pkg::STROBE;

    // LSU
    import lsu_pkg::lsu_cmd_e;

#(
    parameter  int unsigned DW               = 32,
    parameter  int unsigned MEM_AW           = 32,
    parameter  int unsigned CSR_AW           = 7,

    parameter  int unsigned TU_REGILE_SZ     = 32,
    parameter  int unsigned TU_LATCH_R_ADDR  = 1,
    parameter  bit          ONLY_LINT        = `ifdef LINT 1 `else 0 `endif,
    parameter  int unsigned THREAD_CNT       = 4,
    localparam int unsigned THREAD_W         = $clog2(THREAD_CNT)
) (
    /*==========================### COMMON SIGNALS ###========================*/
    input    logic                      clk,
    input    logic                      rst_n,
    /*============================### AHB SIGNALS ###=========================*/
    // input   ahb_sports_t                lsu_ahb_i,
    output   logic [MEM_AW - 1: 0]      lsu_haddr,
    output   logic                      lsu_hwrite,
    output   hsize_e                    lsu_hsize,
    output   hburst_e                   lsu_hburst,
    output   hprot_t                    lsu_hprot,
    output   htrans_e                   lsu_htrans,
    output   logic                      lsu_hmastlock,
    output   logic [DW - 1: 0]          lsu_hwdata,
    // output  ahb_mports_t                lsu_ahb_o,
    input   logic                       lsu_hready,
    input   logic                       lsu_hresp,
    input   logic [DW - 1: 0]           lsu_hrdata,

    // input   ahb_sports_t                ftc_ahb_i,
    output  logic [MEM_AW - 1: 0]       ftc_haddr,
    output  logic                       ftc_hwrite,
    output  hsize_e                     ftc_hsize,
    output  hburst_e                    ftc_hburst,
    output  hprot_t                     ftc_hprot,
    output  htrans_e                    ftc_htrans,
    output  logic                       ftc_hmastlock,
    output  logic [DW - 1: 0]           ftc_hwdata,
    // output  ahb_mports_t                ftc_ahb_o,
    input   logic                       ftc_hready,
    input   logic                       ftc_hresp,
    input   logic [DW - 1: 0]           ftc_hrdata,
    /*============================### APB SIGNALS ###=========================*/
    // output apb4_sports_t                csr_apb_i
    output  logic [DW - 1: 0]           csr_prdata,
    output  logic                       csr_pready,
    output  logic                       csr_pslverr,
    // input  apb4_mports_t                csr_apb_o
    input   logic [CSR_AW - 1: 0]       csr_paddr,
    input   logic [DW - 1: 0]           csr_pwdata,
    input   logic [STROBE - 1: 0]       csr_pstrb,
    input   logic                       csr_psel,
    input   logic                       csr_pwrite,
    input   logic                       csr_penable,
    input   logic [2:0]                 csr_pprot,
    /*=============================### TU SIGNALS ###=========================*/
    output  thread_info_t               thread_info,
    output  logic                       busy_o
    //========================================================================//
);
/*============================================================================//
region AHB
//============================================================================*/
ahb_sports_t lsu_ahb_i, ftc_ahb_i;
ahb_mports_t lsu_ahb_o, ftc_ahb_o;

// Load/Store unit
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

// Fetcher unit
always_comb begin
    ftc_haddr     = ftc_ahb_o.haddr    ;
    ftc_hwrite    = ftc_ahb_o.hwrite   ;
    ftc_hsize     = ftc_ahb_o.hsize    ;
    ftc_hburst    = ftc_ahb_o.hburst   ;
    ftc_hprot     = ftc_ahb_o.hprot    ;
    ftc_htrans    = ftc_ahb_o.htrans   ;
    ftc_hmastlock = ftc_ahb_o.hmastlock;
    ftc_hwdata    = ftc_ahb_o.hwdata   ;
end

always_comb begin
    ftc_ahb_i.hready = ftc_hready;
    ftc_ahb_i.hresp  = ftc_hresp ;
    ftc_ahb_i.hrdata = ftc_hrdata;
end

/*============================================================================//
region APB
//============================================================================*/
apb4_mports_t csr_apb_i;
apb4_sports_t csr_apb_o;

always_comb begin // ->
    csr_prdata  = csr_apb_o.prdata;
    csr_pready  = csr_apb_o.pready;
    csr_pslverr = csr_apb_o.pslverr;
end

always_comb begin // <-
    csr_apb_i.paddr     = csr_paddr;
    csr_apb_i.pwdata    = csr_pwdata;
    csr_apb_i.pstrb     = csr_pstrb;
    csr_apb_i.psel      = csr_psel;
    csr_apb_i.pwrite    = csr_pwrite;
    csr_apb_i.penable   = csr_penable;
    csr_apb_i.pprot     = csr_pprot;
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

cmd_t               ftc_instr;
logic               ftc_instr_valid;
logic               dec_ready;


// CSR <-> CORE
logic               fetcher_read_pc;
logic [DW - 1: 0]   vid_arr [THREAD_CNT];
logic               csr_en;
logic [DW - 1: 0]   csr_pc;
logic               ret_inst;
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

logic [THREAD_CNT - 1: 0] is_busy_tu;
for (genvar i = 0; i < THREAD_CNT; i++) begin: gen_status_tu_req
    assign is_busy_tu[i] = thread_states[i] == TU_STATE_BUSY;
end

logic  tus_ready_get_cmd;
assign tus_ready_get_cmd = (is_busy_tu == '0) && no_req_from_threads;

/*============================================================================//
region OUT
//============================================================================*/

assign busy_o = csr_en;

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
//                   *** CORE FETCHER ***                    //
// NOTE: write a purpose here
core_fetcher #(
    .DW         (DW),
    .AW         (MEM_AW),
    .THREAD_CNT (THREAD_CNT),
    .INST_Q_SZ  (8)
) core_fetcher_u (
    //================### COMMON SIGNALS ###=================//
    .clk           (clk             ), // <-
    .rst_n         (rst_n           ), // <-
    //==================### AHB SIGNALS ###==================//
    .ahb_i         (ftc_ahb_i       ), // <-
    .ahb_o         (ftc_ahb_o       ), // ->
    //==============### SIGNALS TO DECODER ###===============//
    .instr_o       (ftc_instr       ), // ->
    .instr_valid_o (ftc_instr_valid ), // ->
    .dec_ready_i   (dec_ready       ), // <-
    //===============### SIGNALS FROM CORE ###===============//
    .pc_i          (csr_pc          ), // <-
    .en_i          (csr_en          ), // <-
    .pc_readed_o   (fetcher_read_pc )  // ->
    //=======================================================//
);
// ///////////////////////////////////////////////////////// //

// ///////////////////////////////////////////////////////// //
//                   *** CORE DECODER ***                    //
core_decoder #() core_decoder_u (
    //================### COMMON SIGNALS ###=================//
    .clk            (clk                ),    // <-
    .rst_n          (rst_n              ),    // <-
    //===========### SIGNALS FROM CONTROL UNIT ###===========//
    .instr_i        (ftc_instr          ),    // <-
    .instr_valid    (ftc_instr_valid    ),    // <-
    //==================### CMD SIGNALS ###==================//
    .cmd            (cmd                ),    // ->
    .cmd_op_type    (cmd_op_type        ),    // ->
    //================### SIGNALS TO LSU ###=================//
    .lsu_cmd        (lsu_cmd            ),    // ->
    .lsu_cmd_valid  (lsu_cmd_valid      ),    // ->
    //================### SIGNALS TO FPU ###=================//
    .fpu_cmd        (fpu_cmd            ),    // ->
    .fpu_cmd_valid  (fpu_cmd_valid      ),    // ->
    //==============### SIGNALS FROM CORE ###================//
    .threads_valid_i(tus_ready_get_cmd  ),    // <-
    .decoder_ready_o(dec_ready          ),    // ->
    .ret_inst_o     (ret_inst           ),    // ->
    .en_i           (csr_en             )     // <-
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

// ///////////////////////////////////////////////////////// //
//                  *** CORE CSRM HNDL ***                   //
// NOTE: write a purpose here
core_csrm_hndl #(
    .DW         (DW),
    .AW         (CSR_AW),
    .THREAD_CNT (THREAD_CNT)
) core_csrm_hndl_u (
    //================### COMMON SIGNALS ###=================//
    .clk         (clk               ), // <-
    .rst_n       (rst_n             ), // <-
    //==================### APB SIGNALS ###==================//
    .apb4_i      (csr_apb_i         ), // <-
    .apb4_o      (csr_apb_o         ), // ->
    //==================### OUT SIGNALS ###==================//
    .ret_i       (ret_inst          ), // <-
    .en_o        (csr_en            ), // ->
    .vid_o       (vid_arr           ), // ->
    .pc_readed_i (fetcher_read_pc   ), // <-
    .cur_pc_o    (csr_pc            )  // ->
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
        .vid_i          (vid_arr[i]         ),  // <-
        //==================### OUT SIGNALS ###==================//
        .thread_info    (thread_unit_info[i]),  // ->
        .thread_state   (thread_states[i]   )   // ->
        //=======================================================//
    );
    // ///////////////////////////////////////////////////////// //
end

endmodule
