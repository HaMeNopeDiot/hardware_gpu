//------------------------------------------------------------------------------
// Department:            Software Laboratory
// Author:                Starukhin Danila M.
// Author's e-mail:       starukhin.d@milandr.ru
// -----------------------------------------------------------------------------
// Purpose: Compute unit fsm
//------------------------------------------------------------------------------
// Copyright (c) 2026 JSC "ICC Milandr", all rights reserved.
//
// This file contains confidential, proprietary information and trade
// secrets of JSC "ICC Milandr". The information contained in this file
// may only be used by a person authorised under and to the extent
// permitted by a subsisting license agreement or design service
// agreement from JSC "ICC Milandr".
//
// This entire notice must be reproduced on all copies of this file
// and copies of this file may only be made by a person if such person
// is permitted to do so under the terms of a subsisting license
// agreement or design service agreement from JSC "ICC Milandr".
//------------------------------------------------------------------------------

module cu_fsm
    import handshake_fpu_pkg::proccess_t;
    // FSM states
    import handshake_fpu_pkg::FPU_IDLE;
    import handshake_fpu_pkg::FPU_PRELOAD;
    import handshake_fpu_pkg::FPU_LOAD;
    import handshake_fpu_pkg::FPU_PROCESS;
    import handshake_fpu_pkg::FPU_RESULT;
#() (
    /*============================### COMMON SIGNALS ###==========================*/
    input  logic clk,
    input  logic rst_n,
    /*==========================### HANDSHAKE SIGNALS ###=========================*/
    input  logic in_ready_o,
    input  logic out_valid_o,
    output logic out_ready_i,
    output logic in_valid_i
    //============================================================================//
);

logic ready_prev;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        ready_prev <= '0;
    else
        ready_prev <= ready;
end

logic  start;
assign start = ready && ~ready_prev;

// FSM logic
proccess_t process_info;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        process_info.prev_state <= '0;
    else
        process_info.prev_state <= process_info.state;
end

// Make FSM
always_comb begin
    case (process_info.prev_state)
        FPU_IDLE: begin
            if (in_valid_i)
                process_info.state = FPU_PRELOAD;
        end
        FPU_PRELOAD: begin
            if (~in_valid_i)
                process_info.state = FPU_IDLE;
            else if (in_ready_o)
                process_info.state = FPU_LOAD;
        end
        FPU_LOAD: begin
            process_info.state = FPU_PROCESS;
        end
        FPU_PROCESS: begin
            if (out_valid_o)
                process_info.state = FPU_RESULT;
        end
        FPU_RESULT: begin
            if (out_ready_i)
                if(in_valid_i)
                    if(in_ready_o)
                        process_info.state = FPU_LOAD;
                    else
                        process_info.state = FPU_PRELOAD;
                else
                    process_info.state = FPU_IDLE;
        end
        default:
            process_info.state = FPU_IDLE;
    endcase
end

logic  fpu_give_result;
assign fpu_give_result = process_info.state == FPU_RESULT;

logic  fpu_load;
assign fpu_load = process_info.state == FPU_LOAD;

always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        in_valid_i <= '0;
    else if (start)
        in_valid_i <= '1;
    else if (fpu_load)
        in_valid_i <= '0;
end

always_comb begin
    if(fpu_give_result)
        out_ready_i = '1;
    else
        out_ready_i = '0;
end


endmodule
