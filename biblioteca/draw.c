#include "draw.h"

PIXEL** aloca_pixel(COORD *initial, COORD *final)
{
	PIXEL **aux;
	int i, j;
	aux = malloc((final->X - initial->X) * sizeof(PIXEL));
    for(i = 0; i < (final->X - initial->X); i++)
	{    
		aux[i]= malloc((final->Y - initial->Y) * sizeof(PIXEL));
	}
	if(aux == NULL)
	{
		printf("ERRO: Memoria insuficiente.");
		exit(0);
	}
	for(i = 0; i < (final->X - initial->X); i++)
	{
		for(j = 0; j < (final->Y - initial->Y); j++)
		{
			aux[i][j].cor = RGB(255, 255, 255);
			aux[i][j].status = 0;
		}
	}
	return aux;
}

void desaloca_pixel(PIXEL **pixels, COORD *initial, COORD *final)
{
	int i;
    for(i = 0; i < (final->X - initial->X); i++)
	{    
		free(pixels[i]);
	}
	free(pixels);
}

void status_pintar(COORD *size, INFO_PINCEL *pincel, COORD *initial) /*Altera o status pintar e nao pintar*/
{
	if(pincel->mode == 1)
	{
		pincel->mode = 0;
	}
	else
	{
		pincel->mode = 1;
	}
	info_lower(size, pincel, initial);
}

void pintar(INFO_PINCEL *pincel, PIXEL **pixels, COORD *initial, COORD *final)
{
	int i, j;
	if(pincel->mode == 1)
	{
		if(pincel->size > 1)
		{
			for(i = pincel->pos.X - pincel->size; i < pincel->pos.X + pincel->size; ++i)
			{
				for(j = pincel->pos.Y - pincel->size; j < pincel->pos.Y + pincel->size; ++j)
				{
					pixels[i][j].cor = pincel->cor;
					pixels[i][j].status = 1;
					putpixel(i, j, pincel->cor);
				}
			}
		}
		else
		{
			pixels[pincel->pos.X][pincel->pos.Y].cor = pincel->cor;
			pixels[pincel->pos.X][pincel->pos.Y].status = 1;
			putpixel(pincel->pos.X, pincel->pos.Y, pincel->cor);
		}
	}
	for(i = 0; i < (final->X - initial->X); i++)
	{
		for(j = 0; j < (final->Y - initial->Y); j++)
		{
			if(pixels[i][j].status == 1 || pixels[i][j].status == 2)
			{
				putpixel(i, j, pixels[i][j].cor);
				if(pixels[i][j].status == 2)
				{
					pixels[i][j].status = 0;
				}
			}
		}
	}
	if(pincel->cor == RGB(0, 0, 0))
	{
		putpixel(pincel->pos.X - 2, pincel->pos.Y, RGB(255, 0, 0));
		pixels[pincel->pos.X - 2][pincel->pos.Y].status = 2;
		putpixel(pincel->pos.X - 1, pincel->pos.Y, RGB(255, 0, 0));
		pixels[pincel->pos.X - 1][pincel->pos.Y].status = 2;
		putpixel(pincel->pos.X + 2, pincel->pos.Y, RGB(255, 0, 0));
		pixels[pincel->pos.X + 2][pincel->pos.Y].status = 2;
		putpixel(pincel->pos.X + 1, pincel->pos.Y, RGB(255, 0, 0));
		pixels[pincel->pos.X + 1][pincel->pos.Y].status = 2;
		putpixel(pincel->pos.X, pincel->pos.Y - 2, RGB(255, 0, 0));
		pixels[pincel->pos.X][pincel->pos.Y - 2].status = 2;
		putpixel(pincel->pos.X, pincel->pos.Y - 1, RGB(255, 0, 0));
		pixels[pincel->pos.X][pincel->pos.Y - 1].status = 2;
		putpixel(pincel->pos.X, pincel->pos.Y + 2, RGB(255, 0, 0));
		pixels[pincel->pos.X][pincel->pos.Y + 2].status = 2;
		putpixel(pincel->pos.X, pincel->pos.Y + 1, RGB(255, 0, 0));
		pixels[pincel->pos.X][pincel->pos.Y + 1].status = 2;
	}
	else
	{
		putpixel(pincel->pos.X - 2, pincel->pos.Y, RGB(0, 0, 0));
		pixels[pincel->pos.X - 2][pincel->pos.Y].status = 2;
		putpixel(pincel->pos.X - 1, pincel->pos.Y, RGB(0, 0, 0));
		pixels[pincel->pos.X - 1][pincel->pos.Y].status = 2;
		putpixel(pincel->pos.X + 2, pincel->pos.Y, RGB(0, 0, 0));
		pixels[pincel->pos.X + 2][pincel->pos.Y].status = 2;
		putpixel(pincel->pos.X + 1, pincel->pos.Y, RGB(0, 0, 0));
		pixels[pincel->pos.X + 1][pincel->pos.Y].status = 2;
		putpixel(pincel->pos.X, pincel->pos.Y - 2, RGB(0, 0, 0));
		pixels[pincel->pos.X][pincel->pos.Y - 2].status = 2;
		putpixel(pincel->pos.X, pincel->pos.Y - 1, RGB(0, 0, 0));
		pixels[pincel->pos.X][pincel->pos.Y - 1].status = 2;
		putpixel(pincel->pos.X, pincel->pos.Y + 2, RGB(0, 0, 0));
		pixels[pincel->pos.X][pincel->pos.Y + 2].status = 2;
		putpixel(pincel->pos.X, pincel->pos.Y + 1, RGB(0, 0, 0));
		pixels[pincel->pos.X][pincel->pos.Y + 1].status = 2;
	}
}

