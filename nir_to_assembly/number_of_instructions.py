import matplotlib.pyplot as plt

labels = ["NIR", "Транспиляция", "Оптимизация", "Генератор кода", "Ассемблер"]
values = [134, 207, 201, 212, 214]

# Создание столбчатой диаграммы
fig, ax = plt.subplots(figsize=(7, 4))
ax.bar(labels, values, color="C0", edgecolor="black")

# Подписи и сетка
ax.set_xlabel("Фазы компиляции")
ax.set_ylabel("Количество инструкций")
ax.grid(axis="y", linestyle="--", alpha=0.5)

# Подписи значений над столбцами
for i, v in enumerate(values):
    ax.text(i, v, str(v), ha="center", va="bottom")

plt.tight_layout()
plt.show()
