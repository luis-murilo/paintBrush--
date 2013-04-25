#ifndef	DRAW_H
#define DRAW_H

#include <windows.h>
#include <stdio.h>
#include "pencil.h"
#include "info_bar.h"
#include "graphics.h"
#include "console_v1.5.3.h"

PIXEL** aloca_pixel(COORD *initial, COORD *final);
void desaloca_pixel(PIXEL **pixels, COORD *initial, COORD *final);
void status_pintar(COORD *size, INFO_PINCEL *pincel, COORD *initial);
void pintar(INFO_PINCEL *pincel, PIXEL **pixels, COORD *initial, COORD *final);

#endif

