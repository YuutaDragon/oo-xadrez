/*
*	Xadres.cpp: Implementacao Jogo de Xadrez
*	
*	Autores: Guilherme Henrique Rodrigues RA: 743544
*			 Matheus Cerqueira Santana 	  RA: 743579
*			 Rafael Jyo Kondo 			  RA: 743589
*
*	Inplementacao das principais regras de um jogo de xadrez, e possivel
*	jogar um jogo de xadrez com duas pecas, seguindo os principios simples 
*	de um jogo de xadrez.
* 
*
*	Ultima Modificacao: 24 - 04 - 2019
*
*/

/*
*	Como jogar: Cada player pode fazer um movimento. O player 1, peca branca. O player 2, peca preta.
* 				Os player devem digitar as coordenadas da peca que deseja mover - Linha de Origem(0 - 7)
*				e coluna de Origem(A - H) e as coordenadas para o local a onde deseja posicionar a peca
*				- Linha de Destino(0 - 7) e coluna de Destino(A - H). O jogo faz a verificao de movimento
*				se aceito move a peca, caso contr�rio o player da vez, pode redigitar os valores.
*
*
*/

#include "Jogo.h"

using namespace std;

int main(int argc, char** argv) {
    Jogo xadrez;

    
    xadrez.iniciarJogo();
 

    return 0;
}



