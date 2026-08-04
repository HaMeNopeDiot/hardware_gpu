//------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// -----------------------------------------------------------------------------//
// Purpose: Core Control Status Register Map (Core CSRM)
// Date: 2026/06
//------------------------------------------------------------------------------//

module core_csrm
    import core_regblk_pkg::*;
    import core_reg_structure_pkg::*;
/*==============================================================================//
region MODULE DEFINITION
//==============================================================================*/
#(
    // ============================= APB PARAMETERS =========================== //
    parameter  int unsigned AW                      = 32,  // ADDRESS WIDTH
    parameter  int unsigned DW                      = 32,  // DATA WIDTH
    parameter  int unsigned THREAD_CNT              = 4,

    localparam int unsigned STRB_W                  = DW / 8,
    localparam int unsigned RS_VID_END_OFS          = RS_VID_OFS + STRB_W * THREAD_CNT,
    localparam int unsigned VID_W                   = $clog2(THREAD_CNT),
    localparam int unsigned SAW_W                   = $clog2(STRB_W)
) (
    /*==========================### COMMON SIGNALS ###==========================*/
    input  logic                            clk,
    input  logic                            rst_n,

    input  logic [AW - 1: 0]                addr,
    input  logic [DW - 1: 0]                wdata,
    input  logic [DW - 1: 0]                wedata,

    output logic [DW - 1: 0]                rdata,
    /*========================### ADDITIONAL SIGNALS ###========================*/
    input  logic                            ret_i,
    output logic                            en_o,
    output logic [DW - 1: 0]                vid_o [THREAD_CNT],

    output logic [DW - 1: 0]                cur_pc_o,
    input  logic                            pc_readed_i,
    output logic                            thread_en_o [THREAD_CNT],

    input  logic [DW - 1: 0]                next_pc_i,
    input  logic [DW - 1: 0]                new_pc_i,
    input  logic                            new_pc_valid_i
    //==========================================================================//
);
/*==============================================================================//
region TEST ZONE
//==============================================================================*/

// typedef core_csrm_pkg::core_csrm_pkg#(
//     .DW(DW),
//     .THREAD_CNT(THREAD_CNT)) spec_csrm_t;

// spec_csrm_t::csrm_sig_out_t csrm_o;
// spec_csrm_t::csrm_req_sig_t csrm_i;

// assign csrm_i.ret_i         = ret_i;
// assign csrm_i.pc_readed_i   = pc_readed_i;

// assign csrm_o.en_o          = en_o;
// assign csrm_o.vid_o         = '0;
// assign csrm_o.cur_pc_o      = cur_pc_o;
// assign csrm_o.thread_en_o   = '0;

/*==============================================================================//
region LOGIC VARIABLE DEFINITION
//==============================================================================*/

// CORE CTRL
logic [DW - 1: 0] core_ctrl_rdata;
logic [DW - 1: 0] core_ctrl_wedata;
logic [DW - 1: 0] core_ctrl_wdata;

// PC
logic [DW - 1: 0] pc_rdata;
logic [DW - 1: 0] pc_wedata;
logic [DW - 1: 0] pc_wdata;

// TU EN
logic [DW - 1: 0] tu_en_rdata;
logic [DW - 1: 0] tu_en_wedata;
logic [DW - 1: 0] tu_en_wdata;

// VID
logic [DW - 1: 0] vid_rdata [THREAD_CNT];
logic [DW - 1: 0] vid_wedata [THREAD_CNT];
logic [DW - 1: 0] vid_wdata;

/*==============================================================================//
region ASSIGNES
//==============================================================================*/

logic  is_core_ctrl_addr;
assign is_core_ctrl_addr    = addr == (AW)'(R_CORE_CTRL_OFS);

logic  is_pc_addr;
assign is_pc_addr           = addr == (AW)'(R_PC_OFS);

logic  is_tu_addr;
assign is_tu_addr           = addr == (AW)'(R_TU_EN_OFS);

logic  addr_in_vid_range;
assign addr_in_vid_range    = addr >= (AW)'(RS_VID_OFS) && addr <= (AW)'(RS_VID_END_OFS);


/*==============================================================================//
region WRITE ENABLE LOGIC
//==============================================================================*/

assign core_ctrl_wedata = ret_i                 ? (DW)'(1)  : (is_core_ctrl_addr? wedata: '0);
assign tu_en_wedata     = is_tu_addr            ? wedata: '0;

//assign pc_wedata        = pc_readed_i && en_o   ? (DW)'('1) : (is_pc_addr       ? wedata: '0);
always_comb begin
    if (new_pc_valid_i)
        pc_wedata = '1;
    else if (pc_readed_i && en_o)
        pc_wedata = '1;
    else if (is_pc_addr)
        pc_wedata = wedata;
    else
        pc_wedata = '0;
end
/*==============================================================================//
region VID DATA LOGIC
//==============================================================================*/

logic [DW - 1: 0] cur_vid;
if (THREAD_CNT > 1) begin: g_logic_many_threads
    logic [VID_W - 1: 0] local_vid_addr;
    always_comb begin
        if (addr_in_vid_range)
            local_vid_addr = (VID_W)'((addr - (AW)'(RS_VID_OFS)) >> SAW_W);
        else
            local_vid_addr = '0;
    end

    for (genvar i = 0; i < THREAD_CNT; i++) begin: gen_vid_wedata
        assign vid_wedata[i] = (addr_in_vid_range)
                                 && (local_vid_addr == (VID_W)'(i))?
                                    wedata: '0;
    end

    assign cur_vid      = vid_rdata[local_vid_addr];
end
else begin: g_cfgdata_smaller_dw
    /* Here logic when we need only one register for whole cfgdata */
    assign vid_wedata[0]       = (addr_in_vid_range)? wedata: '0;
    assign cur_vid          = vid_rdata[0];
end

/*==============================================================================//
region WDATA LOGIC
//==============================================================================*/

logic [DW - 1: 0] wdata_masked;
assign            wdata_masked = wdata & wedata;

always_comb begin
    if (ret_i)
        core_ctrl_wdata[F_CORE_EN_OFS] = '0;
    if (is_core_ctrl_addr)
        core_ctrl_wdata = wdata_masked;
    else
        core_ctrl_wdata = '0;
end

always_comb begin
    if (new_pc_valid_i)
        pc_wdata = new_pc_i;
    else if (pc_readed_i && en_o)
        pc_wdata = next_pc_i;
    else
        pc_wdata = wdata_masked;
end

assign tu_en_wdata  = wdata_masked;
assign vid_wdata    = wdata;

/*==============================================================================//
region RDATA LOGIC
//==============================================================================*/

// nothing to see here

/*==============================================================================//
region rdata MUX
//==============================================================================*/

// set rdata from register by address
always_comb begin
    case (addr)
        (AW)'(R_CORE_CTRL_OFS):
            rdata = core_ctrl_rdata;
        (AW)'(R_PC_OFS):
            rdata = pc_rdata;
        (AW)'(R_TU_EN_OFS):
            rdata = tu_en_rdata;
        default:
            if (addr_in_vid_range)
                rdata = cur_vid;
            else
                rdata = '0;
    endcase
end
// connect out wires with rdata's

/*==============================================================================//
region INNER OUT LOGIC
//==============================================================================*/

assign cur_pc_o = pc_rdata;
assign en_o     = core_ctrl_rdata[0];

for (genvar i = 0; i < THREAD_CNT; i++) begin: gen_thread_en_signals
    assign thread_en_o[i] = tu_en_rdata[i];
    assign vid_o[i]       = vid_rdata[i];
end
/*============================================================================//
region INSTANCES
//============================================================================*/

// [CORE CTRL]
prim_register #(
    // ----------------- GLOBAL PARAMETERS ----------------- //
    .DW     (DW),
    // ----------------- FIELDS PARAMETERS ----------------- //
    .F_NUM  (CORE_CTRL_F_NUM),
    .F_W    (CORE_CTRL_F_W  ),
    .F_OFS  (CORE_CTRL_F_OFS)
    // ----------------------------------------------------- //
) core_ctrl_reg (
    /*================### COMMON SIGNALS ###=================*/
    .clk    (clk  ),                    // <-
    .rst_n  (rst_n),                    // <-
    /*================### PACKET SIGNALS ###=================*/
    .wdata  (core_ctrl_wdata ),         // <-
    .wedata (core_ctrl_wedata),         // <-
    .rdata  (core_ctrl_rdata )          // ->
    //=======================================================//

);

// [PC]
prim_register #(
    // ----------------- GLOBAL PARAMETERS ----------------- //
    .DW     (DW),
    // ----------------- FIELDS PARAMETERS ----------------- //
    .F_NUM  (PC_F_NUM),
    .F_W    (PC_F_W  ),
    .F_OFS  (PC_F_OFS)
    // ----------------------------------------------------- //
) pc_reg (
    /*================### COMMON SIGNALS ###=================*/
    .clk    (clk  ),                    // <-
    .rst_n  (rst_n),                    // <-
    /*================### PACKET SIGNALS ###=================*/
    .wdata  (pc_wdata ),                // <-
    .wedata (pc_wedata),                // <-
    .rdata  (pc_rdata )                 // ->
    //=======================================================//

);

// [TU EN]
prim_register #(
    // ----------------- GLOBAL PARAMETERS ----------------- //
    .DW     (DW),
    // ----------------- FIELDS PARAMETERS ----------------- //
    .F_NUM  (TU_EN_F_NUM),
    .F_W    (TU_EN_F_W  ),
    .F_OFS  (TU_EN_F_OFS)
    // ----------------------------------------------------- //
) tu_en_reg (
    /*================### COMMON SIGNALS ###=================*/
    .clk    (clk  ),                    // <-
    .rst_n  (rst_n),                    // <-
    /*================### PACKET SIGNALS ###=================*/
    .wdata  (tu_en_wdata ),             // <-
    .wedata (tu_en_wedata),             // <-
    .rdata  (tu_en_rdata )              // ->
    //=======================================================//

);

for (genvar i = 0; i < THREAD_CNT; i++) begin: gen_vid_regs
    // [VID]
    prim_register #(
        // ----------------- GLOBAL PARAMETERS ----------------- //
        .DW     (DW),
        // ----------------- FIELDS PARAMETERS ----------------- //
        .F_NUM  (VID_F_NUM),
        .F_W    (VID_F_W  ),
        .F_OFS  (VID_F_OFS)
        // ----------------------------------------------------- //
    ) vid_reg (
        /*================### COMMON SIGNALS ###=================*/
        .clk    (clk  ),                    // <-
        .rst_n  (rst_n),                    // <-
        /*================### PACKET SIGNALS ###=================*/
        .wdata  (vid_wdata    ),            // <-
        .wedata (vid_wedata[i]),            // <-
        .rdata  (vid_rdata[i] )             // ->
        //=======================================================//

    );
end

//============================================================================//

endmodule
