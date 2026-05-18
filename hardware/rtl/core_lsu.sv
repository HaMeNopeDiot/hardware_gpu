//-------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// ------------------------------------------------------------------------------//
// Purpose: GPU Core LSU
// Date: 2026/05
//-------------------------------------------------------------------------------//

/*===================================================================================//
region MODULE DEFINITION
//===================================================================================*/
module core_lsu
    import tu_pkg::dw_value_t;
    // LSU
    import tu_pkg::lsu_op_e;
    import tu_pkg::LOP_LW;
    import tu_pkg::LOP_SW;
    // LSU FSM
    import core_lsu_fsm_pkg::lsu_fsm_t;
    import core_lsu_fsm_pkg::LSU_IDLE;
    import core_lsu_fsm_pkg::LSU_SEND;
    import core_lsu_fsm_pkg::LSU_RQ  ;
    import core_lsu_fsm_pkg::LSU_DONE;

#(
    parameter int unsigned DW = 64,
    parameter int unsigned MEM_AW = 32
) (
    /*============================### COMMON SIGNALS ###======================*/
    input  logic                    clk,
    input  logic                    rst_n,

    /*=========================### SIGNALS FROM DECODER ###===================*/
    input  lsu_op_e                 lsu_op,
    input  logic                    lsu_op_valid,
    /*=======================### SIGNALS FROM MEMORY BUS ###==================*/
    simple_bus_if.lsu               m_if,

    /*=======================### SIGNALS FROM THREAD UNIT ###=================*/
    reg_if.lsu                      r_if,

    /*=========================### SIGNALS HANDSHAKE ###======================*/
    output logic                    lsu_ready_o,
    input  logic                    lsu_valid_i

    //========================================================================//
);

/*============================================================================//
region LOGIC
//============================================================================*/

// Register interface
logic [DW - 1: 0] rs1,       rs2,       rd;
logic             rs1_valid, rs2_valid, rd_valid;
assign rs1              = r_if.rs1.value;
assign rs1_valid        = r_if.rs1.valid;
assign rs2              = r_if.rs2.value;
assign rs2_valid        = r_if.rs2.valid;

assign r_if.rd.value    = rd;
assign r_if.rd.valid    = rd_valid;

// Simple bus interface
logic [DW - 1: 0]       read_data, write_data;
logic [MEM_AW - 1: 0]   read_addr, write_addr;
logic read_ready, read_valid, write_ready, write_valid;

assign read_data            =   m_if.read_data;
assign read_ready           =  m_if.read_ready;
assign write_ready          = m_if.write_ready;

assign m_if.read_address    =   read_addr;
assign m_if.write_address   =  write_addr;
assign m_if.read_valid      =  read_valid;
assign m_if.write_valid     = write_valid;
assign m_if.write_data      =  write_data;


/*============================================================================//
region FSM
//============================================================================*/
lsu_fsm_t state, next_state;

always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        state <= LSU_IDLE;
    else
        state <= next_state;
end

always_comb begin
    case (state)
        LSU_IDLE: begin // Get command
            if (lsu_op_valid)
                next_state = LSU_SEND;
            else
                next_state = LSU_IDLE;
        end
        LSU_SEND: begin // Wait info from TU and send it to SRAM
            if (read_valid || write_valid)
                next_state = LSU_RQ;
            else
                next_state = LSU_SEND;
        end
        LSU_RQ: begin // Wait answer from SRAM
            if (read_ready || write_ready)
                next_state = LSU_DONE;
            else
                next_state = LSU_RQ;
        end
        LSU_DONE: begin // Hold result
            if (lsu_valid_i)
                next_state = LSU_IDLE;
            else
                next_state = LSU_DONE;
        end
        default:
            next_state = LSU_IDLE;
    endcase
end

logic   send_rq;
assign  send_rq = next_state == LSU_SEND;

logic   get_res;
assign  get_res = next_state == LSU_DONE;

/*============================================================================//
region READ
//============================================================================*/

logic  op_is_load;
assign op_is_load = lsu_op == LOP_LW;

always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        read_addr <= '0;
    else if (send_rq && op_is_load && rs1_valid)
        read_addr <= (MEM_AW)'(rs1); // <rs1 + imm> actually
    else
        read_addr <= '0;
end

always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        read_valid <= '0;
    else if (send_rq && op_is_load)
        read_valid <= rs1_valid;
    else
        read_valid <= '0;
end

always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        rd <= '0;
    else if (get_res && op_is_load)
        rd <= read_data;
    else
        rd <= '0;
end

always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        rd_valid <= '0;
    else if (get_res && op_is_load)
        rd_valid <= read_ready;
    else
        rd_valid <= '0;
end


/*============================================================================//
region WRITE
//============================================================================*/

always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        write_addr <= '0;
    else if (send_rq) begin
        case (lsu_op)
            LOP_SW: begin
                if (rs1_valid)
                    write_addr <= (MEM_AW)'(rs1); // <rs1 + imm> actually
                else
                    write_addr <= '0;
            end
            default:
                write_addr <= '0;
        endcase
    end
end

always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        write_data <= '0;
    else if (send_rq) begin
        case (lsu_op)
            LOP_SW: begin
                if (rs2_valid)
                    write_data <= rs2;
                else
                    write_data <= '0;
            end
            default:
                write_data <= '0;
        endcase
    end
end

always_ff @(posedge clk or negedge rst_n) begin
    if (~rst_n)
        write_valid <= '0;
    else if (send_rq) begin
        case (lsu_op)
            LOP_SW:     write_valid <= rs1_valid && rs2_valid;
            default:    write_valid <= '0;
        endcase
    end
end

/*============================================================================//
region OUT
//============================================================================*/

assign lsu_ready_o = next_state == LSU_DONE;

//============================================================================*/
endmodule
