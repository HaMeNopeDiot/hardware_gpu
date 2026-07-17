start: operator+

operator: define | instr

define: "#define" IDENTIFIER "=" integer
instr: noop
     | ret
     | li
     | mul
     | add
     | lw
     | sw
     | lui
     | addi
     | fadd
     | fmul
     | fdiv
     | fsqrt
     | fneg
     | fmax

noop: "noop"
ret: "ret"
li: "li" register "," identifier_or_literal
mul: "mul" register "," register "," register
add: "add" register "," register "," register
lw: "lw" register "," integer "(" register ")"
sw: "sw" register "," integer "(" register ")"
lui: "lui" register "," identifier_or_literal
addi: "addi" register "," register "," identifier_or_literal
fadd: "fadd" register "," register "," register
fmul: "fmul" register "," register "," register
fdiv: "fdiv" register "," register "," register
fsqrt: "fsqrt" register "," register
fneg: "fneg" register "," register
fmax: "fmax" register "," register "," register


register: REGISTER_INDEX | REGISTER_NAMES
identifier_or_literal: IDENTIFIER | integer
integer: HEXADECIMAL | DECIMAL

IDENTIFIER: /[\.a-zA-Z_]\S+/
HEXADECIMAL: /0x[0-9a-fA-F]+/
DECIMAL: /\d+/

REGISTER_INDEX: /x[0-9]+/
REGISTER_NAMES: "sp" | "v_id" | "zero"


WHITESPACE: " " | "\n" | "\t"
%ignore WHITESPACE
%ignore /\/\/[^\n]*/
%ignore /\/\*[\s\S]*?\*\//
