#include "pencil.h"
#include "info_bar.h"
#include "draw.h"

void inic_pincel(INFO_PINCEL *pincel, COORD *initial, COORD *final)
{
	pincel->pos.X = ((final->X - initial->X) / 2);
	pincel->pos.Y = ((final->Y - initial->Y) / 2);
	pincel->size = 1;
	pincel->mode = 0;
	pincel->cor = RGB(0, 0, 0);
}

void pos_pencil(INFO_PINCEL *pincel, COORD *initial, COORD *final, int key)	/*Atualiza posicao do pincel*/
{
	if((key == SETA_PARA_ESQUERDA) && ((pincel->pos.X - pincel->size + 1) > initial->X))
	{
		--pincel->pos.X;
	}
	if((key == SETA_PARA_DIREITA) && ((pincel->pos.X + pincel->size - 2) < (final->X - pincel->size)))
	{
		++pincel->pos.X;
	}
	if((key == SETA_PARA_CIMA) && ((pincel->pos.Y - pincel->size + 1) > initial->Y))
	{
		--pincel->pos.Y;
	}
	if((key == SETA_PARA_BAIXO) && (pincel->pos.Y + pincel->size - 2 < (final->Y - pincel->size)))
	{
		++pincel->pos.Y;
	}
}

void resize_pencil(INFO_PINCEL *pincel, int state, COORD *size, COORD *initial)
{
	if(state == 1)
	{
		++(pincel->size);
	}
	if((state == 0) && (pincel->size) > 1)
	{
		--(pincel->size);
	}
	info_lower(size, pincel, initial);
}

void seta(INFO_PINCEL *pincel, COORD *initial, COORD *final, int key, COORD *size, PIXEL **pixels)
{
	pos_pencil(pincel, initial, final, key);
	pintar(pincel, pixels, initial, final);
	info_lower(size, pincel, initial);
}

