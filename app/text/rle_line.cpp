/**
 * rle_line.cpp -- создает в памяти структуры для представления текста
 *
 * Copyright (c) 2020, Filin Nikolay <nfilin@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"


int rle_str(text txt)
{
	/*Удаление символов после курсора*/
    if (txt->cursor->pos < (int)(*(txt->cursor->line)).size() - 1){
        (*(txt->cursor->line)) = (*(txt->cursor->line)).erase(txt->cursor->pos,(*( txt->cursor->line)).size() - txt->cursor->pos - 1);
        return 1;
    }
    return 0;
}
