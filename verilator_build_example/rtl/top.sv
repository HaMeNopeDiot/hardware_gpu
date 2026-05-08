module top ();

logic            clk   = '0;
logic            rst_n = '0;
logic            start = '0;
logic            done;

example example_u (
    .clk(clk),
    .rst_n(rst_n),
    .start(start),
    .done(done),
    .mem_data(),
    .mem_addr()
);

always #5 clk = ~clk;
initial begin
    $dumpfile("top.vcd");
    $dumpvars(0, top);
    #3 rst_n = '1;
end

task deassertStart;
    @(posedge clk);
    #1 start = '0;
endtask

export "DPI-C" task startOperations;
task startOperations;
    start = '1;
    fork
        begin
            deassertStart();
        end
    join_none
endtask


export "DPI-C" function isDone;
function int unsigned isDone();
    return {31'b0, done};
endfunction

endmodule