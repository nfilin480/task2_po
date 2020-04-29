/**
 * remove_all.cpp -- реализует функцию очистки текста
 *
 * Copyright (c) 2017, Filin Nikolay <nfilin@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

void remove_all(text txt)
{
    /* Проверяем, имеется ли текст */
    if (txt == NULL) {
        fprintf(stderr, "The text doesn't exist!\n");
        return;
    }
    /*Удаляем весь текст*/
    txt->lines.erase(txt->lines.begin(), txt->lines.end() );

}
