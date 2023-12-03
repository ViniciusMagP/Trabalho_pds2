#include "login.hpp"

void Login::tela_inicial() {
    // clear_screen();
    std::cout << "Bem vindo!" << std::endl << "1 - Logar" << std::endl;
    std::cout << "2 - Registrar novo usuário" << std::endl << "3 - Terminar o programa" << std::endl;
    int x;
    std::cin >> x;
    // clear_screen();

    switch (x) {
    case 1:
        login_user();
        break;

    case 2:
        register_user();
        break;

    case 3:
        // clear_screen();
        exit(0);

    default:
        break;
    }
}

void Login::show_menu() {
    // clear_screen();
    std::cout << "Usuário logado" << std::endl << std::endl << "1 - Jogar" << std::endl;
    std::cout << "2 - Mudar usuário" << std::endl << "3 - Terminar programa" << std::endl;
    int x;
    std::cin >> x;
    switch (x) {
    case 2:
        tela_inicial();
        break;
    case 3:
        // clear_screen();
        exit(0);
        break;

    default:
        break;
    }
}

void Login::register_user() {
    std::cout << "Digite um usuário" << std::endl;
    std::cin >> nome;
    arq.open(nome + ".txt", std::ios::in);
    if (arq) {
        // clear_screen();
        std::cout << "O usuário já existe" << std::endl << std::endl;
        tela_inicial();
    } else {
        std::cout << "Digite uma senha" << std::endl;
        std::cin >> senha;
        arq.open(nome + ".txt", std::ios::out);
        arq << nome << std::endl;
        arq << senha << std::endl;
        // clear_screen();
        std::cout << "Usuário registrado com sucesso" << std::endl << std::endl;
        tela_inicial();
        arq.close();
    }
}

void Login::login_user() {
    std::string nome_aux;
    std::string senha_aux;
    std::cout << "Digite seu usuário" << std::endl;
    std::cin >> nome;
    std::fstream file;
    file.open(nome + ".txt", std::ios::in);
    if (file) {
        getline(file, nome_aux);
        getline(file, senha_aux);
        std::cout << "Bem-vindo " << nome << std::endl << std::endl << "Digite sua senha por favor:" << std::endl;
        std::cin >> senha;

        if (senha == senha_aux) {
            // clear_screen();
            std::cout << "Usuário logado com sucesso" << std::endl << std::endl;
            // show_menu();
        } else {
            // clear_screen();
            std::cout << "Senha incorreta" << std::endl << std::endl;
            tela_inicial();
        }
    } else {
        // clear_screen();
        std::cout << "O usuário fornecido não existe" << std::endl << std::endl;
        tela_inicial();
    }
}