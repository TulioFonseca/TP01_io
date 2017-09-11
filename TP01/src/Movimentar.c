/*
 * Movimentar.c
 *
 *  Created on: 4 de set de 2017
 *      Author: tu-12
 */

#include "Movimentar.h"

int tamanhoPlayer;
int pontuacao;

void movimentarObjeto(int direcao, bool PAUSE, QUADRADO player[], QUADRADO *obstaculos, int numeroMaxObstaculos, QUADRADO *item){

	if (!PAUSE){

		//salvando posicao ultima posicao player
		QUADRADO ultimo = player[tamanhoPlayer];

		//Apagando rastro do player
		for (int i = tamanhoPlayer; i > 0; i--){
			player[i] = player[i-1];
		}


		if (direcao == CIMA){
			player[0].y += PASSO;
			if(colideObstaculos(&player[0], obstaculos, numeroMaxObstaculos)) morre(player);

		}else if (direcao == BAIXO){
			player[0].y -= PASSO;
			if(colideObstaculos(&player[0], obstaculos, numeroMaxObstaculos)) morre(player);

		}else if (direcao == DIREITA){
			player[0].x += PASSO;
			if(colideObstaculos(&player[0], obstaculos, numeroMaxObstaculos)) morre(player);

		}else if(direcao == ESQUERDA){
			player[0].x -= PASSO;
			if(colideObstaculos(&player[0], obstaculos, numeroMaxObstaculos)) morre(player);
		}
		if (colisaoParede(player[0].x,player[0].y)){
			morre(player);
		}



		//Verifica se pegou o item
		if(verificaColisao(item, &player[0])){
			//aumenta tamanho player


			switch(item->tipoItem){
				case 0: // normal
					tamanhoPlayer++;
					player[tamanhoPlayer] = ultimo;
					pontuacao++;
					break;
				case 1: // escudo
					for(int i=0; i <= tamanhoPlayer; i++)
						player[i].escudo = true;
					break;
				case 3: //

					break;
				case 4: //

					break;
				default:
					break;
			}

			//Gera novo item
			geraItem(player, tamanhoPlayer, obstaculos, numeroMaxObstaculos, item);
		}


	}
}





void morre(QUADRADO player[]){

	for(int i=0; i <= tamanhoPlayer; i++){
		if(player[i].escudo){
			player[i].escudo = false;
			player[i].duracaoEscudo = 7;
			continue;
		}
		if(player[i].duracaoEscudo > 0){
			player[i].duracaoEscudo--;
			continue;
		}else if(tamanhoPlayer == 0) finalJogo();
		else{
			tamanhoPlayer--;
			for(int j=0; j <= tamanhoPlayer; j++)
				player[i].escudo = true;
			break;
		}
	}

}

void finalJogo(){
	printf("PONTUACAO: %5d", pontuacao);
	exit(0);
}



