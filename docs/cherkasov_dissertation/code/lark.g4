
start: instruction+

instruction: size DEPENDENCY "=" opcode_and_arguments

size: /[0-9]+(x[0-9]+)?/

opcode_and_arguments: deref_var
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
    | store_deref


deref_var: "deref_var" PARAMETER "(" ("shader_in" | "shader_out") ("vec3" | "vec4") ")"
load_deref: "@load_deref" "(" notated_dependency ")" "(access=none)"
load_const: "load_const" "(" list_of_literals ")" "=" "(" list_of_literals ")"
    | "load_const" "(" LITERAL "=" LITERAL ")"

load_const_buf_base_addr_lvp: "@load_const_buf_base_addr_lvp" "(" notated_dependency ")"
load_ubo: "@load_ubo" "(" notated_dependency "," notated_dependency ")"  "(access=in-bounds, align_mul=" LITERAL ", align_offset=" LITERAL ", range_base=" LITERAL ", range=" LITERAL ")"
fmul: "fmul" notated_dependency "," notated_dependency
fadd: "fadd" notated_dependency "," notated_dependency
fdiv: "fdiv" notated_dependency "," notated_dependency
fneg: "fneg" notated_dependency
fsqrt: "fsqrt" notated_dependency
fmax: "fmax" notated_dependency "," notated_dependency
store_deref: "vec4" notated_dependency "," notated_dependency "," notated_dependency "," notated_dependency "@store_deref" "(" notated_dependency "," notated_dependency ")" "(wrmask=xyzw, access=none)"


notated_dependency: expanded_dependency | expanded_dependency  "." SUBSCRIPT
list_of_literals: list_of_literals "," LITERAL | LITERAL

expanded_dependency: DEPENDENCY ("(" list_of_literals ")")?

DEPENDENCY: /%[0-9]+/
PARAMETER: /&[a-z_A-Z]+|&\.gl_Position/
LITERAL: /0x[0-9a-fA-F]+|[0-9]+.[0-9]+|[0-9]+/
SUBSCRIPT: "x" | "y" | "z" | "w"

WHITESPACE: " " | "\n" | "\t"
%ignore WHITESPACE
