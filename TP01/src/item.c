/*
 * item.c
 *
 *  Created on: 7 de set de 2017
 *      Author: Caio Silva
 */

#ifndef ITEM_C_
#define ITEM_C_
#include "Quadrado.h"
#include "stddef.h"

int duracaoEscudo;
int novoItem;
int colidiuItem;
bool escudo;


void geraItem(QUADRADO player[], int tamanhoPlayer, QUADRADO obstaculos[], int numeroMaxObstaculos, QUADRADO* item, QUADRADO* ponto){
	srand(clock());
	int tipoItem = 5;
	item->tipoItem = tipoItem;
	while(1){
		float x=(rand()%70 + 10);
		float y=(rand()%70 + 10);
		item->x = x;
		item->y = y;
		item->largura = 3;
		item->altura = 3;
		if(colideObstaculos(item, obstaculos, numeroMaxObstaculos) || colideObstaculos(item, player, tamanhoPlayer)
				|| verificaColisao(item, ponto)) continue;
		else break;
	}
	//int tipoItem = (rand()%2);

}

void geraPonto(QUADRADO player[], int tamanhoPlayer, QUADRADO obstaculos[], int numeroMaxObstaculos, QUADRADO* item, QUADRADO* ponto){
	srand(clock());
	while(1){
		float x=(rand()%70 + 10);
		float y=(rand()%70 + 10);
		ponto->x = x;
		ponto->y = y;
		ponto->largura = 3;
		ponto->altura = 3;
		if(colideObstaculos(ponto, obstaculos, numeroMaxObstaculos) || colideObstaculos(ponto, player, tamanhoPlayer)
				|| verificaColisao(ponto, item)) continue;
		else break;
	}
}

void funcaoItem(QUADRADO* item, QUADRADO* player, QUADRADO *obstaculos, int numeroMaxObstaculos, QUADRADO* ponto){
	colidiuItem = true;
	novoItem = 100;
	item->x = 300;
	item->y = 300;


	switch(item->tipoItem){
		case 0: // escudo
			escudo = true;

			break;
		case 1: // 2x

			break;
		case 3: // 3x

			break;
		case 4: // 4x

			break;
		case 5: // TP
			while(1){
				float x=(rand()%70 + 10);
				float y=(rand()%70 + 10);
				player->x = x;
				player->y = y;
				player->largura = 3;
				player->altura = 3;
				if(colideObstaculos(player, obstaculos, numeroMaxObstaculos) || verificaColisao(player, item)
						|| verificaColisao(player, ponto)) continue;
				else break;
			}

			break;
		case 6: // portal


			break;
		default:
			break;
	}

}





#endif /* ITEM_C_ */
