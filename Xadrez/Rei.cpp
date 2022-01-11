/*
*	Classe Rei: Controle da peca especifica bispo. Checagem de moviemnto de acordo com a peca.
*				Caracteristicas especificas da peca.
*
*
*/					  	


#include "Rei.h"
#include <cmath>
#include "Peca.h"

/*	Construtor para a peca Rei
*	emJogo: indica se a peca esta em jogo (emJogo = true) ou nao (emJogo = false). 
*/
Rei::Rei(char c, int i): Peca("Rei", c, i){
    
}

/*	Desenha peca no Tabuleiro
*	Retorna: um Char representativo da peca.
*/
char Rei::desenha(){
	return 'R';
}

/*	checaMovimento: checa o movimento em si para a peca Rei (movimento permitido: diagonal, vartica, horizonta, uma casa).
*	Parametros: linhaOrigem, colunaOrigem, linhaDestino, colunaDestino - ( 0 -7)
* 	Return: retorna um inteiro onde:
* 	 1 - Permite o movimento da peca;
*  	 0 - Peca nao pode ser movida;
*/
bool Rei::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino){
	/*  DeslocV - deslocamento no eixo Y | DeslocH - deslocamento no eixo X */
    int deslocV = abs(linhaDestino - linhaOrigem);     
    int deslocH = abs(colunaDestino - colunaOrigem);
    
    if(deslocV >= 0 && deslocH <= 1 && deslocH >= 0 && deslocV <= 1){
        return true;       
    }   
    else 
        return false;
}

/*	Seta o valor do atributo 'emJogo' de acordo com o usuario 
void Rei::setEmJogo(int n){
    emJogo = n;
};
*/

/* Retorna o valor do atributo 'emJogo' - No jogo = 1, Fora do jogo = 0 
int Rei::getEmJogo(){
    return emJogo;
};
*/

/* Seta o valor do atributo 'cor' de acordo com o usuario = Branco = 'B', Preto = 'P' 
void Rei::setCor(char c){
    cor = c;
};
*/

/* Retorna o valor do atributo 'cor' - Branco = 'B', Preto = 'P' 
char Rei::getCor(){
    return cor;
};
*/