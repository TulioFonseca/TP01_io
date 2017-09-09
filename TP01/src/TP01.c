

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>
#include <stdbool.h>
#include "Movimentar.h"
#include "Quadrado.h"
#include "colisao.h"

int NUMERO_MAX_OBSTACULOS = 10;

int numlados = 1;
int pontoX = 50, pontoY = 50;
int direcao = 0;


bool PAUSE = false;
bool sistema;

int velocidade = 33;
const int larguraTela = 400;
const int alturaTela = 400;
int tamanhoPlayer;

QUADRADO player[1000000]; //tamanho total para ocupar toda a tela
QUADRADO* item;
QUADRADO obstaculos[10];




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
	glLineWidth(5.0f);
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


    // Desenha Player
    glColor3f(0, 0, 1);

    for(int i = 0; i <= tamanhoPlayer; i++){
    	//printf("%5f \n", player[i].altura);

    	desenhaQuadrado(player[i]);
    }


    // Desenha os obstaculos
    glColor3f(1, 1,1);
    for(int i = 0; i < NUMERO_MAX_OBSTACULOS; i++){
    	desenhaQuadrado(obstaculos[i]);
    }


    //Desenha Item
    switch(item->tipoItem){
		case 0: // normal
			glColor3f(0, 1, 0);
			break;
		case 1: // ivulneravel
			glColor3f(1, 1, 0);
			break;
		case 3: //

			break;
		case 4: //

			break;
		default:
			break;
	}

    desenhaQuadrado(*item);

	glutSwapBuffers();

}

// Inicia algumas variáveis de estado
void inicializa(void)
{
    // cor para limpar a tela
    glClearColor(0, 0, 0, 0);

    //Cria Obstaculos
    criaObstaculos(&player[0], obstaculos, NUMERO_MAX_OBSTACULOS);

    item = malloc(sizeof(QUADRADO));
    geraItem(player, tamanhoPlayer, obstaculos, NUMERO_MAX_OBSTACULOS, item);

	//Cobra inicia no meio da tela
    QUADRADO quadrado = {1,1,3,3};
    player[0] = quadrado;
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
	tamanhoPlayer = movimentarObjeto(direcao, PAUSE, player, tamanhoPlayer, obstaculos, NUMERO_MAX_OBSTACULOS, item);
	glutTimerFunc(velocidade, atualiza, 0);
	glutPostRedisplay();

}

void tecladoEspecial (int key, int x, int y){
	switch(key){
		case UP: // 'w'
			if (direcao != BAIXO)
				direcao = CIMA;
		    break;
		case DOWN: // 's'
			if (direcao != CIMA)
				direcao = BAIXO;
		    break;
		case RIGHT: //d
			if (direcao != ESQUERDA)
				direcao = DIREITA;
			break;
		case LEFT: // 'a'
			if (direcao != DIREITA)
				direcao = ESQUERDA;
			break;
		default:
		 break;
		}
}
void reinicia(){
	  PAUSE = true;
	  direcao = 0;
	  NUMERO_MAX_OBSTACULOS = 10;
	  numlados = 1;
	  pontoX = 50, pontoY = 50;
	  direcao = 0;
	  velocidade = 33;
	  tamanhoPlayer = 0;
	  inicializa();
	  PAUSE = false;

}



// Callback de evento de teclado
void teclado(unsigned char key, int x, int y)
{
   switch(key){
		  case 27:
			 exit(0);
			 break;
		  case 119: // 'w'
			  if (direcao != BAIXO)
				  direcao = CIMA;
			  break;
		  case 115: // 's'
			  if(direcao != CIMA)
				  direcao = BAIXO;
			  break;
		  case 100:// 'd'
			  if(direcao != ESQUERDA)
				  direcao = DIREITA;
			  break;
		  case 97: // 'a'
			  if(direcao != DIREITA)
				  direcao = ESQUERDA;
			  break;
		  case 'p':
			  PAUSE = !PAUSE;
			  break;
		  case 'r':
			  reinicia();
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
	glutInitWindowSize(larguraTela, alturaTela);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Quadrado");
	glutDisplayFunc(desenhaCena);
	glutReshapeFunc(redimensiona);
	glutKeyboardFunc(teclado);
	glutSpecialFunc(tecladoEspecial);
	glutTimerFunc(0, atualiza, 0);
	inicializa();
	glutMainLoop();
	return 0;
}





