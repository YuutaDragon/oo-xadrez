/*
*	Classe Peca: Caracteriscas Gerais aplicadas a todas as pecas do jogo.
*
*
*/		

#include "Peca.h"
#include <cmath>
#include <iostream>

using namespace std;

Peca::Peca(string n, char c, int i, bool ejogo) {
    nome = n;
    cor = c;
    emJogo = ejogo;
    id = i;
}

/*	Seta o valor do atributo 'emJogo' para falso, peca eliminada */
void Peca::setEmJogo(bool i){
    emJogo = i;
};

/* Retorna o valor do atributo 'emJogo' - No jogo = 1, Fora do jogo = 0 */
bool Peca::getEmJogo(){
    return emJogo;
};

void Peca::setNome(string n){
    nome = n;
};

string Peca::getNome(){
    return nome;
};

void Peca::setCor(char c){
    cor = c;
};

/* Retorna o valor do atributo 'cor' - Branco = 'B', Preto = 'P' */
char Peca::getCor(){
    return cor;
};

int Peca::getID(){
    return id;
}

ostream& operator<<(ostream& out, const Peca& peca){
    if(peca.emJogo == true){
           out << 1;
        }else out << 0;

    return out;
};

