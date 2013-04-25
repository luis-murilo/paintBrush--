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

void starts(char *argv[], int argc, COORD *orig_window, COORD *initial, COORD *final, INFO_PINCEL *pincel, COORD *size, PALETA *paletas) /*Inicia o programa*/
{
	COORD janela_pixels;
	check_name(argv, argc);
    get_screen(orig_window);
	start_window();
	janela_pixels = pixels_janela();	/*Dimensão da janela de console atual em pixels*/
	area_reserv(janela_pixels, initial, final);	/*Desenha Areas reservadas*/
	(*size) = tamanhoJanelaConsole();
	inic_pincel(pincel, initial, final);
	info_lower(size, pincel, initial);
	info_top(paletas);
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

void read_key(COORD *orig_window, COORD *initial, COORD *final, INFO_PINCEL *pincel, COORD *size)
{
	EVENTO key;
	PIXEL **pixels;
	pixels = aloca_pixel(initial, final);
	pintar(pincel, pixels, initial, final);
	do
	{
		key = Evento();
		switch(key.tipo_evento)
		{
			case KEY_EVENT:
				if((key.teclado.codigo_tecla > 36) && (key.teclado.codigo_tecla < 41) && (key.teclado.status_tecla == PRESSIONADA))
				{
					seta(pincel, initial, final, key.teclado.codigo_tecla, size, pixels);
				}
				if((key.teclado.status_teclas_controle & LEFT_CTRL_PRESSED) == LEFT_CTRL_PRESSED)
				{
					status_pintar(size, pincel, initial);
				}
				if((key.teclado.status_teclas_controle & LEFT_ALT_PRESSED) == LEFT_ALT_PRESSED)
				{
					resize_pencil(pincel, 1, size, initial);
				}
				if(((key.teclado.status_teclas_controle & RIGHT_ALT_PRESSED) == RIGHT_ALT_PRESSED) && (key.teclado.status_tecla == PRESSIONADA))
				{
					resize_pencil(pincel, 0, size, initial);
				}
				break;
			case MOUSE_EVENT:
				if (key.mouse.botao_pressionado & FROM_LEFT_1ST_BUTTON_RELEASED)
				{
					ger_mouse(key, pincel, size);
				}
				if (key.mouse.botao_pressionado & RIGHTMOST_BUTTON_RELEASED)
				{
					
				}
				break;
		}
	}while(key.teclado.codigo_tecla != ESC);
	desaloca_pixel(pixels, initial, final);
}

void ger_mouse(EVENTO key, INFO_PINCEL *pincel, COORD *size)
{
	COORD resolucao_atual, dimensoes_fonte;
	register int colcheck1, colcheck2, lincheck1, lincheck2, intervalo, tam_ver, tam_hor;
	resolucao_atual = getResolucaoMonitor();
	dimensoes_fonte = getTamanhoFonteConsole();
	/*COLUNA alt1 relacionada com tam_hor
	LINHA alt2 relacionada com tam_ver*/
	tam_hor = 2*(resolucao_atual.X / 42);
	tam_ver = 2*(resolucao_atual.X / 70);
	lincheck1 = (resolucao_atual.X / 2) + (resolucao_atual.X / 2.6) ;
	lincheck2 = lincheck1 + tam_hor;
	colcheck1 = resolucao_atual.Y / 50;
	colcheck2 = colcheck1 + tam_ver;
	lincheck1 = lincheck1 /  dimensoes_fonte.X; 
	lincheck2 = lincheck2 /  dimensoes_fonte.X;
	colcheck1 = colcheck1 / dimensoes_fonte.Y;
	colcheck2 = colcheck2 / dimensoes_fonte.Y;
	/*X entre 151 e 159 e Y entre 0 e 3*/
	if (((key.mouse.posicao.X > lincheck1 ) &&  (key.mouse.posicao.X < lincheck2)))
	{
		if((key.mouse.posicao.Y > colcheck1 ) && (key.mouse.posicao.Y < colcheck2 ))
		{
			escolher_cor(size, pincel);
		}
	}
	colcheck1 = resolucao_atual.X - resolucao_atual.X /2.5;/*onde a paleta comeca a ser impressa na tela*/
	intervalo = resolucao_atual.X /35;
	colcheck2 = colcheck1 + (9 * intervalo);
	lincheck1 = resolucao_atual.Y/50;
	lincheck2 = resolucao_atual.Y/10;
	colcheck1 = colcheck1 /  dimensoes_fonte.X; 
	colcheck2 = colcheck2 /  dimensoes_fonte.X; 
	lincheck1 = lincheck1 /  dimensoes_fonte.Y;
	lincheck2 = lincheck2 /  dimensoes_fonte.Y;
	/*mudar a cor via paleta de cores*/
	if (((key.mouse.posicao.Y > lincheck1 ) &&  (key.mouse.posicao.Y < lincheck2)))
	{
		if((key.mouse.posicao.X > colcheck1 ) && (key.mouse.posicao.X < colcheck2 ))
		{
			pixel(key.mouse.posicao, dimensoes_fonte, pincel);
		}
	}
	/*abrir o arquivo*/
	if (((key.mouse.posicao.Y > 0 ) &&  (key.mouse.posicao.Y < 159)))
	{
		if((key.mouse.posicao.X > 150 ) && (key.mouse.posicao.X < 160 ))
		{
	
		}
	}
	/*salvar o arquivo*/
	if (((key.mouse.posicao.Y > 0 ) &&  (key.mouse.posicao.Y < 159)))
	{
		if((key.mouse.posicao.X > 150 ) && (key.mouse.posicao.X < 160 ))
		{
		
		}
	}
}

void escolher_cor(COORD *size, INFO_PINCEL *pincel)
{
	EVENTO e;
	int r, g, b, cont = 1, i = 0;
	char aux[4];
	gotoxy(1, size->Y);
	printf("Informe a cor(Ex: 255,255,255): ");
	do
	{
		e = Evento();
		if(e.tipo_evento == KEY_EVENT)
		{
			if(e.teclado.codigo_tecla > 47 && e.teclado.codigo_tecla < 58 && e.teclado.status_tecla == PRESSIONADA)
			{
				aux[i] = e.teclado.codigo_tecla;
				printf("%c", aux[i]);
				i++;
			}
			if((e.teclado.codigo_tecla == 188 || e.teclado.codigo_tecla == ENTER) && e.teclado.status_tecla == PRESSIONADA)
			{
				i = 0;
				if(cont == 1)
				{
					r = atoi(aux);
					printf(",");
				}
				if(cont == 2)
				{
					g = atoi(aux);
					printf(",");
				}
				if(cont == 3)
				{
					b = atoi(aux);
				}
				cont++;
			}
		}
	}while(e.teclado.codigo_tecla != ENTER);
	pincel->cor = RGB(r, g, b);
	print_user_color(RGB(r, g, b));
	gotoxy(1, size->Y);
	printf("                                                         ");
}

void pixel(COORD coordenada, COORD dimensoes_fonte, INFO_PINCEL *pincel)
{
	COLORREF color;
	coordenada.X = coordenada.X * dimensoes_fonte.X; 
	coordenada.Y = coordenada.Y * dimensoes_fonte.Y; 
	/*nao esta reconhecendo todas as cores*/
	color = getpixel(coordenada.X , coordenada.Y);
	if (color != RGB (3, 128, 128))
	{
		pincel->cor = color;
		print_user_color(color);
	}
}

