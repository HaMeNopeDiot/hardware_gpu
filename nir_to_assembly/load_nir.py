"""
decl_var shader_in INTERP_MODE_NONE none vec4 in_position (VERT_ATTRIB_GENERIC0.xyzw, 0, 0)
decl_var shader_in INTERP_MODE_NONE none vec4 in_color (VERT_ATTRIB_GENERIC1.xyzw, 1, 0)
decl_var shader_in INTERP_MODE_NONE none vec3 in_normal (VERT_ATTRIB_GENERIC2.xyz, 2, 0)
decl_var shader_out INTERP_MODE_NONE none vec4 .gl_Position (VARYING_SLOT_POS.xyzw, 0, 0)
decl_var shader_out INTERP_MODE_NONE none vec4 vVaryingColor (VARYING_SLOT_VAR0.xyzw, 1, 0)
"""

source_code = ""
with open("PREPARSED_MESA_SHADER_VERT", "r") as file:
    source_code = file.read()

lark_grammar = ""
with open("lark.g4", "r") as file:
    lark_grammar = file.read()

from assembler import Assembler
from basic_block_generation import BasicBlockGenerator
from lark import Lark
from nir_visitor import NirCodeLoader
from optimizer import Optimizer
from transpiler import Transpiler

parser = Lark(lark_grammar, ambiguity="explicit")
# print(parser.parse(source_code).pretty())
source_code = NirCodeLoader().transform(parser.parse(source_code))
target_code = Transpiler().transpile(source_code)
target_code = Optimizer().optimize(target_code)


generator = BasicBlockGenerator()
target_code = generator.generate(target_code)


for i in range(len(target_code)):
    print(f"{i:04} : {target_code[i]}")


# print("\n\n")
# print(f"Storage Registers: \n{generator.storage_registers}")
# print(f"Storage memory: \n{generator.storage_memory}")
# print(f"Storage stack: \n{generator.storage_stack}")
# for i in range(len(generator.registers)):
#     print(f"{i:<2} {generator.registers[i]}")
# print(generator.density_history)

assembler = Assembler()
result = assembler.assemble(target_code)
with open("vertex_shader.bin", "bw") as file:
    file.write(result)
with open("vertex_shader.mem", "w") as file:
    file.write(assembler.text)
