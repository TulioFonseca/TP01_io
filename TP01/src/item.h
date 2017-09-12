/*
 * item.h
 *
 *  Created on: 7 de set de 2017
 *      Author: Caio Silva
 */

#ifndef ITEM_H_
#define ITEM_H_
#include "Quadrado.h"

void geraItem(QUADRADO* player, int tamanhoPlayer, QUADRADO obstaculos[], int numeroMaxObstaculos, QUADRADO* item, QUADRADO* ponto);

void geraPonto(QUADRADO* player, int tamanhoPlayer, QUADRADO obstaculos[], int numeroMaxObstaculos, QUADRADO* item, QUADRADO* ponto);

void funcaoItem(QUADRADO* item, QUADRADO* player, QUADRADO *obstaculos, int numeroMaxObstaculos, QUADRADO* ponto);

#endif /* ITEM_H_ */
