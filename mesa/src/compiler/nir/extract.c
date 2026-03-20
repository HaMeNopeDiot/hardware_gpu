#include "extract.h"

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

// bool interpret_nir(nir_shader *nir, unsigned int count, struct vertex_header *verts, struct draw_vertex_buffer *vbuffer, unsigned int buffer_offset) {

//     return false;
// }