#ifndef PENCIL_H
#define PENCIL_H

#include <windows.h>
#include "console_v1.5.3.h"

typedef struct{
	int status;
	COLORREF cor;
}PIXEL;

typedef struct INFO_PINCEL
{
	COORD pos;
	int mode;
	int size;
	COLORREF cor;
} INFO_PINCEL;

void inic_pincel(INFO_PINCEL *pincel, COORD *initial, COORD *final);
void pos_pencil(INFO_PINCEL *pincel, COORD *initial, COORD *final, int key);
void resize_pencil(INFO_PINCEL *pincel, int state, COORD *size, COORD *initial);
void seta(INFO_PINCEL *pincel, COORD *initial, COORD *final, int key, COORD *size, PIXEL **pixels);

#endif

