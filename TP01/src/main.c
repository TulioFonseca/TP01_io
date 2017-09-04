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
QUADRADO obstaculos[10];
QUADRADO cobra;
int qtdObstaculos;
const int numeroMaxObstaculos = 10;

const float PASSO = 1;
int direcao;
const int CIMA = 1, BAIXO = 2, DIREITA = 3, ESQUERDA = 4;

bool PAUSE = false;
bool sistema;


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
    	desenhaQuadrado(obstaculos[i]);
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
			if(verificaColisao(quadrado, obstaculos[i]))
		    	colide = true;
	   }

		if(colideObstaculos(quadrado, obstaculos, qtdObstaculos) || verificaColisao(quadrado, cobra)) continue;
		obstaculos[qtdObstaculos] = quadrado;
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

void morre(){
	exit(0);
}

void atualiza() {
	if (!PAUSE){
		if (direcao == CIMA){
				cobra.y += PASSO;
				if(colideObstaculos(cobra, obstaculos, qtdObstaculos)) morre();

			}else if (direcao == BAIXO){
				cobra.y -= PASSO;
				if(colideObstaculos(cobra, obstaculos,qtdObstaculos)) morre();

			}else if (direcao == DIREITA){
				cobra.x += PASSO;
				if(colideObstaculos(cobra, obstaculos, qtdObstaculos)) morre();

			}else if(direcao == ESQUERDA){
				cobra.x -= PASSO;
				if(colideObstaculos(cobra, obstaculos, qtdObstaculos)) morre();
			}
			if (colisaoParede(cobra.x,cobra.y)){
				exit(0);
			}
	}

	glutTimerFunc(33, atualiza, 0);
	glutPostRedisplay();
}

// Callback de evento de teclado
void teclado(unsigned char key, int x, int y)
{
   switch(key){
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
		  case 'p':
			  PAUSE = !PAUSE;
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


