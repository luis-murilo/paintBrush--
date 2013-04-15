#include "info_lower_bar.h"

void gotoxy_correct(int x, int y, COORD *size)
{
	COORD c;
	if((x < 1) || (x > (*size).X) || (y < 1) || (y > (*size).Y))
	{
		return;
	}
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void info_lower(COORD *size, COORD *pencil_pos, int pencil_size, int mode)
{
	gotoxy_correct(1, (size->Y) - 1, size);
	textbackground(7);
	textcolor(0);
	if(mode == 1)
	{
		printf("Tamanho do pincel: %d | Modo: Pintar | Posicao do cursor: %dx%dpx", pencil_size, pencil_pos->X, pencil_pos->Y);

	}
	else
	{
		printf("Tamanho do pincel: %d | Modo: Nao pintar | Posicao do cursor: %dx%dpx", pencil_size, pencil_pos->X, pencil_pos->Y);
	}
}

