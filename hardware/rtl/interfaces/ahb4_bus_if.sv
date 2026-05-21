//-------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// ------------------------------------------------------------------------------//
// Purpose: AHB4 interface
// Date: 2026/05
//-------------------------------------------------------------------------------//

/* verilator lint_off UNDRIVEN */
/* verilator lint_off UNUSEDSIGNAL */

interface ahb4_bus_if
#(
    parameter int unsigned  DW = 64,
    parameter int unsigned  AW = 64,
    parameter int unsigned  SLAVES = 1,
	localparam int unsigned BUS_SEL_W = $clog2(SLAVES)
) ();
	// select
	logic [BUS_SEL_W - 1: 0] 	hsel;
	// address and control
	logic [AW - 1: 0] 			haddr;
	logic 						hwrite;
	logic [2 :0]				hsize;
	logic [2 :0]				hburst;
	logic [3 :0]				hprot;
	logic [1 :0]				htrans;
	logic						hmastlock;
	logic						hready;
	// data
	logic [DW - 1:0]			hwdata;
	// transfer responce
	logic						hreadyout;
	logic						hresp;
	// data
	logic [DW - 1: 0]			hrdata;

	modport master (
		input hreadyout, hresp, hrdata,
		output hsel, haddr, hwrite, hsize, hburst, hprot, htrans, hmastlock, hready, hwdata
	);

	modport slave (
		output hreadyout, hresp, hrdata,
		input hsel, haddr, hwrite, hsize, hburst, hprot, htrans, hmastlock, hready, hwdata
	);

endinterface // ahb4_buf_if

