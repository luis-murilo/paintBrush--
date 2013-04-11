/*Cabecalho de paint.h*/
#ifndef PAINT_H
#define PAINT_H

#if (_WIN32_WINNT < 0x0500)
    #undef _WIN32_WINNT 
    #define _WIN32_WINNT 0x0500 /* 0x0500 corresponde a versão do Windows 2000 */
#endif

#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "conio_v3.2.1.h"
#include "console_v1.5.3.h"
#include "window.h"

void check_name(char *argv[], int argc);
void start(char *arg[], int argc);
void end(COORD size);
void rect(COORD initial, COORD final, COLORREF cor);

#endif
