#include "pencil.h"

void pos_pencil(COORD *pencil_pos, COORD *initial, COORD *final, int key, int *pencil_size)	/*Atualiza posicao do pincel*/
{
	if(key == 0)	/*Inicializa as coordenadas do pincel*/
	{
		pencil_pos->X = 0;
		pencil_pos->Y = initial->Y;
	}
	else
	{
		if((key == SETA_PARA_ESQUERDA) && ((pencil_pos->X - *pencil_size + 1) > initial->X))
		{
			pencil_pos->X -= (*pencil_size);
		}
		if((key == SETA_PARA_DIREITA) && ((pencil_pos->X + *pencil_size - 2) < (final->X - *pencil_size)))
		{
			pencil_pos->X += (*pencil_size);
		}
		if((key == SETA_PARA_CIMA) && ((pencil_pos->Y - *pencil_size + 1) > initial->Y))
		{
			pencil_pos->Y -= (*pencil_size);
		}
		if((key == SETA_PARA_BAIXO) && (pencil_pos->Y + *pencil_size - 2 < (final->Y - *pencil_size)))
		{
			pencil_pos->Y += (*pencil_size);
		}
	}
}

void resize_pencil(int *pencil_size, int state, COORD *size, COORD *pencil_pos, COORD *initial, int *mode)
{
	if(state == 1)
	{
		++(*pencil_size);
	}
	if((state == 0) && (*pencil_size) > 1)
	{
		--(*pencil_size);
	}
	info_lower(size, pencil_pos, initial, pencil_size, mode);
}

void seta(COORD *pencil_pos, COORD *initial, COORD *final, int key, COORD *size, int *mode, int *pencil_size, PIXEL **pixels)
{
	pintar(pixels, pencil_pos, mode, RGB(0,0,0), key, pencil_size);
	pos_pencil(pencil_pos, initial, final, key, pencil_size);
	pintar(pixels, pencil_pos, mode, RGB(0,0,0), key, pencil_size);
	info_lower(size, pencil_pos, initial, pencil_size, mode);
}

