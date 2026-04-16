//-------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// ------------------------------------------------------------------------------//
// Purpose: Dummy FPU with ports from cvfpu
//-------------------------------------------------------------------------------//

`ifndef TAG_TYPE
  `define TAG_TYPE logic
`endif


module fpu_dummy #(
    parameter fpnew_pkg::fpu_features_t       Features       = fpnew_pkg::RV64D_Xsflt,
    parameter fpnew_pkg::fpu_implementation_t Implementation = fpnew_pkg::DEFAULT_NOREGS,
    parameter fpnew_pkg::divsqrt_unit_t       DivSqrtSel     = fpnew_pkg::THMULTI,
    parameter type                            TagType        = `TAG_TYPE,
    parameter int unsigned                    TrueSIMDClass  = 0,
    parameter int unsigned                    EnableSIMDMask = 0,


    localparam int unsigned NumLanes     = fpnew_pkg::max_num_lanes(Features.Width, Features.FpFmtMask, Features.EnableVectors),
    localparam type         MaskType     = logic [NumLanes-1:0],
    localparam int unsigned WIDTH        = Features.Width,
    localparam int unsigned NUM_OPERANDS = 3
) (
    input logic                               clk_i,
    input logic                               rst_ni,
    // Input signals
    input logic [NUM_OPERANDS-1:0][WIDTH-1:0] operands_i,
    input fpnew_pkg::roundmode_e              rnd_mode_i,
    input fpnew_pkg::operation_e              op_i,
    input logic                               op_mod_i,
    input fpnew_pkg::fp_format_e              src_fmt_i,
    input fpnew_pkg::fp_format_e              dst_fmt_i,
    input fpnew_pkg::int_format_e             int_fmt_i,
    input logic                               vectorial_op_i,
    input TagType                             tag_i,
    input MaskType                            simd_mask_i,
    // Input Handshake
    input  logic                              in_valid_i,
    output logic                              in_ready_o,
    input  logic                              flush_i,
    // Output signals
    output logic [WIDTH-1:0]                  result_o,
    output fpnew_pkg::status_t                status_o,
    output TagType                            tag_o,
    // Output handshake
    output logic                              out_valid_o,
    input  logic                              out_ready_i,
    // Indication of valid data in flight
    output logic                              busy_o,
    output logic                              early_valid_o
);
    logic                               unused1;
    logic                               unused2;
    logic [NUM_OPERANDS-1:0][WIDTH-1:0] unused3;
    fpnew_pkg::roundmode_e              unused4;
    fpnew_pkg::operation_e              unused5;
    logic                               unused6;
    fpnew_pkg::fp_format_e              unused7;
    fpnew_pkg::fp_format_e              unused8;
    fpnew_pkg::int_format_e             unused9;
    TagType                             unused10;
    MaskType                            unused11;
    logic                               unused12;
    logic                               unused13;
    logic                               unused14;

    assign unused1  = clk_i;
    assign unused2  = rst_ni;
    assign unused3  = operands_i;
    assign unused4  = rnd_mode_i;
    assign unused5  = op_i;
    assign unused6  = op_mod_i;
    assign unused7  = src_fmt_i;
    assign unused8  = dst_fmt_i;
    assign unused9  = int_fmt_i;
    assign unused10 = vectorial_op_i;
    assign unused11 = simd_mask_i;
    assign unused12 = in_valid_i;
    assign unused13 = flush_i;
    assign unused14 = out_ready_i;

    assign busy_o           = '0;
    assign early_valid_o    = '0;
    assign out_valid_o      = '0;
    assign status_o         = '0;
    assign tag_o            = '0;
    assign result_o         = '0;
    assign in_ready_o       = '0;
endmodule
