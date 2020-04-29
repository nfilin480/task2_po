#ifndef CP_H
#define CP_H

#include "text/text.h"
#include "load.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/*Перемещение строк*/
int cp(text txt);

#endif // CP_H
