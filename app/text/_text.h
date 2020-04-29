/**
 * _text.h -- внутренние структуры представления текста
 *
 * Этот файл не должен включаться в клиентские модули
 *
 * Copyright (c) 2020, Filin Nikolay  <nfilin@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef _TEXT_H
#define _TEXT_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <list>
#include "text.h"

using namespace std;

/*Структура строки*/
struct _list {
	struct _crsr *cursor;
        list <string> lines;
};

/*Структура курсора*/
struct _crsr {
	int pos;
	list <string> :: iterator line;
};

#endif
