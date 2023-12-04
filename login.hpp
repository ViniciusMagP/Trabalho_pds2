#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

class Login {
protected:
    std::string nomeL;
    std::string senha;
    std::fstream arq;

public:
    // Mostra a tela inicial
    void tela_inicial();

    // Mostra o menu
    void show_menu();

    // Registra um usuário no sistema
    void register_user();

    // Loga um usuário no sistema
    void login_user();

    // Pega o nome do usuário
    std::string getNome() { return nomeL; };
};

#endif // LOGIN_HPP
