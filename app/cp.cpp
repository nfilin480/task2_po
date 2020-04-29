/**
 * cp.cpp -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2020, filin Nikolay  <nfilin@petrsu.ru>
 *
 * This code is licensed under a MIT-style license*/
#include "cp.h"
#include "text/text.h"
#include <iostream>
#include <string.h>
#include <assert.h>
#include <stdio.h>

static void show_line(int index, string contents, int cursor, void *data);

int cp(text txt)
{
    int flag = swap(txt);

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
