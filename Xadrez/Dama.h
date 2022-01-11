/*
*	Classe Dama: Controle da peca especifica bispo. Checagem de moviemnto de acordo com a peca.
*				  Caracteristicas especificas da peca.
*
*
*/

#ifndef DAMA_H
#define DAMA_H

#include <string>
#include "Peca.h"

using namespace std;

class Dama: public Peca{
    private:
    	/* Atributo 'nome' guarda o nome Dama*/
       //string nome;
       
       /* Atributo 'emJogo' controla se a peca esta em jogo (emJogo = 1) ou nao (emJogo = 0) */
       //bool emJogo;
       
       /* Atributo 'cor' guarda a cor da peca Branca ( 'B' ) ou Preta ( 'P' ) */
       //char cor;
        
    public:
    	/* Construtor da classe Dama */
        Dama(char c, int i);
        
        /*	Metodo que retorna o desenho exibido no tabuleiro*/
        virtual char desenha();
        
        /*	Metodo que checa se o movimento e adequado para a peca Dama */
    	virtual bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
        
        /* Muda valor para o atributo 'nome' */       
    	//void setNome(string n);
    	
    	/* Retorna o atributo 'nome' */
    	//string getNome();
       
        /* Muda valor para o atributo 'emJogo' */
    	//void setEmJogo(int n);
    	
    	/* Retorna o atributo 'emJogo*/
    	//bool  getEmJogo();
       
       	/* Muda o valor para o atributo 'cor' */
    	//void setCor(char c);
    	
    	/* Retorna o atributo 'cor' */
    	//char getCor();
};

#endif /* DAMA_H */


