//----------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// ---------------------------------------------------------------------------//
// Purpose: GPU simple core ALU for data and addresses
// Date: 2026/05
//----------------------------------------------------------------------------//

/*============================================================================//
region MODULE DEFINITION
//============================================================================*/
module tu_alu
    import tu_pkg::alu_op_e;

    // operands list
    import tu_pkg::AOP_ADD;
    import tu_pkg::AOP_IMM_LSHIFT;
    import tu_pkg::AOP_MUL;
#(
    parameter int unsigned      DW        = 64
) (
    input  alu_op_e             op_i,
    input  logic [DW - 1: 0]    a1_i,
    input  logic [DW - 1: 0]    a2_i,
    input  logic                valid_i,

    output logic [DW - 1: 0]    r_o,
    output logic                ready_o
);
    always_comb begin
        if (valid_i) begin
            case (op_i)
                AOP_ADD: begin
                    r_o = a1_i + a2_i;
                    ready_o = '1;
                end
                AOP_MUL: begin
                    r_o = a1_i * a2_i;
                    ready_o = '1;
                end
                AOP_IMM_LSHIFT: begin
                    r_o = a1_i << a2_i;
                    ready_o = '1;
                end
                default: begin
                    r_o = '0;
                    ready_o = '1;
                end
            endcase
        end
        else begin
            r_o = '0;
            ready_o = '0;
        end
    end

endmodule
