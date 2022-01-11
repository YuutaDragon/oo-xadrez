/*
*	Classe Peca: Caracteriscas Gerais aplicadas a todas as pecas do jogo.
*
*
*/		

#ifndef PECA_H
#define PECA_H

#include <string>

using namespace std;

class Peca {
    private:
    	/* Atributo 'nome' guarda o nome da peca*/
       string nome;
       
       /* Atributo 'emJogo' controla se a peca esta em jogo (emJogo = 1) ou nao (emJogo = 0) */
       bool emJogo;
       
       /* Atributo 'cor' guarda a cor da peca Branca ( 'B' ) ou Preta ( 'P' ) */
       char cor;
       
       /*Atributo resposavel por indetificar o tipo da peca, utilizado na recuperacao do arquivo*/
       int id;
       
    public:
        Peca(string n, char c , int i, bool ejogo = true);

    	
        void setNome(string n);

    	/* Retorna o atributo 'nome' */
    	string getNome();
       
        /* Muda valor para o atributo 'emJogo' */
    	void setEmJogo(bool i);
    	
    	/* Retorna o atributo 'emJogo*/
    	bool  getEmJogo();
    	
        /*seta a cor da peca*/
        void setCor(char c);
        
    	/* Retorna o atributo 'cor' */
    	char getCor();
        
        /*Metodo virtual para checar movimento*/
        virtual bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino)= 0;
        
         /*Metodo que retorna o desenho exibido no tabuleiro*/
        virtual char desenha() = 0;
        
        /*retorna o id da peca*/
        int getID();
        
        /*sobrecar do operador de saida*/
        friend ostream& operator<<(ostream& out, const Peca& peca);
       
        
       
};

#endif /* PECA_H */


