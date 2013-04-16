#ifndef PENCIL_H
#define PENCIL_H

#include <windows.h>
#include <stdio.h>
#include "console_v1.5.3.h"
#include "info_lower_bar.h"
#include "draw.h"

void pos_pencil(COORD *pencil_pos, COORD *initial, COORD *final, int key);
void resize_pencil(int *pencil_size, int state, COORD *size, COORD *pencil_pos, COORD *initial, int *mode);
void seta(COORD *pencil_pos, COORD *initial, COORD *final, int key, COORD *size, int *mode, int *pencil_size);

#endif

