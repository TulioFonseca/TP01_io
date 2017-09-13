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
bool portal;



void geraItem(QUADRADO player[], int tamanhoPlayer, QUADRADO obstaculos[], int numeroMaxObstaculos, QUADRADO* item, QUADRADO* ponto){
	srand(clock());
	int tipoItem = rand()%3;
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

void funcaoItem(QUADRADO* item, QUADRADO* player, QUADRADO *obstaculos, int numeroMaxObstaculos, QUADRADO* ponto, QUADRADO* portal1, QUADRADO* portal2){
	colidiuItem = true;
	novoItem = 100;
	item->x = 300;
	item->y = 300;
	srand(clock());
	int escolha = (rand()%3);
	float x1, y1;
	float x2, y2;
	float altura, largura;


	switch(item->tipoItem){
		case 0: // escudo
			escudo = true;
			break;

		case 1: // TP
			srand(clock());
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
		case 2: // portal

			portal = true;
			srand(clock());
			switch(escolha){
			case 0:
				y1 = (rand()%81 + 1);
				x1 = 1;
				x2 = 98;
				y2 = (rand()%81 + 1);
				altura = 5;
				largura = 1;
				break;
			case 1:
				y1 = (rand()%81 + 1);
				x1 = 98;
				x2 = 1;
				y2 = (rand()%81 + 1);
				altura = 5;
				largura = 1;
				break;
			case 2:
				x1 = (rand()%93 + 1);
				y1 = 1;
				y2 = 85;
				x2 = (rand()%93 + 1);
				altura = 1;
				largura = 5;
				break;
			case 3:
				x1=(rand()%93 + 1);
				y1 = 85;
				y2 = 1;
				x2 = (rand()%93 + 1);
				altura = 1;
				largura = 5;
				break;
			default:
				break;
			}

			portal1->x = x1;
			portal1->y = y1;
			portal1->altura = altura;
			portal1->largura = largura;

			portal2->x = x2;
			portal2->y = y2;
			portal2->altura = altura;
			portal2->largura = largura;


			break;
		default:
			break;
	}

}





#endif /* ITEM_C_ */
