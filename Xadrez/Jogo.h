/*
*	Classe Jogo: controla o jogo, incializa a pecas, e insere nas posicoes iniciais.
*				 possui o controle do jogo e o estado.
*
*
*/	

#ifndef JOGO_H
#define JOGO_H


#include <string>
#include "Tabuleiro.h"
#include "Jogador.h"
#include "Peca.h"
#include "Bispo.h"
#include "Cavalo.h"
#include "Dama.h"
#include "Peao.h"
#include "Rei.h"
#include "Torre.h"


using namespace std;

class Jogo {
    private:
    	/* atributo 'tabuleiro' responsavel pela manutencao do tabulerio*/
        Tabuleiro *tabuleiro; 
        
        /* atributo 'player1' responsavel pelo player 1*/
        Jogador *player1;
        
        /* atributo 'player2' responsavel pelo player 2*/
        Jogador *player2;

        /* atributos respectivos para cada peca do jogo*/
        Peca *peca[32];
		
        /* atributo 'estado' controla o estado do jogo inicio | xeque | xeque-mate(fim do jogo)*/
        string estado; 

    public:
    	/* contrutor da classe jogo */
        Jogo();
        
        /*destrutor*/
        ~Jogo();
        
        /* metodo que controla todo o jogo*/
        void iniciarJogo(); 
        
        /*metodo que salva o estado do jogo em um arquivo*/
        void salvarJogo(int playerCorrente);
        
        /*metodo responsavel por recuperar o estado do jogo dado um arquivo*/
        int carregarJogo(string nome_arquivo);
        
        /*metodo que exiber as pecas em jogo*/
        void pecasEmJogo();  
};

#endif /* JOGO_H */


