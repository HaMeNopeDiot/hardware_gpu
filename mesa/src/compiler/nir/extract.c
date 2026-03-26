#include "extract.h"
#include <stddef.h>
#include <stdint.h>
#include "inresults.h"
#include "nir.h"

const char* get_opname(nir_alu_instr *instr) {
    return nir_op_infos[instr->op].name;
}

nir_alu_src* get_srcs(nir_alu_instr *instr) {
    return instr->src;
}

nir_def** get_srcs_defs(nir_alu_instr* instr, nir_def **defs) {
    for (unsigned i = 0; i < nir_op_infos[instr->op].num_inputs; i++) {
        defs[i] = instr->src[i].src.ssa;
    }
    return defs;
}

static bool exec_int(char *op_name) {
    // {
    //     printf("Unregistered operation: %s\n", op_name, stderr);
    //     return false;
    // }
    return false;
}


void extract_instr(nir_shader *shader) {
    foreach_instr_in_shader(shader, {
        if (instr->type == nir_instr_type_alu) {
            nir_alu_instr *alu_instr = nir_instr_as_alu(instr);
            printf("destination_index: %i\n", alu_instr->def.index);
            printf("opname: %s\n", get_opname(alu_instr));
            printf("srcs: ");
            nir_def **defs = (nir_def**)malloc(sizeof(nir_def*) * nir_op_infos[alu_instr->op].num_inputs);
            for (unsigned i = 0; i < nir_op_infos[alu_instr->op].num_inputs; i++) {
                printf("%i ", get_srcs_defs(alu_instr, defs)[i]->index);
            }
            free(defs);
            printf("\n");
        }
    })
}

static void nir_deref_instr_handler(nir_deref_instr * deref_instr, inresults_t* inresults, unsigned int buffer_offset, unsigned int vertex_id, struct draw_vertex_buffer *vbuffer, struct draw_context* draw) {
    if (deref_instr->deref_type != nir_deref_type_var) {
        fprintf(stderr, "Ne znayu takoi deref_type: %d\n", deref_instr->deref_type);
        exit(0);
    }
    int location = deref_instr->var->data.driver_location;
    int offset = buffer_offset;
    uint32_t *map = (uint32_t *) vbuffer->map;
    uint32_t *data_offset = map + offset / 4;
    printf("driver location: %d\n", deref_instr->var->data.driver_location);

    uint32_t * temp = data_offset + vertex_id;
    inresults_save_new(inresults, (float*)&temp, 1);
}

static void render_shader(nir_shader *nir, struct vertex_header *verts, struct draw_vertex_buffer *vbuffer, unsigned int buffer_offset, unsigned int vertex_id, inresults_t* inresults, struct draw_context *draw) {
    inresults->data_empty_offset = 0;
    foreach_instr_in_shader(nir, {
        switch (instr->type) {
            // case  nir_instr_type_alu:
            //     break;
            case nir_instr_type_deref:
                nir_deref_instr *deref_instr = nir_instr_as_deref(instr);
                nir_deref_instr_handler(deref_instr, inresults, buffer_offset, vertex_id, vbuffer, draw);
                break;
            case nir_instr_type_intrinsic:
                nir_intrinsic_instr *intrinsic_instr = nir_instr_as_intrinsic(instr);
                printf("Intrinsic: %s\n", intrinsic_instr->name);
                break;
            default:
                fprintf(stderr, "Net takoi funkcii: %d\n", instr->type);
                exit(0);

        }
    });
}

bool interpret_nir(nir_shader *nir, unsigned int count, struct vertex_header *verts, struct draw_vertex_buffer *vbuffer, unsigned int buffer_offset, unsigned int vertex_id_offset, struct draw_context *draw) {
    inresults_t inresults;
    inresults_init(&inresults, 160);
    for (size_t vertex_id = 0; vertex_id < count; vertex_id++) {
        // printf("%d\n", (int)(vertex_id + vertex_id_offset));
        render_shader(nir, verts, vbuffer, buffer_offset, vertex_id + vertex_id_offset, &inresults, draw);
    }
    inresults_destroy(&inresults);
    exit(0);
    return false;
}