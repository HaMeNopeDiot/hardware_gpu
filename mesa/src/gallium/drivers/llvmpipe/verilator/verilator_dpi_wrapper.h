#ifndef WRAPPER_H
#define WRAPPER_H

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

#include <stdlib.h>

#define THREADS_IN_CORE 4

typedef struct {
    void *contextp;
    void *vtop;
} MyVtop;

EXTERNC MyVtop verilator_rtl_init(void);
EXTERNC void verilator_rtl_destroy(MyVtop item);

EXTERNC void verilator_rtl_write_inputs(MyVtop item, float *buffer, unsigned int buffer_len);
EXTERNC void verilator_rtl_read_outputs(
    MyVtop item,
    float *buffer,
    size_t vertex_stride,
    size_t height,
    size_t width,
    int print_debug,
    int vertex_offset,
    unsigned vertex_number,
    int scheduler_vertex_offset
);
EXTERNC void verilator_rtl_run(MyVtop item, int start_vid);


#endif // WRAPPER_H
