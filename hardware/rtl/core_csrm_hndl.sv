//------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// -----------------------------------------------------------------------------//
// Purpose: Handler for Control status register map
// Date: 2026/06
//------------------------------------------------------------------------------//

/*==============================================================================//
region MODULE DEFINITION
//==============================================================================*/
module core_csrm_hndl
    // imports here
    import apb_pkg::apb4_mports_t;
    import apb_pkg::apb4_sports_t;
    import core_regblk_pkg::*;

#(
    parameter   int unsigned DW           = 32,
    parameter   int unsigned AW           = 32,
    parameter   int unsigned THREAD_CNT   = 4,
    localparam  int unsigned STROBE       = DW / 8,

    localparam  int unsigned MIN_ADDR     = '0,
    localparam  int unsigned MAX_ADDR     = F_VID_OFS + THREAD_CNT * STROBE
) (
    /*=======================### COMMON SIGNALS ###===========================*/
    input  logic                    clk,
    input  logic                    rst_n,
    /*=========================### APB SIGNALS ###============================*/
    input  apb4_mports_t            apb4_i,
    output apb4_sports_t            apb4_o,
    /*=========================### OUT SIGNALS ###============================*/
    input  logic                    ret_i,
    output logic                    en_o,
    output logic [DW - 1: 0]        vid_o [THREAD_CNT],
    input  logic                    pc_readed_i,
    output logic [DW - 1: 0]        cur_pc_o
    //========================================================================//
);

/*============================================================================//
region ASSIGNES
//============================================================================*/
// in
logic [AW     - 1: 0] paddr;
logic [DW     - 1: 0] pwdata;
logic [STROBE - 1: 0] pstrb;
logic                 psel;
logic                 pwrite;
logic                 penable;
logic [2: 0]          pprot;

always_comb begin
    paddr   = apb4_i.paddr  ;
    pwdata  = apb4_i.pwdata ;
    pstrb   = apb4_i.pstrb  ;
    psel    = apb4_i.psel   ;
    pwrite  = apb4_i.pwrite ;
    penable = apb4_i.penable;
    pprot   = apb4_i.pprot  ;
end

// out
logic [DW     - 1: 0] prdata;
logic                 pready;
logic                 pslverr;

always_comb begin
    apb4_o.prdata   = prdata;
    apb4_o.pready   = pready;
    apb4_o.pslverr  = pslverr;
end

/*============================================================================//
region LOGIC
//============================================================================*/

logic [DW - 1: 0] csrm_wedata;
logic [DW - 1: 0] csrm_rdata;

/*============================================================================//
region INSTANCES
//============================================================================*/

// ///////////////////////////////////////////////////////// //
//                     *** CORE CSRM ***                     //
// NOTE: write a purpose here
core_csrm #(
    .AW          (AW        ),
    .DW          (DW        ),
    .THREAD_CNT  (THREAD_CNT)
) core_csrm_u (
    //================### COMMON SIGNALS ###=================//
    .clk        (clk        ),  // <-
    .rst_n      (rst_n      ),  // <-
    .addr       (paddr      ),  // <-
    .wdata      (pwdata     ),  // <-
    .wedata     (csrm_wedata),  // <-
    .rdata      (csrm_rdata ),  // ->
    //==============### ADDITIONAL SIGNALS ###===============//
    .ret_i      (ret_i      ),  // <-
    .en_o       (en_o       ),  // ->
    .vid_o      (vid_o      ),  // ->
    .cur_pc_o   (cur_pc_o   ),  // ->
    .pc_readed_i(pc_readed_i)   // <-
    //=======================================================//
);
// ///////////////////////////////////////////////////////// //

// ///////////////////////////////////////////////////////// //
//                     *** APB SLAVE ***                     //
// NOTE: write a purpose here
apb_slave #(
    .AW       (AW       ),
    .DW       (DW       ),
    .MIN_ADDR (MIN_ADDR ),
    .MAX_ADDR (MAX_ADDR )
) apb_slave_u (
    //================### COMMON SIGNALS ###=================//
    .pclk         (clk        ),    // <-
    .presetn      (rst_n      ),    // <-
    //===============### APB SLAVE SIGNALS ###===============//
    //                 --- INPUT SIGNALS ---                 //
    .paddr        (paddr      ),    // <-
    .pprot        (pprot      ),    // <-
    .psel         (psel       ),    // <-
    .penable      (penable    ),    // <-
    .pwrite       (pwrite     ),    // <-
    //.pwdata       (pwdata     ),    // <-
    .pstrb        (pstrb      ),    // <-
    //                --- OUTPUT SIGNALS ---                 //
    .pready       (pready     ),    // ->
    .prdata       (prdata     ),    // ->
    .pslverr      (pslverr    ),    // ->
    //==============### ADDITIONAL SIGNALS ###===============//
    .throw_pready ('0         ),    // <-
    .rdata        (csrm_rdata ),    // <-
    .we_data_out  (csrm_wedata)     // ->
    //=======================================================//
);
// ///////////////////////////////////////////////////////// //


//============================================================================*/
endmodule
