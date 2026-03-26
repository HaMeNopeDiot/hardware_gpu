#include "inresults.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define LARGEST_DATA_ELEM 4

void inresults_init(inresults_t *results, uint32_t magical_data_size)
{
    results->data_size         = magical_data_size;
    results->data_empty_offset = 0ul;
    results->data              = calloc(sizeof(float), magical_data_size);
}


void inresults_destroy(inresults_t *results)
{
    results->data_size = 0ul;
    free(results->data);
    results->data = NULL;
}

uint32_t inresults_save_new(inresults_t *results, float *data, uint32_t size)
{
    if (results->data_empty_offset >= results->data_size) {
        fprintf(stderr, "[ERROR] Inresults array overrun, allocated only for %d\n", results->data_size);
        fflush(stderr);
        exit(1);
    }
    memcpy(results->data + LARGEST_DATA_ELEM * results->data_empty_offset, data, size * sizeof(float));
    return results->data_empty_offset++;
}


float *inresults_get(inresults_t *results, uint32_t offset) {
    if (results->data_empty_offset >= offset) {
        fprintf(stderr, "[ERROR] Inresults trying to fetch non-initialized data at %d, only up to %d available\n", offset, (results->data_empty_offset - 1));
        fflush(stderr);
        exit(1);
    }
    return results->data + LARGEST_DATA_ELEM * offset;
}