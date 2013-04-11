/*Biblioteca window.h*/
#ifndef WINDOW_H
#define WINDOW_H

#include <windows.h>  
#include "console_v1.5.3.h"

void get_screen(COORD *size);
void start_window();
void end_window(COORD size);

#endif
