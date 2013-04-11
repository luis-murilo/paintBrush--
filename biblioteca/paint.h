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

void check_name(char *argv[], int argc);
void starts(char *argv[], int argc, COORD *orig_window);
void end(COORD orig_window);

#endif

