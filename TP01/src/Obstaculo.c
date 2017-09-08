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

void criaObstaculos(QUADRADO player[], QUADRADO obstaculos[], int numeroMaxObstaculos){
	int i = 0;
	srand(clock());
	while(i < numeroMaxObstaculos){

		float x=(rand()%80 + 10);
		float y=(rand()%80 + 10);
		QUADRADO quadrado = {x,y,3,3};

		if(colideObstaculos(&quadrado, obstaculos, numeroMaxObstaculos) || verificaColisao(&quadrado, &player[0])) continue;
		obstaculos[i] = quadrado;
		i++;
	}
	//printf("%5f   %5f \n", obstaculos[0].x, obstaculos[0].y);

}




