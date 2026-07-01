#include "wrapper.h"
#include <stdlib.h>

int main(int argc, char **argv) {
    MyVtop ptr = verilator_rtl_init(argc, argv);

    verilator_rtl_run(ptr);

    verilator_rtl_destroy(ptr);

    ptr.contextp = NULL;
    ptr.vtop = NULL;
    return 0;
}