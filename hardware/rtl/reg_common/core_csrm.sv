//------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// -----------------------------------------------------------------------------//
// Purpose: Core Control Status Register Map (Core CSRM)
// Date: 2026/06
//------------------------------------------------------------------------------//

module core_csrm

/*==============================================================================//
region MODULE DEFINITION
//==============================================================================*/
#(
    // ============================= APB PARAMETERS =========================== //
    parameter  int unsigned AW                      = 32,  // ADDRESS WIDTH
    parameter  int unsigned DW                      = 32,  // DATA WIDTH
    parameter  int unsigned THREAD_CNT              = 4,
    parameter  bit          DEBUG_BUILD             = 0,

    localparam int unsigned VID_STRB_W              = DW / 8,
    localparam int unsigned RS_VID_END_OFS          = VID_F_OFS + VID_STRB_W * THREAD_CNT,
    localparam int unsigned VID_W                   = $clog2(THREAD_CNT)
) (
    /*==========================### COMMON SIGNALS ###==========================*/
    input  logic                            clk,
    input  logic                            rst_n,

    input  logic [AW - 1: 0]                addr,
    input  logic [DW - 1: 0]                wdata,
    input  logic [DW - 1: 0]                wedata,

    output logic [DW - 1: 0]                rdata,
    /*========================### ADDITIONAL SIGNALS ###========================*/
    output logic                            en_o,
    output logic [DW - 1: 0]                vid_o
    //==========================================================================//
);

/*==============================================================================//
region LOGIC VARIABLE DEFINITION
//==============================================================================*/
logic [DW - 1: 0] core_ctrl_rdata;
logic [DW - 1: 0] vid_rdata         [THREAD_CNT];

logic [DW - 1: 0] core_ctrl_wedata;
logic [DW - 1: 0] vid_wedata        [THREAD_CNT];
/*==============================================================================//
region ASSIGNES
//==============================================================================*/

logic  is_core_ctrl_addr;
assign is_core_ctrl_addr = addr == (AW)'(R_CORE_CTRL_OFS);

/*==============================================================================//
region WRITE ENABLE LOGIC
//==============================================================================*/

assign core_ctrl_wedata = is_core_ctrl_addr? wedata: '0;

/*==============================================================================//
region VID DATA LOGIC
//==============================================================================*/
logic  addr_in_vid_range;
assign addr_in_vid_range = addr >= (AW)'(RS_VID_OFS) && addr <= (AW)'(RS_VID_END_OFS);


logic [DW - 1: 0] cur_vid;
if (THREAD_CNT > 1) begin: g_logic_many_threads
    logic [VID_W - 1: 0] local_vid_addr;
    always_comb begin
        if (addr_in_vid_range)
            local_vid_addr = (VID_W)'((addr - (AW)'(RS_VID_OFS)) >> VID_STRB_W);
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

logic [DW - 1: 0] core_ctrl_wdata;
always_comb begin
    if (is_core_ctrl_addr)
        core_ctrl_wdata = wdata;
    else
        core_ctrl_wdata = '0;
end

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

assign en_o = core_ctrl_rdata[0];

/*==============================================================================//
region INSTANCES
//==============================================================================*/

// [CTRL_STAT_REG]
prim_register #(
    // ----------------- GLOBAL PARAMETERS ----------------- //
    .DW(DW),
    // ----------------- FIELDS PARAMETERS ----------------- //
    .F_NUM  (CORE_CTRL_F_NUM),
    .F_W    (CORE_CTRL_F_W),
    .F_OFS  (CORE_CTRL_F_OFS)
    // ----------------------------------------------------- //
) bsld_ctrl_reg (
    /*================### COMMON SIGNALS ###=================*/
    .clk    (clk),                       // <-
    .rst_n  (rst_n),                     // <-
    /*================### PACKET SIGNALS ###=================*/
    .wdata  (core_ctrl_wdata),           // <-
    .wedata (core_ctrl_wedata),          // <-
    .rdata  (core_ctrl_rdata)            // ->
    //=======================================================//
);


// [CFG DATA]
for (genvar i = 0; i < THREAD_CNT; i++) begin: gen_vid_regs
    prim_register #(
        // ----------------- GLOBAL PARAMETERS ----------------- //
        .DW(DW),
        // ----------------- FIELDS PARAMETERS ----------------- //
        .F_NUM  (VID_F_NUM),
        .F_W    (VID_F_W),
        .F_OFS  (VID_F_OFS)
        // ----------------------------------------------------- //
    ) cfg_data_reg (
        /*================### COMMON SIGNALS ###=================*/
        .clk    (clk),                      // <-
        .rst_n  (rst_n),                    // <-
        /*================### PACKET SIGNALS ###=================*/
        .wdata  (wdata),                    // <-
        .wedata (vid_wedata[i]),            // <-
        .rdata  (vid_rdata[i])              // ->
        //=======================================================//
    );

    assign vid_o[i] = vid_rdata[i];
end

//===================================================================================//
endmodule
