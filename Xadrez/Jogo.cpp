/*
*	Classe Jogo: controla o jogo, incializa a pecas, e insere nas posicoes iniciais.
*				 possui o controle do jogo e o estado.
*
*
*/	

#include "Jogo.h"
#include <iostream>
#include <stdexcept>
#include <fstream>

/*	Construtor para a Jogo
*	posicao: inicializa os ponteiros com NULL
*  	estado: inicializa estado com inicio do jogo
*	pecas: inicializa pecas com suas respectivas cores.
*/
Jogo::Jogo(){
    player1 = new Jogador(1);
    player2 = new Jogador(2);
    player1->setRei(0, 3);
    player2->setRei(7, 3);
    
    try{
        tabuleiro = new Tabuleiro();

        for(int i = 0; i < 32; i++){
            peca[i] = NULL;
        }

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

        peca[16]   = new Rei('p', 16);
        peca[17]   = new Dama('p', 17);
        peca[18]   = new Cavalo('p', 18);
        peca[19]   = new Cavalo('p', 19);
        peca[20]   = new Torre('p', 20);
        peca[21]   = new Torre('p', 21);
        peca[22]   = new Bispo('p', 22);
        peca[23]   = new Bispo('p', 23);
        peca[24]   = new Peao('p', 24);
        peca[25]   = new Peao('p', 25);
        peca[26]   = new Peao('p',26);
        peca[27]   = new Peao('p', 27);
        peca[28]   = new Peao('p', 28);
        peca[29]   = new Peao('p', 29);
        peca[30]   = new Peao('p', 30);
        peca[31]   = new Peao('p', 31);
        
      
        
    }
    catch(exception& error){
        cout << "Erro - Alocacao Dinamica" << error.what() << endl;
    }

}


/*Destrutor*/
Jogo::~Jogo(){
    for(int i = 0; i < 32; i++){
        if(peca[i] != NULL){
            delete peca[i];
	    peca[i] = NULL;     		
        }
    }	
    
    delete tabuleiro;
    tabuleiro = NULL;
}



/*	iniciarJogo: inicializa as posicoes com as pecas
*	Parametros: 
* 	Return: 
*/
void Jogo::iniciarJogo() {
   
    /*Variaveis para escolha entre um novo jogo ou carregar um jogo*/   
    int tipo_de_jogo;
    string nome_arquivo;
    int playerCorrente = 2;
    int menu = 1;

    cout << "-------------------------------- Bem Vindo ao Xadrez --------------------------------------" << endl;

    /*responsavel por carregar ou criar um novo jogo*/
    while(menu != 0){
        cout << "1 - NOVO JOGO " << endl;
        cout << "2 - CARREGAR JOGO " << endl;
        cin >> tipo_de_jogo ;

        if(tipo_de_jogo == 1){
            /*Inicializando tabuleiro para um novo jogo*/
            tabuleiro->iniciaJogo(peca, player1->getPlayer(), player2->getPlayer()); 

        }

        else{
            /*tentativa de abrir o arquivo salvo*/
            try{
                cout << "Digite o nome do arquivo a ser carregado: " << endl;
                cin >> nome_arquivo;
                if(carregarJogo(nome_arquivo) == 2)
                    playerCorrente = 1;
                
                menu = 0;
                
            }catch(const char* error){
                cout << error << endl;
                menu = 1;
            }
        }
    }
    
    /* Variaveis: recebem um char de A - H, que serao traduzidas para numeros de 0 - 7.*/
    char cO, cD;
    
    /*Variaveis de controle de entrada para o jogo*/   
    int linhaOrigem, linhaDestino;
    int colunaOrigem = -1, colunaDestino = -1;
    bool aceita = true;
    int jogo = 1;
    int id = -1;  
    int op;
    
  /*menu de interações com o players*/
    while(jogo != 0){
      
        cout << "****************************" << endl;
        cout << "* 1 - Movimento            *" << endl;
        cout << "* 2 - Salvar Jogo          *" << endl;
        cout << "* 3 - Exibir Pecas em Jogo *" << endl;
        cout << "* 0 - Sair                 *\n" << endl;
        cout << "****************************" << endl;
        cin >> op;

        cout << "\n" << endl;
    	//Decide se o player sera alterado ou nao, altera quando o player corrente consegue realizar um movimento.
        if(aceita == true){
            if(playerCorrente == 1)
                playerCorrente = 2;
            else
                playerCorrente = 1;
        }

        colunaOrigem = -1;
        colunaDestino = -1;
        
        switch(op){
            
            case 1:
                
                cout << "---------------------MOVIMENTO-----------------------------------\n" << endl;
                cout << "Player: " << playerCorrente << " Escolha seu Movimento \n" << endl;
                cout << "Digite a Peca que gostaria de mover:" << endl;
                cin >> linhaOrigem;
                cin >> cO;

                cout << "Digite o local para qual gostaria de mover a peca" << endl;
                cin >> linhaDestino;
                cin >> cD;
                

                /* Trocando valores de char (virtual) para os valores inteiros (reais) */
                switch(cO){
                    case 'A':
                        colunaOrigem = 0;
                    break;

                    case 'B':
                        colunaOrigem = 1;
                    break;

                    case 'C':
                        colunaOrigem = 2;
                    break;

                    case 'D':
                        colunaOrigem = 3;
                    break;

                    case 'E':
                        colunaOrigem = 4;
                    break;

                    case 'F':
                        colunaOrigem = 5;
                    break;

                    case 'G':
                        colunaOrigem = 6;
                    break;

                    case 'H':
                        colunaOrigem = 7;
                    break;

                    default:
                        aceita = false;
                        cout << "Valor de coluna origem invalido\n" << endl;                    
                    break;
                }

                switch(cD){

                    case 'A':
                        colunaDestino = 0;
                    break;

                    case 'B':
                        colunaDestino = 1;
                    break;

                    case 'C':
                        colunaDestino = 2;
                    break;

                    case 'D':
                        colunaDestino = 3;
                    break;

                    case 'E':
                        colunaDestino = 4;
                    break;

                    case 'F':
                        colunaDestino = 5;
                    break;

                    case 'G':
                        colunaDestino = 6;
                    break;

                    case 'H':
                        colunaDestino = 7;
                    break;

                    default:
                        aceita = false;
                        cout << "Valor de coluna destino invalido\n" << endl;
                    break;
                }

                /* Verificando se o usuario digitou um valor valido para coluna */
                if(colunaOrigem != -1 || colunaDestino != -1){

                    /* verificando se o usuario digitou um valor dentro do tabulerio */
                    if(linhaOrigem < 8 && linhaOrigem >= 0 && linhaDestino < 8 && linhaDestino >= 0){
                        try{
                            id = -1;
                            if(playerCorrente == 1){
                                /* aceita: contem um valor inteiro indicando se a peca foi movida ou nao */
                                aceita = tabuleiro->moverPeca(linhaOrigem,linhaDestino,colunaOrigem, colunaDestino, playerCorrente, player1, &id);
                                if(aceita == true){
                                    cout << "MOVIMENTO REALIZADO COM SUCESSO\n" << endl;
                                    /*exibe se algum player esta em cheque*/
                                    estado = tabuleiro->verificaCheque(player2->getRei_linha(), player2->getRei_coluna(), playerCorrente);
                                    cout << estado << endl;
                                    cout << "Player: 1 esta em " <<  tabuleiro->verificaCheque(player1->getRei_linha(), player1->getRei_coluna(), 2) << endl;
                                    cout << "Player: 2 esta em " <<  tabuleiro->verificaCheque(player2->getRei_linha(), player2->getRei_coluna(), playerCorrente) << endl;
                                    cout << "\n" << endl;
                                    
                                    /*seta os parametros necessarios de cada jogador a cada movimento, casa alguma peca seja comida*/
                                    if(id != -1){
                                        peca[id]->setEmJogo(false);
                                        player2->setqtdPeca();
                                        player2->setPecaJogo(id - 16);
                                    }

                                }
                            }
                            else{
                                /* aceita: contem um valor inteiro indicando se a peca foi movida ou nao */
                                aceita = tabuleiro->moverPeca(linhaOrigem,linhaDestino,colunaOrigem, colunaDestino, playerCorrente, player2, &id);

                                if(aceita == true){
                                    cout << "MOVIMENTO REALIZADO COM SUCESSO\n" << endl;
                                    
                                    /*exibe se algum player esta em cheque*/
                                    estado = tabuleiro->verificaCheque(player1->getRei_linha(), player1->getRei_coluna(), playerCorrente);
                                    cout << estado << endl;
                                    cout << "Player: 1 esta em " << tabuleiro->verificaCheque(player1->getRei_linha(), player1->getRei_coluna(), playerCorrente) << endl;
                                    cout << "Player: 2 esta em " << tabuleiro->verificaCheque(player2->getRei_linha(), player2->getRei_coluna(), 1) << endl;
                                    cout << "\n" << endl;
                                   
                                    /*seta os parametros necessarios de cada jogador a cada movimento, casa alguma peca seja comida*/
                                      if(id != -1){
                                        peca[id]->setEmJogo(false);
                                        player1->setqtdPeca();
                                        player1->setPecaJogo(id);
                                    }

                                }
                            }

                        }catch(const char* error){
                            /*exibe as mensagens de erro que retornam na tentatia de mover uma peca*/
                            cout << "\nErro - " << error << "\n" << endl;
                            aceita = false;
                        }
                    }

                    else{
                        /* usuario digitou uma linha invalida */
                        aceita = false;
                        cout << "\nValor da linha nao pertence ao tabuleiro" << endl;
                    }
                }
                
            break;
            
            case 2:
                cout << "---------------------SALVAR O JOGO-------------------------------------\n" << endl;
                try{
                    salvarJogo(playerCorrente);
                }catch(const char* error){
                    cout << error << endl;
                }
            break;
                
            case 3:
                cout << "---------------------IMPRIMINDO PECAS-----------------------------------\n" << endl;
                pecasEmJogo();                
            break;

            default:
                jogo = 0;
            break;
        }
    }
}

/*	salvarJogo: salva todas as informações necessarias do jogo em um arquvio txt
*	Parametros: playerCorrente (indicando de qual player e a jogada)
* 	Return: 
*/
void Jogo::salvarJogo(int playerCorrente){

        string nome_arquivo = "xadrez.txt";

        cout << "Digite o local e nome do arquvio em que gostaria de salvar o jogo" << endl;
        cin >> nome_arquivo;
        
        ofstream fout(nome_arquivo);

        if(fout.is_open()){
            /*salva as pecas que estao e nao estao em jogo*/
            for(int i = 0; i < 32; i++){
                fout << *peca[i] << endl;
            }

            fout << "\n";
            
            /*salva em que player parou a jogada*/
            fout << playerCorrente << endl;

            fout << "\n";

            /*salva a configuracao do tabuleiro*/
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    fout << *tabuleiro->getPosicao(i, j) << endl;

                }
            }

           fout.close();
           cout << "Arquivo salvo com SUCESSO" << endl;
        
    }else{
       throw "Erro - Ao Salvar o Arquivo";
    }
}


/*	carregarJogo: recupera as informacoes do arquvio
*	Parametros: nome do arquvio a ser utilizado ou endereço do seu local
* 	Return: em que player deve iniciar a jogada
*/
int Jogo::carregarJogo(string nome_arquivo){

    int i, j;
    ifstream fin(nome_arquivo);
    
    /*recupera quais pecas estao no jogo*/    
    if(fin.is_open()){   
        for(int i = 0; i < 32; i++){
            fin >> j;
                if( j == 1)
                    peca[i]->setEmJogo(true);
                else 
                    peca[i]->setEmJogo(false);   
        }

        /**recupera todo o estado do tabuleiro salvo*/
        Posicao *pos[8][8];
        int linha, coluna, player_arquivo, peca_arquivo, playerCorrente;

        fin >> playerCorrente;

        while(!fin.eof()){
            fin >> linha;
            fin >> coluna;
            fin >> player_arquivo;
            fin >> peca_arquivo;

            if(peca_arquivo != -1){
                pos[linha][coluna] = new Posicao(linha, coluna, player_arquivo, peca[peca_arquivo]);

            }else{
                  pos[linha][coluna] = new Posicao(linha, coluna, player_arquivo, NULL);
            }
        }

        fin.close();

        tabuleiro->setPosicao(pos);

        return playerCorrente;

    }else{
        throw "ERRO - Abrir o arquivo FALHOU";
        return -1;
    }
    
};

/*	pecasEmJogo: exibe todas as pecas em jogo
*	Parametros: 
* 	Return: 
*/
void Jogo::pecasEmJogo(){
    cout << "Pecas em Jogo \n" << endl;
    for(int i = 0; i < 32; i++){
        if(peca[i]->getEmJogo())
            cout << "Peca: " << peca[i]->getNome() << "\t Cor: " << peca[i]->getCor() << endl;
    }
    
    cout << endl;
    player1->imprimirPecaJogo();
    
    cout << endl;
    player2->imprimirPecaJogo();
}