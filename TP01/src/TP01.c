

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>
#include <stdbool.h>
#include "Quadrado.h"
#include "colisao.h"
#include "Teclado.h"
#include "Variaveis.h"


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
	glLineWidth(10.0f);
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
	if(!menuAtivado){
		tecladoEspecialMovimentacao(key,x,y);
	}else{
		tecladoEspecialMovimentacaoMenu(key,x,y);
	}
}

// Callback de evento de teclado
void teclado(unsigned char key, int x, int y)
{
	if(!menuAtivado){
		if(tecladoMovimentacao(key,x,y) == 1){
			glutDisplayFunc(desenhaCena);
		}

	}else{
		if(tecladoMovimentacaoMenu(key,x, y) == 1){
			glutDisplayFunc(desenhaCena);
		}
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
	if(menuAtivado){
		glutDisplayFunc(menu);
	}
	glutReshapeFunc(redimensiona);
	glutKeyboardFunc(teclado);
	glutSpecialFunc(tecladoEspecial);
	glutTimerFunc(0, atualiza, 0);
	inicializa();
	glutMainLoop();
	return 0;
}
