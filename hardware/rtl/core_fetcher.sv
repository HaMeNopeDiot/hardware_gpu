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


    import ahb_pkg::htrans_e;

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
    parameter   int unsigned INST_Q_SZ    = 8,
    localparam  int unsigned INST_Q_W     = $clog2(INST_Q_SZ)

) (
    /*=======================### COMMON SIGNALS ###===========================*/
    input  logic                clk,
    input  logic                rst_n,

    /*========================### AHB SIGNALS ###=============================*/
    ahb4_bus_if.master          ahb_bus,

    /*=====================### SIGNALS TO DECODER ###=========================*/
    output cmd_t                instr_i,
    output logic                instr_valid_o,
    /*======================### SIGNALS FROM TU ###===========================*/
    input  logic                dec_ready_i,    // decoder is read
    input  logic [DW - 1: 0]    pc_i,
    input  logic                en_i

    //========================================================================//
);

/*============================================================================//
region ASSIGNES
//============================================================================*/

hsize_e     hsize;
hburst_e    hburst;
hprot_t     hprot;
htrans_e    htrans;
logic hsel, hwrite, hmastlock;
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

//============================================================================*/
// QUEUE
//============================================================================*/

logic q_data_get;
logic q_data_give;

assign q_data_give = instr_valid_o && dec_ready_i;
// write q_data_get

logic [DW - 1       : 0]    inst_q [INST_Q_SZ];
logic [INST_Q_W - 1 : 0]    inst_ptr_q;
logic [INST_Q_W - 1 : 0]    next_inst_ptr_q;
logic [INST_Q_W     : 0]    inst_buf_len;


logic  inst_q_empty;
logic  inst_q_full;

assign inst_q_empty = inst_buf_len == '0;
assign inst_q_full  = inst_buf_len == INST_Q_SZ;

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
    else if (q_data_get && ~inst_q_empty)
        inst_buf_len <= inst_buf_len + (INST_Q_W + 1)'(1);
    else if (q_data_give && ~inst_q_full)
        inst_buf_len <= inst_buf_len - (INST_Q_W + 1)'(1);
end


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
            if (en_i)
                fst_state_next = AHB_ACTIVE;
            else
                fst_state_next = AHB_IDLE;
        end
        AHB_ACTIVE: AHB_STALL: begin
            if (hresp)
                fst_state_next = AHB_ERROR;
            else
                if (en_i)
                    if (hready)
                        fst_state_next = AHB_STALL;
                    else
                        fst_state_next = AHB_ACTIVE;
                else
                    fst_state = AHB_IDLE;
        end
        default:
            fst_state_next = AHB_IDLE;
    endcase
end

logic  mng_is_wait, mng_is_active, mng_is_err, mng_is_idle;
assign mng_is_wait      = fst_state_next == AHB_STALL;
assign mng_is_active    = fst_state_next == AHB_ACTIVE;
assign mng_is_err       = fst_state_next == AHB_ERROR;
assign mng_is_idle      = fst_state_next == AHB_IDLE;

//============================================================================*/
// AHB LOGIC
//============================================================================*/

// hprot status
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        hprot <= '0;
    else if (~mng_is_idle) begin
        hprot.cache         <= HTRANS_CACH_OFF;
        hprot.buffer        <= INST_Q_SZ == 1? HTRANS_BUFE_OFF: HTRANS_BUFE_ON;
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
if (INST_Q_SZ < 4) begin: gen_buffer_sz_less_4
    always_ff @(posedge clk or negedge rst_n) begin
        if (~rst_n)
            hburst <= HBURST_SINGLE;
        else if ((INST_Q_W + 1) - inst_buf_len > (INST_Q_W + 1)'(1))
            hburst <= HBURST_INCR;
        else
            hburst <= HBURST_SINGLE;
    end
end
else if (INST_Q_SZ < 8) begin: gen_buffer_sz_less_8
    // Write something here
end

// htrans
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        htrans <= HTRANS_IDLE;
    else
        htrans <= HTRANS_IDLE;
end

//============================================================================*/

endmodule
