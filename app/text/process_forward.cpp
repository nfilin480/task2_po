/**
 * process_forward.c -- реализует обобщенную функцию обработки текста
 *
 * Copyright (c) 2017, Filin Nikolay <nfilin@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

void process_forward(text txt,
    void (*process)(int index, string contents, int cursor, void *data),
    void *data)
{

    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->lines.size() == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return;
    }
    /*Всегда получаем существующую строку*/
    assert(!(txt->lines.empty()));

    int index = 0;
    int cursor_position = -1;

    /*Обработка*/
    for (list <string> :: iterator it = txt->lines.begin(); it != txt->lines.end(); it++) {
	if (txt->cursor->line == it) cursor_position = txt->cursor->pos; else cursor_position = -1;
	process(index, *it, cursor_position, data);
        index++;
    }
}
