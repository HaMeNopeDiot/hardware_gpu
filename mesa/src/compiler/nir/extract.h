#ifndef EXTRACT_H
#define EXTRACT_H

#include "nir.h"
#include "list.h"
#include "../../gallium/auxiliary/draw/draw_context.h"


struct sources_float {
    float src0;
    float src1;
};

struct sources_int {
    int src0;
    int src1;
};

typedef struct vec3_t {
    float x;
    float y;
    float z;
} vec3_t;

typedef struct dots_coordinates_t {
    vec3_t front;
    vec3_t back;
    vec3_t right;
    vec3_t left;
    vec3_t top;
    vec3_t bottom;
} dots_coordinates_t;

typedef struct sources_float sources_float;

struct vertex_header;
struct draw_vertex_buffer;

void extract_instr(nir_shader *shader);
const char* get_opname(nir_alu_instr *instr);
nir_alu_src* get_srcs(nir_alu_instr *instr);
nir_def** get_srcs_defs(nir_alu_instr* instr, nir_def **defs);
bool interpret_nir(nir_shader *nir, unsigned int count, struct vertex_header *verts, struct draw_vertex_buffer *vbuffer, unsigned int buffer_offset, unsigned int verted_id_offset, struct draw_context *draw);


#define foreach_instr_in_shader(shader, function_body)                          \
    foreach_list_typed(nir_function, func, node, &shader->functions) {          \
        if (func->impl != NULL) {                                               \
            foreach_list_typed(nir_cf_node, node, node, &(func->impl)->body) {  \
                if (node->type == nir_cf_node_block) {                          \
                    nir_block *block = nir_cf_node_as_block(node);              \
                    nir_foreach_instr(instr, block) {                           \
                        function_body                                           \
                    }                                                           \
                }                                                               \
            }                                                                   \
        }                                                                       \
    }

#endif