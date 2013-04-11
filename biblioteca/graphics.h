
#ifndef _GRAPHICS_  /* incluir este arquivo somente uma vez */
 #define _GRAPHICS_

/* Biblioteca gr�fica que permite plotar pixels na janela de console
   Observa��o: todo programa que for utiliz�-la deve link�-lo juntamente com a biblioteca libgdi32.a.
               Exemplo: gcc -o prog prog.c graphics.c -lgdi32 -Wall -pedantic
*/			   

#include <windows.h>

/* - Plotar 1 pixel na tela na posi��o: (x,y), com x variando no intervalo [0; altura da �rea do prompt de comando] e
     y variando no intervalo [0; largura da �rea do prompt de comando]
   - Cor do pixel dada pelo tipo: COLORREF.
     COLORREF: usa a macro RGB (http://msdn.microsoft.com/en-us/library/aa927387.aspx)
               COLORREF RGB(BYTE byRed, BYTE byGreen, BYTE byBlue);
     Exemplos de uso:
     putpixel(100,100, RGB(255, 0, 0));   
     putpixel(100,100, 0x00FF0000);
     -> Refer�ncia para consulta de COLORREF: http://msdn.microsoft.com/en-us/library/aa923096.aspx
*/   
void putpixel(int x, int y, COLORREF);

/* Recuperar o valor RGB da cor do pixel especificado pelas coordenadas x,y. 
   Exemplo de uso:
           setpixel(100, 100, RGB(255, 0, 254));   
           printf("%08x", (unsigned) getpixel(100, 100));
		   
           Nessa linha o resultado ser�: 00FF00FE
		   1� BYTE (mais alta ordem -> byte mais a esquerda) = valor 00 (valor fixo e sempre igual a 00)
		   2� BYTE = FF (representa a intensidade da cor VERMELHA)
		   3� BYTE = 00 (representa a intensidade da cor VERDE)
		   4� BYTE (mais baixa ordem -> byte mais a direita) = FE (representa a intensidade da cor AZUL 
   
   Retorna a estrutura COLORREF que � um valor de 32 bits sem sinal (ou seja, um unsigned int):
   - Refer�ncia para consulta de COLORREF: http://msdn.microsoft.com/en-us/library/aa923096.aspx
*/
COLORREF getpixel(int x, int y);

/* Desenhar uma linha de pixels na tela.
   Entrada: 
   -> x1, y1: coordenadas do ponto inicial da linha na tela
   -> x2, y2: coordenadas do ponto final da linha na tela   
   -> cor: cor no formato RGB (R = RED, G = GREEN, B = BLUE) com a qual a linha ser� desenhada na tela. 
      Ex.: cor_vermelha = RGB(255, 0, 0);  
*/
void linha(int x1, int y1, int x2, int y2, COLORREF cor);

#endif /* fim do #if */
