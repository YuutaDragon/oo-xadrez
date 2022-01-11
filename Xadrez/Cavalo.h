/*
*	Classe Cavalo: Controle da peca especifica Cavalo Checagem de moviemnto de acordo com a peca.
*				   Caracteristicas especificas da peca.
*
*
*/

#ifndef CAVALO_H
#define CAVALO_H

#include <string>
#include "Peca.h"

using namespace std;

class Cavalo: public Peca{
    private:
    	/* Atributo 'nome' guarda o nome Bispo*/
       //string nome;
       
       /* Atributo 'emJogo' controla se a peca esta em jogo (emJogo = 1) ou nao (emJogo = 0) */
       //bool emJogo;
       
       /* Atributo 'cor' guarda a cor da peca Branca ( 'B' ) ou Preta ( 'P' ) */
       //char cor;
       
    public:
    	/* Construtor da classe Cavalo */
        Cavalo(char c, int i);
        
        /* Metodo que retorna o desenho exibido no tabuleiro*/
        virtual char desenha();
        
        /* Metodo que checa se o movimento e adequado para a peca Cavalo*/
        virtual bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
        
        /* Muda valor para o atributo 'nome' */          
    	//void setNome(string n);
       
       	/* Retorna o atributo 'nome' */
    	//string getNome();
       
         /* Muda valor para o atributo 'emJogo' */
    	//void setEmJogo(int n);
    	
    	/* Retorna o atributo 'emJogo*/
    	//int  getEmJogo();
       
       	/* Muda o valor para o atributo 'cor' */
    	//void setCor(char c);
    	
    	/* Retorna o atributo 'cor' */
    	//char getCor();
    	
};

#endif /* CAVALO_H */


