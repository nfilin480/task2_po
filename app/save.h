#ifndef SAVE_H
#define SAVE_H

#include "text/text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

int save(text txt, char* filename);

#endif // SAVE_H
