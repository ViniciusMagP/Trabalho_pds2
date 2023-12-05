#include "Game.hpp"
#include "Tabuleiro.hpp"
#include "Login.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <filesystem>

//ambas as próximas funções servem apenas para controle de dados e estatísticas
void Game::IncreaseTurn(){
    turn++;
}
unsigned Game::GetTurn(){
    return 1 + (turn/2);
}

std::string Game::WhoTurn(){
    if(turn %2 == 0){
        return "brancas";
    }
    if(turn %2 != 0){
        return "pretas";
    }
    return "[erro]";
}

//Ao errar, caso o jogador não tenha percebido/não saiba o que fez de errado
//As funções especificam o erro em forma de dica
bool Game::PeaoB(int x, int y, int xp, int yp){
    bool frente = 0;
    if(turn == 1) {
        if(xp == x + 2){
            frente = 1;
        }
    }
    if(xp == x + 1){
        frente = 1;
    }
    bool cond1 = 0;
    if(y == yp && Tab.pieces[xp][yp].tipo == '-'){
        cond1 = 1;
    }
    bool cond2 = 0;
    if((yp == y + 1 || yp == y - 1) && Tab.pieces[xp][yp].tipo != '-'){
        cond2 = 1;
    }
    if(frente && (cond1 || cond2)){
        return 1;
    }
    std::cout << "Movimento invalido" << std::endl;
    std::cout << "[DICA] O peao se move 1 casa pra frente e captura nas diagonais frontais." << std::endl;
    return 0;
}
bool Game::PeaoP(int x, int y, int xp, int yp){
    bool frente = 0;
    if(turn == 1) {
        if(xp == x - 2){
            frente = 1;
        }
    }
    if(xp == x - 1){
        frente = 1;
    }
    bool cond1 = 0;
    if(y == yp && Tab.pieces[xp][yp].tipo == '-'){
        cond1 = 1;
    }
    bool cond2 = 0;
    if((yp == y + 1 || yp == y - 1) && Tab.pieces[xp][yp].tipo != '-'){
        cond2 = 1;
    }
    if(frente && (cond1 || cond2)){
        return 1;
    }
    std::cout << "Movimento invalido" << std::endl;
    std::cout << "[DICA] O peao se move 1 casa pra frente e captura nas diagonais frontais." << std::endl;
    return 0;
}

bool Game::Torre(int x, int y, int xp, int yp){
    bool cond1 = 0;
    if(x != xp && yp == y){
        cond1 = 1;
    }
    bool cond2 = 0;
    if(x == xp && y != yp){
        cond2 = 1;
    }
    if(!(cond1 || cond2)){
        std::cout << "Movimento invalido" << std::endl;
        std::cout << "[DICA] A torre se move apenas nas laterais." << std::endl;
        return 0;
    }
    if(cond1 && x > xp){
        for(int i = 1; i < x - xp; i++){
            if(Tab.pieces[xp - i][y].tipo != '-'){
                std::cout << "Movimento invalido" << std::endl;
                std::cout << "[DICA] A torre nao eh capaz de pular pecas." << std::endl;
                return 0;
            }
        }
    }
    if(cond1 && xp > x){
        for(int i = 1; i < xp - x; i++){
            if(Tab.pieces[x - i][y].tipo != '-'){
                std::cout << "Movimento invalido" << std::endl;
                std::cout << "[DICA] A torre nao eh capaz de pular pecas." << std::endl;
                return 0;
            }
        }
    }
    if(cond2 && yp > y){
        for(int i = 1; i < yp - y; i++){
            if(Tab.pieces[x][y - i].tipo != '-'){
                std::cout << "Movimento invalido" << std::endl;
                std::cout << "[DICA] A torre nao eh capaz de pular pecas." << std::endl;
                return 0;
            }
        }
    }
    if(cond2 && y > yp){
        for(int i = 1; i < y - yp; i++){
            if(Tab.pieces[x][yp - i].tipo != '-'){
                std::cout << "Movimento invalido" << std::endl;
                std::cout << "[DICA] A torre nao eh capaz de pular pecas." << std::endl;
                return 0;
            }
        }
    }
    return 1;
}

bool Game::Cavalo(int x, int y, int xp, int yp){
    if((xp == x + 1 && yp == y + 2) || (xp == x - 1 && yp == y + 2)){
        return 1;
    }
    if((xp == x + 1 && yp == y - 2) || (xp == x - 1 && yp == y - 2)){
        return 1;
    }
    if((xp == x + 2 && yp == y + 1) ||(xp == x - 2 && yp == y + 1)){
        return 1;
    }
    if((xp == x + 2 && yp == y - 1) || (xp == x - 2 && yp == y - 1)){
        return 1;
    }
    std::cout << "Movimento invalido" << std::endl;
    std::cout << "[DICA] O cavalo se move apenas em L." << std::endl; 
    return 0;
}

bool Game::Bispo(int x, int y, int xp, int yp){
    int difx = xp - x;
    int dify = yp - y;
    if(difx != dify && difx != -1*dify){
        std::cout << "Movimento invalido" << std::endl;
        std::cout << "[DICA] O bispo apenas se move nas diagonais." << std::endl;
        return 0;
    }
    //diagonal inferior esquerda
    if(difx > 0 && dify > 0){
        for(int i = 1; i < xp - x; i++){
            if(Tab.pieces[xp - i][yp - i].tipo != '-'){
                std::cout << "Movimento invalido" << std::endl;
                std::cout << "[DICA] O bispo nao eh capaz de pular pecas." << std::endl; 
                return 0;
            }
        }
        return 1;
    }
    if(difx > 0 && dify < 0){
        for(int i = 1; i < xp - x; i++){
            if(Tab.pieces[xp - i][y - i].tipo != '-'){
                std::cout << "Movimento invalido" << std::endl;
                std::cout << "[DICA] O bispo nao eh capaz de pular pecas." << std::endl; 
                return 0;
            }
        }
        return 1;
    }
    if(difx < 0 && dify > 0){
        for(int i = 1; i < x - xp; i++){
            if(Tab.pieces[x - i][yp - i].tipo != '-'){
                std::cout << "Movimento invalido" << std::endl;
                std::cout << "[DICA] O bispo nao eh capaz de pular pecas." << std::endl;
                return 0; 
            }
        }
        return 1;
    }
    if(difx < 0 && dify < 0){
        for(int i = 1; i < x - xp; i++){
            if(Tab.pieces[x - i][y - i].tipo != '-'){
                std::cout << "Movimento invalido" << std::endl;
                std::cout << "[DICA] O bispo nao eh capaz de pular pecas." << std::endl;
                return 0; 
            }
        }
        return 1;
    }
    std::cout << "nem sei oq aconteceu";
    return 0;
}

bool Game::King(int x, int y, int xp, int yp){
    bool cond1 = 0;
    if(xp == x + 1 || xp == x - 1 || xp == x){
        cond1 = 1;
    }
    bool cond2 = 0;
    if(yp == y + 1 || yp == y - 1 || yp == y){
        cond2 = 1;
    }
    if(cond1 && cond2){
        return 1;
    }
    std::cout << "Movimento invalido" << std::endl;
    std::cout << "[DICA] O rei se move apenas 1 casa em todas as direcoes." << std::endl;
    return 0;
}

bool Game::Queen(int x, int y, int xp, int yp){
    int difx = xp - x;
    int dify = yp - y;
    if(difx == dify || difx == -1*dify){
        if(difx > 0 && dify > 0){
            for(int i = 1; i < xp - x; i++){
                if(Tab.pieces[xp - i][yp - i].tipo != '-'){
                    std::cout << "Movimento invalido" << std::endl;
                    std::cout << "[DICA] A rainha nao eh capaz de pular pecas." << std::endl; 
                    return 0;
                }
            }
            return 1;
        }
        if(difx > 0 && dify < 0){
            for(int i = 1; i < xp - x; i++){
                if(Tab.pieces[xp - i][y - i].tipo != '-'){
                    std::cout << "Movimento invalido" << std::endl;
                    std::cout << "[DICA] A rainha nao eh capaz de pular pecas." << std::endl; 
                    return 0;
                }
            }
            return 1;
        }
        if(difx < 0 && dify > 0){
            for(int i = 1; i < x - xp; i++){
                if(Tab.pieces[x - i][yp - i].tipo != '-'){
                    std::cout << "Movimento invalido" << std::endl;
                    std::cout << "[DICA] A rainha nao eh capaz de pular pecas." << std::endl;
                    return 0; 
                }
            }
            return 1;
        }
        if(difx < 0 && dify < 0){
            for(int i = 1; i < x - xp; i++){
                if(Tab.pieces[x - i][y - i].tipo != '-'){
                    std::cout << "Movimento invalido" << std::endl;
                    std::cout << "[DICA] A rainha nao eh capaz de pular pecas." << std::endl;
                    return 0; 
                }   
            }
            return 1;
        }
    }
    if((x != xp && yp == y) || (x == xp && y != yp)){
        if((x != xp && yp == y) && x > xp){
            for(int i = 1; i < x - xp; i++){
                if(Tab.pieces[xp - i][y].tipo != '-'){
                    std::cout << "Movimento invalido" << std::endl;
                    std::cout << "[DICA] A rainha nao eh capaz de pular pecas." << std::endl;
                    return 0;
                }
            }
            return 1;
        }
        if((x != xp && yp == y) && xp > x){
            for(int i = 1; i < xp - x; i++){
                if(Tab.pieces[x - i][y].tipo != '-'){
                    std::cout << "Movimento invalido" << std::endl;
                    std::cout << "[DICA] A rainha nao eh capaz de pular pecas." << std::endl;
                    return 0;
                }
            }
            return 1;
        }
        if((x == xp && y != yp) && yp > y){
            for(int i = 1; i < yp - y; i++){
                if(Tab.pieces[x][y - i].tipo != '-'){
                    std::cout << "Movimento invalido" << std::endl;
                    std::cout << "[DICA] A rainha nao eh capaz de pular pecas." << std::endl;
                    return 0;
                }
            }
            return 1;
        }
        if((x == xp && y != yp) && y > yp){
            for(int i = 1; i < y - yp; i++){
                if(Tab.pieces[x][yp - i].tipo != '-'){
                    std::cout << "Movimento invalido" << std::endl;
                    std::cout << "[DICA] A rainha nao eh capaz de pular pecas." << std::endl;
                    return 0;
                }
            }
            return 1;
        }
    }
    std::cout << "Movimento invalido" << std::endl;
    std::cout << "[DICA] A rainha se move nas laterais e diagonais livremente." << std::endl;
    return 0;
}

bool Game::IsValid(int x, int y, int xp, int yp){
    //regras globais para todas as peças do jogo
    if(Tab.pieces[x][y].tipo == '-'){
        std::cout << "Peca inexistente" << std::endl;
        return 0;
    }
    if(xp > 8 || yp > 8){
        std::cout << "Posicao alvo inexistente" << std::endl;
        return 0;
    }
    if(x == xp && y == yp){
        std::cout << "Movimento invalido" << std::endl;
        return 0;
    }
    if(Tab.pieces[x][y].cor == Tab.pieces[xp][yp].cor){
        std::cout << "Movimento invalido" << std::endl;
        std::cout << "[DICA] Tente nao atacar seus aliados" << std::endl;
        return 0;
    }
    //regras específicas de peças
    switch (Tab.pieces[x][y].tipo){
        case 'p':
            return PeaoB(x, y, xp, yp);
            break;
        case 'P':
            return PeaoP(x, y, xp, yp);
            break;
        case 'T':
            return Torre(x, y, xp, yp);
            break;
        case 't':
            return Torre(x, y, xp, yp);
            break;
        case 'C':
            return Cavalo(x, y, xp, yp);
            break;
        case 'c':
            return Cavalo(x, y, xp, yp);
            break;
        case 'K':
            return King(x, y, xp, yp);
            break;
        case 'k':
            return King(x, y, xp, yp);
            break;
        case 'B':
            return Bispo(x, y, xp, yp);
            break;
        case 'b':
            return Bispo(x, y, xp, yp);
            break;
        case 'Q':
            return Queen(x, y, xp, yp);
            break;
        case 'q':
            return Queen(x, y, xp, yp);
            break;
    }
    //caso passe desse ponto, significa que não se trata de uma peça implementada de xadrez e algo deu errado
    std::cout << "Peca desconhecida" << std::endl;
    return 0;
}

void Game::Move(int x, int y, int xp, int yp){
    //como já há uma função para validar movimentos, esta apenas executa a ação
    Tab.pieces[xp][yp].tipo = Tab.pieces[x][y].tipo;
    Tab.pieces[xp][yp].cor = Tab.pieces[x][y].cor;
    Tab.pieces[x][y].tipo = '-';
    Tab.pieces[x][y].cor = '-';
    //checando o Xeque-Mate
    bool checB = 0;
    bool checP = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(Tab.pieces[i][j].tipo == 'k'){
                checB = 1;    
            }
            if(Tab.pieces[i][j].tipo == 'K'){
                checP = 1;
            }
        }
    }
    //Anunciando a vitória caso haja xeque
    if(!checB){
        std::cout << "Pretos ganharam!" << std::endl;
        game = 0;
    }
    if(!checP){
        std::cout << "Brancos ganharam!" << std::endl;
        game = 0;
    }

}

bool Game::exist(std::string name){
    std::fstream filetest;
    filetest.open(name, std::ios::in);
    if(filetest){
        return 1;
    }
    return 0;
}

void Game::SavePlay(int x, int y, int xp, int yp, std::string nomea, std::string nomedouser) {
    // Armazena no vetor a jogada para que seja salva posteriormente
    Hist temp = {x, y, xp, yp};
    History.push_back(temp);

    std::string userFolderPath = "user/" + nomedouser;

    // Verifica se o diretório do usuário existe e cria se não existir
    if (!std::filesystem::exists(userFolderPath)) {
        std::filesystem::create_directory(userFolderPath);
    }

    std::string userFilePath = userFolderPath + "/" + nomea + ".txt";
    // Abre o arquivo do usuário e grava as ações do jogo
    std::fstream arquivo(userFilePath, std::ios::out | std::ios::app);

    arquivo << x << " " << y << " " << xp << " " << yp << std::endl;

    arquivo.close();
}

int getchar(char x){
    int get;
    char y = tolower(x);
    switch(y){
        case 'a':
        get = 0;
        break;
        case 'b':
        get = 1;
        break;
        case 'c':
        get = 2;
        break;
        case 'd':
        get = 3;
        break;
        case 'e':
        get = 4;
        break;
        case 'f':
        get = 5;
        break;
        case 'g':
        get = 6;
        break;
        case 'h':
        get = 7;
        break;
        case '1':
        get = 0;
        break;
        case '2':
        get = 1;
        break;
        case '3':
        get = 2;
        break;
        case '4':
        get = 3;
        break;
        case '5':
        get = 4;
        break;
        case '6':
        get = 5;
        break;
        case '7':
        get = 6;
        break;
        case '8':
        get = 7;
        break;
        default:
        get = 10;
        break;
    }
    return get;
}

void Game::GameStart(std::string nomea, std::string nomedouser){
    //esta função é responsável por executar o jogo, de maneira padrão
    char x, xp;
    char y, yp;
    turn = 0;
    std::cout << "Bem vindo ao jogo de xadrez" << std::endl
     << "Pecas brancas em minusculo e pretas em maiusculo" << std::endl
     << "Para parar o jogo, digite apenas S" << std::endl;
    Tab.Print();
    std::cout << "Turno " << GetTurn() << ", vez das "<< WhoTurn() << std::endl;
    std::cout << "Digite as coordenadas: ";
    while(game == 1){
        std::cin >> x;
        if(x == 'S' || x == 's'){
            game = 0;
            break;
        }
        std::cin >> y >> xp >> yp;
        system("CLS");
        //caso a jogada seja inválida, a função responsável avisará o motivo e nada ocorrerá no tabuleiro
        if(IsValid(getchar(y), getchar(x), getchar(yp), getchar(xp))){
            //caso seja válida, salva a jogada e executa
            SavePlay(getchar(y), getchar(x), getchar(yp), getchar(xp), nomea, nomedouser);
            Move(getchar(y), getchar(x), getchar(yp), getchar(xp));
            IncreaseTurn();
        }
        Tab.Print();
        if(game == 0){
            break;
        }
        std::cout << "Turno " << GetTurn() << ", vez das "<< WhoTurn() << std::endl;
        std::cout << "Digite as coordenadas: ";
    }
    std::cout << "O jogo terminou, pressione uma tecla para continuar: ";
    std::string a;
    game = 1;
    Tab.Reset();
    std::cin >> a;
}

void Game::LoadGame(std::string jogo){
    std::fstream f;
    f.open(jogo, std::ios::in);
    int x, y, xp, yp;
    Hist temp;
    while(f >> x >> y >> xp >> yp){
        Move(x, y, xp, yp);
        IncreaseTurn();
        temp.x = x;
        temp.y = y;
        temp.xp = xp;
        temp.yp = yp;
        History.push_back(temp);
    }
//esta função está relacionada com o banco de dados,
//onde é possível capturar as jogadas realizadas e continuar de onde tenha parado
//Nota que não é preciso validar jogadas, uma vez que apenas jogadas válidas são salvas
//Para continuar o progresso, basta usar a função antes de iniciar com GameStart()
}
