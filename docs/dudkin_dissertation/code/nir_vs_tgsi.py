import matplotlib.pyplot as plt
import numpy as np


# first of tuple - stock
# second of tuple - nir
test_results = {
    'BioShock Infinite': (150, 160),
    'Deus Ex: Mankind Divided': (42.3, 41.0),
    'DiRT Showdown': (269, 267),
    'Dota 2': (110, 113),
    'Dawn of War III': (81.69, 83.25),
    'HITMAN': (89.68, 89.99),
    'Metro: Last Light Redux': (92.75, 92.89),
    'OpenArena': (397, 391),
    'Portal': (491, 504),
    'SuperTuxKart': (196, 202),
    'Tesseract': (348, 339),
    'Tomb Raider': (121, 121),
    'GpuTest TessMark': (15924, 16175),
    'GpuTest Pixmark Piano': (870, 894),
    'GpuTest Pixmark Volplosion': (2069, 2153),
}


def boost_percentage(tests: dict[str, tuple(float, float)]) -> dict[str, float]:
    result = {}
    for app, fps in tests.items():
        result.update({app: fps[1]/fps[0] * 100 - 100})
    return result


def average_boost_percentage(tests: dict[str, tuple(float, float)]) -> float:
    result = 0
    for percentage in tests.values():
        result += percentage
    return result / len(tests.values())


without_gpu_test = {k: test_results[k] for k in test_results.keys() - {'GpuTest TessMark', 'GpuTest Pixmark Piano', 'GpuTest Pixmark Volplosion'}}

stock = []
nir = []
width = 0.4
x = np.arange(len(without_gpu_test.keys()))
for game, fps in without_gpu_test.items():
    stock.append(fps[0])
    nir.append(fps[1])

plt.figure(1)
plt.rcParams.update({'font.size': 6})
plt.grid(True, color='#cccccc')
plt.bar(x - 0.2, stock, width)
plt.bar(x + 0.2, nir, width)
plt.xticks(x, without_gpu_test.keys())
plt.xlabel('Игры')
plt.ylabel('Кадры в секунду, fps')
plt.legend(['TGSI', "NIR"])
plt.show()


plt.figure(2)
plt.rcParams.update({'font.size': 6})
plt.grid(True, color='#cccccc')
x = np.arange(len(test_results.keys()))
percentages = boost_percentage(test_results)
plt.bar(x, percentages.values(), width)
plt.xticks(x, test_results.keys())
plt.xlabel('Игры')
plt.ylabel('Процент изменения количества кадров в секунду, %')
plt.show()

print('Средний прирост производительности')
print(average_boost_percentage(percentages))
