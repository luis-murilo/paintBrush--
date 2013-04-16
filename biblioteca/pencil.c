#include "pencil.h"

void pos_pencil(COORD *pencil_pos, COORD *initial, COORD *final, int key)	/*Atualiza posicao do pincel*/
{
	if(key == 0)	/*Inicializa as coordenadas do pincel*/
	{
		pencil_pos->X = 0;
		pencil_pos->Y = initial->Y;
	}
	else
	{
		if((key == SETA_PARA_ESQUERDA) && (pencil_pos->X > initial->X))
		{
			--pencil_pos->X;
		}
		if((key == SETA_PARA_DIREITA) && (pencil_pos->X < final->X))
		{
			++pencil_pos->X;
		}
		if((key == SETA_PARA_CIMA) && (pencil_pos->Y > initial->Y))
		{
			--pencil_pos->Y;
		}
		if((key == SETA_PARA_BAIXO) && (pencil_pos->Y < final->Y))
		{
			++pencil_pos->Y;
		}
	}
}

void resize_pencil(int *pencil_size, int state, COORD *size, COORD *pencil_pos, COORD *initial, int *mode)
{
	if(state == 1)
	{
		++(*pencil_size);
	}
	else
	{
		--(*pencil_size);
	}
	info_lower(size, pencil_pos, initial, pencil_size, mode);
}

void seta(COORD *pencil_pos, COORD *initial, COORD *final, int key, COORD *size, int *mode, int *pencil_size)
{
	pos_pencil(pencil_pos, initial, final, key);
	pintar(pencil_pos, mode, RGB(0,0,0));
	info_lower(size, pencil_pos, initial, pencil_size, mode);
}

