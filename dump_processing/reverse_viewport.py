HEIGHT = 768
WIDTH = 1024


def reverse_viewport(x, y):
    return (2 * x / WIDTH - 1, 2 * y / HEIGHT - 1)


def viewport(u, v):
    return ((u + 1) * WIDTH / 2, (v + 1) * HEIGHT / 2)


core_position = [
    -3.3026556968688965,
    -1.6052165031433105,
    3.6104564666748047,
    7.444182395935059,
]
core_position = [x / core_position[-1] for x in core_position]
print(core_position)
print(f"VIEWPORT: {viewport(core_position[0], core_position[1])}")
