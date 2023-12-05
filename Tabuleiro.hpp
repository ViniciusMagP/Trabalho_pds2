#pragma once

//struct básico representando a peça, contendo tipo e cor da peça
typedef struct Piece{
    char tipo;
    char cor;
}Piece;

//Tabuleiro de xadrez, responsabilidades gráficas e construtivas
class Tabuleiro{
    public:
///@brief inicializa o tabuleiro
///@return tabuleiro pronto
    //Inicia o Tabuleiro da maneira tradicional
    Tabuleiro();
///@return exibe o tabuleiro na tela
    //Exibe o Tabuleiro no painel de comandos
    void Print();
///@brief reseta o tabuleiro
///@return tabuleiro resetado
    //Reseta o tabuleiro para o normal
    void Reset();
    //Forma do tabuleiro em si
    Piece pieces[8][8];
};
