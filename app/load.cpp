/**
 * load.cpp -- функция загрузки текста из файла
 *
 * Copyright (c) 2020, Filin Nikolay  <nfilin@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "text/text.h"
#include <stdio.h>
#include <fstream>
#include <iostream>

using namespace std;
void load(text txt, char *filename)
{
    FILE *f;
    char buf[MAXLINE + 1];
    //char filename[] = "/input.txt";

    /* Открываем файл для чтения, контролируя ошибки */
    if ((f = fopen(filename, "r")) == NULL){
        printf("The file cannot be opened\n");
        return;
    }

    /* Удаляем предыдущее содержимое */
    remove_all(txt);

    /* Считываем содержимое строка за строкой и загружаем*/
    while (fgets(buf, MAXLINE, f)) {
        string s = (char*) buf;
	append_line(txt, s);
    }
    fclose(f);
}
