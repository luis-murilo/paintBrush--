/*Cabecalho de paint.h*/
#ifndef PAINT_H
#define PAINT_H

#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "pencil.h"
#include "conio_v3.2.3.h"
#include "console_v1.5.3.h"
#include "window.h"
#include "interface.h"
#include "info_bar.h"
#include "draw.h"
#include "info_top_bar.h"

void check_name(char *argv[], int argc);
void area_reserv(COORD janela_pixels, COORD *initial, COORD *final);
void starts(char *argv[], int argc, COORD *orig_window, COORD *initial, COORD *final, INFO_PINCEL *pincel, COORD *size, PALETA *paletas);
void end(COORD orig_window);
void read_key(COORD *orig_window, COORD *initial, COORD *final, INFO_PINCEL *pincel, COORD *size);
void ger_mouse(EVENTO key, INFO_PINCEL *pincel, COORD *size);
void escolher_cor(COORD *size, INFO_PINCEL *pincel);
void pixel(COORD coordenada, COORD dimensoes_fonte, INFO_PINCEL *pincel);

#endif

