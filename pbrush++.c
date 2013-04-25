#include <windows.h>
#include "pencil.h"
#include "paint.h"
#include "window.h"
#include "draw.h"
#include "info_top_bar.h"

int main(int argc, char *argv[])
{
	COORD orig_window, initial, final, size;
	INFO_PINCEL pincel;
	PALETA *paletas;
	paletas = aloca();
	starts(argv, argc, &orig_window, &initial, &final, &pincel, &size, paletas);
	read_key(&orig_window, &initial, &final, &pincel, &size);
	end(orig_window);
	return 0;
}

