#pragma once

//struct básico representando a peça, contendo tipo e cor da peça
typedef struct Piece{
    char tipo;
    char cor;
}Piece;

//Tabuleiro de xadrez, responsabilidades gráficas e construtivas
class Tabuleiro{
    public:
    //Inicia o Tabuleiro da maneira tradicional
    Tabuleiro();
    //Exibe o Tabuleiro no painel de comandos
    void Print();
    //Reseta o tabuleiro para o normal
    void Reset();
    //Forma do tabuleiro em si
    Piece pieces[8][8];
};