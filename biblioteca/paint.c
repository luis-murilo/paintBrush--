/*Biblioteca paint.h*/
#include "paint.h"

void check_name(char *argv[], int argc)
{
	if(((strcmp(argv[0],"pbrush++")) && (strcmp(argv[0],"pbrush++.exe"))) || (argc != 1))/*se o nome for igual a strcmp retorna 0, caso contrario ela retorna 1*/
	{
		printf("\aNome do programa invalido.");
		exit(0);
	}
}

void starts(char *argv[], int argc, COORD *orig_window) /*Inicia o programa*/
{
	clrscr();
	check_name(argv, argc);
    get_screen(orig_window);
	start_window();
	top_bar();
	lower_bar();
	work_area();
}

void end(COORD orig_window) /*Encerra o programa*/
{
	setCursorStatus(LIGAR);
	end_window(orig_window);
	setEstadoBarraTarefas(VISIVEL);
}

