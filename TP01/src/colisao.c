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


	/*printf("esquerda1 %f\n", quadrado1->x);
	printf("direita1 %f\n", direita1);
	printf("baixo1 %f\n", baixo1);
	printf("cima1 %f\n", cima1);
	printf("esquerda2 %f\n", esquerda2);
	printf("direita2 %f\n", direita2);
	printf("baixo2 %f\n", baixo2);
	printf("cima2 %f\n", cima2);*/

	if (esquerda1 > direita2){
		//printf("Teste1");
		return false; //
	}
	if (direita1 < esquerda2){
		//printf("Teste2");
		return false; //
	}
	if (baixo1 > cima2) {
		//("Teste3");
		return false; //
	}
	if (cima1 < baixo2){
		//printf("Teste4");
		return false; //
	}			  //do
	return true;
}

bool colideObstaculos(QUADRADO *quadrado, QUADRADO obstaculos[], int qtdObstaculos){
	for(int i = 0; i < qtdObstaculos; i++){
		if(verificaColisao(quadrado, obstaculos++))
			return true;
	}
	return false;

}

bool colisaoParede(float pontoX, float pontoY){
	if (pontoY >= 100.0 || pontoX >= 100.0 || pontoX <= 0.0 || pontoY <= 0.0 ){
			return true;
		}
		return false;
}
