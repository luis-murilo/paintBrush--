#ifndef	DRAW_H
#define DRAW_H

#include <windows.h>
#include <stdio.h>
#include "graphics.h"
#include "console_v1.5.3.h"

typedef struct
{
	COORD pos;
	COLORREF cor;
}PIXEL;

void pintar(PIXEL **pixels, COORD *pencil_pos, int *mode, COLORREF cor, int key, int *pencil_size);

#endif

