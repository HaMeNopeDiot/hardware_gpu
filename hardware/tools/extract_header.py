import re


def extract_header(line: str) -> str | None:
    """
    Извлекает заголовок из строки комментария.

    Поддерживаемые форматы:
    - // ... --- HEADER --- ... //
    - // ... ### HEADER ### ... //
    - /* ... --- HEADER --- ... */
    - /* ... ### HEADER ### ... */

    Args:
        line: Строка для парсинга

    Returns:
        Извлечённый заголовок или None, если заголовок не найден
    """
    # Убираем пробелы по краям
    line = line.strip()

    # Паттерн для поиска заголовка между разделителями (--- или ###)
    # Поддерживает // ... // и /* ... */
    pattern = r'''
        (?://|/\*)           # Начало комментария: // или /*
        .*?                  # Любые символы (не жадно)
        (?:---|\#\#\#)       # Открывающий разделитель: --- или ###
        \s*                  # Пробелы
        ([A-Za-z0-9_\s]+?)   # Захватываем заголовок (буквы, цифры, пробелы, подчёркивания)
        \s*                  # Пробелы
        (?:---|\#\#\#)       # Закрывающий разделитель: --- или ###
        .*?                  # Любые символы (не жадно)
        (?://|\*/)           # Конец комментария: // или */
    '''

    match = re.search(pattern, line, re.VERBOSE)

    if match:
        # Извлекаем заголовок и убираем лишние пробелы
        header = match.group(1).strip()
        # Нормализуем пробелы (убираем множественные пробелы)
        header = re.sub(r'\s+', ' ', header)
        return header

    return None


def extract_headers_from_text(text: str) -> list[str]:
    """
    Извлекает все заголовки из многострочного текста.

    Args:
        text: Многострочный текст

    Returns:
        Список найденных заголовков
    """
    headers = []
    for line in text.split('\n'):
        header = extract_header(line)
        if header:
            headers.append(header)
    return headers


# Тестирование
if __name__ == "__main__":
    test_lines = [
        "//                           --- OUTPUT SIGNALS ---                              //",
        "//==========================### ADDITIONAL SIGNALS ###===========================//",
        "/*                           --- INPUT SIGNALS ---                              */",
        "/*==========================### CONTROL SIGNALS ###===========================*/",
        "//------------- --- DATA BUS --- -------------//",
        "/* ### POWER MANAGEMENT ### */",
        "// Обычный комментарий без заголовка",
        "//=== Не подходящий формат ===//",
    ]

    print("=" * 60)
    print("Тестирование извлечения заголовков")
    print("=" * 60)

    for line in test_lines:
        result = extract_header(line)
        print(f"\nВход:  {line[:60]}{'...' if len(line) > 60 else ''}")
        print(f"Выход: {result if result else 'Заголовок не найден'}")

    print("\n" + "=" * 60)
    print("Тест с многострочным текстом")
    print("=" * 60)

    multiline_text = """
    //                           --- OUTPUT SIGNALS ---                              //
    wire [7:0] data_out;
    wire valid;
    //==========================### ADDITIONAL SIGNALS ###===========================//
    wire clk;
    wire rst;
    /*                           --- DEBUG SIGNALS ---                              */
    """

    headers = extract_headers_from_text(multiline_text)
    print(f"\nНайденные заголовки: {headers}")


def give_char_fill_from_header(header: str) -> str:
    for char in header:
        if char != "/" and char != "*":
            return char

def give_header_borders(header: str) -> str:
    for index, char in enumerate(header):
        if char.isalpha():
            return header[index - 2]
    return None