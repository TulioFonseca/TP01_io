#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>
int numlados = 1;

void desenhaCena(void)
{

	//OPA
    int valor = 360 / numlados;
	int r = 35;
	int x = 50;
	int y = 50;
	float posicaoX = 0 ;
	float posicaoY = 0;
	float angulo = 0;
	float primeiraPosicaoX = 0;
	float primeiraPosicaoY = 0;
	float posicaoAnteriorX = 0;
	float posicaoAnteriorY = 0;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);

	for(int i = 0; i <= numlados; i++){

    	glBegin(GL_LINES);
		posicaoX = x + r*cos((angulo*3.14159265)/180);
		posicaoY = y + r*sin((angulo*3.14159265)/180);

		if (i == 0){

			primeiraPosicaoX = posicaoX;
			primeiraPosicaoY = posicaoY;
			glVertex3f(posicaoX,posicaoY,0);
			posicaoAnteriorX = posicaoX;
			posicaoAnteriorY = posicaoY;

		}else if(i == numlados){
			glVertex3f(posicaoAnteriorX,posicaoAnteriorY,0);
			glVertex3f(primeiraPosicaoX,primeiraPosicaoY,0);


		}else{

			glVertex3f(posicaoAnteriorX,posicaoAnteriorY,0);
			glVertex3f(posicaoX,posicaoY,0);
			posicaoAnteriorX = posicaoX;
			posicaoAnteriorY = posicaoY;

		}
		angulo += valor;
		glEnd();
}

    glFlush();
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

// Callback de evento de teclado
void teclado(unsigned char key, int x, int y)
{
   switch(key)
   {
      // Tecla ESC
      case 27:
         exit(0);
         break;
      case 43:
    	  numlados++;
    	  desenhaCena();
    	  break;
      case 45:
    	  if (numlados == 1){
    		  numlados = 1;
    	  }else{
    		  numlados--;
    	  }


    	  desenhaCena();
      default:
    	 break;
   }
}

// Rotina principal
int main(int argc, char **argv)
{
    // Acordando o GLUT
    glutInit(&argc, argv);

    // Definindo a versão do OpenGL que vamos usar
    glutInitContextVersion(1, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    // Configuração inicial da janela do GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);

    // Abre a janela
    glutCreateWindow("Quadrado");

    // Registra callbacks para alguns eventos
    glutDisplayFunc(desenhaCena);
    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclado);
    inicializa();

    // Entra em loop e nunca sai
    glutMainLoop();
    return 0;
}


