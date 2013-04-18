#ifndef INTERFACE_H
#define INTERFACE_H

#if (_WIN32_WINNT < 0x0500)
    #undef _WIN32_WINNT 
    #define _WIN32_WINNT 0x0500 /* 0x0500 corresponde a versão do Windows 2000 */
#endif

#include <windows.h>
#include <stdio.h>
#include "console_v1.5.3.h"

void rect(COORD *initial, COORD *final, COLORREF cor);
COORD pixels_janela();
void top_bar(COORD janela_pixels);
void lower_bar(COORD janela_pixels);
void work_area(COORD janela_pixels, COORD *initial, COORD *final);

#endif

