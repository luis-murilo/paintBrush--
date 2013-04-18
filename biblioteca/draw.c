#include "draw.h"

void pintar(PIXEL **pixels, COORD *pencil_pos, int *mode, COLORREF cor, int key, int *pencil_size)
{
	int i, j;
	if((*mode) == 1)
	{
		if(*pencil_size != 1)
		{
			for(i = 0; i < (*pencil_size); ++i)
			{
				for(j = 0; j < (*pencil_size); ++j)
				{
					putpixel(pencil_pos->X + i, pencil_pos->Y + j, cor);
					pixels[i][j].pos.X = pencil_pos->X + i;
					pixels[i][j].pos.Y = pencil_pos->Y + j;
					pixels[i][j].cor = cor;
				}
			}
		}
		else
		{
			putpixel(pencil_pos->X, pencil_pos->Y, cor);
		}
	}
}

