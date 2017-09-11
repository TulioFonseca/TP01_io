/*
 * Teclado.h
 *
 *  Created on: 11 de set de 2017
 *      Author: tu-12
 */

#ifndef TECLADO_H_
#define TECLADO_H_

#include "Movimentar.h"
#include "TelasDeMenu.h"
#include <stdbool.h>



void reiniciar();
int reiniciando();
int tecladoMovimentacao (unsigned char key, int x, int y);
void tecladoEspecialMovimentacao(int key, int x, int y);
void tecladoEspecialMovimentacaoMenu(int key, int x, int y);
int tecladoMovimentacaoMenu(unsigned char key, int x, int y);



#endif /* TECLADO_H_ */
