#ifndef SHOWTRIMMEDFROMSTART_H
#define SHOWTRIMMEDFROMSTART_H

#include "text/text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/*Вывод без ведузих пробелов*/
void showfromstart(text txt);

#endif // SHOWTRIMMEDFROMSTART_H
