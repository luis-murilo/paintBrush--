/*Cabecalho de paint.h*/
#ifndef PAINT_H
#define PAINT_H

#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "conio_v3.2.3.h"
#include "console_v1.5.3.h"
#include "window.h"
#include "interface.h"
#include "info_bar.h"
#include "pencil.h"
#include "draw.h"
#include "info_top_bar.h"

void check_name(char *argv[], int argc);
void area_reserv(COORD janela_pixels, COORD *initial, COORD *final);
void starts(char *argv[], int argc, COORD *orig_window, COORD *initial, COORD *final, COORD *pencil_pos, int *pencil_size, int *mode, COORD *size, PALETA *paletas);
void end(COORD orig_window);
void mode_status(COORD *size, COORD *pencil_pos, COORD *initial, int *pencil_size, int *mode);

#endif

