/*
 * Movimentar.c
 *
 *  Created on: 4 de set de 2017
 *      Author: tu-12
 */

#include "Movimentar.h"


int movimentarObjeto(int direcao, bool PAUSE, QUADRADO player[], int tamanhoPlayer, QUADRADO *obstaculos, int numeroMaxObstaculos, QUADRADO *item){

	if (!PAUSE){

		//salvando posicao ultima posicao player
		QUADRADO ultimo = player[tamanhoPlayer];

		//Apagando rastro do player
		for (int i = tamanhoPlayer; i > 0; i--){
			player[i] = player[i-1];
		}


		if (direcao == CIMA){
			player[0].y += PASSO;
			if(colideObstaculos(&player[0], obstaculos, numeroMaxObstaculos)) tamanhoPlayer = morre(&player[0], tamanhoPlayer);

		}else if (direcao == BAIXO){
			player[0].y -= PASSO;
			if(colideObstaculos(&player[0], obstaculos, numeroMaxObstaculos)) tamanhoPlayer = morre(&player[0], tamanhoPlayer);

		}else if (direcao == DIREITA){
			player[0].x += PASSO;
			if(colideObstaculos(&player[0], obstaculos, numeroMaxObstaculos)) tamanhoPlayer = morre(&player[0], tamanhoPlayer);

		}else if(direcao == ESQUERDA){
			player[0].x -= PASSO;
			if(colideObstaculos(&player[0], obstaculos, numeroMaxObstaculos)) tamanhoPlayer = morre(&player[0], tamanhoPlayer);
		}
		if (colisaoParede(player[0].x,player[0].y)){
			tamanhoPlayer= morre(&player[0], tamanhoPlayer);
		}



		//Verifica se pegou o item
		if(verificaColisao(item, &player[0])){
			//aumenta tamanho player


			switch(item->tipoItem){
				case 0: // normal
					tamanhoPlayer++;
					player[tamanhoPlayer] = ultimo;
					break;
				case 1: // ivulneravel
					player[0].escudo = true;

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
	return tamanhoPlayer;
}



int morre(QUADRADO* player, int tamanhoPlayer){
	//printf("PASSEI AQUI \n");
	//if(player->escudo){
		//player->escudo = false;

		//return tamanhoPlayer;
	//}

	//if(tamanhoPlayer == 0) exit(0);

	//tamanhoPlayer--;
	//return tamanhoPlayer;

	exit(0);
}



