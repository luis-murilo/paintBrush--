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

void start(char *argv[], int argc) /*Inicia o programa*/
{
	COORD size, initial, final;
	clrscr();
	check_name(argv, argc);
	setCursorStatus(DESLIGAR);
    get_screen(&size);
	setTituloConsole("pbrush++");
	setEstadoBarraTarefas(INVISIVEL);
	start_window();
	rect(initial, final, RGB(255,255,255));
	end(size);
	system("pause");
}

void end(COORD size) /*Encerra o programa*/
{
	setCursorStatus(LIGAR);
	end_window(size);
	textbackground(BLACK);
	setEstadoBarraTarefas(VISIVEL);
}

void rect(COORD initial, COORD final, COLORREF cor)
{
	HWND hWnd;	/* handle Window */
	HDC hDC;	/* handle Device Context */
	RECT rect;
	HBRUSH brush;
	hWnd = GetConsoleWindow(); 	/* armazenar o controlador da janela do prompt de comando */
	hDC = GetDC(hWnd);	/* armazenar o controlador da área de desenho na janela do prompt de comando */
	
	brush = CreateSolidBrush(cor);
	rect.left = 0;
	rect.top = 0;
	rect.right = 100;
	rect.bottom = 100;
    
	FillRect(hDC, &rect, brush);	/* Plotar o pixel na posição do retângulo com a cor "cor" */
	ReleaseDC(hWnd, hDC);	/* liberar o controlador da área gráfica */
}
