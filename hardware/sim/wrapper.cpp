
#include "Vtop_env__Dpi.h"
#include <stdlib.h>
#include <verilated_syms.h>
#include <stdio.h>


MyVtop verilator_rtl_init(void) {
    MyVtop context;
    const char *name = "main";
    const char **fake_argv = &name;

    VerilatedContext *contextp = new VerilatedContext();
    context.contextp = (void *)contextp;
    contextp->commandArgs(0, fake_argv);
    contextp->threads(1);

    Vtop_env *vtop = new Vtop_env(contextp);
    context.vtop = (void *) vtop;

    const svScope scope = svGetScopeFromName("TOP.top_env");
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
    Vtop_env *vtop = (Vtop_env *)item.vtop;
    VerilatedContext *contextp = (VerilatedContext *)item.contextp;

    vtop->final();
    vtop->~Vtop_env();
    contextp->~VerilatedContext();
}


void verilator_rtl_run(MyVtop item) {
    Vtop_env *vtop = (Vtop_env *)item.vtop;
    VerilatedContext *contextp = (VerilatedContext *)item.contextp;

    vtop->start();
    const int MAX_ITERATIONS = 30000;
    int iter = 0;
    while (!vtop->is_done() && iter < MAX_ITERATIONS) {
        vtop->eval();
        contextp->time(contextp->time() + 1);

        iter++;
    }
    if (!vtop->is_done()) {
        printf("Simulation was killed (timeout)\n");
    }
}

void verilator_rtl_write_inputs(float *buffer, unsigned int buffer_len){}
void verilator_rtl_read_outputs(float *buffer, unsigned int buffer_len){}
