#include "draw.h"

void pintar(COORD *pencil_pos, int *mode, COLORREF cor)
{
	if((*mode) == 1)
	{
		putpixel(pencil_pos->X, pencil_pos->Y, cor);
	}
}

