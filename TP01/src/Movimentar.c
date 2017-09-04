/*
 * Movimentar.c
 *
 *  Created on: 4 de set de 2017
 *      Author: tu-12
 */

#include "Movimentar.h"


void movimentarObjeto(int direcao, bool PAUSE, QUADRADO *player, QUADRADO *obstaculos, int qtdObstaculos){

	if (!PAUSE){
		if (direcao == CIMA){
			player->y += PASSO;
			if(colideObstaculos(player, obstaculos, qtdObstaculos)) morre();

		}else if (direcao == BAIXO){
			player->y -= PASSO;
			if(colideObstaculos(player, obstaculos,qtdObstaculos)) morre();

		}else if (direcao == DIREITA){
			player->x += PASSO;
			if(colideObstaculos(player, obstaculos, qtdObstaculos)) morre();

		}else if(direcao == ESQUERDA){
			player->x -= PASSO;
			if(colideObstaculos(player, obstaculos, qtdObstaculos)) morre();
		}
		if (colisaoParede(player->x,player->y)){
			morre();
		}
	}
}

void morre(){
	exit(0);
}

