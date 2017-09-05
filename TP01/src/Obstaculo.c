/*
 * Obstaculo.c
 *
 *  Created on: 4 de set de 2017
 *      Author: Caio Silva
 */


#include "Obstaculo.h"
#include "Quadrado.h"
#include "colisao.h"
#include "stddef.h"

void criaObstaculos(QUADRADO* player, QUADRADO obstaculos[], int numeroMaxObstaculos){
	int i = 0;
	srand(time(NULL));
	while(i < numeroMaxObstaculos){

		float x=(rand()%80 + 10);
		float y=(rand()%80 + 10);
		QUADRADO quadrado = {x,y,3,3};

		if(colideObstaculos(&quadrado, obstaculos, numeroMaxObstaculos) || verificaColisao(&quadrado, player)) continue;
		obstaculos[i] = quadrado;
		i++;
	}
}

QUADRADO geraItem(QUADRADO* player, QUADRADO obstaculos[], int numeroMaxObstaculos){
	srand(time(NULL));
	while(1){
		float x=(rand()%80 + 10);
		float y=(rand()%80 + 10);
		QUADRADO item = {x,y,3,3};
		if(colideObstaculos(&item, obstaculos, numeroMaxObstaculos) || verificaColisao(&item, player)) continue;
		else return item;




	}

}


