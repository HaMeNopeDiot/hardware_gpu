#ifndef WRAPPER_H
#define WRAPPER_H

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

#include <stdlib.h>

typedef struct {
    void *contextp;
    void *vtop;
} MyVtop;

EXTERNC MyVtop verilator_rtl_init(void);
EXTERNC void verilator_rtl_destroy(MyVtop item);

EXTERNC void verilator_rtl_write_inputs(
    float *buffer,
    unsigned int buffer_len
);
EXTERNC void verilator_rtl_read_outputs(
    MyVtop item,
    float *buffer,
    size_t vertex_stride,
    size_t height,
    size_t width,
    int print_debug
);
EXTERNC void verilator_rtl_run(MyVtop item);


#endif // WRAPPER_H
