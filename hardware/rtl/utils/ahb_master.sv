//------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// -----------------------------------------------------------------------------//
// Purpose: AHB Master
// Date: 2026/06
//------------------------------------------------------------------------------//

/*==============================================================================//
region MODULE DEFINITION
//==============================================================================*/
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

    import ahb_pkg::ahb_fsm_e;
    import ahb_pkg::AHB_FSM_IDLE ;
    import ahb_pkg::AHB_FSM_SADDR;
    import ahb_pkg::AHB_FSM_SDATA;
    import ahb_pkg::AHB_FSM_BOTH ;
    import ahb_pkg::AHB_FSM_ERROR;

    import ahb_pkg::hsize_e;
    import ahb_pkg::HSIZE_BYTE ;
    import ahb_pkg::HSIZE_HWORD;
    import ahb_pkg::HSIZE_WORD ;
    import ahb_pkg::HSIZE_DWORD;


    import ahb_pkg::ahb_mports_t;
    import ahb_pkg::ahb_sports_t;
#(
    parameter   int unsigned DW           = 32,
    parameter   int unsigned AW           = 32,
    parameter   int unsigned TW           = 2
) (
    /*=======================### COMMON SIGNALS ###===========================*/
    input  logic                    clk,
    input  logic                    rst_n,

    /*========================### AHB SIGNALS ###=============================*/
    input  ahb_sports_t             ahb_i,
    output ahb_mports_t             ahb_o,
    /*=====================### CONTROL SIGNALS ###============================*/
    input  logic                    req_txn_i,      // launch txn
    input  logic                    rw_i,           // read/write mode

    input  logic [TW - 1: 0]        txn_amount_i,   // how much need to get/give
    /*=========================### IN SIGNALS ###=============================*/
    input  logic [AW - 1: 0]        addr_i,
    input  logic [DW - 1: 0]        data_i,

    /*========================### OUT SIGNALS ###=============================*/
    output logic [DW - 1: 0]        data_o,
    output logic                    data_valid_o

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
always_comb begin
    ahb_o.haddr      = haddr;
    ahb_o.hwdata     = hwdata;
    ahb_o.hwrite     = hwrite;
    ahb_o.hsize      = hsize;
    ahb_o.hburst     = hburst;
    ahb_o.hprot      = hprot;
    ahb_o.htrans     = htrans;
    ahb_o.hmastlock  = hmastlock;
end
// in
assign hready           = ahb_i.hready;
assign hresp            = ahb_i.hresp;
assign hrdata           = ahb_i.hrdata;

/*============================================================================//
region LOGIC
//============================================================================*/

logic  req_active;
assign req_active = req_txn_i;

//============================================================================*/
// AHB FSM
//============================================================================*/

ahb_fsm_e state, next_state;

always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n) begin
        state <= AHB_FSM_IDLE;
    end
    else begin
        state <= next_state;
    end
end

always_comb begin
    case (state)
        AHB_FSM_IDLE:
            if (req_active)
                next_state = AHB_FSM_SADDR;
            else
                next_state = AHB_FSM_IDLE;
        AHB_FSM_SADDR:
            if (req_active)
                next_state = AHB_FSM_BOTH;
            else
                next_state = AHB_FSM_SDATA;
        AHB_FSM_SDATA:
            if (hready)
                if (req_active)
                    next_state = AHB_FSM_SADDR;
                else if (~hresp)
                    next_state = AHB_FSM_IDLE;
                else
                    next_state = AHB_FSM_ERROR;
            else
                next_state = AHB_FSM_SDATA;
        AHB_FSM_BOTH:
            if (hready)
                if (req_active)
                    next_state = AHB_FSM_BOTH;
                else if (~hresp)
                    next_state = AHB_FSM_SDATA;
                else
                    next_state = AHB_FSM_ERROR;
            else
                next_state = AHB_FSM_BOTH;
        AHB_FSM_ERROR:
            if (req_active)
                next_state = AHB_FSM_SADDR;
            else
                next_state = AHB_FSM_ERROR;
        default:
            next_state = AHB_FSM_IDLE;
    endcase
end

// old version

// logic  req_ahb_txn;
logic  res_ahb_txn;
assign res_ahb_txn =    ((state == AHB_FSM_SDATA) || (state == AHB_FSM_BOTH)) && hready;


// logic  mng_is_wait, mng_is_active,
logic  mng_is_idle; // mng_is_err,
// assign mng_is_wait      = next_state == AHB_STALL;
// assign mng_is_active    = next_state == AHB_ACTIVE;
// assign mng_is_err       = fst_state_next == AHB_ERROR;
assign mng_is_idle      = next_state == AHB_FSM_IDLE;


//============================================================================*/
// AHB LOGIC
//============================================================================*/

// hprot status
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        hprot <= '0;
    else if (~mng_is_idle) begin
        hprot.cache         <= HTRANS_CACH_OFF;
        hprot.buffer        <= HTRANS_BUFE_OFF;
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
    assign bfsm2 = txn_amount_i >= (TW)'(2);

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
    assign bfsm2 = txn_amount_i >= (TW)'(2);
    assign bfsm4 = txn_amount_i >= (TW)'(4);

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
    assign bfsm2 = txn_amount_i >= (TW)'(2);
    assign bfsm4 = txn_amount_i >= (TW)'(4);
    assign bfsm8 = txn_amount_i >= (TW)'(8);

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
    assign bfsm2    = txn_amount_i >= (TW)'(2);
    assign bfsm4    = txn_amount_i >= (TW)'(4);
    assign bfsm8    = txn_amount_i >= (TW)'(8);
    assign bfsm16   = txn_amount_i >= (TW)'(16);

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
    else if (req_active && htrans == HTRANS_IDLE)
        htrans <= HTRANS_NONSEQ;
    else if (req_active && (htrans == HTRANS_NONSEQ || htrans == HTRANS_SEQ))
        htrans <= HTRANS_SEQ;
    else
        htrans <= HTRANS_IDLE; // BUSY write later. mng can hold
end

// hwrite
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        hwrite <= '0;
    else
        hwrite <= req_txn_i? rw_i: '0;
end

// hwdata
logic [DW - 1: 0] hwdata_i;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        hwdata_i <= '0;
    else
        hwdata_i <= req_txn_i? data_i: '0;
end

logic req_txn_ff;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        req_txn_ff <= '0;
    else
        req_txn_ff <= req_txn_i;
end

always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        hwdata <= '0;
    else if (req_txn_ff)
        hwdata <= hwdata_i;
    else if (hready)
        hwdata <= '0;
    else
        hwdata <= hwdata;
end

// hmastlock
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        hmastlock <= '0;
    else
        hmastlock <= ~mng_is_idle;
end

// haddr
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        haddr <= '0;
    else
        haddr <= req_txn_i? addr_i: '0;
end

/*============================================================================//
region OUT
//============================================================================*/

assign data_o = res_ahb_txn? hrdata: '0;
assign data_valid_o = res_ahb_txn;

//============================================================================*/
endmodule
