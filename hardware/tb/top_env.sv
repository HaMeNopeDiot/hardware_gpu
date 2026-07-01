//----------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// ---------------------------------------------------------------------------//
// Purpose: Graphic core tb
// Date: 2026/06
//----------------------------------------------------------------------------//

/*============================================================================//
region MODULE DEFINITION
//============================================================================*/
module top_env
    import tu_pkg::thread_info_t;

    import ahb_pkg::ahb_mports_t;
    import ahb_pkg::ahb_sports_t;

    import apb_pkg::apb4_mports_t;
    import apb_pkg::apb4_sports_t;

    import edge_detector_pkg::EDGE_CATCH_T_FE;
    import core_regblk_pkg::*;
#(
    parameter   int unsigned MEM_AW         = 32,
    parameter   int unsigned CSR_AW         = 6,
    parameter   int unsigned MEM_DW         = 32,
    parameter   int unsigned REGFILE_SZ     = 32,
    parameter   int unsigned THREAD_CNT     = 4,

    parameter   int unsigned RMEM_AW        = 16,

    localparam  int unsigned STROBE         = MEM_DW / 8,
    localparam  int unsigned NUM_REG_MEM    = 1 << RMEM_AW
) ();
logic clk;
logic rst_n;

always #5 clk = ~clk;

/*============================================================================//
region DEFINITIONS
//============================================================================*/
typedef logic [MEM_DW - 1: 0] mem_t [NUM_REG_MEM];
typedef int mem_func_t [(1 << RMEM_AW)];

/* verilator lint_off UNUSEDSIGNAL */
ahb_mports_t    lsu_ahb_o, fet_ahb_o;
ahb_sports_t    lsu_ahb_i, fet_ahb_i;

assign lsu_ahb_i.hready = '1;
assign lsu_ahb_i.hresp  = '0;

assign fet_ahb_i.hready = '1;
assign fet_ahb_i.hresp  = '0;

apb4_mports_t   apb_in;
apb4_sports_t   apb_out;

logic           active;
logic           core_busy, core_busy_fe;

/* verilator lint_off UNUSEDSIGNAL */
thread_info_t   thread_info;

/*============================================================================//
region STRUCTURE DEBUG INFO FOR GTKW
//============================================================================*/

// from master
logic [CSR_AW - 1: 0] csr_x_paddr;
logic [MEM_DW - 1: 0] csr_x_pwdata;
logic [STROBE - 1: 0] csr_x_pstrb;
logic                 csr_x_psel;
logic                 csr_x_pwrite;
logic                 csr_x_penable;
logic                 csr_x_pprot;

always_comb begin
    apb_in.paddr   = csr_x_paddr   ;
    apb_in.pwdata  = csr_x_pwdata  ;
    apb_in.pstrb   = csr_x_pstrb   ;
    apb_in.psel    = csr_x_psel    ;
    apb_in.pwrite  = csr_x_pwrite  ;
    apb_in.penable = csr_x_penable ;
    apb_in.pprot   = csr_x_pprot   ;
end

// from slave
logic [MEM_DW - 1: 0] csr_x_prdata;
logic                 csr_x_pready;
logic                 csr_x_pslverr;

always_comb begin
    csr_x_prdata  = apb_out.prdata ;
    csr_x_pready  = apb_out.pready ;
    csr_x_pslverr = apb_out.pslverr;
end

/*============================================================================//
region FUNCTIONS
//============================================================================*/

/* I fully understand that I'm creating two memory banks of size 1 << RMEM, each
utilized only up to half their capacity. However, I don't want to get overly
involved with implementing bank switching based on the most significant bit for
this testbench, so I decided to keep it as is.*/

// load memory with data
export "DPI-C" function read_data_mem;
function automatic int read_data_mem(input int address);
    return ahb_lsu_mem_u.mem[address];
endfunction

export "DPI-C" function write_data_mem;
function automatic write_data_mem(input int address, input int data);
    ahb_lsu_mem_u.mem[address] = data;
endfunction

export "DPI-C" function read_fetcher_mem;
function automatic int read_fetcher_mem(input int address);
    return ahb_fet_mem_u.mem[address];
endfunction

export "DPI-C" function write_fetcher_mem;
function automatic write_fetcher_mem(input int address, input int data);
    ahb_fet_mem_u.mem[address] = data;
endfunction

// quality of life, for things that are unlikely to change accross simulations
export "DPI-C" function load_vertex_shader_mem;
function automatic load_vertex_shader_mem();
    $readmemh("../hardware/mem/vertex_shader.mem", ahb_fet_mem_u.mem);
endfunction

export "DPI-C" function load_vertex_buffer_mem;
function automatic load_vertex_buffer_mem();
    $readmemh("../hardware/mem/vertex_buffer.mem", ahb_lsu_mem_u.mem);
endfunction


// section APB
//----------------------------------------------------------------------------//

// Clear APB bus as Master
// verilog_lint: waive explicit-task-lifetime
task apb_release_bus();
    apb_in.paddr    <= '0;
    apb_in.pwdata   <= '0;
    apb_in.pstrb    <= '0;
    apb_in.psel     <= '0;
    apb_in.pwrite   <= '0;
    apb_in.penable  <= '0;
endtask

// Make write txn
// verilog_lint: waive explicit-task-lifetime
task apb_write(
        input logic [CSR_AW - 1:0] addr,
        input logic [MEM_DW - 1:0] data,
        input logic [STROBE - 1:0] strb = (STROBE)'('1),
        input logic                make_space = 1'b0
                            );
        @(posedge clk); // set first cycle (set parameters)
        apb_in.paddr   <= addr;
        apb_in.pwdata  <= data;
        apb_in.pstrb   <= strb;
        apb_in.psel    <= 1'b1;
        apb_in.pwrite  <= 1'b1;
        apb_in.penable <= 1'b0;
        @(posedge clk); // set second and subsequent cycles
        apb_in.penable <= 1'b1;
        #1;
        while (apb_out.pready == 1'b0) begin
            @(posedge clk);
            #1;
        end
        if (make_space) begin
            apb_release_bus();
        end
    endtask


// Make read txn
// verilog_lint: waive explicit-task-lifetime
task apb_read(
    input logic [CSR_AW - 1:0] addr,
    input logic                make_space = 1'b0
                        );
    @(posedge clk); // set first cycle (set parameters)
    #1;
    apb_in.paddr   = addr;
    apb_in.psel    = 1'b1;
    apb_in.pwrite  = 1'b0;
    apb_in.penable = 1'b0;
    @(posedge clk); // set second and subsequent cycles
    #1;
    apb_in.penable = 1'b1;
    while (apb_out.pready == 1'b0) begin
        @(posedge clk);
        // #1;
    end
    if (make_space) begin
        @(posedge clk);
        apb_release_bus();
    end
endtask


// Activate read txn APB loop. Do not call this task.
// verilog_lint: waive explicit-task-lifetime
task monitor_core_active();
    logic [MEM_DW - 1: 0] ccr;
    begin
        while (active) begin
            apb_read((CSR_AW)'(R_CORE_CTRL_OFS));
            ccr <= apb_out.prdata;
            if (ccr[F_CORE_EN_OFS] == '1)
                active <= '0;
        end
    end
endtask

// Start Core
// verilog_lint: waive explicit-task-lifetime
export "DPI-C" task start;
task start(input int start_vid);
    logic [MEM_DW - 1: 0] vid       [THREAD_CNT];
    logic [MEM_DW - 1: 0] start_pc;
    begin
        for (int unsigned i = 0; i < THREAD_CNT; i++) begin
            vid[i] <= (MEM_DW)'(i);
        end
        // Also you can set theese vid
        vid[0]      <= 32'(start_vid);
        vid[1]      <= 32'(start_vid + 1);
        vid[2]      <= 32'(start_vid + 2);
        vid[3]      <= 32'(start_vid + 3);
        start_pc    <= 32'(0);
        fork
            begin
                while (rst_n != '1)
                    @(posedge clk);
                // set vid to each thread
                for (int unsigned i = 0; i < THREAD_CNT; i++) begin
                    apb_write((CSR_AW)'(RS_VID_OFS + i * STROBE), (MEM_DW)'(vid[i]));
                end
                // set start program counter
                apb_write((CSR_AW)'(R_PC_OFS),         (MEM_DW)'(start_pc));
                // Enable all threads
                apb_write((CSR_AW)'(R_TU_EN_OFS),      (MEM_DW)'((1 << THREAD_CNT) - 1));
                // launch core
                apb_write((CSR_AW)'(R_CORE_CTRL_OFS),  (MEM_DW)'(1));
                active <= 1;
                @(posedge clk);
                apb_release_bus();
                // Check state of core
                monitor_core_active();
            end
        join_none
    end
endtask

// verilog_lint: waive explicit-function-lifetime
export "DPI-C" function is_done;
function logic is_done();
    return core_busy_fe;
endfunction

/*============================================================================//
region INITIAL
//============================================================================*/

initial begin
    $dumpfile("top_env.vcd");
    $dumpvars(0, top_env);
    apb_in   = '0;
    clk      = '0;
    #20;
    rst_n    = '0;
    #3 rst_n = '1;

end

/*============================================================================//
region LOGIC
//============================================================================*/

// you can write your code here
logic  wrng_pprot;
assign wrng_pprot = (apb_in.pprot[1]) || (apb_in.pprot[2]);

logic  csr_we;
assign csr_we = (apb_in.psel) && (apb_in.pwrite) && (~wrng_pprot);

/*============================================================================//
region INSTANCES
//============================================================================*/

// ///////////////////////////////////////////////////////// //
//                       *** CORE ***                        //
// NOTE: Graphic Core
core #(
    .DW              (MEM_DW                        ),
    .MEM_AW          (MEM_AW                        ),
    .CSR_AW          (CSR_AW                        ),
    .TU_REGILE_SZ    (REGFILE_SZ                    ),
    .TU_LATCH_R_ADDR (1                             ),
    .ONLY_LINT       (0                             ), // `ifdef LINT 1 `else 0 `endif get fixed later
    .THREAD_CNT      (THREAD_CNT                    )
) core_u (
    //================### COMMON SIGNALS ###=================//
    .clk           (clk                 ), // <-
    .rst_n         (rst_n               ), // <-
    //==================### AHB SIGNALS ###==================//
    .lsu_haddr     (lsu_ahb_o.haddr     ), // ->
    .lsu_hwrite    (lsu_ahb_o.hwrite    ), // ->
    .lsu_hsize     (lsu_ahb_o.hsize     ), // ->
    .lsu_hburst    (lsu_ahb_o.hburst    ), // ->
    .lsu_hprot     (lsu_ahb_o.hprot     ), // ->
    .lsu_htrans    (lsu_ahb_o.htrans    ), // ->
    .lsu_hmastlock (lsu_ahb_o.hmastlock ), // ->
    .lsu_hwdata    (lsu_ahb_o.hwdata    ), // ->
    .lsu_hready    (lsu_ahb_i.hready    ), // <-
    .lsu_hresp     (lsu_ahb_i.hresp     ), // <-
    .lsu_hrdata    (lsu_ahb_i.hrdata    ), // <-
    .ftc_haddr     (fet_ahb_o.haddr     ), // ->
    .ftc_hwrite    (fet_ahb_o.hwrite    ), // ->
    .ftc_hsize     (fet_ahb_o.hsize     ), // ->
    .ftc_hburst    (fet_ahb_o.hburst    ), // ->
    .ftc_hprot     (fet_ahb_o.hprot     ), // ->
    .ftc_htrans    (fet_ahb_o.htrans    ), // ->
    .ftc_hmastlock (fet_ahb_o.hmastlock ), // ->
    .ftc_hwdata    (fet_ahb_o.hwdata    ), // ->
    .ftc_hready    (fet_ahb_i.hready    ), // <-
    .ftc_hresp     (fet_ahb_i.hresp     ), // <-
    .ftc_hrdata    (fet_ahb_i.hrdata    ), // <-
    //==================### APB SIGNALS ###==================//
    .csr_prdata    (apb_out.prdata      ), // ->
    .csr_pready    (apb_out.pready      ), // ->
    .csr_pslverr   (apb_out.pslverr     ), // ->
    .csr_paddr     (apb_in.paddr        ), // <-
    .csr_pwdata    (apb_in.pwdata       ), // <-
    .csr_pstrb     (apb_in.pstrb        ), // <-
    .csr_psel      (apb_in.psel         ), // <-
    .csr_pwrite    (apb_in.pwrite       ), // <-
    .csr_penable   (apb_in.penable      ), // <-
    .csr_pprot     (apb_in.pprot        ), // <-
    //==================### TU SIGNALS ###===================//
    .thread_info   (thread_info         ), // ->
    .busy_o        (core_busy           )  // ->
    //=======================================================//
);
// ///////////////////////////////////////////////////////// //

// ///////////////////////////////////////////////////////// //
//                  *** AHB LSU MEM ***                      //
// NOTE: AHB Slave MEMORY
ahb_mem #(
    .DEPTH              (NUM_REG_MEM),
    .AW                 (RMEM_AW),
    .DW                 (MEM_DW),
    .DEBUG_MODE         ('1),
    .DEBUG_REGS_TRACE   (8),
    .DEBUG_TRACE_OFS    (32'h1000)
) ahb_lsu_mem_u (
    //================### COMMON SIGNALS ###=================//
    .HCLK    (clk                               ), // <-
    .HRESETn (rst_n                             ), // <-
    .HADDR   (lsu_ahb_o.haddr[RMEM_AW - 1: 0]   ), // <-
    .HTRANS  (lsu_ahb_o.htrans                  ), // <-
    .HWDATA  (lsu_ahb_o.hwdata                  ), // <-
    .HWRITE  (lsu_ahb_o.hwrite                  ), // <-
    .HRDATA  (lsu_ahb_i.hrdata                  )  // ->
    //=======================================================//
);
// ///////////////////////////////////////////////////////// //

// ///////////////////////////////////////////////////////// //
//                  *** AHB FETCHER MEM ***                  //
// NOTE: AHB Slave MEMORY
ahb_mem #(
    .DEPTH      (NUM_REG_MEM),
    .AW         (RMEM_AW),
    .DW         (MEM_DW),
    .DEBUG_MODE ('1)
) ahb_fet_mem_u (
    //================### COMMON SIGNALS ###=================//
    .HCLK    (clk                               ), // <-
    .HRESETn (rst_n                             ), // <-
    .HADDR   (fet_ahb_o.haddr[RMEM_AW - 1: 0]   ), // <-
    .HTRANS  (fet_ahb_o.htrans                  ), // <-
    .HWDATA  (fet_ahb_o.hwdata                  ), // <-
    .HWRITE  (fet_ahb_o.hwrite                  ), // <-
    .HRDATA  (fet_ahb_i.hrdata                  )  // ->
    //=======================================================//
);
// ///////////////////////////////////////////////////////// //

// ///////////////////////////////////////////////////////// //
//                   *** EDGE DETECTOR ***                   //
// NOTE: Edge detector for active state
edge_detector #(
    .ED_CATCH_T       (EDGE_CATCH_T_FE),
    .DEF_PREV_SIG_VAL (0)
) edge_detector_u (
    //================### COMMON SIGNALS ###=================//
    .clk      (clk          ),  // <-
    .rst_n    (rst_n        ),  // <-
    .sig      (core_busy    ),  // <-
    .sig_edge (core_busy_fe )   // ->
    //=======================================================//
);
// ///////////////////////////////////////////////////////// //


//============================================================================*/
endmodule
