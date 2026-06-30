#ifndef WRAPPER_H
#define WRAPPER_H

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

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
   float *buffer,
   unsigned int buffer_len
);
EXTERNC void verilator_rtl_run(MyVtop item);


#endif // WRAPPER_H
