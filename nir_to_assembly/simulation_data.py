INSTRUCTIONS = [
    "lui",
    "addi",
    "mul",
    "add",
    "lui",
    "addi",
    "addi",
    "mul",
    "add",
    "lw",
    "lw",
    "lw",
    "lw",
    "lui",
    "addi",
    "addi",
    "mul",
    "add",
    "lw",
    "lw",
    "lw",
    "lui",
    "addi",
    "addi",
    "mul",
    "add",
    "lw",
    "lw",
    "lw",
    "lui",
    "lui",
    "addi",
    "lui",
    "add",
    "lw",
    "lw",
    "lw",
    "lw",
    "addi",
    "add",
    "lw",
    "lw",
    "lw",
    "lw",
    "addi",
    "add",
    "lw",
    "lw",
    "lw",
    "lw",
    "addi",
    "add",
    "lw",
    "lw",
    "lw",
    "lw",
    "fmul",
    "fmul",
    "fmul",
    "fmul",
    "fmul",
    "fmul",
    "fmul",
    "fmul",
    "fadd",
    "fadd",
    "fadd",
    "fadd",
    "fmul",
    "fmul",
    "fmul",
    "fmul",
    "fadd",
    "fadd",
    "fadd",
    "fadd",
    "fmul",
    "fmul",
    "fmul",
    "fmul",
    "fadd",
    "fadd",
    "fadd",
    "fadd",
    "addi",
    "add",
    "lw",
    "lw",
    "lw",
    "addi",
    "add",
    "lw",
    "lw",
    "lw",
    "addi",
    "add",
    "lw",
    "lw",
    "lw",
    "fmul",
    "fmul",
    "fmul",
    "fmul",
    "fmul",
    "fmul",
    "fadd",
    "fadd",
    "fadd",
    "fmul",
    "fmul",
    "fmul",
    "fadd",
    "fadd",
    "fadd",
    "lw",
    "lw",
    "lw",
    "lw",
    "addi",
    "add",
    "lw",
    "lw",
    "lw",
    "lw",
    "addi",
    "add",
    "lw",
    "lw",
    "lw",
    "lw",
    "sw",
    "addi",
    "add",
    "lw",
    "sw",
    "lw",
    "sw",
    "lw",
    "lw",
    "fmul",
    "fmul",
    "fmul",
    "fmul",
    "fmul",
    "fmul",
    "fmul",
    "fmul",
    "fadd",
    "fadd",
    "fadd",
    "fadd",
    "fmul",
    "fmul",
    "fmul",
    "fmul",
    "fadd",
    "fadd",
    "fadd",
    "fadd",
    "fmul",
    "fmul",
    "fmul",
    "fmul",
    "fadd",
    "fadd",
    "fadd",
    "fadd",
    "fdiv",
    "fdiv",
    "fdiv",
    "fneg",
    "fneg",
    "fneg",
    "fadd",
    "fadd",
    "fadd",
    "fmul",
    "fmul",
    "fadd",
    "fmul",
    "fadd",
    "fsqrt",
    "fdiv",
    "fdiv",
    "fdiv",
    "fmul",
    "fmul",
    "fadd",
    "fmul",
    "fadd",
    "fmax",
    "fmul",
    "fmul",
    "fmul",
    "lui",
    "lui",
    "addi",
    "addi",
    "mul",
    "add",
    "sw",
    "sw",
    "sw",
    "sw",
    "lui",
    "addi",
    "mul",
    "add",
    "sw",
    "lw",
    "sw",
    "lw",
    "sw",
    "lw",
    "sw",
    "ret",
]

TOTAL_EXECUTION_TIME = {
    "addi": 5,
    "lui": 5,
    "mul": 5,
    "add": 5,
    "lw": 20,
    "fadd": 5,
    "fmul": 5,
    "fdiv": 17,
    "fsqrt": 17,
    "fneg": 5,
    "fmax": 5,
    "sw": 20,
    "ret": 5,
}


import matplotlib.pyplot as plt
import numpy as np

plt.figure()

execution_time = [0]
i = 0
for instr in INSTRUCTIONS:
    execution_time.append(execution_time[i] + TOTAL_EXECUTION_TIME[instr])
    i += 1
print(f"Total execution time: {execution_time[-1]} (clk periods)")

plt.plot(execution_time, linestyle="-", color="C0")
plt.ylabel("Время (период тактового сигнала)")
plt.xlabel("Номер инструкции")
plt.grid(True)
plt.tight_layout()
plt.show()


########################################################################
EXEC_STAGE_CONTRIBUTION = {
    "addi": 1,
    "lui": 1,
    "mul": 1,
    "add": 1,
    "lw": 16,
    "fadd": 1,
    "fmul": 1,
    "fdiv": 13,
    "fsqrt": 13,
    "fneg": 1,
    "fmax": 1,
    "sw": 16,
    "ret": 1,
}

stages_execution_time = {
    "fetch": 2 * len(INSTRUCTIONS),
    "decode": len(INSTRUCTIONS),
    "exec": np.sum([EXEC_STAGE_CONTRIBUTION[code] for code in INSTRUCTIONS]),
    "store": len(INSTRUCTIONS),
}

labels = list(stages_execution_time.keys())
values = list(stages_execution_time.values())

# Создание столбчатой диаграммы
fig, ax = plt.subplots(figsize=(7, 4))
ax.bar(labels, values, color="C0", edgecolor="black")

# Подписи и сетка
ax.set_xlabel("Стадии fetch-execute цикла")
ax.set_ylabel("Вклад по времени (в периодах тактового сигнала)")
ax.grid(axis="y", linestyle="--", alpha=0.5)

# Подписи значений над столбцами
for i, v in enumerate(values):
    ax.text(i, v, str(v), ha="center", va="bottom")

plt.tight_layout()
plt.show()


########################################################################
per_instruction_execution_time = {}
per_instruciton_count = {}
for key in TOTAL_EXECUTION_TIME.keys():
    per_instruction_execution_time[key] = TOTAL_EXECUTION_TIME[
        key
    ] * INSTRUCTIONS.count(key)
    per_instruciton_count[key] = INSTRUCTIONS.count(key)
labels = list(per_instruction_execution_time.keys())
values1 = list(per_instruction_execution_time.values())
values2 = list(per_instruciton_count.values())

# Создание столбчатой диаграммы
fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(7, 4))
ax1.bar(labels, values1, color="C0", edgecolor="black")
ax2.bar(labels, values2, color="orange", edgecolor="black")

# Подписи и сетка
ax1.set_xlabel("Тип инструкции")
ax1.set_ylabel("Вклад по времени (в периодах тактового сигнала)")
ax2.set_xlabel("Тип инструкции")
ax2.set_ylabel("Количество инструкций")
ax1.grid(axis="y", linestyle="--", alpha=0.5)

# Подписи значений над столбцами
for i, v in enumerate(values1):
    ax1.text(i, v, str(v), ha="center", va="bottom")
for i, v in enumerate(values2):
    ax2.text(i, v, str(v), ha="center", va="bottom")


plt.tight_layout()
plt.show()


########################################################################
relative_exec_time = {}
for key in TOTAL_EXECUTION_TIME.keys():
    relative_exec_time[key] = (
        TOTAL_EXECUTION_TIME[key] * INSTRUCTIONS.count(key) / execution_time[-1]
    )


labels = list(relative_exec_time.keys())
values = list(relative_exec_time.values())

# Создание столбчатой диаграммы
fig, ax = plt.subplots(figsize=(7, 4))
ax.bar(labels, values, color="C0", edgecolor="black")

# Подписи и сетка
ax.set_xlabel("Тип инструкции")
ax.set_ylabel("Относительный вклад в время исполнения")
ax.grid(axis="y", linestyle="--", alpha=0.5)


plt.tight_layout()
plt.show()
