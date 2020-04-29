/**
 * move_cursor.cpp -- создает в памяти структуры для представления текста
 *
 * Copyright (c) 2020, Filin Nikolay <nfilin@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"
#include <iostream>

int move_cursor(text txt, int str, int col)
{
    /* Проверяем, имеется ли текст */
    if (txt == NULL) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return 0;
    }
    int flag = 0;
   /*Задание значений курсора*/
   list <string> :: iterator it = txt->lines.begin();
   if (str >= 0 && txt->lines.size() > (size_t)str) {
       flag = 1;
       advance(it, str);
   } else {
       advance(it, txt->lines.size() - 1);
       flag = 0;
   }
   txt->cursor->line = it;

   if ( (*(txt->cursor->line)).size() > (size_t) col) {
       txt->cursor->pos = col;
   } else {
       txt->cursor->pos = (*(txt->cursor->line)).size();
       return 0;
   }
   return flag;
}


