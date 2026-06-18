//-------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// ------------------------------------------------------------------------------//
// Purpose: GPU Core fetcher
// Date: 2026/06
//-------------------------------------------------------------------------------//

/*===================================================================================//
region MODULE DEFINITION
//===================================================================================*/
module core_fetcher
    // imports here
    import tu_pkg::cmd_t;
    import ahb_pkg::hburst_e;
    import ahb_pkg::HBURST_SINGLE;
    import ahb_pkg::HBURST_INCR;
    import ahb_pkg::HBURST_INCR4;
    import ahb_pkg::HBURST_INCR8;
    import ahb_pkg::HBURST_INCR16;

    import ahb_pkg::htrans_e;
    import ahb_pkg::HTRANS_IDLE;
    import ahb_pkg::HTRANS_NONSEQ;
    import ahb_pkg::HTRANS_SEQ;

    import ahb_pkg::hprot_t;

    import ahb_pkg::HTRANS_DORO_OPCODE;
    import ahb_pkg::HTRANS_ACCS_PRIV;
    import ahb_pkg::HTRANS_BUFE_OFF;
    import ahb_pkg::HTRANS_BUFE_ON;
    import ahb_pkg::HTRANS_CACH_OFF;

    import ahb_pkg::ahb_txn_e;
    import ahb_pkg::AHB_IDLE  ;
    import ahb_pkg::AHB_STALL ;
    import ahb_pkg::AHB_ACTIVE;
    import ahb_pkg::AHB_ERROR ;

    import ahb_pkg::hsize_e;
    import ahb_pkg::HSIZE_BYTE ;
    import ahb_pkg::HSIZE_HWORD;
    import ahb_pkg::HSIZE_WORD ;
    import ahb_pkg::HSIZE_DWORD;

    // AHB
    import ahb_pkg::ahb_mports_t;
    import ahb_pkg::ahb_sports_t;
#(
    parameter   int unsigned DW           = 32,
    parameter   int unsigned AW           = 32,
    parameter   int unsigned THREAD_CNT   = 4,

    localparam  int unsigned TW           = $clog2(THREAD_CNT),

    parameter   int unsigned INST_Q_SZ    = 8,
    localparam  int unsigned INST_Q_W     = $clog2(INST_Q_SZ)
) (
    /*=======================### COMMON SIGNALS ###===========================*/
    input  logic                clk,
    input  logic                rst_n,

    /*========================### AHB SIGNALS ###=============================*/
    // ahb4_bus_if.master          ahb_bus,
`ifdef SIMPLE_AHB_PORTS
    // input   ahb_sports_t                lsu_ahb_i,
    output   logic [MEM_AW - 1: 0]  haddr,
    output   logic                  hwrite,
    output   hsize_e                hsize,
    output   hburst_e               hburst,
    output   hprot_t                hprot,
    output   htrans_e               htrans,
    output   logic                  hmastlock,
    output   logic [DW - 1: 0]      hwdata,
    // output  ahb_mports_t                lsu_ahb_o,
    input   logic                   hready,
    input   logic                   hresp,
    input   logic [DW - 1: 0]       hrdata,
`else
    input  ahb_sports_t             ahb_i,
    output ahb_mports_t             ahb_o,
`endif


    /*=====================### SIGNALS TO DECODER ###=========================*/
    output cmd_t                instr_o,
    output logic                instr_valid_o,
    input  logic                dec_ready_i,    // decoder is read
    /*======================### SIGNALS FROM CORE ###=========================*/
    input  logic [DW - 1: 0]    pc_i,
    input  logic                en_i,
    output logic                pc_readed_o

    //========================================================================//
);

/*============================================================================//
region ASSIGNES
//============================================================================*/

`ifdef SIMPLE_AHB_PORTS
    ahb_sports_t ahb_i;
    ahb_mports_t ahb_o;

    always_comb begin
        haddr     = ahb_o.haddr    ;
        hwrite    = ahb_o.hwrite   ;
        hsize     = ahb_o.hsize    ;
        hburst    = ahb_o.hburst   ;
        hprot     = ahb_o.hprot    ;
        htrans    = ahb_o.htrans   ;
        hmastlock = ahb_o.hmastlock;
        hwdata    = ahb_o.hwdata   ;
    end

    always_comb begin
        ahb_i.hready = hready;
        ahb_i.hresp  = hresp ;
        ahb_i.hrdata = hrdata;
    end
`endif


//============================================================================*/
// QUEUE
//============================================================================*/

logic  stop_load_pc;
assign stop_load_pc = free_buf_space <= (INST_Q_W)'(2); // need 2 cycles to determine what happenin

logic  stop_load_pc_ff;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        stop_load_pc_ff <= '0;
    else
        stop_load_pc_ff <= stop_load_pc;
end


logic  q_data_get;
assign q_data_get = gdata_valid;

logic q_data_give;

logic [DW - 1: 0] getted_data;
logic gdata_valid;//, gdata_valid_prev;

logic [DW - 1: 0] pc_i_ff;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        pc_i_ff <= '0;
    else if (ahb_i.hready)
        pc_i_ff <= pc_i;
    else
        pc_i_ff <= pc_i_ff;
end

logic [DW - 1: 0] ahb_addr;
always_comb begin
    if (ahb_i.hready)
        ahb_addr = pc_i;
    else
        ahb_addr = pc_i_ff;
end

logic  make_it_done;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        make_it_done <= '0;
    else if (~make_it_done && en_i && ~(ahb_i.hready))
        make_it_done <= '1;
    else if (make_it_done && ~en_i && (ahb_i.hready))
        make_it_done <= '0;
end

logic  ahb_rq;
assign ahb_rq = (en_i || make_it_done) && ~stop_load_pc_ff;


logic en_i_prev;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        en_i_prev <= '0;
    else
        en_i_prev <= en_i;
end

logic  start;
assign start = ~en_i_prev && en_i;

logic  start_d1;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        start_d1 <= '0;
    else
        start_d1 <= start;
end


assign q_data_give = instr_valid_o && dec_ready_i;
// write q_data_get

logic [DW - 1       : 0]    inst_q [INST_Q_SZ];
logic [INST_Q_W - 1 : 0]    inst_ptr_q;
logic [INST_Q_W - 1 : 0]    next_inst_ptr_q;
logic [INST_Q_W     : 0]    inst_buf_len;


logic  inst_q_empty;
logic  inst_q_full;

logic [INST_Q_W     : 0]    free_buf_space;
assign free_buf_space = (INST_Q_W + 1)'(INST_Q_SZ) - inst_buf_len;

assign inst_q_empty = inst_buf_len   == '0;
assign inst_q_full  = free_buf_space == '0;


always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        inst_ptr_q <= '0;
    else if (q_data_get && ~inst_q_full)
        if (inst_ptr_q == (INST_Q_W)'(INST_Q_SZ - 1))
            inst_ptr_q <= '0;
        else
            inst_ptr_q <= inst_ptr_q + (INST_Q_W)'(1);
end

always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        next_inst_ptr_q <= '0;
    else if (q_data_give && ~inst_q_empty)
        if (next_inst_ptr_q == (INST_Q_W)'(INST_Q_SZ - 1))
            next_inst_ptr_q <= '0;
        else
            next_inst_ptr_q <= next_inst_ptr_q + (INST_Q_W)'(1);
end

always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        inst_buf_len <= '0;
    else if (q_data_get && ~inst_q_full && q_data_give && ~inst_q_empty)
        inst_buf_len <= inst_buf_len;
    else if (q_data_get && ~inst_q_full)
        inst_buf_len <= inst_buf_len + (INST_Q_W + 1)'(1);
    else if (q_data_give && ~inst_q_empty)
        inst_buf_len <= inst_buf_len - (INST_Q_W + 1)'(1);
end

always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        for (int unsigned i = 0; i < INST_Q_SZ; i++) begin: gen_reset_inst_q
            inst_q[i] <= '0;
        end
    else if (q_data_get && ~inst_q_full)
        inst_q[inst_ptr_q] <= getted_data;

end

//============================================================================*/
// FETCH LOGIC
//============================================================================*/

assign instr_valid_o = ~inst_q_empty;

assign instr_o = inst_q[next_inst_ptr_q];

assign pc_readed_o = (start || (ahb_i.hready)) && ~stop_load_pc;

//============================================================================*/
// INSTANCES
//============================================================================*/

// ///////////////////////////////////////////////////////// //
//                    *** AHB MASTER ***                     //
// NOTE: Master AHB to memory for Fetcher
ahb_master #(
    .DW (DW),
    .AW (AW),
    .TW (TW)
) ahb_master_u (
    //================### COMMON SIGNALS ###=================//
    .clk          (clk          ),  // <-
    .rst_n        (rst_n        ),  // <-
    //==================### AHB SIGNALS ###==================//
    .ahb_i        (ahb_i        ),  // <-
    .ahb_o        (ahb_o        ),  // ->
    //================### CONTROL SIGNALS ###================//
    .req_txn_i    (ahb_rq       ),  // <-
    .rw_i         ('0           ),  // <-
    .txn_amount_i (2'b01        ),  // <-
    //==================### IN SIGNALS ###===================//
    .addr_i       (ahb_addr     ),  // <-
    .data_i       ('0           ),  // <-
    //==================### OUT SIGNALS ###==================//
    .data_o       (getted_data  ),  // ->
    .data_valid_o (gdata_valid  )   // ->
    //=======================================================//
);
// ///////////////////////////////////////////////////////// //

//============================================================================*/

endmodule
