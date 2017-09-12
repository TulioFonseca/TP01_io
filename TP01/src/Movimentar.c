/*
 * Movimentar.c
 *
 *  Created on: 4 de set de 2017
 *      Author: tu-12
 */

#include "Movimentar.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int tamanhoPlayer;
int pontuacao;
bool escudo;
int duracaoEscudo;
int novoItem;
int colidiuItem;



void movimentaMouse(QUADRADO player[], int x, int y, QUADRADO *obstaculos, int numeroMaxObstaculos, QUADRADO *item, bool PAUSE, QUADRADO* ponto){
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
		//Verifica se pegou o ponto
		if(verificaColisao(ponto, &player[0])){
			//aumenta tamanho player
			tamanhoPlayer++;
			player[tamanhoPlayer] = ultimo;
			pontuacao++;
			geraPonto(player, tamanhoPlayer, obstaculos, numeroMaxObstaculos, item, ponto);
		}

		//Verifica se pegou o item
		if(verificaColisao(item, &player[0])){
			funcaoItem(item, &player[0], obstaculos, numeroMaxObstaculos, ponto);
		}
		//Gera novo item
		if(colidiuItem && novoItem > 0) novoItem --;
		else if(colidiuItem){
			colidiuItem = false;
			geraItem(player, tamanhoPlayer, obstaculos, numeroMaxObstaculos, item, ponto);
		}

		}


void movimentarObjeto(int direcao, bool PAUSE, QUADRADO player[], QUADRADO *obstaculos, int numeroMaxObstaculos, QUADRADO *item, QUADRADO* ponto){
	if (!PAUSE){
		//salvando posicao ultima posicao player
		QUADRADO ultimo = player[tamanhoPlayer];
		//Apagando rastro do player
		for (int i = tamanhoPlayer; i > 0; i--){
			player[i] = player[i-1];
		}
		if (direcao == CIMA){
			player[0].y += PASSO;
			if(colideObstaculos(&player[0], obstaculos, numeroMaxObstaculos)) morre(&player[0],PAUSE);
		}else if (direcao == BAIXO){
			player[0].y -= PASSO;
			if(colideObstaculos(&player[0], obstaculos, numeroMaxObstaculos)) morre(&player[0],PAUSE);
		}else if (direcao == DIREITA){
			player[0].x += PASSO;
			if(colideObstaculos(&player[0], obstaculos, numeroMaxObstaculos)) morre(&player[0],PAUSE);
		}else if(direcao == ESQUERDA){
			player[0].x -= PASSO;
			if(colideObstaculos(&player[0], obstaculos, numeroMaxObstaculos)) morre(&player[0],PAUSE);
		}
		if (colisaoParede(player[0].x,player[0].y)){
			//morre(player);
			finalJogo(PAUSE);
		}
		//Verifica se pegou o ponto
		if(verificaColisao(ponto, &player[0])){
			//aumenta tamanho player
			tamanhoPlayer++;
			player[tamanhoPlayer] = ultimo;
			pontuacao++;
			geraPonto(player, tamanhoPlayer, obstaculos, numeroMaxObstaculos, item, ponto);
		}

		//Verifica se pegou o item
		if(verificaColisao(item, &player[0])){
			funcaoItem(item, &player[0], obstaculos, numeroMaxObstaculos, ponto);

		}

		//Gera novo item
		if(colidiuItem && novoItem > 0) novoItem --;
		else if(colidiuItem){
			colidiuItem = false;
			geraItem(player, tamanhoPlayer, obstaculos, numeroMaxObstaculos, item, ponto);
		}


	}
}



void morre(QUADRADO* player, bool PAUSE){
	if(escudo){
		escudo = false;
		duracaoEscudo = 7;

	}else if(duracaoEscudo > 0){
		duracaoEscudo--;

	}else if(tamanhoPlayer == 0) {
		finalJogo(PAUSE);

	}else{
		tamanhoPlayer--;
		duracaoEscudo = 7;
	}

}



void finalJogo(bool PAUSE){
	PAUSE = true;
	gameOver();
	Sleep(3000);
	//printf("PONTUACAO: %5d", pontuacao);
	exit(0);
}



