#ifndef INFO_LOWER_BAR_H
#define INFO_LOWER_BAR_H

#include <windows.h>
#include "conio_v3.2.1.h"

void gotoxy_correct(int x, int y, COORD *size);
void info_lower(COORD *size, COORD *pencil_pos, int pencil_size, int mode);

#endif

