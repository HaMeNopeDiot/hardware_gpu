import re
import sys
import os

from extract_header import extract_header, give_char_fill_from_header, give_header_borders

def extract_port_block(raw_content):
    """
    Извлекает текст блока портов: ) ( ... );
    Возвращает список строк этого блока.
    """
    # Ищем начало: закрывающая скобка параметров, затем открывающая скобка портов
    # Ре: ) ( ... );
    # Используем non-greedy поиск до первой закрывающей скобки в конце
    match = re.search(r'\)\s*\(\s*(.*?)\s*\);', raw_content, re.DOTALL)
    if match:
        return match.group(1).splitlines()
    return []

def parse_verilog_module_with_headers(raw_content):
    """
    Парсит модуль, сохраняя структуру заголовков.
    Возвращает список словарей, где каждый порт имеет поле 'headers' (список строк-заголовков над ним).
    """
    port_block_lines = extract_port_block(raw_content)

    ports = []
    current_headers = []
    max_name_len = 0

    # Паттерн для поиска порта (аналогичен предыдущему, но без очистки текста)
    # Важно: мы ищем порт в "грязном" тексте, но заголовки обрабатываем отдельно
    port_pattern = re.compile(
        r'\b(input|output|inout)\s+([\w\s]+(?:\[\s*.*?\s*\])*)\s+(\w+)\s*(?:,|\))?',
        re.IGNORECASE
    )

    # Паттерн для заголовков (комментарии)
    # Ищем строки, начинающиеся с /* или //, которые не являются частью объявления порта
    header_pattern = re.compile(r'^\s*(/\*.*?\*/|//.*$)', re.MULTILINE)

    for line in port_block_lines:
        # 1. Проверяем, является ли строка заголовком
        header_match = header_pattern.match(line)
        if header_match:
            # Если это заголовок, добавляем его в текущий список
            # Сохраняем оригинальную строку (без лишних пробелов в начале, если нужно, или с ними для красоты)
            current_headers.append(line.strip())
            continue

        # 2. Проверяем, является ли строка объявлением порта
        port_match = port_pattern.search(line)
        if port_match:
            direction = port_match.group(1)
            port_type = port_match.group(2).strip()
            port_name = port_match.group(3)

            # Определяем стрелку
            if direction.lower() == 'input':
                arrow = '<-'
                direction_str = 'input'
            elif direction.lower() == 'output':
                arrow = '->'
                direction_str = 'output'
            else:
                arrow = '<->'
                direction_str = 'inout'

            # Сохраняем порт с его заголовками
            ports.append({
                'name': port_name,
                'type': port_type,
                'direction': direction_str,
                'arrow': arrow,
                'headers': list(current_headers) # Копия текущего списка заголовков
            })

            # Обновляем максимальную длину имени для выравнивания
            if len(port_name) > max_name_len:
                max_name_len = len(port_name)

        # Если строка пустая или не порт и не заголовок, можно сбросить заголовки?
        # Обычно в Verilog заголовки идут сразу перед портами.
        # Если встречается пустая строка между заголовком и портом, обычно заголовки сохраняются.
        # Но если между портами есть пустая строка без новых заголовков, старые заголовки не должны повторяться.
        # Логика: сбрасываем заголовки, если мы встретили порт и он не был сгруппирован?
        # В текущей логике: если мы нашли порт, мы сохраняем текущий список.
        # Для следующего порта, если он идет сразу после (или после пустой строки), мы продолжим использовать старые заголовки?
        # Обычно заголовки привязаны к группе. Если между портами нет новых заголовков, они не должны повторяться.
        # Поэтому: после добавления порта, очищаем список, если следующий элемент не заголовок?
        # Нет, правильнее: очистим заголовки, только если мы видим, что следующий блок — это новый заголовок.
        # Но проще: очистим заголовки после каждого порта, ЕСЛИ мы не находим новый заголовок сразу после.
        # Однако, в вашем примере:
        # /* HEADER */
        # input a
        # input b
        # /* NEW HEADER */
        # input c

        # Если мы очистим заголовки после 'a', то у 'b' их не будет.
        # Значит, мы НЕ должны очищать заголовки после порта.
        # Мы должны очищать заголовки только когда находим НОВЫЙ заголовок (что мы уже делаем: append).
        # Но проблема: если между портами пустая строка, мы не сбрасываем.
        # Если между портами нет заголовков, 'b' получит те же заголовки, что и 'a'. Это верно для вашей структуры.
        pass

    # Если в конце остались заголовки без портов, игнорируем их.

    return {
        'name': None, # Имя модуля будем искать отдельно или из контекста
        'params': {}, # Параметры пока не парсим в этой функции, можно добавить отдельно
        'ports': ports,
        'max_port_len': max_name_len
    }

def parse_full_module(content):
    """
    Основная функция парсинга: имя, параметры, порты с заголовками.
    """
    # 1. Имя модуля (без комментариев)
    clean_content = re.sub(r'/\*.*?\*/', '', content, flags=re.DOTALL)
    clean_content = re.sub(r'//.*$', '', clean_content, flags=re.MULTILINE)

    module_match = re.search(r'\bmodule\s+(\w+)', clean_content)
    module_name = module_match.group(1) if module_match else "unknown"

    # 2. Параметры (без комментариев)
    param_pattern = r'\bparameter\s+(?!type\s+)(?:[\w\s\[\]:\-]+?)\s+(\w+)\s*=\s*([^\n,;]+)'
    params = re.findall(param_pattern, clean_content)
    param_dict = {name: val.strip() for name, val in params}

    # 3. Порты с заголовками (с комментариями)
    ports_data = parse_verilog_module_with_headers(content)

    return {
        'name': module_name,
        'params': param_dict,
        'ports': ports_data['ports'],
        'max_port_len': ports_data['max_port_len']
    }

def generate_instance_template(module_info, instance_name="inst_name", instance_w=63, extra_tab=False):
    """
    Генерирует шаблон с умным выводом заголовков.
    """
    tab_str = " " * 4
    lines = []

    # Заголовок модуля
    module_name = module_info['name'].upper().replace('_', ' ')
    border_len = instance_w - 6
    border_str = "/" * border_len
    module_len = len(module_name)
    left_pad = int((instance_w - 14 - module_len) / 2)
    right_pad = instance_w - 14 - module_len - left_pad

    if extra_tab:
        lines.append(f"{tab_str}// {border_str} //")
        lines.append(f"{tab_str}// {' ' * left_pad}*** {module_name} ***{' ' * right_pad} //")
        lines.append(f"{tab_str}// NOTE: write a purpose here")
    else:
        lines.append(f"// {border_str} //")
        lines.append(f"// {' ' * left_pad}*** {module_name} ***{' ' * right_pad} //")
        lines.append(f"// NOTE: write a purpose here")

    # Параметры
    tabs_inst = f"{tab_str}" if extra_tab else ""
    if module_info['params']:
        max_p_len = max(len(k) for k in module_info['params'].keys())
        lines.append(f"{tabs_inst}{module_info['name']} #(")
        index = 0
        params_cnt = len(module_info['params'])
        for p_name, p_val in module_info['params'].items():
            comma = ","
            if index == params_cnt - 1:
                comma = ""
            index += 1
            shift = " " * (max_p_len - len(p_name) + 1)
            lines.append(f"{tabs_inst}{tab_str}.{p_name}{shift}({p_val}){comma}")
        lines.append(f"{tabs_inst}) {instance_name} (")
    else:
        lines.append(f"{tabs_inst}{module_info['name']} {instance_name} (")

    # Порты с заголовками
    max_p_len = module_info['max_port_len']

    prev_headers = [] # Список заголовков предыдущего порта

    # Дефолтный заголовок, если их нет
    has_any_headers = any(p['headers'] for p in module_info['ports'])
    if not has_any_headers:
        default_header = "/*============================### COMMON SIGNALS ###=============================*/"
        for port in module_info['ports']:
            port['headers'] = [default_header]

    port_cnt = len(module_info['ports'])
    index = 0
    for port in module_info['ports']:
        current_headers = port['headers']

        # Логика вывода новых заголовков
        headers_to_print = []

        if not prev_headers:
            # Первый порт - выводим все его заголовки
            headers_to_print = current_headers
        else:
            # Проверяем, является ли prev_headers префиксом current_headers
            if len(current_headers) > len(prev_headers) and current_headers[:len(prev_headers)] == prev_headers:
                # Есть продолжение - выводим только новую часть
                headers_to_print = current_headers[len(prev_headers):]
            elif current_headers != prev_headers:
                # Полная смена группы (или ошибка последовательности) - выводим всё
                headers_to_print = current_headers
            # Если равны - ничего не выводим

        # Выводим отобранные заголовки
        for header in headers_to_print:
            header_extracted = extract_header(header)
            if header_extracted != None:
                borders = instance_w - len(header_extracted) - 12 - len(tab_str)
                lborder = int(borders / 2)
                rborder = borders - lborder
                char = give_char_fill_from_header(header)
                bor_char = give_header_borders(header)
                lines.append(f"{tab_str}//{char*lborder}{bor_char * 3} {header_extracted} {bor_char * 3}{char*rborder}//")

        # Обновляем состояние для следующего порта
        prev_headers = current_headers

        # Вывод порта
        comma = ","
        if index == port_cnt - 1:
            comma = " "
        index += 1
        shift = " " * (max_p_len - len(port['name']) + 1)
        lines.append(f"{tab_str}.{port['name']}{shift}(){comma} // {port['arrow']}")

    lines.append(f"{tab_str}//{'=' * (instance_w - 8)}//")
    lines.append(f"{tabs_inst});")

    if extra_tab:
        lines.append(f"{tab_str}// {border_str} //")
    else:
        lines.append(f"// {border_str} //")

    return "\n".join(lines)

def main():
    if len(sys.argv) < 2:
        print("Использование: python generate_instance.py <file.v>")
        sys.exit(1)

    filepath = sys.argv[1]
    if not os.path.exists(filepath):
        print(f"Ошибка: Файл '{filepath}' не найден.")
        sys.exit(1)

    try:
        with open(filepath, 'r', encoding='utf-8') as f:
            content = f.read()

        module_info = parse_full_module(content)
        instance_name = f"{module_info['name']}_u"

        # Сброс статического атрибута перед генерацией
        if hasattr(generate_instance_template, 'last_headers'):
            del generate_instance_template.last_headers


        # print((module_info))
        instance_w = 63

        template = generate_instance_template(module_info, instance_name, instance_w=instance_w, extra_tab=False)

        print("-" * instance_w)
        print(f"Сгенерирован код для модуля: {module_info['name']}")
        print("Параметры:", module_info['params'])
        print(f"Портов найдено: {len(module_info['ports'])}")
        print("-" * instance_w)
        print(template)
        print("-" * instance_w)

    except Exception as e:
        print(f"Ошибка: {e}")
        import traceback
        traceback.print_exc()

if __name__ == "__main__":
    main()