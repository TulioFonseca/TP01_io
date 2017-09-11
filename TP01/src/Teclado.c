/*
 * Teclado.c
 *
 *  Created on: 11 de set de 2017
 *      Author: tu-12
 */
#include "Teclado.h"
int NUMERO_MAX_OBSTACULOS;
int pontoX, pontoY;
int direcao;
bool menuAtivado;

int velocidade;
const int larguraTela;
const int alturaTela;
int tamanhoPlayer;

bool reinicia;
bool PAUSE;
bool sistema;
int contador;
int contadorOpcao;
int liberarMenu;


void reiniciar(){
	PAUSE = true;
    reinicia = true;

    glutDisplayFunc(menuOpcao);




}
int reiniciando(){
	if(contadorOpcao == 3){
			  direcao = 0;
			  NUMERO_MAX_OBSTACULOS = 10;
			  pontoX = 50, pontoY = 50;
			  direcao = 0;
			  velocidade = 33;
			  tamanhoPlayer = 0;
			  inicializa();
			  PAUSE = false;
	}else if(contadorOpcao == 2){
		PAUSE = false;
	}
	return 1;
}





int tecladoMovimentacao (unsigned char key, int x, int y){
	switch(key){
				case 13:
					  if(reinicia){
						  reinicia = false;
						  if (reiniciando() == 1) return 1;

					  }
					  break;
				  case 27:
					  finalJogo();
					 //exit(0);
					 break;
				  case 119: // 'w'
					  if(reinicia){
							if(contadorOpcao < 3){
								 menuOpcao(SOBE,contadorOpcao);
								 contadorOpcao++;

							}
					  }else{
						  if (direcao != BAIXO)
							  direcao = CIMA;
					  }
					  break;
				  case 115: // 's'
					  if(reinicia){
						  if(contadorOpcao >2){
							  menuOpcao(DESCE,contadorOpcao);
							  contadorOpcao--;
						  }
					  }else{
						  if(direcao != CIMA)
							  direcao = BAIXO;}
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
					  reiniciar();
					  break;
				  default:
					 break;
		return 0;
	}
}
void tecladoEspecialMovimentacao(int key, int x, int y){
	switch(key){
			case 13:
				  if(reinicia){
					  reinicia = false;
					  reiniciando();

				  }
				  break;
			case UP: // 'w'
				if(reinicia){
					if(contadorOpcao < 3){
						 menuOpcao(SOBE,contadorOpcao);
						 contadorOpcao++;

					}
				}else{
					if (direcao != BAIXO)
						direcao = CIMA;
				}
			    break;
			case DOWN: // 's'
				if(reinicia){
					if(contadorOpcao >2){
						menuOpcao(DESCE,contadorOpcao);
						contadorOpcao--;

					}
				}else{
					if (direcao != CIMA)
						direcao = BAIXO;
				}
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

void tecladoEspecialMovimentacaoMenu(int key, int x, int y){
	switch(key){
			case UP: // 'w'
				if(contador < 3){
					menu(SOBE,contador);
					contador++;

				}
			    break;
			case DOWN: // 's'
				if(contador > 1){
					menu(DESCE,contador);
					contador--;
				}
				break;
			default:
				break;
			}
}

int tecladoMovimentacaoMenu(unsigned char key, int x, int y){
	switch(key){
				  case 27:
					  finalJogo();
					 //exit(0);
					 break;
				  case 13:
					  liberarMenu = selecionar(contador);
					  if(liberarMenu == 1){
						  menuAtivado = false;
						  return 1;

					  }
					  break;
				  case 119: // 'w'
					 if(contador < 3){
						 menu(SOBE,contador);
						 contador++;
					 }
					  break;
				  case 115: // 's'
	     			  if(contador > 1){
	     				 menu(DESCE,contador);
	     				 contador--;
	     			  }
					  break;
				  default:
					 break;
				}
	return 0;
}
