#ifndef INRESULTS_H
#define INRESULTS_H

#include <stdint.h>

typedef struct {
    // size of data_width array
    uint32_t data_size;
    // the first avaiable empty space in the data array
    uint32_t data_empty_offset;

    // the data itself
    float* data;
} inresults_t;

void inresults_init(inresults_t *results, uint32_t magical_data_size);
void inresults_destroy(inresults_t *results);

// returns index
uint32_t inresults_save_new(inresults_t *results, float *data, uint32_t size);
float *inresults_get(inresults_t *results, uint32_t offset);

#endif