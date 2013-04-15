#include "info_lower_bar.h"

void info_lower(COORD *size, COORD *pencil_pos, COORD *initial, int pencil_size, int mode)
{
	gotoxy(1, ((size->Y) - 1));
	textbackground(7);
	textcolor(0);
	if(mode == 1)
	{
		printf("Tamanho do pincel: %d | Modo: Pintar | Posicao do cursor: %dx%dpx", pencil_size, pencil_pos->X, ((pencil_pos->Y) -  initial->Y));

	}
	else
	{
		printf("Tamanho do pincel: %d | Modo: Nao pintar | Posicao do cursor: %dx%dpx", pencil_size, pencil_pos->X, ((pencil_pos->Y) -  initial->Y));
	}
}

