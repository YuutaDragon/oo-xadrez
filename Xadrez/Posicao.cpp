/*
*	Classe Posicao: controle e informacoes sobre as posicoes no tabuleiro
*
*
*/		

#include "Posicao.h"
#include "Peca.h"
#include <string>

#include <iostream>
using namespace std;
/*	Construtor para a peca Bispo
*	ponteiros para pecas: inicializa com NULL.  
*/


Posicao::Posicao(int lin, int col) {   
    peca = NULL;
    
        switch(lin){
            case 0:
               linha = 'A';
            break;

            case 1:
                linha = 'B';
            break;

            case 2:
                linha = 'C';
            break;

            case 3:
                linha = 'D';
            break;

            case 4:
                linha = 'E';
            break;

            case 5:
                linha = 'F';
            break;

            case 6:
                linha = 'G';
            break;

            case 7:
                linha = 'H';
            break;

            default:
                break;
        }
        
        
        coluna = col;
        player = 0;
}

Posicao::Posicao(int lin, int col, int Player, Peca* p){
        peca = p;
    
        switch(lin){
            case 0:
               linha = 'A';
            break;

            case 1:
                linha = 'B';
            break;

            case 2:
                linha = 'C';
            break;

            case 3:
                linha = 'D';
            break;

            case 4:
                linha = 'E';
            break;

            case 5:
                linha = 'F';
            break;

            case 6:
                linha = 'G';
            break;

            case 7:
                linha = 'H';
            break;

            default:
                break;
        }
        
        
        coluna = col;
        player = Player;
}

/*retorna o atributo 'player'*/
int Posicao::getPlayer(){
    return player;
};

/*seta o atributo 'player' */
void Posicao::setPlayer(int p){
    player = p;
};

/*retorn o um ponteiro para o atributo 'peca'*/
Peca* Posicao::getPeca(){
    return peca;
};

/*seta o atributo 'peca'*/
void Posicao::setPeca(Peca *p){
    peca = p;
};

/* Seta o atributo 'cor' */
void Posicao::setCor(char c){
    cor = c;
};
            
/* Retorna o atributo 'cor' */
char Posicao::getCor(){
    return cor;
};
            
/* retorna o atributo 'linha' */
char Posicao::getLinha(){
    return linha;
};
            
/* Retorna o atributo 'coluna' */
int Posicao::getColuna(){
    return coluna;
};    


ostream& operator<<(ostream& out, const Posicao& posicao){
    /*Passando a linha para o arquivo*/
      switch(posicao.linha){
            case 'A':
                out << 0 << endl;
            break;

            case 'B':
               out << 1 << endl;
            break;

            case 'C':
                out << 2 << endl;
            break;

            case 'D':
                out << 3 << endl;
            break;

            case 'E':
                out << 4 << endl;
            break;

            case 'F':
                out << 5 << endl;
            break;

            case 'G':
                out << 6 << endl;
            break;

            case 'H':
                out << 7 << endl;
            break;

            default:
                break;
        }
        
      /*passando coluna para o arquivo*/
      out << posicao.coluna << endl;
      
      /*passando o player para o arquivo*/
      out << posicao.player << endl;
      
      /*peca = id, indica o tipo da peca que ocupa a posicao ou peca = -1, posicao vazia*/
      if(posicao.peca != NULL){
        out << posicao.peca->getID() << endl;
      } else{
        out << -1 << endl;
      }
};

