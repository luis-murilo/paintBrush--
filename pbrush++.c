#include <windows.h>
#include "paint.h"
#include "window.h"
#include "pencil.h"
#include "draw.h"
#include "info_top_bar.h"

int main(int argc, char *argv[])
{
	PIXEL **pixels;
	COORD orig_window, initial, final, pencil_pos, size;
	EVENTO key;
	int mode = 1, pencil_size = 1, state = 1, i;
	PALETA *paletas;
	paletas = aloca();
	starts(argv, argc, &orig_window, &initial, &final, &pencil_pos, &pencil_size, &mode, &size, paletas);
	pixels = malloc((final.X - initial.X) * sizeof(PIXEL));
    for(i = 0; i < (final.X - initial.X); ++i)
	{    
		pixels[i]= malloc((final.Y - initial.Y) * sizeof(PIXEL));
	}
	if(pixels == NULL)
	{
		printf("ERRO: Memoria insuficiente.");
		exit(0);
	}
	do
	{
		key = Evento();
		switch(key.tipo_evento)
		{
			case KEY_EVENT:
				if((key.teclado.codigo_tecla > 36) && (key.teclado.codigo_tecla < 41) && (key.teclado.status_tecla == PRESSIONADA))
				{
					seta(&pencil_pos, &initial, &final, key.teclado.codigo_tecla, &size, &mode, &pencil_size, pixels);
				}
				if((key.teclado.status_teclas_controle & LEFT_CTRL_PRESSED) == LEFT_CTRL_PRESSED)
				{
					mode_status(&size, &pencil_pos, &initial, &pencil_size, &mode);
				}
				if((key.teclado.status_teclas_controle & LEFT_ALT_PRESSED) == LEFT_ALT_PRESSED)
				{
					state = 1;
					resize_pencil(&pencil_size, state, &size, &pencil_pos, &initial, &mode);
				}
				if(((key.teclado.status_teclas_controle & RIGHT_ALT_PRESSED) == RIGHT_ALT_PRESSED) && (key.teclado.status_tecla == PRESSIONADA))
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
	desaloca(paletas);
	free(pixels);
	end(orig_window);
	return 0;
}

