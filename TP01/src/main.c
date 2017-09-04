/*
 * main.c
 *
 *  Created on: 3 de set de 2017
 *      Author: Caio Silva
 */
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>
#include "Quadrado.h"
#include "colisao.h"
#include <stdbool.h>
#include <GL/freeglut.h>
#include <time.h>

const int tamanhoTela = 700;
QUADRADO obstaculo[10];
QUADRADO cobra;
int qtdObstaculos;
const int numeroMaxObstaculos = 10;

const float PASSO = 1;
int direcao;
const int CIMA = 1, BAIXO = 2, DIREITA = 3, ESQUERDA = 4;

void desenhaQuadrado(QUADRADO quadrado){

    glBegin(GL_POLYGON);
        glVertex3f(quadrado.x, quadrado.y, 0);
        glVertex3f(quadrado.x, quadrado.y + quadrado.altura, 0);
        glVertex3f(quadrado.x + quadrado.largura, quadrado.y + quadrado.altura, 0);
        glVertex3f(quadrado.x + quadrado.largura, quadrado.y, 0);

    glEnd();
    glFlush();
}

void desenhaCena(void)
{

    // Limpa a tela (com a cor definida por glClearColor(r,g,b)) para que
    // possamos desenhar
    glClear(GL_COLOR_BUFFER_BIT);

    // Começa a usar a cor preto

    // Desenha Cobra
    glColor3f(1, 0, 0);
    desenhaQuadrado(cobra);

    // Desenha os obstaculos
    glColor3f(0, 0, 0);
    for(int i = 0; i < qtdObstaculos; i++){
    	desenhaQuadrado(obstaculo[i]);
    }

    // Diz ao OpenGL para colocar o que desenhamos na tela
    glFlush();
}

void criaObstaculos(){
	srand(time(NULL));
	bool colide = false;
	for(int i = 0; i < numeroMaxObstaculos;){

		float x=(rand()%90 + 10);
		float y=(rand()%90 + 10);
		QUADRADO quadrado = {x,y,3,3};
		for(int i = 0; i < qtdObstaculos; i++){
			if(verificaColisao(quadrado, obstaculo[i]))
		    	colide = true;
	   }
		if(colide || verificaColisao(quadrado, cobra)) continue;
		obstaculo[qtdObstaculos] = quadrado;
		qtdObstaculos += 1;
		i++;
	}
}



void inicializa(void)
{
    // cor para limpar a tela
    glClearColor(1, 1, 1, 0);      // branco
    criaObstaculos();

    //Cobra inicia no meio da tela
    cobra.x = 90;
    cobra.y = 50;
    cobra.largura = 1;
    cobra.altura = 1;

}

void atualiza() {
	if (direcao == CIMA){
		cobra.y += PASSO;

	}else if (direcao == BAIXO){
		cobra.y -= PASSO;

	}else if (direcao == DIREITA){
		cobra.x += PASSO;

	}else if(direcao == ESQUERDA){
		cobra.x -= PASSO;

	}
	if (colisaoParede(pontoX,pontoY) == 1){
		printf("Colidiu no ponto x : %d e ponto y: %d \n", pontoX, pontoY);
		Sleep(500);
		exit(0);
	}

	glutTimerFunc(fps, atualiza, 0);
	glutPostRedisplay();
}

void teclado(unsigned char key, int x, int y)
{
   switch(key)
   {
      // Tecla ESC
      case 27:
         exit(0);
         break;
      case 119: // 'w'
      	direcao = CIMA;
      	break;
      case 115: // 's'
      	direcao = BAIXO;
      	break;
      case 100:// 'd'
      	direcao = DIREITA;
      	break;
      case 97: // 'a'
      	direcao = ESQUERDA;
      	break;
      default:
         break;
   }
}

void redimensiona(int w, int h)
{
   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0, 100, 0, 100, -1, 1);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}


int main(int argc, char **argv)
{

	// Acordando o GLUT
	    glutInit(&argc, argv);

	    // Definindo a versão do OpenGL que vamos usar
	    //glutInitContextVersion(1, 1);
	    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	    // Configuração inicial da janela do GLUT
	    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	    glutInitWindowSize(tamanhoTela, tamanhoTela);
	    glutInitWindowPosition(100, 100);

	    // Abre a janela
	    glutCreateWindow("Snake");
	    inicializa();
	    // Registra callbacks para alguns eventos
	    glutDisplayFunc(desenhaCena);
	    glutReshapeFunc(redimensiona);
	    glutKeyboardFunc(teclado);


	    // Entra em loop e nunca sai
	    glutMainLoop();
	    return 0;

}


