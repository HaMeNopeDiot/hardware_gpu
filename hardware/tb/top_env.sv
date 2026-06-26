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
    parameter   int unsigned MEM_DW         = 32,
    parameter   int unsigned REGFILE_SZ     = 32,
    parameter   int unsigned THREAD_CNT     = 4,

    parameter   int unsigned RMEM_AW        = 16,

    localparam  int unsigned STROBE         = MEM_DW / 8,
    localparam  int unsigned NUM_REG_MEM    = 1 << RMEM_AW
) (
    input logic clk,
    input logic rst_n
);
/*============================================================================//
region DEFINITIONS
//============================================================================*/
typedef logic [MEM_DW - 1: 0] mem_t [NUM_REG_MEM];

/* verilator lint_off UNUSEDSIGNAL */
ahb_mports_t    lsu_ahb_o, fet_ahb_o;
ahb_sports_t    lsu_ahb_i, fet_ahb_i;

assign lsu_ahb_i.hready = '1;
assign lsu_ahb_i.hresp  = '0;

assign fet_ahb_i.hready = '1;
assign fet_ahb_i.hresp  = '0;

apb4_mports_t   apb_in = '0;
apb4_sports_t   apb_out;

logic           active;
logic           core_busy, core_busy_fe;

/* verilator lint_off UNUSEDSIGNAL */
thread_info_t   thread_info;

/*============================================================================//
region FUNCTIONS
//============================================================================*/

function automatic load_values(input mem_t data);
    for (int unsigned i = 0; i < (1 << (MEM_AW - 1)); i++) begin
        ahb_fet_mem_u.mem[i] = data[i];
        ahb_lsu_mem_u.mem[i] = data[(1 << (MEM_AW - 1)) + i];
    end
endfunction

function automatic mem_t save_values();
    mem_t lmem;
    for (int unsigned i = 0; i < NUM_REG_MEM; i++) begin
        lmem[i]                         = ahb_fet_mem_u.mem[i];
        lmem[(1 << (MEM_AW - 1)) + i]   = ahb_lsu_mem_u.mem[i];
    end
    return lmem;
endfunction

// section APB
//----------------------------------------------------------------------------//

task automatic apb_release_bus();
    apb_in.paddr    <= '0;
    apb_in.pwdata   <= '0;
    apb_in.pstrb    <= '0;
    apb_in.psel     <= '0;
    apb_in.pwrite   <= '0;
    apb_in.penable  <= '0;
endtask

task automatic apb_write(
    input  logic [MEM_AW - 1: 0]    addr,
    input  logic [MEM_DW - 1: 0]    data,
    input  logic [STROBE - 1: 0]    strb       = (STROBE)'('1),
    input logic                     make_space = 1'b0
                        );
    @(posedge clk); // set first cycle (set parameters)
    apb_in.paddr   = addr;
    apb_in.pwdata  = data;
    apb_in.pstrb   = strb;
    apb_in.psel    = 1'b1;
    apb_in.pwrite  = 1'b1;
    apb_in.penable = 1'b0;
    @(posedge clk); // set second and subsequent cycles
    apb_in.penable = 1'b1;
    #1;
    while (apb_out.pready == 1'b0) begin
        @(posedge clk);
        #1;
    end
    if (apb_out.pslverr)
        $display ("SLVERR");
    if (make_space) begin
        apb_release_bus();
    end
endtask

task automatic apb_read(
    input logic [MEM_AW - 1: 0]     addr,
    input logic                     make_space = 1'b0
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

// verilog_lint: waive explicit-task-lifetime
task monitor_core_active();
    logic [MEM_DW - 1: 0] ccr;
    begin
        while (active) begin
            apb_read((MEM_AW)'(R_CORE_CTRL_OFS));
            ccr = apb_out.prdata;
            if (ccr[F_CORE_EN_OFS] == '1)
                active = '0;
        end
    end
endtask


// verilog_lint: waive explicit-task-lifetime
task start();
    logic [MEM_DW - 1: 0] vid       [THREAD_CNT];
    logic [MEM_DW - 1: 0] start_pc;
    begin
        for (int unsigned i = 0; i < THREAD_CNT; i++) begin
            vid[i] = (MEM_DW)'(i);
        end
        // Also you can set theese vid
        // vid[0]      = 32'(0);
        // vid[1]      = 32'(1);
        // vid[2]      = 32'(2);
        // vid[3]      = 32'(3);
        start_pc    = 32'(0);
        fork
            begin
                // set vid to each thread
                for (int unsigned i = 0; i < THREAD_CNT; i++) begin
                    apb_write(RS_VID_OFS, (MEM_DW)'(vid[i]));
                end
                // set start program counter
                apb_write((MEM_AW)'(R_PC_OFS),         (MEM_DW)'(start_pc));
                // launch core
                apb_write((MEM_AW)'(R_CORE_CTRL_OFS),  (MEM_DW)'(1));
                active = 1;
                // Check state of core
                monitor_core_active();
            end
        join_none
    end
endtask

// verilog_lint: waive explicit-function-lifetime
function logic is_done();
    return core_busy_fe;
endfunction

/*============================================================================//
region INITIAL
//============================================================================*/

initial begin
    $readmemh("mem/vertex_buffer.mem", ahb_lsu_mem_u.mem);
    $readmemb("mem/vertex_shader.mem", ahb_fet_mem_u.mem);
end

/*============================================================================//
region LOGIC
//============================================================================*/

// you can write your code here

/*============================================================================//
region INSTANCES
//============================================================================*/

// ///////////////////////////////////////////////////////// //
//                       *** CORE ***                        //
// NOTE: Graphic Core
core #(
    .DW              (MEM_DW                        ),
    .MEM_AW          (MEM_AW                        ),
    .TU_REGILE_SZ    (REGFILE_SZ                    ),
    .TU_LATCH_R_ADDR (1                             ),
    .ONLY_LINT       (`ifdef LINT 1 `else 0 `endif  ),
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
    .DEPTH (NUM_REG_MEM),
    .AW    (RMEM_AW),
    .DW    (MEM_DW)
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
    .DEPTH (NUM_REG_MEM),
    .AW    (RMEM_AW),
    .DW    (MEM_DW)
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
