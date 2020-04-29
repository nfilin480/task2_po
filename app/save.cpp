/**
 * save.cpp -- функция загрузки текста из файла
 *
 * Copyright (c) 2020, Filin Nikolay <nfilin@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "load.h"
#include "text/text.h"
#include <assert.h>
#include <stdio.h>

static void save_line(int index, string contents, int cursor, void *data);


int save(text txt, char *filename)
{
    FILE *f;

    /* Открываем файл для письма, контролируя ошибки */
    if ((f = fopen(filename, "w")) == NULL) {
        printf("The file %s cannot be opened\n", filename);
        return 0;
    }

    /* Применяем функцию save_line к каждой строке текста */
   process_forward(txt, save_line, (void*)f);

   fclose(f);
   return 1;
}
static void save_line(int index, string contents, int cursor, void *data)
{
    FILE *f = (FILE*)data;

    /* Функция обработчик всегда получает существующую строку */
    assert(!(contents.empty()));

    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);

    /* Выводим строку на экран */
    fprintf(f,"%s", contents.c_str());
}


