/*
 * Movimentar.c
 *
 *  Created on: 4 de set de 2017
 *      Author: tu-12
 */

#include "Movimentar.h"
#include <stdio.h>
#include <string.h>

int tamanhoPlayer;
int pontuacao;


void movimentaMouse(QUADRADO player[], int x, int y, QUADRADO *obstaculos, int numeroMaxObstaculos, QUADRADO *item,bool PAUSE){
		QUADRADO ultimo = player[tamanhoPlayer];

				//Apagando rastro do player


		player[0].y += ((100-(y/4))-player[0].y);
		player[0].x += (((x/4))-player[0].x);
		for (int i = tamanhoPlayer; i > 0; i--){
				player[i] = player[i-1];
			}
		if(colideObstaculos(&player[0], obstaculos, numeroMaxObstaculos)) morre(player,PAUSE);
		if (colisaoParedeMouse(player[0].x,player[0].y)){
					//morre(player);


			finalJogo(PAUSE);
		}
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
					geraItem(player, tamanhoPlayer, obstaculos, numeroMaxObstaculos, item);

		}
}

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
			if(colideObstaculos(&player[0], obstaculos, numeroMaxObstaculos)) morre(player,PAUSE);
		}else if (direcao == BAIXO){
			player[0].y -= PASSO;
			if(colideObstaculos(&player[0], obstaculos, numeroMaxObstaculos)) morre(player,PAUSE);
		}else if (direcao == DIREITA){
			player[0].x += PASSO;
			if(colideObstaculos(&player[0], obstaculos, numeroMaxObstaculos)) morre(player,PAUSE);
		}else if(direcao == ESQUERDA){
			player[0].x -= PASSO;
			if(colideObstaculos(&player[0], obstaculos, numeroMaxObstaculos)) morre(player,PAUSE);
		}
		if (colisaoParede(player[0].x,player[0].y)){
			//morre(player);
			finalJogo(PAUSE);
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





void morre(QUADRADO player[], bool PAUSE){

	for(int i=0; i <= tamanhoPlayer; i++){
		if(player[i].escudo){
			player[i].escudo = false;
			player[i].duracaoEscudo = 7;
			continue;
		}
		if(player[i].duracaoEscudo > 0){
			player[i].duracaoEscudo--;
			continue;
		}else if(tamanhoPlayer == 0){
			printf("Teste");
			finalJogo(PAUSE);
		}
		else{
			tamanhoPlayer--;
			for(int j=0; j <= tamanhoPlayer; j++)
				player[i].escudo = true;
			break;
		}
	}

}



void finalJogo(bool PAUSE){
	PAUSE = true;
	gameOver();
	Sleep(3000);
	//printf("PONTUACAO: %5d", pontuacao);
	exit(0);
}



