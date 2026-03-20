#ifndef EXEC_H
#define EXEC_H

#include <stdbool.h>
#include "extract.h"

extern bool exec_float(char *op_name, float *dst, struct sources_float srcs);
extern bool exec_int(char *op_name, int *dst, struct sources_int srcs);
int imax(int x, int y);

/**
* Execute right type of function depends on given <type> argument: float or int
*/
#define exec(type, op, dst, ...)                                \
    exec_##type(op, &dst, (struct sources_##type){__VA_ARGS__})


#endif