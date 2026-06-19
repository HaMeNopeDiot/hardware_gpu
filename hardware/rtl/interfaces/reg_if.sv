//-------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// ------------------------------------------------------------------------------//
// Purpose: Registers bus interface
// Date: 2026/05
//-------------------------------------------------------------------------------//

/* verilator lint_off UNDRIVEN */
/* verilator lint_off UNUSEDSIGNAL */
interface reg_if;
    import tu_pkg::dw_value_t;

    dw_value_t rs1, rs2, rd;

    modport lsu (
        input  rs1, rs2,
        output rd
    );

    modport tu (
        output rs1, rs2,
        input  rd
    );

endinterface // simple_bus_if

