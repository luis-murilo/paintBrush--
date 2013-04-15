#include "pencil.h"

void pos_pencil(COORD *pencil_pos, COORD *initial, COORD *final, int key)	/*Atualiza posicao do pincel*/
{
	if(key == 1)	/*Inicializa as coordenadas do pincel*/
	{
		pencil_pos->X = 0;
		pencil_pos->Y = 0;
	}
			printf("%d", key);
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
		printf("entro");
		--pencil_pos->Y;
	}
	if((key == SETA_PARA_BAIXO) && (pencil_pos->Y < final->Y))
	{
		++pencil_pos->Y;
	}
}


