/*
 * colisao.c
 *
 *  Created on: 3 de set de 2017
 *      Author: Caio Silva
 */


#include "Quadrado.h"
#include <stdbool.h>

bool verificaColisao(QUADRADO *quadrado1, QUADRADO *quadrado2) {
	int esquerda1, direita1, cima1, baixo1;
	int esquerda2, direita2, cima2, baixo2;
	esquerda1 = quadrado1->x;
	direita1 = quadrado1->x + quadrado1->largura;
	cima1 = quadrado1->y;
	baixo1 = quadrado1->y + quadrado1->altura;
	esquerda2 = quadrado2->x;
	direita2 = quadrado2->x + quadrado2->largura;
	 cima2 = quadrado2->y;
	 baixo2 = quadrado2->y + quadrado2->altura;
	if (esquerda1 > direita2){
		return false; // (não colisão)
	}
	if (direita1 < esquerda2){
		return false; // (não colisão)
	}
	if (cima1 > baixo2) {
		return false; // (não colisão)
	}
	if (baixo1 < cima2){
		return false; // (não colisão)
	}			  //do contrário (COLISÃO)/
	return true;
}
