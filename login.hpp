#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

//class que representa as informações pessoais de login do usuário
class Login {
protected:
    std::string nomeL;
    std::string senha;
    std::fstream arq;

public:
    ///@return exibe a primeira tela do jogo
    void tela_inicial();

    ///@return exibe o menu principal do jogo
    void show_menu();

    ///@brief registra um usuario no sistema
    void register_user();

    ///@brief faz o login de um usuario no sistema
    void login_user();

    ///@return exibe o nome do usuario
    ///@param verifica se o usuario existe
    std::string getNome() { return nomeL; };
};

#endif // LOGIN_HPP
