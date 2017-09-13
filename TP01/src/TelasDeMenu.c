/*
 * menuIniciar.c
 *
 *  Created on: 9 de set de 2017
 *      Author: tu-12
 */
#include "TelasDeMenu.h"

int posicaoXborda = 5;
int posicaoYborda = 70;
bool mouse;
bool mouseHabilitado;
float pontoMouseX, pontoMouseY;
int contadorParadaMouse = 0;

void menu(int opcao, int contador){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1,1);
	DesenhaTextoInstrucao("Precione ENTER para selecionar",0,90);
	DesenhaTexto("INICIAR JOGO",10,60);
	DesenhaTexto("SAIR",10,40);
	//DesenhaTexto("SAIR",10,20);
	movimentoSetasMouseTeclado(opcao);
	DesenhaBorda(posicaoXborda,posicaoYborda);
	glutSwapBuffers();

}




void movimentoSetasMouseTeclado(int opcao){
	 if(mouse){

			if(!mouseHabilitado){
				if(pontoMouseX >= 10.0 && pontoMouseX <= 390.0 && pontoMouseY >= 140.0 && pontoMouseY <= 180.0 ){
					posicaoYborda = 70;
				}else if(pontoMouseX >= 10.0 && pontoMouseX <= 390.0 && pontoMouseY >= 200.0 && pontoMouseY <= 240.0 ){
					posicaoYborda = 30;
				}
			}else if (mouseHabilitado){
				if(pontoMouseX >= 10.0 && pontoMouseX <= 390.0 && pontoMouseY >= 140.0 && pontoMouseY <= 180.0 ){
					posicaoYborda = 70;
				}else if(pontoMouseX >= 10.0 && pontoMouseX <= 390.0 && pontoMouseY >= 200.0 && pontoMouseY <= 240.0 ){
					posicaoYborda = 50;
				}
			}

		}else{
			if(opcao == DESCE)
				posicaoYborda -= 20;
			if(opcao == SOBE)
				posicaoYborda += 20;
		}
}

void gameOver(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1,1);
	DesenhaGameOver("GAME OVER",30,50);
	glutSwapBuffers();
}


void menuOpcao(int opcao, int contador){
	glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1, 1,1);
		DesenhaTextoInstrucao("Precione ENTER para selecionar",0,90);
		DesenhaTexto("DESEJA REINICIAR O JOGO ?",10,80);
		DesenhaTexto("SIM",10,60);
		DesenhaTexto("NAO",10,40);
		movimentoSetasMouseTeclado(opcao);
		DesenhaBorda(posicaoXborda,posicaoYborda);
		glutSwapBuffers();
}
int selecionar(int contador){
	if(contador == 2){
		exit(0);
	}else if(contador == 3){
		return 1;
	}
	return 0;
}


void DesenhaPontuacao(char *string, int x, int y){
	    glPushMatrix();
	        // Posição no universo onde o texto será colocado
	        //glRasterPos2f(-win,win-(win*0.08));
	  	glRasterPos2f(x,y);
	        // Exibe caracter a caracter
		while(*string)
			 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,*string++);
		glPopMatrix();
}
void DesenhaGameOver(char *string, int x , int y){
	glPushMatrix();
		// Posição no universo onde o texto será colocado
		//glRasterPos2f(-win,win-(win*0.08));
	glRasterPos2f(x,y);
		// Exibe caracter a caracter
	while(*string)
		 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*string++);
	glPopMatrix();


}

void DesenhaBordaPontucao(int x, int y){
	glLineWidth(1.0f);
	glColor3f(1.00f, 0.00f, 0.00f);
		glBegin(GL_LINE_LOOP);
		glVertex2f(x,y);
		glVertex2f(95,y);
		glVertex2f(95, y-15);
		glVertex2f(x, y-15);
	glEnd();

}

void DesenhaBorda(int x, int y){
	glLineWidth(1.0f);
	glColor3f(1.00f, 0.00f, 0.00f);
		glBegin(GL_LINE_LOOP);
		glVertex2f(x,y);
		glVertex2f(95,y);
		glVertex2f(95, y-15);
		glVertex2f(x, y-15);
	glEnd();

}




void DesenhaTexto(char *string, int x , int y)
{
  	glPushMatrix();
        // Posição no universo onde o texto será colocado
        //glRasterPos2f(-win,win-(win*0.08));
  	glRasterPos2f(x,y);
        // Exibe caracter a caracter
	while(*string)
		 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*string++);
	glPopMatrix();
}

void DesenhaTextoInstrucao(char *string, int x , int y)
{
  	glPushMatrix();
        // Posição no universo onde o texto será colocado
        //glRasterPos2f(-win,win-(win*0.08));
  	glRasterPos2f(x,y);
        // Exibe caracter a caracter
	while(*string)
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*string++);
	glPopMatrix();
}

