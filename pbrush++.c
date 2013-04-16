#include "paint.h"
#include "window.h"
#include "pencil.h"
#include "draw.h"
#include <windows.h>

typedef struct
{
	COORD pos;
	COLORREF cor;
}PIXEL;

int main(int argc, char *argv[])
{
	PIXEL **pixels;
	COORD orig_window, initial, final, pencil_pos, size;
	EVENTO key;
	int mode = 1, pencil_size = 1, state = 1, i;
	starts(argv, argc, &orig_window, &initial, &final, &pencil_pos, &pencil_size, &mode, &size);
	printf("%d-%d", (initial.X - final.X), (initial.Y - final.Y));
	pixels = malloc((final.X - initial.X) * sizeof(PIXEL));
    for(i = 0; i < (final.X - initial.X); ++i)
	{    
		pixels[i]= malloc((final.Y - initial.Y) * sizeof(PIXEL));
	}
	if(pixels == NULL)
	{
		printf("ERRO: Memoria insuficiente.");
	}
	do
	{
		key = Evento();
		switch(key.tipo_evento)
		{
			case KEY_EVENT:
				if((key.teclado.codigo_tecla > 36) && (key.teclado.codigo_tecla < 41) && (key.teclado.status_tecla == PRESSIONADA))
				{
					seta(&pencil_pos, &initial, &final, key.teclado.codigo_tecla, &size, &mode, &pencil_size);
				}
				if((key.teclado.codigo_tecla == 17) && (key.teclado.status_tecla == PRESSIONADA))
				{
					mode_status(&size, &pencil_pos, &initial, &pencil_size, &mode);
				}
				if((key.teclado.codigo_tecla == 18) && (key.teclado.status_tecla == PRESSIONADA))
				{
					state = 1;
					resize_pencil(&pencil_size, state, &size, &pencil_pos, &initial, &mode);
				}
				if((key.teclado.codigo_tecla == 18) && (key.teclado.status_tecla == LIBERADA))
				{
					state = 0;
					resize_pencil(&pencil_size, state, &size, &pencil_pos, &initial, &mode);
				}
				break;
			case MOUSE_EVENT:
				break;
		}
	}while(key.teclado.codigo_tecla != ESC);
    for(i = 0; i < (final.X - initial.X); ++i)
	{    
		free(pixels[i]);
	}
	free(pixels);
	end(orig_window);
	return 0;
}

