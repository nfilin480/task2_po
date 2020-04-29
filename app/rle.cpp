/**
 * rle.cpp -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2017, Filin Nikolay <nfilin@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "load.h"
#include "text/text.h"
#include <string.h>
#include <iostream>
#include <assert.h>
#include <stdio.h>

static void rle_line(int index, string contents, int cursor, void *data);

int rle(text txt)
{
   int flag = rle_str(txt);
   /* Применяем функцию rle_line к каждой строке текста и удаляем текст после курсора*/
   process_forward(txt, rle_line, NULL);
   cout << flag;
   return flag;
}

static void rle_line(int index, string contents, int cursor, void *data)
{
    /*Получаем на вход существующую строку*/
    assert(!(contents.empty()));

    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(data);

    int a = 0;
    int i = 0;
    /* Выводим строку на экран */
        if (cursor != -1) {
                while (i != cursor){
                        if ((a = contents.size()) == cursor && i + 1 == cursor) a = -1; else
                        cout << contents.substr(i, 1);
                        i++;
                }
                        printf("|");
			printf("\n");
        } else cout << contents.substr(i, contents.size());
}


