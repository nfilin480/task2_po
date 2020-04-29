/**
 * move.cpp -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2020, Filin Nikolay <nfilin@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <iostream>
#include "load.h"
#include "text/text.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>

static void show_line(int index, string contents, int cursor, void *data);

int move(text txt, int str, int col)
{
    /* Меняем позицию курсора и выводим*/
    int flag = move_cursor(txt, str, col);

    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, show_line, NULL);
    return flag;
}

static void show_line(int index, string contents, int cursor, void *data)
{

    /*Получаем всегда существующую строку*/
     assert(!(contents.empty()));

    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(data);

    int a = 0;
    int i = 0;

    /* Выводим строку на экран */
        if (cursor != -1) {
                while (i != cursor) {
                        if ((a = contents.size()) == cursor && i + 1 == cursor) a = -1;

                        else    std::cout << contents.substr(i, 1);

                        i++;
                }
                        printf("|");
                        std::cout << contents.substr(i, contents.size());
                        if (a==-1) printf ("\n");
        } else std::cout << contents.substr(0, contents.size() - 1) << std::endl;
}

