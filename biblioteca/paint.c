/*Biblioteca paint.h*/
#include "paint.h"

void check_name(char *argv[], int argc) /*Verifica nome do programa*/
{
	if(((strcmp(argv[0],"pbrush++")) && (strcmp(argv[0],"pbrush++.exe"))) || (argc != 1))/*se o nome for igual a strcmp retorna 0, caso contrario ela retorna 1*/
	{
		printf("\aNome do programa invalido.");
		exit(0);
	}
}

void area_reserv(COORD janela_pixels, COORD *initial, COORD *final)	/*Desenha áreas reservadas*/
{
	top_bar(janela_pixels);
	lower_bar(janela_pixels);
	work_area(janela_pixels, initial, final);
}

void starts(char *argv[], int argc, COORD *orig_window, COORD *initial, COORD *final, COORD *pencil_pos, int pencil_size, int mode, COORD *size) /*Inicia o programa*/
{
	COORD janela_pixels;
	check_name(argv, argc);
    get_screen(orig_window);
	start_window();
	janela_pixels = pixels_janela();	/*Dimensão da janela de console atual em pixels*/
	area_reserv(janela_pixels, initial, final);	/*Desenha Areas reservadas*/
	(*size) = tamanhoJanelaConsole();
	pos_pencil(pencil_pos, initial, final, 0);
	info_lower(size, pencil_pos, initial, pencil_size, mode);
}

void end(COORD orig_window) /*Encerra o programa*/
{
	setCursorStatus(LIGAR);
	end_window(orig_window);
	setEstadoBarraTarefas(VISIVEL);
	textbackground(0);
	textcolor(15);
	gotoxy(1,1);
	clrscr();
}

void seta(COORD *pencil_pos, COORD *initial, COORD *final, int key, COORD *size, int mode, int pencil_size)
{
	pos_pencil(pencil_pos, initial, final, key);
	pintar(pencil_pos, mode, RGB(0,0,0));
	info_lower(size, pencil_pos, initial, pencil_size, mode);
}

void mode_status(int *mode)
{
	if(*mode == 1)
	{
		*mode = 0;
	}
	if(*mode == 0)
	{
		*mode = 1;
	}
}

