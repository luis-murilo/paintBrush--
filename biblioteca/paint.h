/*Cabecalho de paint.h*/
#ifndef PAINT_H
#define PAINT_H

#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "conio_v3.2.1.h"
#include "console_v1.5.3.h"
#include "window.h"
#include "interface.h"
#include "info_lower_bar.h"
#include "pencil.h"

void check_name(char *argv[], int argc);
void area_reserv(COORD janela_pixels, COORD *initial, COORD *final);
void starts(char *argv[], int argc, COORD *orig_window, COORD *initial, COORD *final, COORD *pencil_pos, int pencil_size, int mode, COORD *size);
void end(COORD orig_window);

#endif

