/**
 * text.h -- внешний интерфейс библиотеки для работы с текстом
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef TEXT_H
#define TEXT_H

#define MAXLINE 255

#include <list>
#include <string>

using namespace std;

/*Абстракция структур*/
typedef struct _crsr *cursor;
typedef struct _list *text;

/*Добавление строк в конец*/
void append_line(text txt, string contents);

/*Выделение памяти и установка курсора в конец*/
text create_text();

/*Обработка строк*/
void process_forward(text txt,
    void (*process)(int index, string contents, int cursor_position, void *data),
    void *data);

/*Новая позиция курсора*/
int move_cursor(text txt, int str, int col);

/*Удаление символов после курсора*/
int rle_str(text txt);

/*Удаление*/
void remove_all(text txt);

/*Перемещение строк*/
int swap(text txt);

#endif
