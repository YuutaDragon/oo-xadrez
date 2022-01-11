/*
*	Classe Tabuleiro: Responasavel pelo controle do tabuleiro. Exibicao das pecas, 
*					  checagem de movimento da peca em relacao ao tabuleiro, exibicao
*					  do tabulerio.
*
*
*/	

#include <cmath>
#include "Tabuleiro.h"
#include <iostream>
#include "Peca.h"
#include <string>
#include <cstring>
#include "Posicao.h"
#include "Rei.h"
#include "Bispo.h"
#include "Cavalo.h"
#include "Dama.h"
#include "Peao.h"
#include "Torre.h"
#include "Jogador.h"
#include <stdexcept>

using namespace std;

/*	Construtor para a peca Tbuelrio
*	posicao: inicializa cada posicao com nullptr - vazia. 
*/
Tabuleiro::Tabuleiro(){
     for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            posicao[i][j] = NULL;
        }
    }
    
    try{
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                posicao[i][j] = new Posicao(i, j);

                if(i%2 == 0){
                    if(j%2 == 0){
                        posicao[i][j]->setCor('P');
                    }
                    else{
                        posicao[i][j]->setCor('B');
                    }

                }else{
                    if(j%2 == 0){
                        posicao[i][j]->setCor('B');
                    }
                    else{
                        posicao[i][j]->setCor('P');
                    }

                }
            }
        }
        
    }catch(exception& error){
        cout << "Erro - Alocacao Dinamica" << error.what() << endl;
    }
}

/*Destrutor*/
Tabuleiro::~Tabuleiro(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(posicao[i][j] != NULL){	
                delete posicao[i][j];
                posicao[i][j] = NULL;
            }
        }
    }
	
}

/*passa os indices das posicao, e retornas um ponteiro para a posicao*/
Posicao* Tabuleiro::getPosicao(int i, int j){
    return posicao[i][j];
}

/*seta as posicoes com os valor passado no parametro*/
void Tabuleiro::setPosicao(Posicao *p[8][8]){
      for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(p[i][j]->getPeca() != NULL){
                posicao[i][j]->setPeca(p[i][j]->getPeca());
                posicao[i][j]->setPlayer(p[i][j]->getPlayer());
            }
        }
    }
    
    this->displayTabuleiro();
}

/*  iniciaJogo: inicia as posicoes inciais com suas respectivas pecas e exibie o tabulerio incial.
*	Parametros: *p[8][8] - ponteiro para uma matriz de posicoes.
* 	Return: 
*
*/
void Tabuleiro::iniciaJogo(Peca *peca[32], int player1, int player2){
   
    /*setando a posicao para cada player*/
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 8; j++){
              posicao[i][j]->setPlayer(player1);
              
        }
    }
    
    for(int i = 7; i > 5; i--){
        for(int j = 0; j < 8; j++){
            posicao[i][j]->setPlayer(player2);
        }
    }
   
    
    
    
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << posicao[i][j]->getLinha() << " - " << posicao[i][j]->getColuna() << ": "<< posicao[i][j]->getPlayer() << "|";
        }
        cout << "\n";
    }
    
    
    
    
/* Alocando as pecas em seus respectivos lugares iniciais pecas brancas */
    posicao[0][0]->setPeca(peca[4]);
    posicao[0][1]->setPeca(peca[2]);
    posicao[0][2]->setPeca(peca[6]);
    posicao[0][3]->setPeca(peca[0]);
    posicao[0][4]->setPeca(peca[1]);
    posicao[0][5]->setPeca(peca[7]);
    posicao[0][6]->setPeca(peca[3]);
    posicao[0][7]->setPeca(peca[5]);
    posicao[1][0]->setPeca(peca[8]);
    posicao[1][1]->setPeca(peca[9]);
    posicao[1][2]->setPeca(peca[10]);
    posicao[1][3]->setPeca(peca[11]);
    posicao[1][4]->setPeca(peca[12]);
    posicao[1][5]->setPeca(peca[13]);
    posicao[1][6]->setPeca(peca[14]);
    posicao[1][7]->setPeca(peca[15]);
    
    /* Alocando as pecas em seus respectivos lugares iniciais pecas pretas*/
    posicao[7][0]->setPeca(peca[20]);
    posicao[7][1]->setPeca(peca[18]);
    posicao[7][2]->setPeca(peca[22]);
    posicao[7][3]->setPeca(peca[16]);
    posicao[7][4]->setPeca(peca[17]);
    posicao[7][5]->setPeca(peca[23]);
    posicao[7][6]->setPeca(peca[19]);
    posicao[7][7]->setPeca(peca[21]);
    posicao[6][0]->setPeca(peca[24]);
    posicao[6][1]->setPeca(peca[25]);
    posicao[6][2]->setPeca(peca[26]);
    posicao[6][3]->setPeca(peca[27]);
    posicao[6][4]->setPeca(peca[28]);
    posicao[6][5]->setPeca(peca[29]);
    posicao[6][6]->setPeca(peca[30]);
    posicao[6][7]->setPeca(peca[31]);

    /* Metodo para exibir o tabuleiro*/
    displayTabuleiro();
}

/*  displayTabuleiro: converte as posicoes virtuais do atributo 'posicao' para as posicoes do tabuleiro que sera exibido aos players, e imprime o tabuleiro.
*	Parametros: 
* 	Return: 
*
*/
void Tabuleiro::displayTabuleiro() {

    /* Tabuleiro Real - Desenho de tabuleiro apresentado aos players */
    char displayTabuleiro[38][53] = {

	{' ', ' ', ' ', ' ', ' ', ' ', ' ', 'A', ' ', ' ', ' ', ' ', ' ', 'B', ' ', ' ', ' ', ' ', ' ', 'C', ' ', ' ', ' ', ' ', ' ', 'D', ' ', ' ', ' ', ' ', ' ', 'E', ' ', ' ', ' ', ' ', ' ', 'F', ' ', ' ', ' ', ' ', ' ', 'G', ' ', ' ', ' ', ' ', ' ', 'H', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', '7', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', '6', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', '5', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', '4', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', '3', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', '2', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', '1', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', '0', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    };

    /* Conversao do tabuleiro virtutal para o real - DISPLAY*/
    
    /*linhas reais */
    int dL0 = 31;
    int dL1 = 27;
    int dL2 = 23;
    int dL3 = 19;
    int dL4 = 15;
    int dL5 = 11;
    int dL6 = 7;
    int dL7 = 3;

    /*colunas reais*/
    int dC0 = 7;
    int dC1 = 13;
    int dC2 = 19;
    int dC3 = 25;
    int dC4 = 31;
    int dC5 = 37;
    int dC6 = 43;
    int dC7 = 49;
	
	
    int linha = 0;
    int coluna = 0;

    /*convertendo posicaro virtual para real*/
    /*linhas*/
    for(int i = 0; i < 8; i++){
        if(i == 0)
            linha = dL0;
        else if(i == 1)
            linha = dL1;
	else if(i == 2)
            linha = dL2;
	else if(i == 3)
            linha = dL3;
	else if(i == 4)
            linha = dL4;
	else if(i == 5)
            linha = dL5;
	else if(i == 6)
            linha = dL6;
	else
            linha = dL7;

	/*colunas*/
	for(int j = 0; j < 8; j++){
            if(j == 0)
		coluna = dC0;
            else if(j == 1)
		coluna = dC1;
            else if(j == 2)
		coluna = dC2;
            else if(j == 3)
		coluna = dC3;
            else if(j == 4)
		coluna = dC4;
            else if(j == 5)
		coluna = dC5;
            else if(j == 6)
		coluna = dC6;
            else
		coluna = dC7;


		/*atualizando o tabueleiros com as pecas*/
                if(posicao[i][j]->getPeca() != NULL){
                    displayTabuleiro[linha][coluna] = posicao[i][j]->getPeca()->desenha();
                    displayTabuleiro[linha + 1][coluna + 1] = posicao[i][j]->getPeca()->getCor();
                 
                }
                else
                    displayTabuleiro[linha][coluna] = ' ';
        }
    }
	
    /* Imprimir o tabulerio */
    for(int i = 0; i < 34; i++){

	cout << endl;

            for(int j = 0; j < 53; j++){

		cout << displayTabuleiro[i][j];

            }
    }
    cout << endl << endl;
}

/*  moverPeca: move a peca requisita para o local de destino, se o movimento for adequado para a peca, e imprime o tabuleiro.
*	Parametros: linhaOrigem, linhaDestino, colunaOrigem, linhaDestino, colunaDestino - ( 0 - 7), player ( 1 ou 2).
* 	Return: retorna um inteiro onde:
*	true - movimento ok, peca e movida
*	false - movimento erro
*/
bool Tabuleiro::moverPeca(int linhaOrigem, int linhaDestino, int colunaOrigem, int colunaDestino, int playerCorrente, Jogador *player, int *id){
	/*posicoa origem e valida, diferente de vazia*/
	if(posicao[linhaOrigem][colunaOrigem]->getPeca() != NULL){

		/*peca de origem pertence ao player corrente*/
		if(posicao[linhaOrigem][colunaOrigem]->getPlayer() == playerCorrente){
		
                    /*checa se o movimento da peca e adequado e se existe peca no caminho */
                    int checa = checaMovimento(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino);
			
                    /* Pode realizar o movimento*/
		    if(checa == 1){
                        /**/
                        if( posicao[linhaDestino][colunaDestino]->getPeca() != NULL){  
                          *id = posicao[linhaDestino][colunaDestino]->getPeca()->getID();
                        }else *id = -1;
 
                        /* Movimento */                         
                        posicao[linhaDestino][colunaDestino]->setPeca(posicao[linhaOrigem][colunaOrigem]->getPeca());
                        posicao[linhaDestino][colunaDestino]->setPlayer(posicao[linhaOrigem][colunaOrigem]->getPlayer());

		        /* posicao origem fica vazia apos o movimento*/
		        posicao[linhaOrigem][colunaOrigem]->setPeca(NULL);
                        posicao[linhaOrigem][colunaOrigem]->setPlayer(0);
                            
		        /* movimento realizado exibe tabuleiro*/
                        displayTabuleiro();
                        
                        if(posicao[linhaDestino][colunaDestino]->getPeca()->getNome() == "Rei"){
                            player->setRei(linhaDestino, colunaDestino);
                        }
                
                        return true;
		    }
		    
		    /* Existe peca no caminho */
		    else if(checa == 0){
                        throw "Movimento Impedido";
                        return false;
		    }
		    
		    /* ERROR */
		    else if(checa == -2){
		        throw "ERROR";
                        return false;
		    }
		    
		    /* O movimento nao corresponde a peca*/
		    else{
                        throw "Movimento Inadequado Para Peca";
                        return false;
		    }
		}
		/*Tentando peca inimiga*/
		else{
                    throw "Movimento de Peca Inimiga"; 
                    return false;
                }
	}
	else{
           throw "Espaço Vazio"; 
           return false;
        }
}




/*  checaMovimento: checa o movimento das pecas, tanto o movimento especifico, se a pecas no caminho, e se no destino tem peca aliada ou nao.
*	Parametros: linhaOrigem, linhaDestino, colunaOrigem, linhaDestino, colunaDestino - ( 0 - 7).
* 	Return: retorna um inteiro onde:
*	 1 - movimento ok, pode mover a peca
*	 0 - movimento impedido - peca no caminho ou posicao final com peca aliada
*	-1 - movimento inadequado, movimento especifico nao correponde a peca.
*/
int Tabuleiro::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino){
    
    /* deslocV - deslocamento no eixo Y | deslocH - deslocamento no eixo X*/
    int deslocV = linhaOrigem - linhaDestino;
    int deslocH = colunaOrigem - colunaDestino;
	
	/* Verificar movimento da peca Rei */
    if((posicao[linhaOrigem][colunaOrigem]->getPeca()->getNome() == "Rei")){
    	
    	/* verificar movimento especifico*/
        if(posicao[linhaOrigem][colunaOrigem]->getPeca()->checaMovimento(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino)){
        	
            /* verificar peca no caminho ou peca aliada no destino*/
            if(posicao[linhaDestino][colunaDestino]->getPeca() == NULL || posicao[linhaOrigem][colunaOrigem]->getPlayer() != posicao[linhaDestino][colunaDestino]->getPlayer()){	
		/* movimento ok*/
                cout << posicao[linhaOrigem][colunaOrigem]->getPlayer() << " - " <<posicao[linhaDestino][colunaDestino]->getPlayer() << endl;
		return 1;
            }
            else
            	/*peca no camilho ou peca aliada no destino*/
                return 0;
        }
        else
            /*movimento especifico inadequado*/
            return -1;
    }
	
	/*verifiar moviemento da peca Dama*/
    else if((posicao[linhaOrigem][colunaOrigem]->getPeca()->getNome() == "Dama")){
    	
    	/*verifica movimento especifico*/
        if(posicao[linhaOrigem][colunaOrigem]->getPeca()->checaMovimento(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino)){
        	
            /*verifica peca no caminho e peca aliada no destino*/
            if(posicao[linhaDestino][colunaDestino]->getPeca() == NULL || posicao[linhaOrigem][colunaOrigem]->getPlayer() != posicao[linhaDestino][colunaDestino]->getPlayer()){
				
				           	
                if(deslocV > 0 && deslocH > 0){
                	int i = linhaOrigem - 1;
                	int j = colunaOrigem - 1;
                    while( i > linhaDestino && j > colunaDestino){
                        if(posicao[i--][j--]->getPeca() != NULL){
                            return 0;
                        }
                    }
                }
                

                else if(deslocV > 0 && deslocH < 0){
                	int i = linhaOrigem - 1;
                	int j = colunaOrigem + 1;
                	while(i > linhaDestino && j < colunaDestino){
                		if(posicao[i--][j++]->getPeca() != NULL){
                            return 0;
                        }
                    }
                }

                else if(deslocV < 0 && deslocH > 0){
                	int i = linhaOrigem + 1;
                	int j = colunaOrigem - 1;
                	while(i < linhaDestino && j > colunaDestino){
                		if(posicao[i++][j--]->getPeca() != NULL){
                            return 0;
                       }
                    }
                }
                
                else if (deslocV < 0 && deslocH < 0){
                	int i = linhaOrigem + 1;
                	int j = colunaOrigem + 1;
                	while(i < linhaDestino && j < colunaDestino){
                		if(posicao[i++][j++]->getPeca() != NULL){
                            return 0;
                    	}
                    }
		}
				
		else if(deslocV == 0 && deslocH > 0){
                    for(int i = colunaOrigem - 1; i > colunaDestino; i--){
                        if(posicao[linhaOrigem][i]->getPeca() != NULL){
                             return  0;
                        }
                    }
                }

                else if(deslocV == 0 && deslocH < 0){
                    for(int i = colunaOrigem + 1; i < colunaDestino; i++){
                        if(posicao[linhaOrigem][i]->getPeca() != NULL){
                            return  0;

                        }
                    }
                }

                else if(deslocH == 0 && deslocV > 0){
                    for(int i = linhaOrigem - 1; i > linhaDestino; i--){
                        if(posicao[i][colunaOrigem]->getPeca() != NULL){
                            return  0;
                        }
                    }
                }

                else{
                	for(int i = linhaOrigem + 1; i < linhaDestino; i++){
                    	if(posicao[i][colunaOrigem]->getPeca() != NULL){
                            return  0;
                        }
                    }
                }
				
		/* movimento ok */
		return 1;
                    
            }
            /*posicao destino com peca aliado*/
            else
               	return 0;
        }
        /*movimento inadequado para peca*/
        else
            return -1;
    }
	
	/* verifica movimento para a peca cavalo */
    else if((posicao[linhaOrigem][colunaOrigem]->getPeca()->getNome() == "Cavalo")){
    	
    	/* verica movimento especifico */
        if(posicao[linhaOrigem][colunaOrigem]->getPeca()->checaMovimento(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino)){

			/* verifica peca aliada no destino*/
            if(posicao[linhaDestino][colunaDestino]->getPeca() == NULL || posicao[linhaOrigem][colunaOrigem]->getPlayer() != posicao[linhaDestino][colunaDestino]->getPlayer()){
				/*movimento ok*/
                return 1;
            }
            /*posicao destino possui peca aliada*/
            else
                return 0;
        }
        /*movimento inadequado para peca*/
        else return -1;
    }
	
	/*verifica movimento para a peca Bispo*/
    else if((posicao[linhaOrigem][colunaOrigem]->getPeca()->getNome() == "Bispo")){
    	
    	/*verifica movimento especifico */
        if(posicao[linhaOrigem][colunaOrigem]->getPeca()->checaMovimento(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino)){
        	
        	/* verifica peca no caminho e peca aliada no destino */
            if(posicao[linhaDestino][colunaDestino]->getPeca() == NULL || posicao[linhaOrigem][colunaOrigem]->getPlayer() != posicao[linhaDestino][colunaDestino]->getPlayer()){
            	
                if(deslocV > 0 && deslocH > 0){
                	int i = linhaOrigem - 1;
                	int j = colunaOrigem - 1;
                    while( i > linhaDestino && j > colunaDestino){
                        if(posicao[i--][j--]->getPeca() != NULL){
                            return 0;
                        }
                    }
                }
                

                else if(deslocV > 0 && deslocH < 0){
                	int i = linhaOrigem - 1;
                	int j = colunaOrigem + 1;
                	while(i > linhaDestino && j < colunaDestino){
                		if(posicao[i--][j++]->getPeca() != NULL){
                            return 0;
                        }
					}
                }

                else if(deslocV < 0 && deslocH > 0){
                	int i = linhaOrigem + 1;
                	int j = colunaOrigem - 1;
                	while(i < linhaDestino && j > colunaDestino){
                		if(posicao[i++][j--]->getPeca() != NULL){
                            return 0;
                       }
					}
                }
                
                else{
                	int i = linhaOrigem + 1;
                	int j = colunaOrigem + 1;
                	while(i < linhaDestino && j < colunaDestino){
                		if(posicao[i++][j++]->getPeca() != NULL){
                            return 0;
                    	}
					}
				}
				
                 /*Movimento ok*/  
                return 1;
            }
            /*posicao destino possui peca aliada ou peca no caminho*/
            else
                return 0;
        }
        /*movimento inadequado para peca*/
        else
            return -1;
    }
	
	/*verifica movimento para a peca Torre */
    else if((posicao[linhaOrigem][colunaOrigem]->getPeca()->getNome() == "Torre")){ 
    
    	/*verifica movimento especifico*/
        if(posicao[linhaOrigem][colunaOrigem]->getPeca()->checaMovimento(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino)){ 
        
        	/* verifica peca no caminho ou pela alida no destino */
            if(posicao[linhaDestino][colunaDestino]->getPeca() == NULL || posicao[linhaOrigem][colunaOrigem]->getPlayer() != posicao[linhaDestino][colunaDestino]->getPlayer()){
				
                if(deslocV == 0 && deslocH > 0){
                    for(int i = colunaOrigem - 1; i > colunaDestino; i--){
                        if(posicao[linhaOrigem][i]->getPeca() != NULL){
                             return  0;
                        }
                    }
                }

                else if(deslocV == 0 && deslocH < 0){
                    for(int i = colunaOrigem + 1; i < colunaDestino; i++){
                        if(posicao[linhaOrigem][i]->getPeca() != NULL){
                            return  0;

                        }
                    }
                }

                else if(deslocH == 0 && deslocV > 0){
                    for(int i = linhaOrigem - 1; i > linhaDestino; i--){
                        if(posicao[i][colunaOrigem]->getPeca() != NULL){
                            return  0;
                        }
                    }
                }

                else{
                	for(int i = linhaOrigem + 1; i < linhaDestino; i++){
                    	if(posicao[i][colunaOrigem]->getPeca() != NULL){
                            return  0;
                        }
                    }
                }
                
                return 1; /* se sobreviver as condicoes de movimento, a peca pode mover*/
                

            }
            /*posicao destino possui peca aliada ou peca no caminho*/
            else{
                return 0;
            }
        }
        /*movimento inadequado para a peca*/
        else{
            return -1;
        }
    }
    
	/*verifica movimento para a peca peao*/
    else if((posicao[linhaOrigem][colunaOrigem]->getPeca()->getNome() == "Peao")){
    	
            /* verifica movimento especifico e peca no caminho */
            if(posicao[linhaOrigem][colunaOrigem]->getPeca()->checaMovimento(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino) && posicao[linhaDestino][colunaDestino]->getPeca() == NULL){
               
			    /*movimento ok*/
				return 1;
            }
            
            /*movimento de captura do peao*/
            else if(abs(deslocH) == 1 && abs(deslocV) == 1 && posicao[linhaDestino][colunaDestino]->getPeca() != NULL){
				if(posicao[linhaOrigem][colunaOrigem]->getPlayer() != posicao[linhaDestino][colunaDestino]->getPlayer()){
              	  /*movimento ok*/
					return 1;
            	}
       		}
            else
            	/*movimento inadequado par ao peao ou peca no caminho*/
                return 0;
        }
    
	/*ERROR*/  
    else{
        return -2;
    }
        
};


string Tabuleiro::verificaChequeMate(int linhaRei, int colunaRei, int playerCorrente){
     cout << "entro" << endl;
    if(verificaCheque(linhaRei, colunaRei, playerCorrente) == "CHEQUE"){
        /*VERIFICAR O CHEQUE MATE*/
         cout << "entro0" << endl;
            if((verificaCheque(linhaRei + 1, colunaRei , playerCorrente) == "CHEQUE") && checaMovimento(linhaRei, colunaRei, linhaRei + 1, colunaRei) == 1){
                cout << "entro1" << endl;
                if(verificaCheque(linhaRei - 1, colunaRei , playerCorrente) == "CHEQUE" && checaMovimento(linhaRei, colunaRei, linhaRei - 1, colunaRei) == 1){
                     cout << "entro2" << endl;
                    if(verificaCheque(linhaRei, colunaRei + 1, playerCorrente) == "CHEQUE" && checaMovimento(linhaRei, colunaRei, linhaRei, colunaRei + 1) == 1){
                         cout << "entro3" << endl;
                        if(verificaCheque(linhaRei, colunaRei - 1, playerCorrente) == "CHEQUE"&& checaMovimento(linhaRei, colunaRei, linhaRei, colunaRei - 1) == 1){
                             cout << "entro4" << endl;
                             if(verificaCheque(linhaRei + 1, colunaRei + 1, playerCorrente) == "CHEQUE" && checaMovimento(linhaRei, colunaRei, linhaRei + 1, colunaRei + 1) == 1){
                                  cout << "entro5" << endl;
                                  if(verificaCheque(linhaRei - 1, colunaRei - 1, playerCorrente) == "CHEQUE" && checaMovimento(linhaRei, colunaRei, linhaRei - 1, colunaRei - 1) == 1){
                                       cout << "entro6" << endl;
                                       if(verificaCheque(linhaRei + 1, colunaRei - 1, playerCorrente) == "CHEQUE" && checaMovimento(linhaRei, colunaRei, linhaRei + 1, colunaRei - 1) == 1){
                                            cout << "entro7" << endl;
                                            if(verificaCheque(linhaRei - 1, colunaRei + 1, playerCorrente) == "CHEQUE" && checaMovimento(linhaRei, colunaRei, linhaRei - 1, colunaRei + 1) == 1){
                                                cout << "entro8" << endl;
                                                return "CHEQUE MATE";   
                                            }else return "CHEQUE";
                                       }else return "CHEQUE";
                                  }else return "CHEQUE";
                             }else return "CHEQUE";
                        }else return "CHEQUE";
                    }else return "CHEQUE";
                }else return "CHEQUE";      
            }else return "CHEQUE"; 
    }else return "NORMAL";
    
};




string Tabuleiro::verificaCheque(int linhaRei, int colunaRei, int playerCorrente){
    int linha = linhaRei;
    int coluna = colunaRei;
    
    while(++linha < 8){
        if(posicao[linha][coluna]->getPeca() != NULL && posicao[linha][coluna]->getPlayer() == playerCorrente){
           if(checaMovimento(linha, coluna, linhaRei, colunaRei) == 1) 
               return "CHEQUE";
           }
    }
 
    linha = linhaRei;
    coluna = colunaRei;
    while(--linha >= 0){
        if(posicao[linha][coluna]->getPeca() != NULL && posicao[linha][coluna]->getPlayer() == playerCorrente){
           if(checaMovimento(linha, coluna, linhaRei, colunaRei) == 1) 
               return "CHEQUE";

        }
    }  


    linha = linhaRei;
    coluna = colunaRei;
    while(++coluna < 8){
        if(posicao[linha][coluna]->getPeca() != NULL && posicao[linha][coluna]->getPlayer() == playerCorrente){
           if(checaMovimento(linha, coluna, linhaRei, colunaRei) == 1) 
               return "CHEQUE";
        }
    }       
	
  
    linha = linhaRei;
    coluna = colunaRei;
    while(coluna >= 0){
        if(posicao[linha][coluna]->getPeca() != NULL && posicao[linha][coluna]->getPlayer() == playerCorrente){
           if(checaMovimento(linha, coluna, linhaRei, colunaRei) == 1) 
               return "CHEQUE";
        }
        coluna--;
    }
    

    linha = linhaRei;
    coluna = colunaRei;
    while((++coluna) < 8 && (++linha) < 8){
        if(posicao[linha][coluna]->getPeca() != NULL && posicao[linha][coluna]->getPlayer() == playerCorrente){
           if(checaMovimento(linha, coluna, linhaRei, colunaRei) == 1) 
               return "CHEQUE";
        }
    } 
    

    linha = linhaRei;
    coluna = colunaRei;
    while((++coluna) < 8 && (--linha) >= 0){
        if(posicao[linha][coluna]->getPeca() != NULL && posicao[linha][coluna]->getPlayer() == playerCorrente){
           if(checaMovimento(linha, coluna, linhaRei, colunaRei) == 1) 
               return "CHEQUE";
        }
    } 
    
  
    linha = linhaRei;
    coluna = colunaRei;
    while((--coluna) >= 0 && (++linha) < 8){
        if(posicao[linha][coluna]->getPeca() != NULL && posicao[linha][coluna]->getPlayer() == playerCorrente){
           if(checaMovimento(linha, coluna, linhaRei, colunaRei) == 1) 
               return "CHEQUE";
        }
    } 
    
     
       
    linha = linhaRei;
    coluna = colunaRei;
    while((--coluna) >= 0 && (--linha) >= 0){
        if(posicao[linha][coluna]->getPeca() != NULL && posicao[linha][coluna]->getPlayer() == playerCorrente){
           if(checaMovimento(linha, coluna, linhaRei, colunaRei) == 1) 
               return "CHEQUE";
        }
    }

    return "NORMAL";
    
    
};