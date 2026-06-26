// the grammar is written such that any deviation from the original (which probably means an unhandled condition)
// will result in an error


start: header declarations implementations

header: shader_type\
        blake3_hash\
        num_ubos\
        inputs_read\
        outputs_read\
        api_subgroup_size\
        max_subgroup_size\
        min_subgroup_size\
        bit_sizes_float\
        bit_sizes_int\
        flrp_lowered\
        inputs\
        outputs

shader_type: "shader" ":" SHADER_TYPE
blake3_hash: "source_blake3" ":" "{" HEX_NUMERAL "," HEX_NUMERAL "," HEX_NUMERAL "," HEX_NUMERAL "," HEX_NUMERAL "," HEX_NUMERAL ","\
    HEX_NUMERAL "," HEX_NUMERAL"}"
num_ubos: "num_ubos" ":" "1"
inputs_read: "inputs_read" ":" "15" "-" "17"

outputs_read: "outputs_written" ":" "0" "," "32"
api_subgroup_size: "api_subgroup_size" ":" "8"
max_subgroup_size: "max_subgroup_size" ":" "8"
min_subgroup_size: "min_subgroup_size" ":" "8"

bit_sizes_float: "bit_sizes_float" ":" "0x20"
bit_sizes_int: "bit_sizes_int" ":" "0x20"
flrp_lowered: "flrp_lowered" ":" "true"
inputs: "inputs" ":" "18"
outputs: "outputs" ":" "2"


// DECLARATIONS
declarations: (decl_var | decl_function)+

decl_var: "decl_var" (var_shader_in | var_shader_out | var_ubo)

var_shader_in: "shader_in" "INTERP_MODE_NONE" "none" VAR_TYPE IDENTIFIER "(" ATTRIBUTE_GENERIC "." ATTRIBUTE_SUBSCRIPTS "," DEC_NUMERAL "," "0" ")"
var_shader_out: "shader_out" "INTERP_MODE_NONE" "none" VAR_TYPE IDENTIFIER "(" ATTRIBUTE_VARYING "." ATTRIBUTE_SUBSCRIPTS "," DEC_NUMERAL "," "0" ")"
var_ubo: "ubo" "INTERP_MODE_NONE" "none" "block" "#0" "(" "~0" "," "0" "," "0" ")"

decl_function: "decl_function" "main" "()" "(entrypoint)"


// IMPLEMENTATIONS
implementations: function


function: "impl" IDENTIFIER "{" code_block+ "}"

code_block: "block" IDENTIFIER ":" ("//" "preds" ":" IDENTIFIER?)? instr* ("//" "succs" ":" IDENTIFIER)?

instr: instr_with_retval | instr_without_retval
instr_without_retval: storage_deref

instr_with_retval: STORAGE_SIZE STORAGE_IDENTIFIER "=" operation
operation: deref_var
         | load_deref
         | load_const
         | load_const_buf_base_addr_lvp
         | load_ubo
         | fmul
         | fadd
         | fdiv
         | fneg
         | fsqrt
         | fmax
         | vec4


deref_var: "deref_var" "&" IDENTIFIER "(" ("shader_in" | "shader_out") VAR_TYPE ")"
load_deref: "@load_deref" "(" STORAGE_IDENTIFIER ")" "(" "access" "=" "none" ")"
load_const: "load_const" "(" list_hex_numerals ")" "=" "(" list_fp_numerals ")"
          | "load_const" "(" HEX_NUMERAL "=" (FP_NUMERAL | DEC_NUMERAL) ")"

load_const_buf_base_addr_lvp: "@load_const_buf_base_addr_lvp" "(" expanded_storage_identifier ")"
load_ubo: "@load_ubo" "(" STORAGE_IDENTIFIER "," notated_storage_identifier ")" "(access=in-bounds, align_mul=4, align_offset=0, range_base=" DEC_NUMERAL ", range=" DEC_NUMERAL ")"

fmul: "fmul" notated_storage_identifier "," notated_storage_identifier
fadd: "fadd" notated_storage_identifier "," notated_storage_identifier
fdiv: "fdiv" notated_storage_identifier "," notated_storage_identifier
fneg: "fneg" notated_storage_identifier
fsqrt: "fsqrt" notated_storage_identifier
fmax: "fmax" notated_storage_identifier "," notated_storage_identifier

vec4: "vec4" notated_storage_identifier "," notated_storage_identifier "," notated_storage_identifier "," notated_storage_identifier

storage_deref: "@store_deref" "(" STORAGE_IDENTIFIER "," STORAGE_IDENTIFIER ")" "(wrmask=xyzw, access=none)"


// COMMON
notated_storage_identifier: expanded_storage_identifier ("." SUBSCRIPT)?
expanded_storage_identifier: STORAGE_IDENTIFIER ("(" (list_fp_numerals | list_hex_numerals) ")")?

list_hex_numerals: (HEX_NUMERAL ",")* HEX_NUMERAL
list_dec_numerals: (DEC_NUMERAL ",")* DEC_NUMERAL
list_fp_numerals: (FP_NUMERAL ",")* FP_NUMERAL

// TERMINALS

SHADER_TYPE: "MESA_SHADER_VERTEX"
VAR_TYPE: "vec3" | "vec4"

IDENTIFIER: /[a-zA-Z_][a-zA-Z0-9_]*|\.gl_Position/

HEX_NUMERAL: /0x[0-9a-fA-F]+/
DEC_NUMERAL: /[0-9]+/
FP_NUMERAL: /[0-9]+(\.[0-9]+)?/

ATTRIBUTE_GENERIC: /VERT_ATTRIB_GENERIC\d+/
ATTRIBUTE_SUBSCRIPTS: "xyz" | "xyzw"
ATTRIBUTE_VARYING: /VARYING_SLOT_POS|VARYING_SLOT_VAR\d+/

STORAGE_SIZE: DEC_NUMERAL ("x" DEC_NUMERAL)?
STORAGE_IDENTIFIER: /%[0-9]+/
SUBSCRIPT: "x" | "y" | "z" | "w"

WHITESPACE: " " | "\n" | "\t"
%ignore WHITESPACE
