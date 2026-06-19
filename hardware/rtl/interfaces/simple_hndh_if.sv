//-------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// ------------------------------------------------------------------------------//
// Purpose: Simple handshake interface
// Date: 2026/05
//-------------------------------------------------------------------------------//

/* verilator lint_off UNDRIVEN */
/* verilator lint_off UNUSEDSIGNAL */
interface simple_hndh_if;
	logic ready;
	logic valid;

	modport master (
		input 	ready,
		output	valid
	);
	modport slave (
		output 	ready,
		input	valid
	);
endinterface // simple_hndh_if

