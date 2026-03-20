#include "execute.h"

#include <stdio.h>
#include <math.h>
#include <string.h>


bool exec_float(char *op_name, float *dst, struct sources_float srcs) {
    if (strcmp(op_name, "fadd") == 0) {
        *dst = srcs.src0 + srcs.src1;
        return true;
    }

    else if (strcmp(op_name, "fmul") == 0) {
        *dst = srcs.src0 * srcs.src1;
        return true;
    }

    else if (strcmp(op_name, "fdiv") == 0) {
        *dst = srcs.src0 / srcs.src1;
        return true;
    }

    else if (strcmp(op_name, "fneg") == 0) {
        *dst = -srcs.src0;
        return true;
    }

    else if (strcmp(op_name, "fsqrt") == 0) {
        *dst = sqrtf(srcs.src0);
        return true;
    }

    else if (strcmp(op_name, "fmax") == 0) {
        *dst = fmaxf(srcs.src0, srcs.src1);
        return true;
    }

    else {
        printf("Unregistered operation\n", stderr);
        return false;
    }
}


bool exec_int(char *op_name, int *dst, struct sources_int srcs) {
    if (strcmp(op_name, "iadd") == 0) {
        *dst = srcs.src0 + srcs.src1;
        return true;
    }

    else if (strcmp(op_name, "imul") == 0) {
        *dst = srcs.src0 * srcs.src1;
        return true;
    }

    else if (strcmp(op_name, "idiv") == 0) {
        *dst = srcs.src0 / srcs.src1;
        return true;
    }

    else if (strcmp(op_name, "ineg") == 0) {
        *dst = -srcs.src0;
        return true;
    }

    else if (strcmp(op_name, "imax") == 0) {
        *dst = imax(srcs.src0, srcs.src1);
        return true;
    }

    else {
        printf("Unregistered operation: %s\n", op_name, stderr);
        return false;
    }
}


int imax(int x, int y) {
    return x > y ? x : y;
}
