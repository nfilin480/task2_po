/**
 * create_text.c -- создает в памяти структуры для представления текста
 *
 * Copyright (c) 2020, Filin Nikolay <nfilin@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

text create_text()
{
   /*Выделение памяти*/
   text txt = new _list;
   txt->cursor = new _crsr;

   /*Задание начальных значений*/
   txt->cursor->line = --(txt->lines.end() );
   txt->cursor->pos = txt->lines.back().size();

  return txt;
}
