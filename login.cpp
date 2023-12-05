#include "login.hpp"
#include "Game.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>

void Login::tela_inicial() {
    system("cls");
    std::cout << "Bem vindo!" << std::endl << "1 - Logar" << std::endl;
    std::cout << "2 - Registrar novo usuario" << std::endl << "3 - Terminar o programa" << std::endl;
    char x;
    std::cin >> x;
    system("cls");

    switch (x) {
    case '1':
        login_user();
        break;

    case '2':
        register_user();
        break;

    case '3':
        system("cls");
        exit(0);

    default:
        tela_inicial();
        break;
    }
}

Game Jogo;

void Login::show_menu() {
    system("cls");
    std::cout << "Usuario logado" << std::endl << std::endl << "1 - Jogar" << std::endl << "2 - Carregar Jogo" << std::endl;
    std::cout << "3 - Mudar usuario" << std::endl << "4 - Terminar programa" << std::endl;
    char x;
    std::cin >> x;
    std::string JogoNome;
    std::string auxnome;
    switch (x) {
    case '1':
        system("cls");
        std::cout << "Escreva o nome da partida" << std::endl;
        std::cin >> JogoNome;
        Jogo.GameStart(JogoNome, getNome());
        show_menu();
        break;
    case '2':
        system("cls");
        std::cout << "Escreva o nome da partida" << std::endl;
        std::cin >> JogoNome;
        auxnome = "user/" + getNome() + "/" + JogoNome + ".txt";
        if(Jogo.exist(auxnome)){
            Jogo.LoadGame(auxnome);
            Jogo.GameStart(JogoNome, getNome());
        }
        show_menu();
        break;
    case '3':
        tela_inicial();
        break;
    case '4':
        system("cls");
        exit(0);
        break;

    default:
        show_menu();
        break;
    }
}

void Login::register_user() {
    std::cout << "Digite um usuario" << std::endl;
    std::cin >> nomeL;

    // Verifica se o diretório "user" existe e cria se não existir
    if (!std::filesystem::exists("user")) {
        std::filesystem::create_directory("user");
    }

    std::string userFilePath = "user/" + nomeL + ".txt";

    std::fstream arq(userFilePath, std::ios::in);

    if (arq) {
        system("cls");
        std::cout << "O usuario ja existe" << std::endl << std::endl;
        tela_inicial();
    } else {
        std::cout << "Digite uma senha" << std::endl;
        std::cin >> senha;

        std::fstream arq(userFilePath, std::ios::out);
        arq << nomeL << std::endl;
        arq << senha << std::endl;

        arq.close();
        system("cls");
        std::cout << "Usuario registrado com sucesso" << std::endl << std::endl;
        tela_inicial();
    }
}

void Login::login_user() {
    std::string nome_aux;
    std::string senha_aux;

    std::cout << "Digite seu usuario" << std::endl;
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
            system("cls");
            std::cout << "Usuario logado com sucesso" << std::endl << std::endl;
            show_menu();
        } else {
            system("cls");
            std::cout << "Senha incorreta" << std::endl << std::endl;
            tela_inicial();
        }
    } else {
        system("cls");
        std::cout << "O usuario fornecido nao existe" << std::endl << std::endl;
        tela_inicial();
    }

    file.close();
}
