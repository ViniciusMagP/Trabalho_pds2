#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>


class Login{

    protected:

    std::string nome;
    std::string senha;
    std::fstream arq;

    public:

    //mostra a tela inicial
    void tela_inicial();

    //mostra o menu
    void show_menu();

    //registra um usuario no sistema
        void register_user();

    //loga um usuario no sistema
        void login_user();

    //pega o nome do usuario

    std::string getNome() {return nome;};


};