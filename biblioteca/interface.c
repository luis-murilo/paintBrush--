#include "interface.h"

void rect(COORD *initial, COORD *final, COLORREF cor) /*Plota o pixel na posição retângulo desejado*/
{
	HWND hWnd;	/* handle Window */
	HDC hDC;	/* handle Device Context */
	RECT rect;
	HBRUSH brush;
	hWnd = GetConsoleWindow(); 	/* armazenar o controlador da janela do prompt de comando */
	hDC = GetDC(hWnd);	/* armazenar o controlador da área de desenho na janela do prompt de comando */
	
	brush = CreateSolidBrush(cor);
	rect.left = initial->X;
	rect.top = initial->Y;
	rect.right = final->X;
	rect.bottom = final->Y;
    
	FillRect(hDC, &rect, brush);	/* Plotar o pixel na posição do retângulo com a cor "cor" */
	ReleaseDC(hWnd, hDC);	/* liberar o controlador da área gráfica */
}

COORD pixels_janela()	/* Calcular a dimensao da janela de console atual em pixels */
{
	COORD dimensoes_janela, dimensoes_fonte, janela_pixels;
	dimensoes_janela = tamanhoJanelaConsole();
	dimensoes_fonte = getTamanhoFonteConsole();
	janela_pixels.X = dimensoes_janela.X * dimensoes_fonte.X;
	janela_pixels.Y = dimensoes_janela.Y * dimensoes_fonte.Y;
	return janela_pixels;
}

void top_bar(COORD janela_pixels)	/*Desenha a barra superior e sua borda*/
{
	COORD initial;
	COLORREF cor;	/*Dimensão da janela de console atual em pixels*/
	/*Desenha barra superior*/
	initial.X = 0;
	initial.Y = 0;
	janela_pixels.Y = (janela_pixels.Y) / 8;
	cor = RGB(198, 206, 240);
	rect(&initial, &janela_pixels, cor);
	/*Desenha borda da barra superior*/
	initial.Y = janela_pixels.Y;
	janela_pixels.Y = (janela_pixels.Y) + 2;
	cor = RGB(94, 117, 213);
	rect(&initial, &janela_pixels, cor);
}

void lower_bar(COORD janela_pixels)	/*Desenha a barra inferior e sua borda*/
{
	COORD initial;
	COLORREF cor;
	/*Desenha a barra inferior*/
	cor = RGB(192, 192, 192);
	initial.X = 0;
	initial.Y = (janela_pixels.Y) - 30;
	rect(&initial, &janela_pixels, cor);
	/*Desenha a borda inferior*/
	cor = RGB(150, 150, 150);
	initial.Y = (janela_pixels.Y) - 32;
	janela_pixels.Y = (janela_pixels.Y) - 30;
	rect(&initial, &janela_pixels, cor);
}

void work_area(COORD janela_pixels, COORD *initial, COORD *final)	/*Desenha área de trabalho*/
{
	COLORREF cor;
	/*Desenha Área de trabalho*/
	cor = RGB(255, 255, 255);
	initial->X = 0;
	initial->Y = ((janela_pixels.Y) / 8) + 2;
	final->X = janela_pixels.X;
	final->Y = (janela_pixels.Y) - 32;
	rect(initial, final, cor);
}

