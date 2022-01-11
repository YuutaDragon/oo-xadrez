/*
*	Classe Cavalo: Controle da peca especifica Cavalo Checagem de moviemnto de acordo com a peca.
*				   Caracteristicas especificas da peca.
*
*
*/					  	

#include "Cavalo.h"
#include <cmath>

/*	Construtor para a peca Cavalo
*	emJogo: indica se a peca esta em jogo (emJogo = 1) ou nao (emJogo = 0). 
*/
Cavalo::Cavalo(char c, int i) : Peca("Cavalo", c, i){
    
}

/*	Desenha peca no Tabuleiro
*	Retorna: um Char representativo da peca.
*/
char Cavalo::desenha(){
	return 'C';
}

/*	checaMovimento: checa o movimento em si para a peca Cavalo (movimento permitido: L).
*	Parametros: linhaOrigem, colunaOrigem, linhaDestino, colunaDestino - ( 0 -7)
* 	Return: retorna um inteiro onde:
* 	 1 - Permite o movimento da peca;
*  	 0 - Peca nao pode ser movida;
*/
bool Cavalo::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino){
    int deslocV = abs(linhaDestino - linhaOrigem);
    int deslocH = abs(colunaDestino - colunaOrigem);

    if(deslocV*deslocH == 2){
        return true;
    }
    else
        return false;
}

/*	Seta o valor do atributo emJogo de acordo com o usuario 
void Cavalo::setEmJogo(int n){
    emJogo = n;
};


/* Retorna o valor do atributo emJogo - No jogo = 1, Fora do jogo = 0 
int  Cavalo::getEmJogo(){
    return emJogo;
};

/* Seta o valor do atributo cor da peca Cavalo de acordo com o usuario = Branco = 'B', Preto = 'P' 
void Cavalo::setCor(char c){
    cor = c;
};

/* Retorna o valor do atributo cor - Branco = 'B', Preto = 'P' 
char Cavalo::getCor(){
    return cor;
};

*/