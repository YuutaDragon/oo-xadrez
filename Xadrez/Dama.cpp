/*
*	Classe Dama: Controle da peca especifica bispo. Checagem de moviemnto de acordo com a peca.
*				  Caracteristicas especificas da peca.
*
*
*/

#include "Dama.h"
#include <cmath>

/*	Construtor para a peca Dama
*	emJogo: indica se a peca esta em jogo (emJogo = 1) ou nao (emJogo = 0). 
*/
Dama::Dama(char c, int i): Peca("Dama", c , i){

}

/*	Desenha peca no Tabuleiro
*	Retorna: um Char representativo da peca.
*/
char Dama::desenha(){
	return 'D';
}

/*	checaMovimento: checa o movimento em si para a peca Dama (movimento permitido: diagonal, horizontal e vertical).
*	Parametros: linhaOrigem, colunaOrigem, linhaDestino, colunaDestino - ( 0 -7)
* 	Return: retorna um inteiro onde:
* 	 1 - Permite o movimento da peca;
*  	 0 - Peca nao pode ser movida;
*/
bool Dama::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino){
	/*  DeslocV - deslocamento no eixo Y | DeslocH - deslocamento no eixo X */
     int deslocV = abs(linhaDestino - linhaOrigem);     
     int deslocH = abs(colunaDestino - colunaOrigem);

    if((deslocV == deslocH) || (deslocV == 0) || (deslocH == 0)){
        return true;
    }
    else
        return false;
}


/*	Seta o valor do atributo 'emJogo' de acordo com o usuario 
void Dama::setEmJogo(int n){
    emJogo = n;
};

/* Retorna o valor do atributo 'emJogo' - No jogo = 1, Fora do jogo = 0 
int Dama::getEmJogo(){
    return emJogo;
};

/* Seta o valor do atributo 'cor' de acordo com o usuario = Branco = 'B', Preto = 'P' 
void Dama::setCor(char c){
    cor = c;
};

/* Retorna o valor do atributo 'cor' - Branco = 'B', Preto = 'P' 
char Dama::getCor(){
    return cor;
};


*/