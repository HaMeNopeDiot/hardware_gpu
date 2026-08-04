//----------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// ---------------------------------------------------------------------------//
// Purpose: Simple adder constant pow of 2
// Date: 2026/08
//----------------------------------------------------------------------------//

/*============================================================================//
region MODULE DEFINITION
//============================================================================*/
module adder_pow2
#(
    parameter   int unsigned  DW      = 32,

    localparam  int unsigned  ADD_VAL = DW / 8,
    localparam  int unsigned  K       = $clog2(ADD_VAL)
) (
    /*=======================### COMMON SIGNALS ###===========================*/
    input  logic [DW - 1: 0]    operand,
    output logic [DW - 1: 0]    result
    //========================================================================//
);

// Simulation check to ensure you only passed a valid power of 2
// synthesis translate_off
initial begin
    assert((1 << K) == ADD_VAL) else $fatal(1, "ADD_VAL must be a power of 2!");
end
// synthesis translate_on


/*============================================================================//
region OUT
//============================================================================*/

assign result[K  - 1: 0] = operand[K  - 1: 0];
assign result[DW - 1: K] = operand[DW - 1: 2] + 1'b1;

//============================================================================*/
endmodule
