import numpy as np

STRUCTURE = {
    "modelView": {"elems": 4, "type": "vec4"},
    "modelViewProjection": {"elems": 4, "type": "vec4"},
    "normals": {"elems": 3, "type": "vec4"},
    "in_position": {"elems": 24, "type": "vec3"},
    "in_color": {"elems": 24, "type": "vec3"},
    "in_normal": {"elems": 24, "type": "vec3"},
}


def dump_contents(file, dump, struct=STRUCTURE, elem_size=4):
    output_offset = 0
    input_offset = 0
    for key, value in struct.items():
        file.write(f"// {key}\n")
        for i in range(value["elems"]):
            if value["type"] == "vec3":
                file.write(
                    f"{dump[input_offset]} {dump[input_offset + 1]} {dump[input_offset + 2]} 3f800000 // 0x{output_offset * elem_size:04x}\n"
                )
                input_offset += 3
                output_offset += 4
            elif value["type"] == "vec4":
                file.write(
                    f"{dump[input_offset]} {dump[input_offset + 1]} {dump[input_offset + 2]} {dump[input_offset + 3]} // 0x{output_offset * elem_size:04x}\n"
                )
                input_offset += 4
                output_offset += 4

        file.write("\n\n")


dump = []
with open("input_data_dump", "r") as file:
    dump = file.read()[:-1].split(" ")


dump = list(map(lambda x: "00000000" if x == "0" else x, dump))


with open("output_data_dump", "w") as file:
    dump_contents(file, dump)
