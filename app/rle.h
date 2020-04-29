#ifndef RLE_H
#define RLE_H

#include "text/text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/*Удаляет символы справа от курсора*/
int rle(text txt);

#endif // RLE_H
