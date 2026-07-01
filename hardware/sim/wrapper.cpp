
#include "Vtop_env__Dpi.h"
#include <stdint.h>
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


typedef union {
   int32_t integer;
   float fp;
} mem_t;
void verilator_rtl_read_outputs(MyVtop item, float *buffer, size_t height, size_t width, int print_debug){
    Vtop_env *vtop = (Vtop_env *)item.vtop;

    const size_t MESA_VERTEX_BASE = 0u;
    const size_t MESA_VERTEX_STRIDE = 77u;
    const size_t MESA_ATTRIBUTE_STRIDE = 4u;
    const size_t MESA_COORD_STRIDE = 1u;

    const int VERTEX_NUMBER = 4;
    const int ATTRIBUTES_NUMBER = 2;
    const int ATTRIBUTES_SIZE = 4;

    const char *attributes[2] = {".gl_Position", "vVaryingColor"};

    // reading output data
    for (int vertex = 0; vertex < VERTEX_NUMBER; vertex++) {
        for (int attribute = 0; attribute < ATTRIBUTES_NUMBER; attribute++) {
            for (int coord = 0; coord < ATTRIBUTES_SIZE; coord++) {
                mem_t value;
                value.integer = vtop->get_vertex_attribute(vertex, attribute, coord);

                size_t address = MESA_VERTEX_BASE;
                address += MESA_VERTEX_STRIDE * vertex;
                address += MESA_ATTRIBUTE_STRIDE * attribute;
                address += MESA_COORD_STRIDE * coord;
                buffer[address] = value.fp;
            }
        }
    }

    if (print_debug != 0) {
        printf("As-read from the simulation\n");
        for (int vertex = 0; vertex < VERTEX_NUMBER; vertex++) {
            printf("\tVertex: %d\n", vertex);
            for (int attribute = 0; attribute < ATTRIBUTES_NUMBER; attribute++) {
                printf("\t\t%s: ", attributes[attribute]);
                for (int coord = 0; coord < ATTRIBUTES_SIZE; coord++) {
                    size_t address = MESA_VERTEX_BASE;
                    address += MESA_VERTEX_STRIDE * vertex;
                    address += MESA_ATTRIBUTE_STRIDE * attribute;
                    address += MESA_COORD_STRIDE * coord;

                    mem_t value;
                    value.fp = buffer[address];
                    printf("%f (%8x), ", value.fp, value.integer);
                }
                printf("\n");
            }
        }
    }

    // post-processing of .gl_Position
    for (int vertex = 0; vertex < VERTEX_NUMBER; vertex++) {
        int attribute = 0;

        size_t address = MESA_VERTEX_BASE;
        address += MESA_VERTEX_STRIDE * vertex;

        size_t gl_Position_X = address;
        size_t gl_Position_Y = address + MESA_COORD_STRIDE;
        size_t gl_Position_Z = address + MESA_COORD_STRIDE * 2;
        size_t gl_Position_W = address + MESA_COORD_STRIDE * 3;

        // normalized device coordinates
        buffer[gl_Position_X] = buffer[gl_Position_X] / buffer[gl_Position_W];
        buffer[gl_Position_Y] = buffer[gl_Position_Y] / buffer[gl_Position_W];
        buffer[gl_Position_Z] = buffer[gl_Position_Z] / buffer[gl_Position_W];
        buffer[gl_Position_W] = 1.0f / buffer[gl_Position_W];

        // viewport transform
        buffer[gl_Position_X] = (buffer[gl_Position_X] + 1.0f) * width / 2.0f;
        buffer[gl_Position_Y] = (buffer[gl_Position_Y] + 1.0f) * width / 2.0f;
    }


    if (print_debug != 0) {
        printf("Post-viewport coordinates\n");
        for (int vertex = 0; vertex < VERTEX_NUMBER; vertex++) {
            printf("\tVertex: %d\n", vertex);
            for (int attribute = 0; attribute < ATTRIBUTES_NUMBER; attribute++) {
                printf("\t\t%s: ", attributes[attribute]);
                for (int coord = 0; coord < ATTRIBUTES_SIZE; coord++) {
                    size_t address = MESA_VERTEX_BASE;
                    address += MESA_VERTEX_STRIDE * vertex;
                    address += MESA_ATTRIBUTE_STRIDE * attribute;
                    address += MESA_COORD_STRIDE * coord;

                    mem_t value;
                    value.fp = buffer[address];
                    printf("%f (%8x), ", value.fp, value.integer);
                }
                printf("\n");
            }
        }
    }
}
