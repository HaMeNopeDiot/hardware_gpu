//------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// -----------------------------------------------------------------------------//
// Purpose: APB Slave
// Date: 2026/06
//------------------------------------------------------------------------------//

/*==============================================================================//
region MODULE DEFINITION
//==============================================================================*/
module apb_slave
    import efpga_bl_apb_pkg::*;
#(
    /*==========================================================================//
    region PARAMS
    //==========================================================================*/

    // ----------------------------- APB4 PARAMETERS -------------------------- //
    parameter  int unsigned AW                      = 32,  // ADDRESS WIDTH
    parameter  int unsigned DW                      = 32,  // DATA WIDTH
    // Number of bytes in a single register of DW size.
    localparam int unsigned STRBSIZE                = DW / 8,
    // Size of register with local address (for cfgdata)
    localparam int unsigned AW_OFS                  = $clog2(STRBSIZE),
    // --------------------------- ADDRESSING PARAMETERS ---------------------- //
    parameter int unsigned MIN_ADDR                = 'h0,
    parameter int unsigned MAX_ADDR                = 'h1
    // ------------------------------------------------------------------------ //
) (
    /*==========================================================================//
    region PORTS
    //==========================================================================*/

    /*===============================### COMMON SIGNALS ###=====================*/
    input logic                         pclk,
    input logic                         presetn,
    /*=============================### APB SLAVE SIGNALS ###====================*/
    //                            --- INPUT SIGNALS ---                         //
    input logic [AW - 1 : 0]            paddr,
    input logic [2 : 0]                 pprot,

    input logic                         psel,
    input logic                         penable,
    input logic                         pwrite,
    input logic [DW - 1 : 0]            pwdata,
    input logic [STRBSIZE - 1 : 0]      pstrb,

    //                           --- OUTPUT SIGNALS ---                         //
    output logic                        pready,
    output logic [DW - 1: 0]            prdata,
    output logic                        pslverr,
    //==========================### ADDITIONAL SIGNALS ###======================//
    input  logic                        throw_pready,
    input  logic [DW - 1: 0]            rdata,
    output logic [DW - 1: 0]            we_data_out
    //==========================================================================//
);
/*==============================================================================//
region FUNCTIONS
//==============================================================================*/

function automatic [DW - 1: 0] get_we_mask_from_strb (
    input logic [STRBSIZE - 1: 0]   strb
);
    logic [DW - 1: 0] mask;
    for (integer i = 0; i < STRBSIZE; i++)
        mask[8*i+:8] = strb[i]? '1: 0;
    return mask;
endfunction

/*==============================================================================//
region FINAL STATE MACHINE
//==============================================================================*/

apb_slv_fsm_e next_state, state;

always_ff @(posedge pclk or negedge presetn) begin
    if (~presetn)
        state <= APB_SLV_IDLE;
    else
        state <= next_state;
end

always_comb begin
    case (state)
        APB_SLV_IDLE:
            if (psel && ~penable)
                next_state = APB_SLV_SETUP;
            else
                next_state = APB_SLV_IDLE;
        APB_SLV_SETUP:
            if (pready)
                next_state = APB_SLV_ACCESS;
            else
                next_state = APB_SLV_STALL;
        APB_SLV_STALL:
            if (pready)
                next_state = APB_SLV_ACCESS;
            else
                next_state = APB_SLV_STALL;
        APB_SLV_ACCESS:
            if (psel && ~penable)
                next_state = APB_SLV_SETUP;
            else
                next_state = APB_SLV_IDLE;
        default:
            next_state = APB_SLV_IDLE;
    endcase
end

/*==============================================================================//
region SUPPORT VARS
//==============================================================================*/

logic  wrong_pprot;
assign wrong_pprot = (pprot[1]) || (pprot[2]);

// is unaligned addr
logic is_unaligned_addr;
assign is_unaligned_addr = (paddr[AW_OFS - 1: 0] != '0);

// enables signals
// ---------------------------------------------------------------------------- //

logic  txn_proc;
assign txn_proc = (next_state == APB_SLV_SETUP);

assign we = (psel) && (pwrite) && (~wrong_pprot);  // write enable
assign re = (psel) && (~pwrite) && (~wrong_pprot); // read enable
assign wse = we && ~is_unaligned_addr && txn_proc; // write save value enable

/*==============================================================================//
region APB_LOGIC
//==============================================================================*/

// pready
assign pready = ~(throw_pready && we);

// "Read"-block
always_ff @(posedge pclk or negedge presetn) begin
    if (~presetn)
        prdata <= '0;
    else
        if(re && (~is_unaligned_addr))
            if (~penable)
                prdata <= rdata;
            else
                prdata <= '0;
end

// "Write"-block
always_comb begin
    if (wse)
        we_data_out = get_we_mask_from_strb(pstrb);
    else
        we_data_out = '0;
end

// slverr
// ---------------------------------------------------------------------------- //
logic addr_not_in_range;
if (MIN_ADDR == '0) begin: gen_addr_in_range_cond_right
    assign addr_not_in_range = paddr > (AW)'(MAX_ADDR);
end
else begin: gen_addr_in_range_cond_both
    assign addr_not_in_range = (paddr < (AW)'(MIN_ADDR)) | (paddr > (AW)'(MAX_ADDR));
end

logic  r_invalid, w_invalid;
assign r_invalid = re & (is_unaligned_addr | addr_not_in_range);
assign w_invalid = we & (is_unaligned_addr | addr_not_in_range);

logic  invalid_txn;
assign invalid_txn = r_invalid | w_invalid;


logic  last_cycle_txn;
assign last_cycle_txn = (psel) && (penable) && (pready);
assign pslverr = (last_cycle_txn) && ((wrong_pprot) || (invalid_txn));

endmodule
