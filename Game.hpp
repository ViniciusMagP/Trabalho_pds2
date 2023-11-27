#pragma once
#include "Tabuleiro.hpp"
#include <iostream>
#include <vector>

//struct representando uma jogada com ponto de partida (x,y) e ponto final (xp,yp)
typedef struct Hist{
    int x;
    int y;
    int xp;
    int yp;
}Hist;

class Game{
    public:
//Relacionados a quantidade de turnos:
    void IncreaseTurn();
    unsigned GetTurn();
    std::string WhoTurn();
//Relacionados ao histórico de partida:
    void SavePlay(int x, int y, int xp, int yp);
    void LoadGame();
//Administração/execução do jogo
    void GameStart();
//Movimentos pre definidos das peças
    bool Cavalo(int x, int y, int xp, int yp);
    bool Torre(int x, int y, int xp, int yp);
    bool PeaoP(int x, int y, int xp, int yp);
    bool PeaoB(int x, int y, int xp, int yp);
    bool King(int x, int y, int xp, int yp);
    bool Bispo(int x, int y, int xp, int yp);
    bool Queen(int x, int y, int xp, int yp);
//Checagem e execução utilizando as funcoes anteriores
    bool IsValid(int x, int y, int xp, int yp);
    void Move(int x, int y, int xp, int yp);

    private:
//Vetor contendo cada jogada
    std::vector<Hist> History;
//Tabuleiro atribuído ao jogo
    Tabuleiro Tab;
//Quantidade de turnos
    unsigned turn = 0;
//indicador se o jogo ainda está rodando
    bool game = 1;
};