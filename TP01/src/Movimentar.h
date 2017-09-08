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

int movimentarObjeto(int direcao, bool PAUSE, QUADRADO player[], int tamanhoPlayer, QUADRADO *obstaculos, int numeroMaxObstaculos, QUADRADO* item);
int morre(QUADRADO* player, int tamanhoPlayer);
#endif /* MOVIMENTAR_H_ */
