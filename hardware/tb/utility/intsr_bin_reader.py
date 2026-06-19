hex_string = "30 00 01 00 60 40 06 00 22 00 00 00" # Пример данных


def hex2word(hex_string):
    # 1. Убираем пробелы и преобразуем в объект bytes
    raw_data = bytes.fromhex(hex_string.replace(" ", ""))

    # 2. Разбиваем на группы по 4 байта и конвертируем
    words = []
    for i in range(0, len(raw_data) - (len(raw_data) % 4), 4):
        chunk = raw_data[i:i+4]
        # 'little' для младшего байта в начале, 'big' для старшего
        num = int.from_bytes(chunk, byteorder='little')
        words.append(num)

    print(f"Результат (десятичный): {words}")
    print(f"Результат (HEX): {[hex(w) for w in words]}")