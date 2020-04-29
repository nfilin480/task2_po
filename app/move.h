#ifndef MOVE_H
#define MOVE_H

#include "text/text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/*Перемещение курсора*/
int move(text txt, int line, int col);

#endif // MOVE_H
