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
module ahb_master
    // imports here
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
#(
    parameter   int unsigned DW           = 32,
    parameter   int unsigned AW           = 32,
    parameter   int unsigned TW           = 2

) (
    /*=======================### COMMON SIGNALS ###===========================*/
    input  logic                    clk,
    input  logic                    rst_n,

    /*========================### AHB SIGNALS ###=============================*/
    ahb4_bus_if.master              ahb_bus,
    /*=====================### CONTROL SIGNALS ###============================*/
    input  logic                    req_txn_i,
    input  logic                    rw_i,

    input  logic [INST_Q_W - 1: 0]  txn_amount_i,
    /*=========================### IN SIGNALS ###=============================*/

    input  logic [AW - 1: 0]        addr_i,
    input  logic [DW - 1: 0]        data_i,
    input  logic                    txn_valid_i,
    /*========================### OUT SIGNALS ###=============================*/

    output logic [DW - 1: 0]        data_o,
    output logic                    data_valid_o,
    output logic                    ahb_ready_o

    //========================================================================//
);

/*============================================================================//
region ASSIGNES
//============================================================================*/

hsize_e     hsize;
hburst_e    hburst;
hprot_t     hprot;
htrans_e    htrans;
logic       hwrite, hmastlock;
logic hresp,  hready;

logic [DW - 1: 0] hrdata, hwdata;
logic [AW - 1: 0] haddr;
// out
assign ahb_bus.haddr        = haddr;
assign ahb_bus.hwdata       = hwdata;
assign ahb_bus.hwrite       = hwrite;
assign ahb_bus.hsize        = hsize;    // t
assign ahb_bus.hburst       = hburst;   // t
assign ahb_bus.hprot        = hprot;    // t
assign ahb_bus.htrans       = htrans;   // t
assign ahb_bus.hmastlock    = hmastlock;
// in
assign hready               = ahb_bus.hready;
assign hresp                = ahb_bus.hresp;
assign hrdata               = ahb_bus.hrdata;

/*============================================================================//
region LOGIC
//============================================================================*/

logic  req_active;
assign req_active = req_txn_i && txn_valid_i;

//============================================================================*/
// AHB FSM
//============================================================================*/

ahb_txn_e fst_state, fst_state_next;

always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n) begin
        fst_state <= AHB_IDLE;
    end
    else begin
        fst_state <= fst_state_next;
    end
end

always_comb begin
    case (fst_state)
        AHB_IDLE: begin
            if (req_active)
                fst_state_next = AHB_ACTIVE;
            else
                fst_state_next = AHB_IDLE;
        end
        AHB_ACTIVE, AHB_STALL: begin
            if (hresp)
                fst_state_next = AHB_ERROR;
            else
                if (req_active)
                    if (hready)
                        fst_state_next = AHB_STALL;
                    else
                        fst_state_next = AHB_ACTIVE;
                else
                    fst_state_next = AHB_IDLE;
        end
        AHB_ERROR: begin
            if (hresp)
                fst_state_next = AHB_ERROR;
            else
                fst_state_next = AHB_IDLE; // maybe need fix this
        end
        default:
            fst_state_next = AHB_IDLE;
    endcase
end

logic  mng_is_wait, mng_is_active, mng_is_idle; // mng_is_err,
assign mng_is_wait      = fst_state_next == AHB_STALL;
assign mng_is_active    = fst_state_next == AHB_ACTIVE;
// assign mng_is_err       = fst_state_next == AHB_ERROR;
assign mng_is_idle      = fst_state_next == AHB_IDLE;

logic mng_is_stable_active = mng_is_active || mng_is_wait;

//============================================================================*/
// AHB LOGIC
//============================================================================*/

// hprot status
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        hprot <= '0;
    else if (~mng_is_idle) begin
        hprot.cache         <= HTRANS_CACH_OFF;
        hprot.buffer        <= BUFFERABLE;
        hprot.access_type   <= HTRANS_ACCS_PRIV;
        hprot.txn_type      <= HTRANS_DORO_OPCODE;
    end
end

// hsize

if (DW == 8) begin: gen_byte_hsize
    assign hsize = HSIZE_BYTE;
end
else if (DW == 16) begin: gen_hword_hsize
    assign hsize = HSIZE_HWORD;
end
else if (DW == 32) begin: gen_word_hsize
    assign hsize = HSIZE_WORD;
end
else if (DW >= 64) begin: gen_dword_hsize
    assign hsize = HSIZE_DWORD;
end

// hburst
if (TW == 1) begin: gen_hburst_logic_eq_1
    always_ff @(posedge clk or negedge rst_n) begin
        if (~rst_n)
            hburst <= HBURST_SINGLE;
        else
            hburst <= HBURST_SINGLE;
    end
end
else if (TW == 2) begin: gen_hburst_logic_less_4
    logic  bfsm2; // bus (have) 2 free space or more
    assign bfsm2 = txn_amount_i[1] == 1'b1;

    always_ff @(posedge clk or negedge rst_n) begin
        if (~rst_n)
            hburst <= HBURST_SINGLE;
        else if (bfsm2)
            hburst <= HBURST_INCR;
        else
            hburst <= HBURST_SINGLE;
    end
end
else if (TW < 3) begin: gen_hburst_logic_less_8
    // bus (have) <x> free space or more. (Where x typed in bfsmx var name)
    logic  bfsm2, bfsm4;
    assign bfsm2 = txn_amount_i[1] == 1'b1;
    assign bfsm4 = txn_amount_i[2] == 1'b1;

    always_ff @(posedge clk or negedge rst_n) begin
        if (~rst_n)
            hburst <= HBURST_SINGLE;
        else if (bfsm4)
            hburst <= HBURST_INCR4;
        else if (bfsm2)
            hburst <= HBURST_INCR;
        else
            hburst <= HBURST_SINGLE;
    end
end
else if (TW < 4) begin: gen_hburst_logic_less_16
    // bus (have) <x> free space or more. (Where x typed in bfsmx var name)
    logic  bfsm2, bfsm4, bfsm8;
    assign bfsm2 = txn_amount_i[1] == 1'b1;
    assign bfsm4 = txn_amount_i[2] == 1'b1;
    assign bfsm8 = txn_amount_i[3] == 1'b1;

    always_ff @(posedge clk or negedge rst_n) begin
        if (~rst_n)
            hburst <= HBURST_SINGLE;
        else if (bfsm8)
            hburst <= HBURST_INCR8;
        else if (bfsm4)
            hburst <= HBURST_INCR4;
        else if (bfsm2)
            hburst <= HBURST_INCR;
        else
            hburst <= HBURST_SINGLE;
    end
end
else begin: gen_hburst_logic_more_16
    // bus (have) <x> free space or more. (Where x typed in bfsmx var name)
    logic  bfsm2, bfsm4, bfsm8, bfsm16;
    assign bfsm2    = txn_amount_i[1] == 1'b1;
    assign bfsm4    = txn_amount_i[2] == 1'b1;
    assign bfsm8    = txn_amount_i[3] == 1'b1;
    assign bfsm16   = txn_amount_i[4] == 1'b1;

    always_ff @(posedge clk or negedge rst_n) begin
        if (~rst_n)
            hburst <= HBURST_SINGLE;
        else if (bfsm16)
            hburst <= HBURST_INCR16;
        else if (bfsm8)
            hburst <= HBURST_INCR8;
        else if (bfsm4)
            hburst <= HBURST_INCR4;
        else if (bfsm2)
            hburst <= HBURST_INCR;
        else
            hburst <= HBURST_SINGLE;
    end
end

// htrans
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        htrans <= HTRANS_IDLE;
    else if (mng_is_stable_active && htrans == HTRANS_IDLE)
        htrans <= HTRANS_NONSEQ;
    else if (mng_is_stable_active && htrans == HTRANS_NONSEQ)
        htrans <= HTRANS_SEQ;
    else
        htrans <= HTRANS_IDLE; // BUSY write later. mng can hold
end

// hwrite
assign hwrite = req_active? rw_i: '0;

// hwdata
assign hwdata = req_active? data_i: '0;

// hmastlock
assign hmastlock = ~mng_is_idle;

// haddr
assign haddr = req_active? addr_i: '0;

// get data
logic  data_get_ph;
assign data_get_ph = (~hwrite) && (hready) && (fst_state == AHB_STALL || fst_state == AHB_ACTIVE);


/*============================================================================//
region OUT
//============================================================================*/

assign data_o = data_get_ph? hrdata: '0;
assign data_valid_o = data_get_ph;

assign ahb_ready_o = mng_is_idle;

endmodule
