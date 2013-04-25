#ifndef INFO_TOP_BAR_H
#define INFO_TOP_BAR_H

#include <windows.h>
#include <time.h>
#include "pencil.h"
#include "console_v1.5.3.h"
#include "graphics.h"
#include "conio_v3.2.3.h"
#include "interface.h"
#define altura 20
#define qtd_color 30

typedef struct PALETA{
	COLORREF cod_cor;
	COLORREF cod_cores_personalizadas;
	COORD position;
}PALETA;

void icon_file();
void icon_save();
COLORREF initPaleta(int pos_color);
PALETA *aloca();
void print_paleta(PALETA *paleta, int pos, COORD resolution);
void paleta();
void print_edit_colors();
void print_user_color(COLORREF color);

#endif

