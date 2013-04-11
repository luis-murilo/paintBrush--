#include "interface.h"

void rect(COORD initial, COORD final, COLORREF cor) /*Plota o pixel na posição retângulo desejado*/
{
	HWND hWnd;	/* handle Window */
	HDC hDC;	/* handle Device Context */
	RECT rect;
	HBRUSH brush;
	hWnd = GetConsoleWindow(); 	/* armazenar o controlador da janela do prompt de comando */
	hDC = GetDC(hWnd);	/* armazenar o controlador da área de desenho na janela do prompt de comando */
	
	brush = CreateSolidBrush(cor);
	rect.left = initial.X;
	rect.top = initial.Y;
	rect.right = final.X;
	rect.bottom = final.Y;
    
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

void top_bar()	/*Desenha a barra superior e sua borda*/
{
	COORD final, initial;
	COLORREF cor;
	final = pixels_janela();	/*Dimensão da janela de console atual em pixels*/
	/*Desenha barra superior*/
	initial.X = 0;
	initial.Y = 0;
	final.Y = (final.Y) / 8;
	cor = RGB(206, 240, 198);
	rect(initial, final, cor);
	/*Desenha borda da barra superior*/
	initial.Y = final.Y;
	final.Y = (final.Y) + 2;
	cor = RGB(3, 128, 128);
	rect(initial, final, cor);
}

void lower_bar()	/*Desenha a barra inferior e sua borda*/
{
	COORD final, initial;
	COLORREF cor;
	final = pixels_janela();	/*Dimensão da janela de console atual em pixels*/
	/*Desenha a barra inferior*/
	cor = RGB(206, 240, 198);
	initial.X = 0;
	initial.Y = (final.Y) - 30;
	rect(initial, final, cor);
	/*Desenha a borda inferior*/
	cor = RGB(3, 128, 128);
	initial.Y = (final.Y) - 32;
	final.Y = (final.Y) - 30;
	rect(initial, final, cor);	
}

void work_area()
{
	COORD final, initial;
	COLORREF cor;
	final = pixels_janela();	/*Dimensão da janela de console atual em pixels*/
	/*Desenha Área de trabalho*/
	cor = RGB(255, 255, 255);
	initial.X = 0;
	initial.Y = ((final.Y) / 8) + 2;
	final.Y = (final.Y) - 32;
	rect(initial, final, cor);
}

