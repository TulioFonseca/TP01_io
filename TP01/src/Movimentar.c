/*
 * Movimentar.c
 *
 *  Created on: 4 de set de 2017
 *      Author: tu-12
 */
#include <stdbool.h>
void movimentarObjeto(int direcao, bool PAUSE){
	if (!PAUSE){
			if (direcao == CIMA){
					pontoY += PASSO;
				}else if (direcao == BAIXO){
					pontoY -= PASSO;

				}else if (direcao == DIREITA){
					pontoX += PASSO;

				}else if(direcao == ESQUERDA){
					pontoX -= PASSO;
				}
				if (colisaoParede(pontoX,pontoY) == 1){
					printf("Colidiu no ponto x : %d e ponto y: %d \n", pontoX, pontoY);
					Sleep(500);
					exit(0);
				}

		}
}

