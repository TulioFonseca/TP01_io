/*
 * colisao.c
 *
 *  Created on: 3 de set de 2017
 *      Author: Caio Silva
 */


#include "Quadrado.h"
#include <stdbool.h>
#include "colisao.h"

bool verificaColisao(QUADRADO *quadrado1, QUADRADO *quadrado2) {
	float esquerda1, direita1, cima1, baixo1;
	float esquerda2, direita2, cima2, baixo2;

	esquerda1 = quadrado1->x;
	direita1 = quadrado1->x + quadrado1->largura;
	baixo1 = quadrado1->y;
	cima1 = quadrado1->y + quadrado1->altura;
	esquerda2 = quadrado2->x;
	direita2 = quadrado2->x + quadrado2->largura;
	baixo2 = quadrado2->y;
	cima2 = quadrado2->y + quadrado2->altura;


	if (esquerda1 > direita2){

		return false; //
	}
	if (direita1 < esquerda2){

		return false; //
	}
	if (baixo1 > cima2) {

		return false; //
	}
	if (cima1 < baixo2){

		return false; //
	}
	return true;
}

bool colideObstaculos(QUADRADO *quadrado, QUADRADO obstaculos[], int numeroMaxObstaculos){
	for(int i = 0; i < numeroMaxObstaculos; i++){
		if(verificaColisao(quadrado, obstaculos))
			return true;
		obstaculos++;
	}

	return false;

}

bool colisaoParede(float pontoX, float pontoY){
	if (pontoY >= 85.0 || pontoX >= 100.0 || pontoX <= 0.0 || pontoY <= 0.0 ){
			return true;
		}
		return false;
}

bool colisaoParedeMouse(float pontoX, float pontoY){
	if (pontoY >= 85.0 || pontoX >= 98.0 || pontoX <= 0.0 || pontoY <= 1.0 ){
			return true;
		}
		return false;
}

