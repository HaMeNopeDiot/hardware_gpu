//------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// -----------------------------------------------------------------------------//
// Purpose: Primary register
// Date: 2026/06
//------------------------------------------------------------------------------//

/*==========================### IMPORTANT NOTE ###==============================//
Before using this module, I strongly recommend reading this comment.

This register accepts 4 parameters as arguments:
- DW - data width. The size of the input and output ports. Roughly speaking, it can be called
the register size, although not all bits may be used in this register.
- F_NUM - the number of fields in this register. The value of F_NUM determines the size of
the next two parameters, which are arrays.

The sizes of the elements in these arrays strictly have the size F_PARAM_W. F_PARAM_W is
determined by the size of DW, since field offsets and sizes cannot exceed the boundaries
of the register size itself. Example: if DW is 32, then the F_PARAM_W size will be 6, because
only 6 bits can define the number 32. These two parameters are:

- F_W - an array of field sizes in bits.
- F_OFS - an array of field offsets in bits.

Due to the specifics of SystemVerilog 2005, these arrays must be passed using concatenation.
Example:

prim_register #(
    .DW(32),
    .F_NUM(5),
    .F_W({(F_PARAM_W)'(1), (F_PARAM_W)'(4), (F_PARAM_W)'(8), (F_PARAM_W)'(2), (F_PARAM_W)'(5)}),
    .F_OFS({(F_PARAM_W)'(1), (F_PARAM_W)'(2), (F_PARAM_W)'(8), (F_PARAM_W)'(16), (F_PARAM_W)'(25)})
) reg_u (
    .clk(clk),
...
    .rdata(rdata)
);

With such an assignment, we get a register with 4 fields. We will separate different fields
with a digit. In case of a skipped bit, we will indicate it with the letter R. Also for
convenience, we will separate each byte with an underscore. With such notations, we will get
a register of the following form:

R12222RR_33333333_44RRRRRR_R55555RR (freaky, huh?)

All fields must have defined sizes and offsets. If a field has a size of 0, this will lead to
unexpected errors, if such code compiles at all. Therefore, the minimum size is 1.

All register bits that are not occupied by a field are not created in the register, and when
reading the register, 0s will be output in the places of these bits. Writing to such bits will
also be ignored.

In case of identical offsets or collision cases (when one field's size overlaps the offset of
another field), the module will not work correctly. The behavior of such a module is undefined.

//==============================================================================*/


module prim_register
#(
    /*==========================### COMMON SIGNALS ###==========================*/
    parameter  int unsigned                 DW              = 32,               // DATA WIDTH
    parameter  int unsigned                 F_NUM           = 1,                // FIELDS NUM

    localparam int unsigned                 F_PARAM_W       = $clog2(DW) + 1,   // FIELDS PARAM WIDTH
    localparam int unsigned                 STRUCT_PARAM_W  = F_NUM * F_PARAM_W,

    parameter logic [STRUCT_PARAM_W - 1:0]  F_W             = {(F_PARAM_W)'(32)},

    parameter logic [STRUCT_PARAM_W - 1:0]  F_OFS           = {(F_PARAM_W)'(0)}

) (
    /*==========================### COMMON SIGNALS ###==========================*/
    input logic                         clk,
    input logic                         rst_n,

    /*===========================### WRITE SIGNALS ###==========================*/
    input logic [DW - 1: 0]             wdata,
    input logic [DW - 1: 0]             wedata,

    /*============================### READ SIGNALS ###==========================*/
    output logic [DW - 1: 0]            rdata
    /*==========================================================================*/
);
//==============================================================================//
// LOGIC
//==============================================================================//
for (genvar i = F_NUM - 1; i >= 0; i--) begin: g_fields
    localparam int unsigned CUR_F_W     = (32)'(F_W[(i+1) * F_PARAM_W - 1: i * F_PARAM_W]);
    localparam int unsigned CUR_F_OFS   = (32)'(F_OFS[(i+1) * F_PARAM_W - 1: i * F_PARAM_W]);

    localparam int unsigned F_TOP_BIT = CUR_F_OFS + CUR_F_W - 1;
    localparam int unsigned F_BOT_BIT = CUR_F_OFS;

    // ///////////////////////////////////////////////////////// //
    //                    *** PRIMARY FIELD ***                  //
    // A single field defined as a module
    prim_field #(
        .FIELD_W(CUR_F_W)
    ) field_u (
        /*================### COMMON SIGNALS ###=================*/
        .clk    (clk),                                        // <-
        .rst_n  (rst_n),                                      // <-
        /*================### PACKET SIGNALS ###=================*/
        .wedata (wedata[F_TOP_BIT: F_BOT_BIT]),               // <-
        .wdata  (wdata [F_TOP_BIT: F_BOT_BIT]),               // <-
        .rdata  (rdata [F_TOP_BIT: F_BOT_BIT])                // ->
        //=======================================================//
    );
    // ///////////////////////////////////////////////////////// //

    // Here we generate reserved bits in register. In comments I use F[N]
    // as FIELD_N. So, F[0], F[1] it's FIELD_0, FIELD_1 and etc.
    localparam int unsigned F_CUR_END_OFS = CUR_F_OFS + CUR_F_W;
    if (i == 0) begin: g_res_rdata_last_field
        // check edge near DW
        // Destination case: [..., F[N], ..., F[N+1], {here}]
        if (F_CUR_END_OFS != DW) begin: gen_last_res_if_exist_space
            assign rdata[DW - 1: F_CUR_END_OFS] = '0 & (wdata[DW - 1: F_CUR_END_OFS]
                                                     & wedata[DW - 1: F_CUR_END_OFS]);
        end
    end
    else begin: g_reg_res_between_field
        // check edge near zero
        // Destination case: [{here}, F[0], ..., F[1], ...]
        if (i == F_NUM - 1) begin: g_res_first_field
            if (CUR_F_OFS != 0) begin: g_res_if_first_ofs_non_zero
                assign rdata[CUR_F_OFS - 1: 0] = '0 & (wdata[CUR_F_OFS - 1: 0]
                                                    & wedata[CUR_F_OFS - 1: 0]);

            end
        end
        // generate reserved bits beetween fields
        // Destination case: [..., F[0], {here}, F[1], ...]
        localparam int unsigned F_NEXT_OFS = (32)'(F_OFS[(i) * F_PARAM_W - 1: (i-1) * F_PARAM_W]);
        if (F_NEXT_OFS != F_CUR_END_OFS) begin: gen_res
            assign rdata[F_NEXT_OFS - 1: F_CUR_END_OFS] = '0
                                                    & (wdata[F_NEXT_OFS - 1: F_CUR_END_OFS]
                                                    & wedata[F_NEXT_OFS - 1: F_CUR_END_OFS]);
        end
    end
end: g_fields

//==============================================================================//
endmodule
