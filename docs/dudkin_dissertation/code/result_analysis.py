import numpy as np
import matplotlib.pyplot as plt

names = [
    "video-nvidia-470xx",
    "Mesa3D lavapipe",
    "Mesa3D\nинтерпретатор NIR",
]

cpu = [
    20,
    40,
    70,
]

gpu = [
    50,
    90,
    50,
]

fps = [
    60,
    140,
    10,
]

x = np.arange(len(names))

plt.figure(1)
plt.grid(True, color="#cccccc")
plt.bar(x, cpu)
plt.xlabel("Драйвер")
plt.ylabel("Нагрузка центрального процессора, %")
plt.xticks(x, names)
plt.show()

plt.figure(2)
plt.grid(True, color="#cccccc")
plt.bar(x, gpu)
plt.xlabel("Драйвер")
plt.ylabel("Нагрузка графического ускорителя, %")
plt.xticks(x, names)
plt.show()

plt.figure(3)
plt.grid(True, color="#cccccc")
plt.bar(x, fps)
plt.xlabel("Драйвер")
plt.ylabel("Количество кадров в секунду")
plt.xticks(x, names)
plt.show()
