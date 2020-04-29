/**
 * showtrimmedfromstart.cpp -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2020, Filin Nikolay <nfilin@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "load.h"
#include "text/text.h"
#include <cctype>
#include <string.h>
#include <iostream>
#include <assert.h>

static void showfromstart_line(int index, string contents, int cursor, void *data);

void showfromstart(text txt)
{
    /*Применяем функцию showfromstart_line к каждой строке*/
    process_forward(txt, showfromstart_line, NULL);

}

static void showfromstart_line(int index, string contents, int cursor, void *data)
{
    /*Получаем всегда существующую строку*/
    assert(!(contents.empty()));

    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);

    /*Обрабатываем строку*/
    int i = 0;
    while(isspace(contents[i]) != 0) i++;

    /* Выводим строку на экран */
    cout << contents.substr(i, contents.size());
}

