#include <iostream>
#include "Tabuleiro.hpp"
#include "Game.hpp"


//Inicializa o Tabuleiro padrão
Tabuleiro::Tabuleiro(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            pieces[i][j].tipo = '-';
        }
    }
    for(int i = 0; i < 8; i++){
        pieces[1][i].tipo = 'p';
        pieces[6][i].tipo = 'P';
    }
    pieces[7][0].tipo = 'T';
    pieces[7][7].tipo = 'T';
    pieces[0][0].tipo = 't';
    pieces[0][7].tipo = 't';
    pieces[7][1].tipo = 'C';
    pieces[7][6].tipo = 'C';
    pieces[0][1].tipo = 'c';
    pieces[0][6].tipo = 'c';
    pieces[7][2].tipo = 'B';
    pieces[7][5].tipo = 'B';
    pieces[0][2].tipo = 'b';
    pieces[0][5].tipo = 'b';
    pieces[7][3].tipo = 'Q';
    pieces[7][4].tipo = 'K';
    pieces[0][3].tipo = 'k';
    pieces[0][4].tipo = 'q';

    for(int i = 0; i < 8; i++){
        pieces[0][i].cor = 'B';
        pieces[1][i].cor = 'B';
        pieces[6][i].cor = 'P';
        pieces[7][i].cor = 'P';
    }
}

//Simula um tabuleiro de xadrez na interface de comandos
void Tabuleiro::Print(){
    std::cout << "--------------------------------------" << std::endl;
    std::cout << " | A | B | C | D | E | F | G | H | x/y" << std::endl;
    for(int i = 0; i < 8; i++){
        std::cout << "--------------------------------------" << std::endl;
        for(int j = 0; j < 8; j++){
            std::cout << " | " << pieces[i][j].tipo;
        }
        std::cout << " | " << i + 1 << " | " <<  std::endl;
    }
    std::cout << "--------------------------------------" << std::endl;
}

//Reseta o tabuleiro para o normal, para que a pessoa possa navegar entre as jogadas com a função LoadGame() escolhendo a jogada
void Tabuleiro::Reset(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            pieces[i][j].tipo = '-';
        }
    }
    for(int i = 0; i < 8; i++){
        pieces[1][i].tipo = 'p';
        pieces[6][i].tipo = 'P';
    }
    pieces[7][0].tipo = 'T';
    pieces[7][7].tipo = 'T';
    pieces[0][0].tipo = 't';
    pieces[0][7].tipo = 't';
    pieces[7][1].tipo = 'C';
    pieces[7][6].tipo = 'C';
    pieces[0][1].tipo = 'c';
    pieces[0][6].tipo = 'c';
    pieces[7][2].tipo = 'B';
    pieces[7][5].tipo = 'B';
    pieces[0][2].tipo = 'b';
    pieces[0][5].tipo = 'b';
    pieces[7][3].tipo = 'Q';
    pieces[7][4].tipo = 'K';
    pieces[0][3].tipo = 'k';
    pieces[0][4].tipo = 'q';

    for(int i = 0; i < 8; i++){
        pieces[0][i].cor = 'B';
        pieces[1][i].cor = 'B';
        pieces[6][i].cor = 'P';
        pieces[7][i].cor = 'P';
    }
}
