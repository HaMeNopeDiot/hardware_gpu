
module example #(
    parameter  int DW = 32,
    parameter  int AW = 8
) (
    input  logic            clk,
    input  logic            rst_n,

    input  logic            start,
    output logic            done,

    input  logic [DW-1:0]   mem_data,
    output logic [AW-1:0]   mem_addr
);

logic [2:0] counter;
assign done = counter == '1;

logic busy;
always_ff @(posedge clk or negedge rst_n) begin : busy_blk
    if (!rst_n) begin
        busy <= '0;
    end
    else begin
        busy <= busy && !done || start;
    end
end

always_ff @(posedge clk or negedge rst_n) begin: counter_blk
    if (!rst_n) begin
        counter <= '0;
    end
    else if (busy) begin
        counter <= counter + 'd1;
    end
    else begin
        counter <= '0;
    end
end

assign mem_addr = '0;

endmodule
