/*
 * Movimentar.h
 *
 *  Created on: 4 de set de 2017
 *      Author: tu-12
 */

#ifndef MOVIMENTAR_H_
#define MOVIMENTAR_H_

#include <stdbool.h>
#include <stdbool.h>
#include "Quadrado.h"
#include "colisao.h"

#define PASSO 1
#define CIMA 1
#define BAIXO 2
#define DIREITA 3
#define ESQUERDA 4

#define RIGHT 102
#define LEFT 100
#define UP 101
#define DOWN 103

void movimentarObjeto(int direcao, bool PAUSE, QUADRADO player[], QUADRADO *obstaculos, int numeroMaxObstaculos, QUADRADO* item);
void morre(QUADRADO* player);
#endif /* MOVIMENTAR_H_ */
