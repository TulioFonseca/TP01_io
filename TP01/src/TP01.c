

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>
#include <stdbool.h>
#include "Movimentar.h"
#include "Quadrado.h"
#include "colisao.h"
int numlados = 1;
int pontoX = 50, pontoY = 50;
int direcao = 0;


//int fps = 33;
bool PAUSE = false;
bool sistema;

const int tamanhoTela = 700;
QUADRADO obstaculos[10];
QUADRADO cobra;
int qtdObstaculos;
const int numeroMaxObstaculos = 10;

void desenhaQuadrado(QUADRADO quadrado){

    glBegin(GL_POLYGON);
        glVertex3f(quadrado.x, quadrado.y, 0);
        glVertex3f(quadrado.x, quadrado.y + quadrado.altura, 0);
        glVertex3f(quadrado.x + quadrado.largura, quadrado.y + quadrado.altura, 0);
        glVertex3f(quadrado.x + quadrado.largura, quadrado.y, 0);

    glEnd();
}

void desenhaCena(void)
{	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glLineWidth(50.0f);
	glBegin(GL_LINE_LOOP); // Desenhando o contorno do labirinto;
		glVertex3f(0,0,0);
		glVertex3f(0,100,0);
		glVertex3f(0,100,0);
		glVertex3f(100,100,0);
		glVertex3f(100,100,0);
		glVertex3f(100,0,0);
	glEnd();
	glColor3f(1, 0, 0); //

	//glFlush();


    // Desenha Cobra
    glColor3f(0, 0, 1);
    desenhaQuadrado(cobra);

    // Desenha os obstaculos
    glColor3f(1, 1,1);
    for(int i = 0; i < qtdObstaculos; i++){
    	desenhaQuadrado(obstaculos[i]);
    }

	glutSwapBuffers();

}

void criaObstaculos(){
	srand(time(NULL));
	for(int i = 0; i < numeroMaxObstaculos;){

		float x=(rand()%90 + 10);
		float y=(rand()%90 + 10);
		QUADRADO quadrado = {x,y,3,3};

		//if(colideObstaculos(&quadrado, &obstaculos, qtdObstaculos) || verificaColisao(&quadrado, &cobra)) continue;
		obstaculos[qtdObstaculos] = quadrado;
		qtdObstaculos += 1;
		i++;
	}
}

// Inicia algumas variáveis de estado
void inicializa(void)
{
    // cor para limpar a tela
    glClearColor(0, 0, 0, 0);      // branco

    criaObstaculos();
        //Cobra inicia no meio da tela
        cobra.x = 1;
        cobra.y = 1;
        cobra.largura = 3;
        cobra.altura = 3;
}

// Callback de redimensionamento
void redimensiona(int w, int h)
{
   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0, 100, 0, 100, -1, 1);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}



void atualiza() {
	//if(direcao != 0){

		movimentarObjeto(direcao, PAUSE, &cobra, &obstaculos, qtdObstaculos);
		glutTimerFunc(33, atualiza, 0);
		glutPostRedisplay();
	//}

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

// Rotina principal
int main(int argc, char **argv) {
	// Acordando o GLUT
	    glutInit(&argc, argv);
	    glutInitContextVersion(1, 1);
	    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	    glutInitWindowSize(400, 400);
	    glutInitWindowPosition(100, 100);
	    glutCreateWindow("Quadrado");
	    glutDisplayFunc(desenhaCena);
	    glutReshapeFunc(redimensiona);
	    glutKeyboardFunc(teclado);
	    glutTimerFunc(0, atualiza, 0);
	    inicializa();
	    glutMainLoop();
	    return 0;
}






