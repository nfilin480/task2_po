/**
 * cp_swap.cpp -- создает в памяти структуры для представления текста
 *
 * Copyright (c) 2020, Filin Nikolay <nfilin@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"
#include <iostream>

using namespace std;

int swap(text txt)
{
    /*Перемещение строки с курсором на 1 выше*/
    if (txt->cursor->line != txt->lines.begin() ){
    list <string> :: iterator it = txt->cursor->line;
    swap(*it, *it--);
    txt->cursor->line--;
    return 1;
    }
    return 0;
}
