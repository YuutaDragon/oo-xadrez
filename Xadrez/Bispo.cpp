/*
*	Classe Bispo: Controle da peca especifica bispo. Checagem de moviemnto de acordo com a peca.
*				  Caracteristicas especificas da peca.
*
*
*/					  	

#include "Bispo.h"
#include <cmath>
#include "Peca.h"

/*	Construtor para a peca Bispo
*	emJogo: indica se a peca esta em jogo (emJogo = 1) ou nao (emJogo = 0). 
*/
Bispo::Bispo(char c, int i): Peca("Bispo", c, i){
    setNome("Bispo");
    setCor(c);
}

/*	Desenha peca no Tabuleiro
*	Retorna: um Char representativo da peca.
*/
char Bispo::desenha(){
	return 'B';
}

/*	checaMovimento: checa o movimento em si para a peca Bispo (movimento permitido: diagonal).
*	Parametros: linhaOrigem, colunaOrigem, linhaDestino, colunaDestino - ( 0 -7)
* 	Return: retorna um inteiro onde:
* 	 1 - Permite o movimento da peca;
*  	 0 - Peca nao pode ser movida;
*/
bool Bispo::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino){
	/*  DeslocV - deslocamento no eixo Y | DeslocH - deslocamento no eixo X */
    int deslocV = abs(linhaDestino - linhaOrigem);     
    int deslocH = abs(colunaDestino - colunaOrigem);

    if(deslocV == deslocH){
        return true;
    }
    else
        return false;
}

/*	Seta o valor do atributo 'emJogo' de acordo com o usuario 
void Bispo::setEmJogo(int n){
    emJogo = n;
};

/* Retorna o valor do atributo 'emJogo' - No jogo = 1, Fora do jogo = 0 
int Bispo::getEmJogo(){
    return emJogo;
};

/* Seta o valor do atributo 'cor' de acordo com o usuario = Branco = 'B', Preto = 'P' 
void Bispo::setCor(char c){
    cor = c;
};

/* Retorna o valor do atributo 'cor' - Branco = 'B', Preto = 'P' 
char Bispo::getCor(){
    return cor;
};

*/