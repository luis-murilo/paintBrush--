#include "paint.h"
#include "window.h"
#include "pencil.h"
#include "draw.h"
#include <windows.h>

int main(int argc, char *argv[])
{
	COORD orig_window, initial, final, pencil_pos, size;
	EVENTO key;
	int mode = 1, pencil_size = 1;
	starts(argv, argc, &orig_window, &initial, &final, &pencil_pos, pencil_size, mode, &size);
	do
	{
		key.teclado.codigo_tecla = 0;
		key = Evento();
		if((key.teclado.codigo_tecla > 36) && (key.teclado.codigo_tecla < 41))
		{
			seta(&pencil_pos, &initial, &final, key.teclado.codigo_tecla, &size, mode, pencil_size);
		}
		if(key.teclado.codigo_tecla == 17)
		{
			printf("entro");
			mode_status(&mode);
		}
	}while(key.teclado.codigo_tecla != ESC);
	end(orig_window);
	return 0;
}

