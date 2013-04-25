/*info_top_bar.c*/
#include "info_top_bar.h"

void icon_file()
{
	register int i;
    float	j, cont;
	COLORREF cor;
	COORD resolucao_atual;
	BYTE red, green, blue;
	red = 255;
	green = 210;
	blue = 0;
	resolucao_atual = getResolucaoMonitor();
	for(i = 10; i < resolucao_atual.Y / 17; i++)
	{
		cor = RGB(red, green, blue);
		for(j = 10; j < resolucao_atual.X / 25 ; j++)
		{
			putpixel( i, j, cor);/*linha, coluna, cor*/
		}
		/* a cada dois pixels ee vai clarer mais o amarelo, atraves do verde */			
		if (i % 2 == 0) green+=2;
	};
	red = 255;
	green =  235;
	blue = 98;
	for(i = 10; i <  resolucao_atual.Y / 20; i++)
	{
		cor = RGB(red, green, blue);
		for(j = 10; j  < (resolucao_atual.X / 40) + cont; j++)
		{
			putpixel(i, j, cor);/*linha, coluna, cor*/
		}
		cont+=0.5;	
		if (i % 2 == 0) green-=2;
	}
	gotoxy(2,6);
	printf("Abrir");
}

void icon_save()
{
	register int i,j;
	COLORREF cor;
	COORD resolucao_atual;
	BYTE red, green, blue;
	red = 77;
	green = 12;
	blue = 90;
	resolucao_atual = getResolucaoMonitor();
	for(i = 70; i <  resolucao_atual.Y / 7; i++)
	{
		cor = RGB(red, green, blue);
		for(j = altura ; j  < (resolucao_atual.X / 25); j++)
		{
			putpixel( i, j, cor);/*linha, coluna, cor*/
		}
	}	
	/*desenha as linhas do disquete*/
	red = 219;
	green = 219;
	blue = 219;
	resolucao_atual = getResolucaoMonitor();
	for(i = 73; i <  (resolucao_atual.Y / 7) -3; i++)
	{
		cor = RGB(red, green, blue);
		for(j = altura + 2 ; j  < (resolucao_atual.X / 25) - 17; j+=2)
		{
			putpixel( i, j, cor);/*linha, coluna, cor*/
		}
	}	
	/*desenha o quadradinho do disquete*/	
	red = 0;
	green = 0;
	blue = 0;
	resolucao_atual = getResolucaoMonitor();
	for(i = 75; i <  (resolucao_atual.Y / 7) - 20; i+=2)
	{
		cor = RGB(red, green, blue);
		for(j = altura + 4 ; j  < (resolucao_atual.X / 25) - 20; j++)
		{
			putpixel( i, j, cor);/*linha, coluna, cor*/
		}
	}
	gotoxy(10,6);
	printf("Salvar");
}

COLORREF initPaleta(int pos_color)
{
	COLORREF color;
	pos_color++;
	switch (pos_color)
	{
		case 1:
			color = RGB(0, 0, 0);
			return color;
			break;
		case 2:
			color = RGB(127, 127, 127);
			return color;
			break;
		case 3:
			color = RGB(136, 0, 21);
			return color;
			break;
		case 4:
			color = RGB(237, 28, 36);
			return color;
			break;
		case 5:
			color = RGB(255, 127, 39);
			return color;
			break;
		case 6:
			color = RGB(255, 242, 0);
			return color;
			break;
		case 7:
			color = RGB(34, 177, 76);
			return color;
			break;
		case 8:
			color = RGB(0, 162, 232);
			return color;
			break;
		case 9:
			color = RGB(63, 72, 204);
			return color;
			break;
		case 10:
			color = RGB(163, 73, 164);
			return color;
			break;
		case 11:
			color = RGB(255, 255, 255);
			return color;
			break;
		case 12:
			color = RGB(195, 195, 195);
			return color;
			break;
		case 13:
			color = RGB(185, 122, 187);
			return color;
			break;
		case 14:
			color = RGB(255, 174, 201);
			return color;
			break;
		case 15:
			color = RGB(255, 201, 14);
			return color;
			break;
		case 16:
			color = RGB(239, 228, 176);
			return color;
			break;
		case 17:
			color = RGB(181, 230, 29);
			return color;
			break;
		case 18:
			color = RGB(153, 217, 234);
			return color;
			break;
		case 19:
			color = RGB(112, 146, 190);
			return color;
			break;
		case 20:
			color = RGB(200, 191, 231);
			return color;
			break;
	}
	return (RGB(198,206,240));
}

PALETA *aloca()
{
	PALETA *pont;
	pont = (PALETA *) calloc( 31, sizeof(PALETA));
	if (pont == NULL)
	{
        printf ("/a** Erro: Memoria Insuficiente /a");
        exit(0);
    }
	return pont;
}
 
/*Imprime a paleta de cores recebe como um parametro um vetor do tipo PALETA 
e um inteiro que representa qual o elemento do vetor a ser impresso
*/
void print_paleta(PALETA *paleta, int pos, COORD resolution)
{
	register int i, j, cont;
	int alt1, alt2;
	if (pos < 10)
	{
		alt1 = resolution.Y / 50;
		alt2 = resolution.Y / 20;
		for(i = paleta[pos].position.X; i < paleta[pos+1].position.X; i++)
		{
			
			for (cont = alt1 - 2; cont < alt1; cont ++)
			{
				putpixel(i, cont, RGB(3, 128, 128));
			}
			for(j = alt1; j < alt2; j++)
			{
				putpixel(i, j, paleta[pos].cod_cor);
				for (cont =  paleta[pos].position.X; cont < ( paleta[pos].position.X + 3); cont ++)
				{
					putpixel(cont , j, RGB(3, 128, 128));
				}
			}
		}
	}
	if ((pos >= 10) && (pos < 20))
	{
		alt1 = resolution.Y / 20;
		alt2 = resolution.Y / 13;
		for(i = paleta[pos].position.X; i < paleta[pos+1].position.X; i++)
		{
			for (cont = alt1 - 2; cont < alt1; cont ++)
			{
				putpixel(i, cont, RGB(3, 128, 128));
			}
			for(j = alt1; j < alt2; j++)
			{
				putpixel(i, j, paleta[pos].cod_cor);
				for (cont =  paleta[pos].position.X; cont < ( paleta[pos].position.X + 3); cont ++)
				{
					putpixel(cont , j, RGB(3, 128, 128));
				}
			}
	
		}
	}
	if (pos >= 20)
	{
		alt1 = resolution.Y / 13;
		alt2 = resolution.Y / 10;
		for(i = paleta[pos].position.X; i < paleta[pos+1].position.X; i++)
		{
			for (cont = alt1 - 2; cont < alt1; cont ++)
			{
				putpixel(i, cont, RGB(3, 128, 128));
			}
			for(j = alt1; j < alt2; j++)
			{
				putpixel(i, j, paleta[pos].cod_cor);
				for (cont =  paleta[pos].position.X; cont < ( paleta[pos].position.X + 3); cont ++)
				{
					putpixel(cont , j, RGB(3, 128, 128));
				}
			}
			for (cont = alt2; cont <  alt2 + 2; cont ++)
			{
				putpixel(i, cont, RGB(3, 128, 128));
			}
		}
		if(pos == 29)
		{
			alt1 = resolution.Y / 50;/*desenha a linha lateral direita*/
			alt2 = resolution.Y / 10;
			for(i = paleta[pos].position.X; i < paleta[pos].position.X + 3; i++)
			{
				for (cont = alt1 - 2; cont < alt2; cont ++)
				{
					putpixel( i,cont, RGB(3, 128, 128));
				}	
			}
		}
	}
}
 
/*desenha inicia a paleta de cores.
nao recebe nenhum parametro e nao tem retorno.
Chama a funcao aloca() para alocar um vetor de estruturas PALETA e inicializa o mesmo.
*/
void paleta()
{
	PALETA *paleta;
	COORD resolucao_atual;
	register int i,cont1,cont2, inicial_cont, tam_quad_color;
	paleta = aloca();
	resolucao_atual = getResolucaoMonitor();
	/*checar a posicao da coluna em relacao a resolucao*/
	inicial_cont = cont1 = resolucao_atual.X - resolucao_atual.X /2.5;/*onde a paleta comeca a ser impressa na tela*/
	tam_quad_color = resolucao_atual.X /35;
	cont2 = resolucao_atual.Y/10;
	for(i = 0; i < qtd_color; i++)
	{	
		paleta[i].cod_cor = initPaleta(i);
		paleta[i].position.X = cont1;
		paleta[i].position.Y = cont2;
		cont1 += tam_quad_color;
		if ((cont1 == ((tam_quad_color * 10) + inicial_cont)) ||  (cont1 == ((tam_quad_color * 20) + inicial_cont)))
		{
			cont1 = inicial_cont;
		}
	}
	paleta[30].position.X = inicial_cont  + (9 * tam_quad_color);
	for(i = 0; i < qtd_color; i++)
	{
		print_paleta( paleta, i, resolucao_atual);
	}
	free(paleta);
}

void print_edit_colors()
{
	COORD resolution;
	COLORREF color;
	BYTE red, green, blue;
	register int i, j;
	int alt1, alt2, tam_hor, tam_ver;
	resolution = getResolucaoMonitor();
	tam_hor = 2*(resolution.X / 42);
	tam_ver = 2*(resolution.X / 70);
	alt1 = (resolution.X / 2) + (resolution.X / 2.6) ;
	alt2 = resolution.Y / 50;
	srand(time(NULL));
	/*desenha a barra superior e inferior*/
	for(i = alt1 -3; i < alt1 + tam_hor + 3; i++)
	{
		for(j = alt2 - 3; j < alt2; j++)
		{
			putpixel( i, j, RGB(3, 128, 128));
		}	
		for(j = alt2 + tam_ver; j < alt2 + tam_ver + 3; j++)
		{
			putpixel( i, j, RGB(3, 128, 128));
		}
	}
	/*desenha as barras laterais*/
	for(j = alt2; j < alt2 + tam_ver; j++)
	{
		for(i = alt1 -3; i < alt1; i++)
		{
			putpixel( i, j, RGB(3, 128, 128));
		}	
		for(i = alt1 + tam_hor; i < alt1 + tam_hor + 3; i++)
		{
			putpixel( i, j, RGB(3, 128, 128));
		}
	}
	/*desenha o quadrado de cores*/
	for(i = alt1 ; i <  alt1 + tam_hor; i++)
	{	
		red = rand()% 256;
		green = rand()% 256;
		blue = rand()% 256;
		color = RGB(red, green, blue);
		for (j = alt2; j < alt2 + tam_ver; j++)
		{
			putpixel(i, j, color);
		}
	}
	gotoxy(152,6);
	printf("Editar cor");
}

/*quadradinho da cor de ser dividido por 3 + /3 a resolucaoX*/
void print_user_color(COLORREF color)
{
	COORD resolution;
	register int i, j;
	int pos_ver, pos_hor, tam_quad;
	resolution = getResolucaoMonitor();
	pos_hor = (resolution.X / 3) + (resolution.X / 5);
	pos_ver = resolution.Y / 45;
	tam_quad = resolution.X / 35;
	for(i = pos_hor; i < pos_hor + tam_quad; i++)
	{
		for(j = pos_ver; j < pos_ver + tam_quad; j++)
		{
			putpixel(i, j, color);
		}
	}	
	/*desenha a barra superior e inferior*/
	for(i = pos_hor; i < pos_hor + tam_quad + 3; i++)
	{
		for(j = pos_ver - 3; j < pos_ver; j++)
		{
			putpixel( i, j, RGB(3, 128, 128));
		}
		for(j = pos_ver + tam_quad; j < pos_ver + tam_quad + 3; j++)
		{
			putpixel( i, j, RGB(3, 128, 128));
		}
	}
	/*desenha as barras laterais*/
	for(j = pos_ver - 3; j < pos_ver + tam_quad + 3; j++)
	{
		for(i = pos_hor -3; i < pos_hor; i++)
		{
			putpixel( i, j, RGB(3, 128, 128));
		}	
		for(i = pos_hor + tam_quad; i < pos_hor + tam_quad + 3; i++)
		{
			putpixel( i, j, RGB(3, 128, 128));
		}
	}
}

