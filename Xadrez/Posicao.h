/*
*	Classe Posicao: controle e informacoes sobre as posicoes no tabuleiro
*
*
*/		


#ifndef POSICAO_H
#define POSICAO_H

#include <string>
#include "Peca.h"


using namespace std;

class Posicao {
    private:
    	
    	/* ponteiros para a peca que ocupa a posicao*/        
        Peca *peca;
                
        /* atributo 'player' informa que a posicao ocupada pelo player 1 ou 2*/
        int player; 
        
        /*Cor da posicao*/
        char cor;
        
        /*posicao*/
        char linha;
        
        int coluna;
 
    public:
	    /* construtor da classe posicao */       
	    Posicao(int lin, int col);
            
            /*sobrecar do construtor*/
            Posicao(int lin, int col, int Player, Peca *p);
                    	    
	    /* retorna um ponteiro para a peca que esta na posicao*/
	    Peca*  getPeca();
	    
	    /*seta um ponteiro pra a peca que esta na posicao*/
	    void  setPeca(Peca *p);
	    
	    /*seta um valor para player, 1 ou 2*/
	    int getPlayer();
	    
	    /*retorna o valor de player*/
	    void setPlayer(int p);
            
            /* Seta o atributo 'cor' */
            void setCor(char c);
            
            /* Retorna o atributo 'cor' */
            char getCor();
            
             /* retorna o atributo 'linha' */
            char getLinha();
            
            /* Retorna o atributo 'coluna' */
            int getColuna();          
                        
           /*sobrecarfa do operador de saida << */
           friend ostream& operator<<(ostream& out, const Posicao& posicao); 
           
       
};

#endif /* POSICAO_H */


