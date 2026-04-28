//-------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// ------------------------------------------------------------------------------//
// Purpose: Thread unit FSM
//-------------------------------------------------------------------------------//

module tu_fsm
    import handshake_fpu_pkg::proccess_t;
    import handshake_fpu_pkg::fsm_fpu_state_e;
    // FSM states
    import handshake_fpu_pkg::FPU_IDLE;
    import handshake_fpu_pkg::FPU_PRELOAD;
    import handshake_fpu_pkg::FPU_LOAD;
    import handshake_fpu_pkg::FPU_PROCESS;
    import handshake_fpu_pkg::FPU_RESULT;
#() (
    /*============================### COMMON SIGNALS ###==========================*/
    input  logic            clk,
    input  logic            rst_n,
    /*===========================### CONTROL SIGNALS ###==========================*/
    input  logic            ready,
    /*==========================### HANDSHAKE SIGNALS ###=========================*/
    input  logic            in_ready_o,
    input  logic            out_valid_o,
    output logic            out_ready_i,
    output logic            in_valid_i,
    /*===========================### STATUS SIGNALS ###-==========================*/
    output fsm_fpu_state_e  state
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
fsm_fpu_state_e prev_state;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        prev_state <= FPU_IDLE;
    else
        prev_state <= state;
end

// Make FSM
always_comb begin
    case (prev_state)
        FPU_IDLE: begin
            if (in_valid_i)
                if (in_ready_o)
                    state = FPU_LOAD;
                else
                    if (out_valid_o)
                        state = FPU_RESULT;
                    else
                        state = FPU_PRELOAD;
            else
                state = FPU_IDLE;
        end
        FPU_PRELOAD: begin
            if (in_ready_o)
                state = FPU_LOAD;
            else if (~in_valid_i)
                state = FPU_IDLE;
            else
                state = FPU_PRELOAD;
        end
        FPU_LOAD: begin
            state = FPU_PROCESS;
        end
        FPU_PROCESS: begin
            if (out_valid_o)
                state = FPU_RESULT;
            else
                state = FPU_PROCESS;
        end
        FPU_RESULT: begin
            if (out_ready_i)
                if(in_valid_i)
                    if(in_ready_o)
                        state = FPU_LOAD;
                    else
                        state = FPU_PRELOAD;
                else
                    state = FPU_IDLE;
            else
                state = FPU_RESULT;
        end
        default:
            state = FPU_IDLE;
    endcase
end

logic  fpu_give_result;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        fpu_give_result <= '0;
    else
        fpu_give_result <= state == FPU_RESULT;
end

logic  fpu_load;
always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        fpu_load <= '0;
    else
        fpu_load <= state == FPU_LOAD;
end

always_comb begin
    if (start)
        in_valid_i = '1;
    else if (fpu_load)
        in_valid_i = '0;
    else
        in_valid_i = '0;
end

always_comb begin
    if(fpu_give_result)
        out_ready_i = '1;
    else
        out_ready_i = '0;
end


endmodule
