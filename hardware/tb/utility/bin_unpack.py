#------------------------------------------------------------------------------#
# Author:                Starukhin Danila M.
# Author's e-mail:       sniperusus2002@gmail.com
# -----------------------------------------------------------------------------#
# Purpose: Binary unpacking function
# Date: 2026/06
#------------------------------------------------------------------------------#

import struct


# for binary values
def unpack_bin_file(path) -> list:
    with open(path, "rb") as f:
        raw_data = f.read()

    # Отрезаем лишние байты, если длина не кратна 4
    count = len(raw_data) // 4
    raw_data = raw_data[:count * 4]

    # '<I' = little-endian, unsigned int
    words = struct.unpack('<' + 'I' * count, raw_data)
    return words

# for heximial
def read_vbuffer(filename):
    values = []
    try:
        with open(filename, 'r', encoding='utf-8') as f:
            for line in f:
                line = line.strip()

                # Пропускаем пустые строки и комментарии
                if not line or line.startswith('//'):
                    continue

                # Разбиваем строку на части по пробелам
                parts = line.split()

                for part in parts:
                    # На всякий случай проверяем, не является ли часть комментарием
                    if part.startswith('//'):
                        break

                    if part is not None:
                        values.append(part)
    except FileNotFoundError:
        print(f"Файл {filename} не найден.")
        return []

    return values