/*
*	Classe Tabuleiro: Responasavel pelo controle do tabuleiro. Exibicao das pecas, 
*					  checagem de movimento da peca em relacao ao tabuleiro, exibicao
*					  do tabulerio.
*
*
*/	


#ifndef TABULEIRO_H
#define TABULEIRO_H

#include "Posicao.h"
#include "Jogador.h"

class Tabuleiro {
    private:
    	/* Atributo 'posicao' matriz de ponteiros para as posicoes do tabuleiro - posicao vazia = NULL, posicao nao vazia != NULL */
        Posicao *posicao[8][8]; 
        
        /* Metodo para exibir o display para o usuario */
        void displayTabuleiro();
        
        /* Metodo que checa movimento das pecas em relacao ao tabuleiro */
        int checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
                
    public:
    	/* Construtor da classe Tabuleiro */
        Tabuleiro();
        
        ~Tabuleiro();
        
        Posicao* getPosicao(int i, int j);
        
        void setPosicao(Posicao *p[8][8]);
        
        /* Metodo que realiza o movimento da peca */
        bool moverPeca(int linhaOrigem, int linhaDestino, int colunaOrigem, int colunaDestino, int playerCorrente, Jogador *player, int *id); /* chama checa movimento e move a peca se permitido e chama displatboard para exibir o tabuleiro*/
        
        /* Metodo que incializa as posicoes e exibe o primeiro tabuleiro */
	void iniciaJogo(Peca *peca[32], int player1, int player2);
          
        string verificaChequeMate(int linhaRei, int colunaRei, int playerCorrente);
        
        string verificaCheque(int linhaRei, int colunaRei, int playerCorrente);
        
        
    };

#endif /* TABULEIRO_H */


