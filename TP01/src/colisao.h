/*
 * colisao.h
 *
 *  Created on: 3 de set de 2017
 *      Author: Caio Silva
 */



#ifndef COLISAO_H_
#define COLISAO_H_
#include "Quadrado.h"
#include <stdbool.h>

bool verificaColisao(QUADRADO* quadrado1, QUADRADO* quadrado2);

bool colideObstaculos(QUADRADO* quadrado, QUADRADO obstaculos[], int numeroMaxObstaculos);

bool colisaoParede(float pontoX, float pontoY);

bool colisaoParedeMouse(float pontoX, float pontoY);
#endif /* COLISAO_H_ */
