#include "paint.h"
#include "window.h"

int main(int argc, char *argv[])
{
	COORD orig_window;
	starts(argv, argc, &orig_window);
	system("pause");
	end(orig_window);
	system("pause");
	return 0;
}

