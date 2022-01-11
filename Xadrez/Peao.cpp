/*
*	Classe Peao: Controle da peca especifica bispo. Checagem de moviemnto de acordo com a peca.
*				  Caracteristicas especificas da peca.
*
*
*/	

#include "Peao.h"
#include <cmath>

/*	Construtor para a peca Peao
*	emJogo: indica se a peca esta em jogo (emJogo = 1) ou nao (emJogo = 0). 
*/
Peao::Peao(char c, int i) : Peca("Peao", c, i){
  
}

/*	Desenha peca no Tabuleiro
*	Retorna: um Char representativo da peca.
*/
char Peao::desenha(){
	return 'P';
}

/*	checaMovimento: checa o movimento em si para a peca Peao(movimento permitido: vertical, uma casa).
*	Parametros: linhaOrigem, colunaOrigem, linhaDestino, colunaDestino - ( 0 -7)
* 	Return: retorna um inteiro onde:
* 	 1 - Permite o movimento da peca;
*  	 0 - Peca nao pode ser movida;
*/
bool Peao::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino){
	/*  DeslocV - deslocamento no eixo Y | DeslocH - deslocamento no eixo X */
    int deslocV = linhaDestino - linhaOrigem;
    int deslocH = abs(colunaDestino - colunaOrigem);
    
    /* Tratando os casos para as pecas Brancas */
    if(this->getCor() == 'b'){
        if(deslocV == 1 && deslocH == 0){
            return true;
        }
        /* primeiro movimento - mover duas casas */
        else if(linhaOrigem == 1 && deslocV == 2 && deslocH == 0){
            return true;
        }
        else
            return false;
    }

    /*tratando os casos da peca Pretas */
    else{
        if(deslocV == -1 && deslocH == 0){
            return true;
        }

        /* Primeiro movimento -  mover duas casas */
         else if(linhaOrigem == 6  && deslocV == -2 && deslocH == 0){
            return true;
        }
        else
            return false;
    }
}


/*	Seta o valor do atributo 'emJogo' de acordo com o usuario 
void Peao::setEmJogo(int n){
    emJogo = n;
};

/* Retorna o valor do atributo 'emJogo' - No jogo = 1, Fora do jogo = 0
int Peao::getEmJogo(){
    return emJogo;
};

/* Seta o valor do atributo 'cor' de acordo com o usuario = Branco = 'B', Preto = 'P' 
void Peao::setCor(char c){
    cor = c;
};

/* Retorna o valor do atributo 'cor' - Branco = 'B', Preto = 'P' 
char Peao::getCor(){
    return cor;
};
*/
