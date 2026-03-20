#include "execute.h"


int main() {
    float dst;

    exec(float, "fsqrt", dst, .src0=3.0, .src1=5.3);
    printf("%f\n", dst);

    return 0;
}
