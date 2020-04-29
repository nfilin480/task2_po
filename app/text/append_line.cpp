/**
 * append_line.cpp -- создает в памяти структуры для представления текста
 *
 * Copyright (c) 2020, Filin Nikolay <nfilin@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

void append_line(text txt, string contents)
{
  /*Добавление строки в конец*/
  txt->lines.push_back(contents);

  /*Задание курсора*/
  txt->cursor->line = --(txt->lines.end());
  txt->cursor->pos = contents.size();
}


