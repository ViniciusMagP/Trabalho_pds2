#include "user.hpp"
#include "login.hpp"
#include <fstream>
#include <iostream>

void User::register_user(){
    //std::string qualquer_coisa;
    //std::string nome;
    //std::string senha;
    std::cout<<"Digite um usuario"<<std::endl;
    std::cin >> nome;
    std::fstream file;
    file.open(nome, std::ios::in);
    if(file){

        system("CLS");
        std::cout<<"O usuario ja exite"<<std::endl<<std::endl;
        // std::cout<<"Digite qualquer coisa e pressione ENTER para retornar a tela inicial"<<std::endl;
        // std::cin>>qualquer_coisa;
        tela_inicial();

    } 
    else{
        // system("CLS");
        std::cout<<"Digite uma senha"<<std::endl;
        std::cin >> senha;
        file.open(nome, std::ios::out);
        file << nome << std::endl;
        file << senha << std::endl;
        system("CLS");
        std::cout<<"Usuario registrado com sucesso"<<std::endl<<std::endl;
        //std::cout<<"Digite qualquer coisa e pressione ENTER para retornar a tela inicial"<<std::endl;
        // std::cin>>qualquer_coisa;
        tela_inicial();
    }
}


void User::login_user(){
    // system("CLS");
    // std::string qualquer_coisa;
    std::string nome_aux;
    std::string senha_aux;
    std::cout<<"Digite seu usuario"<<std::endl;
    std::cin>> nome;
    std::fstream file;
    file.open(nome, std::ios::in);
    if(file){

        getline(file, nome_aux);
        getline(file, senha_aux);
        // system("CLS");
        std::cout<<"Bem vindo "<<nome<<std::endl<<std::endl<<"Digite sua senha por favor:"<<std::endl;
        std::cin >> senha;

        if(senha==senha_aux){

            system("CLS");
            std::cout<<"Usuario logado com sucesso"<<std::endl<<std::endl;
            // std::cout<<"Digite qualquer coisa e pressione ENTER para ir a tela principal"<<std::endl;
            // std::cin>>qualquer_coisa;
            // show_menu();
            //break;

        }else{

        system("CLS");
        std::cout<<"Senha incorreta"<<std::endl<<std::endl;
        // std::cout<<"Digite qualquer coisa e pressione ENTER para retornar a tela inicial"<<std::endl;
        // std::cin>>qualquer_coisa;
        tela_inicial();

        }
    }else{

    system("CLS");
    std::cout<<"O usuario fornecido nao existe"<<std::endl<<std::endl;
    // std::cout<<"Digite qualquer coisa e pressione ENTER para retornar a tela inicial"<<std::endl;
    // std::cin>>qualquer_coisa;
    tela_inicial();

    }
} 
