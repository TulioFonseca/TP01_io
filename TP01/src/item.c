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

void geraItem(QUADRADO player[], int tamanhoPlayer, QUADRADO obstaculos[], int numeroMaxObstaculos, QUADRADO* item){
	srand(clock());
	while(1){
		float x=(rand()%80 + 10);
		float y=(rand()%80 + 10);
		item->x = x;
		item->y = y;
		item->largura = 3;
		item->altura = 3;
		if(colideObstaculos(item, obstaculos, numeroMaxObstaculos) || colideObstaculos(item, player, tamanhoPlayer)) continue;
		else break;
	}
	//int tipoItem = (rand()%2);
	int tipoItem = 0;
	item->tipoItem = tipoItem;
	switch(tipoItem){
		case 0: // normal
			break;
		case 1: // escudo
			player[0].escudo = 1;
			break;
		case 2: //

			break;
		case 3: //

			break;
		default:
			break;
	}
}


#endif /* ITEM_C_ */
