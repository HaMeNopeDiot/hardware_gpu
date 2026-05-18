//-------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// ------------------------------------------------------------------------------//
// Purpose: Simple memory bus interface
// Date: 2026/05
//-------------------------------------------------------------------------------//

/* verilator lint_off UNDRIVEN */
/* verilator lint_off UNUSEDSIGNAL */
interface simple_bus_if
#(
	parameter int unsigned DW = 64,
	parameter int unsigned MEM_AW = 64
) ();
	logic [DW - 1: 0]        read_data;
	logic [MEM_AW - 1: 0]    read_address;
	logic                    read_ready;
	logic                    read_valid;
	logic [DW - 1: 0]        write_data;
	logic [MEM_AW - 1: 0]    write_address;
	logic                    write_ready;
	logic                    write_valid;

	modport lsu (
		input 	read_data, read_ready, write_ready,
		output	read_address, read_valid, write_data, write_address, write_valid
	);
	modport ram (
		output 	read_data, read_ready, write_ready,
		input	read_address, read_valid, write_data, write_address, write_valid
	);
endinterface // simple_bus_if

