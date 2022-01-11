/*
*	Classe Jogador: Respons�vel pelas informacoes de players no jogo.
*
*
*/

#ifndef JOGADOR_H
#define JOGADOR_H

#include "Peca.h"
#include "Bispo.h"
#include "Cavalo.h"
#include "Dama.h"
#include "Peao.h"
#include "Rei.h"
#include "Torre.h"

class Jogador {
    private:
    	/* atributo 'player' = 1 - player um | 'player' = 2 - player dois*/
        int player; 
        
        /* atributo 'qtdPeca' quantidade de pecas do player em jogo */
        int qtdPeca;
        
        /*Posicao da peca rei - utilizada para verificar cheque ou cheque mate*/
        int linhaRei, colunaRei;
        
        Peca *peca[16];
        
    public:
    	/*construtor da classe jogador*/
		Jogador(int Player);
                ~Jogador();
		
		/*seta valor para o atributo player*/
		void setPlayer(int p);
		
		/* retorna o valor do atributo player*/
		int getPlayer();
		
		/*diminui o valor do atributo qtdPeca*/
		void setqtdPeca();
		
		/*retorna o valor do atributo player*/
		int getqtdPeca();

                /*Seta a posicao do Rei*/
                void setRei(int linha, int coluna);
                
                int getRei_linha();
                
                int getRei_coluna();
                                
                void setPecaJogo(int i);
                
                void imprimirPecaJogo();


};

#endif /* JOGADOR_H  */


