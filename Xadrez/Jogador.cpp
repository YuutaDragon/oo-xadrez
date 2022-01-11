/*
*	Classe Jogador: Responsavel pelas informacoes de players no jogo.
*
*
*/


#include "Jogador.h"
#include "Peca.h"
#include <iostream>
#include "Bispo.h"
#include "Cavalo.h"
#include "Dama.h"
#include "Peao.h"
#include "Rei.h"
#include "Torre.h"

using namespace std;

/*construtor da classe jogador*/
Jogador::Jogador(int Player){
	player = Player;
	qtdPeca = 16;
        linhaRei = -1;
        colunaRei = -1;
        
          
    try{
        for(int i = 0; i < 32; i++){
            peca[i] = NULL;
        }

        if(Player == 1){
            peca[0]   = new Rei('b', 0);
            peca[1]   = new Dama('b', 1);
            peca[2]   = new Cavalo('b', 2);
            peca[3]   = new Cavalo('b', 3);
            peca[4]   = new Torre('b', 4);
            peca[5]   = new Torre('b', 5);
            peca[6]   = new Bispo('b', 6);
            peca[7]   = new Bispo('b', 7);
            peca[8]   = new Peao('b', 8);
            peca[9]   = new Peao('b', 9);
            peca[10]  = new Peao('b', 10);
            peca[11]  = new Peao('b' , 11);
            peca[12]  = new Peao('b', 12);
            peca[13]  = new Peao('b', 13);
            peca[14]  = new Peao('b', 14);
            peca[15]  = new Peao('b', 15);
        }
        else{
            peca[0]   = new Rei('p', 0);
            peca[1]   = new Dama('p', 1);
            peca[2]   = new Cavalo('p', 2);
            peca[3]   = new Cavalo('p', 3);
            peca[4]   = new Torre('p', 4);
            peca[5]   = new Torre('p', 5);
            peca[6]   = new Bispo('p', 6);
            peca[7]   = new Bispo('p', 7);
            peca[8]   = new Peao('p', 8);
            peca[9]   = new Peao('p', 9);
            peca[10]  = new Peao('p', 10);
            peca[11]  = new Peao('p' , 11);
            peca[12]  = new Peao('p', 12);
            peca[13]  = new Peao('p', 13);
            peca[14]  = new Peao('p', 14);
            peca[15]  = new Peao('p', 15);
        }
    }
    catch(exception& error){
        cout << "Erro - Alocacao Dinamica" << error.what() << endl;
    }
};
		
/*seta valor para o atributo player*/
void Jogador::setPlayer(int p){
	player = p;
};
/* retorna o valor do atributo player*/
int Jogador::getPlayer(){
	return player;
};
		
/*diminui o valor do atributo qtdPeca*/
void Jogador::setqtdPeca(){
	qtdPeca = qtdPeca - 1;
};
		
/*retorna o valor do atributo player*/
int Jogador::getqtdPeca(){
	return qtdPeca;
};


void Jogador::setRei(int linha, int coluna){
    linhaRei = linha;
    colunaRei = coluna;
};

int Jogador::getRei_linha(){
    return linhaRei;
};

int Jogador::getRei_coluna(){
    return colunaRei;
};

void Jogador::setPecaJogo(int i){
    peca[i]->setEmJogo(false);
};

void Jogador::imprimirPecaJogo(){
    cout << "Pecas do Jogador " << player << endl;
    for(int i = 0; i < 16; i++){
        if(peca[i]->getEmJogo())
            cout << "Peca: " << peca[i]->getNome() << endl;
        
    }
};
