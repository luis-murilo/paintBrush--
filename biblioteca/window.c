/*Biblioteca window.h*/
#include "window.h"

void get_screen(COORD *orig_window)	/*Armazena o tamanho inicial da tela*/
{
	*orig_window = tamanhoJanelaConsole();
}

void start_window()	/*Modifica  a tela ao iniciar o programa*/
{
	COORD size;
	setCursorStatus(DESLIGAR);
	size = MaxDimensaoJanela();
	setDimensaoJanela(size.X, size.Y);
	setPosicaoJanela(0, 0);	/*Posiciona a janela para cobrir a tela*/
	setTituloConsole("pbrush++");
	setEstadoBarraTarefas(INVISIVEL);
}

void end_window(COORD size)	/*Modifica a tela ao encerrar o programa*/
{
	setDimensaoJanela(size.X, size.Y);
}

