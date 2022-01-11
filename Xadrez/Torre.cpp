/*
*	Classe Torre: Controle da peca especifica bispo. Checagem de moviemnto de acordo com a peca.
*				  Caracteristicas especificas da peca.
*
*
*/

#include "Torre.h"
#include <cmath>

/*	Construtor para a peca Torre
*	emJogo: indica se a peca esta em jogo (emJogo = 1) ou nao (emJogo = 0). 
*/
Torre::Torre(char c, int i): Peca("Torre", c, i){
  
}

/*	Desenha peca no Tabuleiro
*	Retorna: um Char representativo da peca.
*/
char Torre::desenha(){
	return 'T';
}

/*	checaMovimento: checa o movimento em si para a peca Torre (movimento permitido: vertica, horizontal).
*	Parametros: linhaOrigem, colunaOrigem, linhaDestino, colunaDestino - ( 0 -7)
* 	Return: retorna um inteiro onde:
* 	 1 - Permite o movimento da peca;
*  	 0 - Peca nao pode ser movida;
*/
bool Torre::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino){
	/*  DeslocV - deslocamento no eixo Y | DeslocH - deslocamento no eixo X */
    int deslocV = linhaDestino - linhaOrigem;
    int deslocH = colunaDestino - colunaOrigem;

    if(deslocV == 0 || deslocH == 0){
         return true;
    }
    else
        return false;
}

/*	Seta o valor do atributo 'emJogo' de acordo com o usuario 
void Torre::setEmJogo(int n){
    emJogo = n;
};

/* Retorna o valor do atributo 'emJogo' - No jogo = 1, Fora do jogo = 0 
int Torre::getEmJogo(){
    return emJogo;
};

/* Seta o valor do atributo 'cor' de acordo com o usuario = Branco = 'B', Preto = 'P' 
void Torre::setCor(char c){
    cor = c;
};

/* Retorna o valor do atributo 'cor' - Branco = 'B', Preto = 'P' 
char Torre::getCor(){
    return cor;
};
*/
