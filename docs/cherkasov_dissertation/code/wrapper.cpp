
#include "Vtop__Dpi.h"
#include "svdpi.h"
MyVtop verilator_rtl_init(int argc, char **argv) {
    MyVtop context;

    VerilatedContext *contextp = new VerilatedContext();
    context.contextp = (void *)contextp;
    contextp->commandArgs(argc, argv);
    contextp->threads(1);

    Vtop *vtop = new Vtop(contextp);
    context.vtop = (void *) vtop;

    const svScope scope = svGetScopeFromName("TOP.top");
    assert(scope);
    svSetScope(scope);

    Verilated::traceEverOn(true);

    const int RESET_TIMING = 3;
    for (int i = 0; i < RESET_TIMING; i++) {
        vtop->eval();
        contextp->time(contextp->time() + 1);
    }

    return context;
}


void verilator_rtl_destroy(MyVtop item) {
    Vtop *vtop = (Vtop *)item.vtop;
    VerilatedContext *contextp = (VerilatedContext *)item.contextp;

    vtop->final();
    vtop->~Vtop();
    contextp->~VerilatedContext();
}


void verilator_rtl_run(MyVtop item) {
    Vtop *vtop = (Vtop *)item.vtop;
    VerilatedContext *contextp = (VerilatedContext *)item.contextp;

    vtop->startOperations();
    const int MAX_ITERATIONS = 100;
    int iter = 0;
    while (!vtop->isDone() && iter < MAX_ITERATIONS) {
        vtop->eval();
        contextp->time(contextp->time() + 1);

        iter++;
    }
    if (!vtop->isDone()) {
        printf("Simulation was killed (timeout)\n");
    }
}