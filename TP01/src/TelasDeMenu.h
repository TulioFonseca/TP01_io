/*
 * menuIniciar.h
 *
 *  Created on: 9 de set de 2017
 *      Author: tu-12
 */

#ifndef TELASDEMENU_H_
#define TELASDEMENU_H_

#include <GL/glew.h>
#include <GL/freeglut.h>
#define DESCE 1
#define SOBE 2

void menu(int opcao, int contador);
void DesenhaTexto(char *string, int x , int y);
int selecionar(int contador);
void DesenhaBorda(int x, int y);
void DesenhaTextoInstrucao(char *string, int x , int y);
void menuOpcao(int opcao, int contador);
void DesenhaPontuacao(char *string, int x , int y);

#endif /* TELASDEMENU_H_ */
