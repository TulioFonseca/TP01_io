/*
 * Variaveis.h
 *
 *  Created on: 11 de set de 2017
 *      Author: tu-12
 */

#ifndef VARIAVEIS_H_
#define VARIAVEIS_H_
#include <stdbool.h>

int pontuacao;
char pontos[100];
char ponto[100];

char vidas[100];
char vida[100];


int NUMERO_MAX_OBSTACULOS = 10;
//int pontoX = 50, pontoY = 50;
int direcao = 0;
bool menuAtivado = true;

int velocidade = 33;
const int larguraTela = 400;
const int alturaTela = 400;
int tamanhoPlayer;

bool reinicia = false;
bool PAUSE = false;
bool sistema;
int contador = 3;
int contadorOpcao = 3;
int liberarMenu;

int pontuacao;

#endif /* VARIAVEIS_H_ */
