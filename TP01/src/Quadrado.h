/*
 * Quadrado.h
 *
 *  Created on: 3 de set de 2017
 *      Author: Caio Silva
 */

#ifndef QUADRADO_H_
#define QUADRADO_H_
#include <stdbool.h>

typedef struct quadrado {
	float x;
	float y;
	float largura;
	float altura;
	bool escudo;
	int tipoItem;
	int duracaoEscudo;
} QUADRADO;

#endif /* QUADRADO_H_ */
