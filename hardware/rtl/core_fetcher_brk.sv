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

    parameter   int unsigned INST_Q_SZ    = 8
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
// region FROM INSTANCES
//============================================================================*/
logic [DW - 1: 0] getted_data;
logic             gdata_valid;

logic             allow_load_pc;

//============================================================================*/
// region QUEUE LOGIC
//============================================================================*/



logic [DW - 1: 0] pc_i_ff;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        pc_i_ff <= '0;
    else if (ahb_i.hready)
        pc_i_ff <= pc_i;
    else
        pc_i_ff <= pc_i_ff;
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

logic en_i_prev;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        en_i_prev <= '0;
    else
        en_i_prev <= en_i;
end

logic  start;
assign start = ~en_i_prev && en_i;


//============================================================================*/
// region FETCH LOGIC
//============================================================================*/

assign pc_readed_o      = (start || (ahb_i.hready)) && allow_load_pc;

//============================================================================*/
// region TO INSTANCES
//============================================================================*/

logic  ahb_rq;
assign ahb_rq = (en_i || make_it_done) && allow_load_pc;

// when hready is low we can't change pc_i, so we use latch pc_i to pc_i_ff
logic [DW - 1: 0] ahb_addr;
always_comb begin
    if (ahb_i.hready)
        ahb_addr = pc_i;
    else
        ahb_addr = pc_i_ff;
end

//============================================================================*/
// region INSTANCES
//============================================================================*/

// ///////////////////////////////////////////////////////// //
//                     *** QUEUE BLK ***                     //
// NOTE: Here contains instructions
queue_blk #(
    .DW           (DW           ),
    .INST_Q_SZ    (INST_Q_SZ    ),
    // need 2 cycles to determine what happenin`
    // Why it's writed like this: when this Fetcher send address to read from
    // memory (for get instruction), fetcher need 1 cycle to send address to AHB
    // Master and AHB Master need 1 cycle to send transaction and get data. In
    // future need to change AHB Master to AXI Master and try to economy extra
    // cycles in fetcher
    .LD_DELAY     (2            )  // Do not change when set AHB Master as IF
) queue_blk_u (
    //================### COMMON SIGNALS ###=================//
    .clk          (clk          ), // <-
    .rst_n        (rst_n        ), // <-
    .clr          (~en_i        ), // <-
    //================### IN DATA SIGNALS ###================//
    .data_i       (getted_data  ), // <-
    .data_valid_i (gdata_valid  ), // <-
    .data_ready_o (allow_load_pc), // ->
    //===============### OUT DATA SIGNALS ###================//
    .data_o       (instr_o      ), // ->
    .data_valid_o (instr_valid_o), // ->
    .data_ready_i (dec_ready_i  )  // <-
    //=======================================================//
);
// ///////////////////////////////////////////////////////// //


// ///////////////////////////////////////////////////////// //
//                    *** AHB MASTER ***                     //
// NOTE: Master AHB to memory for Fetcher
ahb_master #(
    .DW           (DW           ),
    .AW           (AW           ),
    .TW           (TW           )
) ahb_master_u (
    //================### COMMON SIGNALS ###=================//
    .clk          (clk          ),  // <-
    .rst_n        (rst_n        ),  // <-
    .en_i         (en_i         ),  // <-
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
