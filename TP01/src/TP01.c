

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>
#include <stdbool.h>
int numlados = 1;
int pontoX = 50, pontoY = 50;
int direcao;
const int CIMA = 1, BAIXO = 2, DIREITA = 3, ESQUERDA = 4;
const float PASSO = 1;
int fps = 33;
bool PAUSE = false;
bool sistema;

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
	glPointSize(10);
	glBegin(GL_POINTS); // Desenhando o contorno do labirinto;
		glVertex3f(pontoX,pontoY,0);
	glEnd();
	//glFlush();
	glutSwapBuffers();

}


// Inicia algumas variáveis de estado
void inicializa(void)
{
    // cor para limpar a tela
    glClearColor(1, 1, 1, 0);      // branco
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
	if (!PAUSE){
		if (direcao == CIMA){
				pontoY += PASSO;
			}else if (direcao == BAIXO){
				pontoY -= PASSO;

			}else if (direcao == DIREITA){
				pontoX += PASSO;

			}else if(direcao == ESQUERDA){
				pontoX -= PASSO;
			}
			if (colisaoParede(pontoX,pontoY) == 1){
				printf("Colidiu no ponto x : %d e ponto y: %d \n", pontoX, pontoY);
				Sleep(500);
				exit(0);
			}

	}

	glutTimerFunc(33, atualiza, 0);
	glutPostRedisplay();
}

int colisaoParede(int pontoX, int pontoY){
	if (pontoY >= 100 || pontoX >= 100 || pontoX <= 0 || pontoY <= 0 ){
		return 1;
	}
	return 0;
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
	    glutTimerFunc(33, atualiza, 0);
	    inicializa();
	    glutMainLoop();
	    return 0;
}






