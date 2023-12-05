#include "login.hpp"
#include "Game.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <cstdlib>  

void Login::tela_inicial() {
    #ifdef _WIN32
        std::system("cls"); 
    #else
        std::system("clear");
    #endif
    std::cout << "Bem vindo!" << std::endl << "1 - Logar" << std::endl;
    std::cout << "2 - Registrar novo usuário" << std::endl << "3 - Terminar o programa" << std::endl;
    int x;
    std::cin >> x;
    #ifdef _WIN32
        std::system("cls"); 
    #else
        std::system("clear");
    #endif

    switch (x) {
    case 1:
        login_user();
        break;

    case 2:
        register_user();
        break;

    case 3:
    #ifdef _WIN32
        std::system("cls"); 
    #else
        std::system("clear");
    #endif
        exit(0);

    default:
        break;
    }
}

Game Jogo;

void Login::show_menu() {
    #ifdef _WIN32
        std::system("cls"); 
    #else
        std::system("clear");
    #endif
    std::cout << "Usuário logado" << std::endl << std::endl << "1 - Jogar" << std::endl << "2 - Carregar Jogo" << std::endl;
    std::cout << "3 - Mudar usuário" << std::endl << "4 - Histórico" << std::endl << "5 - Terminar programa" << std::endl;
    int x;
    std::cin >> x;
    std::string JogoNome;
    switch (x) {
    case 1:
        #ifdef _WIN32
        std::system("cls"); 
    #else
        std::system("clear");
    #endif
        std::cout << "Escreve o nome da partida" << std::endl;
        std::cin >> JogoNome;
        Jogo.GameStart(JogoNome);
    case 2:
        #ifdef _WIN32
        std::system("cls"); 
    #else
        std::system("clear");
    #endif
        void LoadGame();
    case 4:
        tela_inicial();
        break;
    case 5:
        #ifdef _WIN32
        std::system("cls"); 
    #else
        std::system("clear");
    #endif
        exit(0);
        break;

    default:
        break;
    }
}

void Login::register_user() {
    std::cout << "Digite um usuário" << std::endl;
    std::cin >> nomeL;

    // Verifica se o diretório "user" existe e cria se não existir
    if (!std::filesystem::exists("user")) {
        std::filesystem::create_directory("user");
    }

    std::string userFilePath = "user/" + nomeL + ".txt";

    std::fstream arq(userFilePath, std::ios::in);

    if (arq) {
        #ifdef _WIN32
        std::system("cls"); 
    #else
        std::system("clear");
    #endif
        std::cout << "O usuário já existe" << std::endl << std::endl;
        tela_inicial();
    } else {
        std::cout << "Digite uma senha" << std::endl;
        std::cin >> senha;

        std::fstream arq(userFilePath, std::ios::out);
        arq << nomeL << std::endl;
        arq << senha << std::endl;

        arq.close();
        #ifdef _WIN32
        std::system("cls"); 
    #else
        std::system("clear");
    #endif
        std::cout << "Usuário registrado com sucesso" << std::endl << std::endl;
        tela_inicial();
    }
}

void Login::login_user() {
    std::string nome_aux;
    std::string senha_aux;

    std::cout << "Digite seu usuário" << std::endl;
    std::cin >> nomeL;

    // Verifica se o diretório "user" existe e cria se não existir
    if (!std::filesystem::exists("user")) {
        std::filesystem::create_directory("user");
    }

    std::string userFilePath = "user/" + nomeL + ".txt";

    std::fstream file;
    file.open(userFilePath, std::ios::in);

    if (file) {
        getline(file, nome_aux);
        getline(file, senha_aux);

        std::cout << "Bem-vindo " << nomeL << std::endl << std::endl << "Digite sua senha por favor:" << std::endl;
        std::cin >> senha;

        if (senha == senha_aux) {
            #ifdef _WIN32
        std::system("cls"); 
    #else
        std::system("clear");
    #endif
            std::cout << "Usuário logado com sucesso" << std::endl << std::endl;
            show_menu();
        } else {
            #ifdef _WIN32
        std::system("cls"); 
    #else
        std::system("clear");
    #endif
            std::cout << "Senha incorreta" << std::endl << std::endl;
            tela_inicial();
        }
    } else {
        #ifdef _WIN32
        std::system("cls"); 
    #else
        std::system("clear");
    #endif
        std::cout << "O usuário fornecido não existe" << std::endl << std::endl;
        tela_inicial();
    }

    file.close();
}