#include "info_bar.h"

void info_lower(COORD *size, INFO_PINCEL *pincel, COORD *initial)
{
	gotoxy(1, ((size->Y) - 1));
	textbackground(7);
	textcolor(0);
	if(pincel->mode == 1)
	{
		printf("Tamanho do pincel: %d | Modo: Pintar | Posicao do cursor: %dx%dpx          ", pincel->size, pincel->pos.X, (pincel->pos.Y - initial->Y));
	}
	else
	{
		printf("Tamanho do pincel: %d | Modo: Nao pintar | Posicao do cursor: %dx%dpx          ", pincel->size, pincel->pos.X, (pincel->pos.Y - initial->Y));
	}
}

void info_top(PALETA *paletas)
{
	paleta(paletas);
	icon_save();
	icon_file();
	print_edit_colors();
	print_user_color(RGB(0, 0, 0));
}

