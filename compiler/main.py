"""
Compiler is explicitely designed for testing and iterations over the design,
the C version will be too cumbersome to iterate over designs quickly
"""

from parser.parser import Parser

source_code = ""
with open("vertex_shader.nir", "r") as file:
    source_code = file.read()

Parser().parse(source_code)
