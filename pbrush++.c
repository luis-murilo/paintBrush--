#include "paint.h"
#include "window.h"
#include "pencil.h"
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
		if((key.teclado.codigo_tecla > 36) || (key.teclado.codigo_tecla < 41))
		{
			pos_pencil(&pencil_pos, &initial, &final, key.teclado.codigo_tecla);
			printf("%lu", key.teclado.codigo_tecla);
			info_lower(&size, &pencil_pos, pencil_size, mode);
		}
	}while(key.teclado.codigo_tecla != ESC);
	end(orig_window);
	return 0;
}

