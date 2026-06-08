

//-------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// ------------------------------------------------------------------------------//
// Purpose: GPU Core LSU Queue
// Date: 2026/06
//-------------------------------------------------------------------------------//

/*===================================================================================//
region MODULE DEFINITION
//===================================================================================*/
module core_lsu_queue
    import core_lsu_pkg::lsu_load_q_elem_t;
    import core_lsu_pkg::lsu_store_q_elem_t;
    import core_lsu_pkg::lsu_q_elem_t;


    import base_pkg::THREADS_CNT;
    import base_pkg::THREADS_W;

#(
    parameter int unsigned DW           = 32,
    parameter int unsigned QUEUE_LEN    = THREADS_CNT,
    parameter int unsigned QUEUE_W      = THREADS_W
) (
    /*============================### COMMON SIGNALS ###======================*/
    input  logic                    clk,
    input  logic                    rst_n,

    /*========================### SIGNALS FROM THREAD ###=====================*/
    // from fpu to queue
    input  logic                    tu_req_valid_i,
    input  lsu_load_q_elem_t        tu_req_i,
    /*==========================### SIGNALS FROM LSU ###======================*/

    // from lsu to queue
    input  logic                    tu_ans_valid_i,
    input  lsu_store_q_elem_t       tu_ans_i,
    /*========================### SIGNALS FOR THREAD ###======================*/

    // for answering to tu
    input  logic [QUEUE_W - 1: 0]   tu_id,
    output logic [DW - 1: 0]        tu_rd,
    output logic                    tu_done
    //========================================================================//
);

/*============================================================================//
region LOGIC
//============================================================================*/

lsu_q_elem_t q[QUEUE_LEN];

logic [QUEUE_W - 1: 0] req_vid;
logic [QUEUE_W - 1: 0] ans_vid;
assign req_vid = tu_req_valid_i? tu_req_i.vid: '0;
assign ans_vid = tu_ans_valid_i? tu_ans_i.vid: '0;

// WRITE
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        for (int unsigned i = 0; i < QUEUE_LEN; i++)
            q[i] <= '0;
    else begin
        if (tu_req_valid_i) begin
            q[req_vid].rs1  <= tu_req_i.rs1;
            q[req_vid].rs2  <= tu_req_i.rs2;
            if (req_vid != ans_vid)
                q[req_vid].done <= '0;
        end
        if (tu_ans_valid_i) begin
            q[ans_vid].rd   <= tu_ans_i.rd;
            q[ans_vid].done <= tu_ans_i.done;
        end
    end
end

// READ
always_comb begin
    tu_rd   = q[tu_id].rd;
    tu_done = q[tu_id].done;
end

//============================================================================*/
endmodule
