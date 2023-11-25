#include "login.hpp"
#include "user.hpp"

void Menu::register_user(){
    std::string qualquer_coisa;
    std::string nome;
    std::string senha;
    std::cout<<"Digite um usuário"<<std::endl;
    std::cin >> nome;
    std::fstream file;
    file.open(nome, std::ios::in);
    if(file){
        system("clear");
        std::cout<<"O usuário ja exite"<<std::endl<<std::endl;
        std::cout<<"Digite qualquer coisa e pressione ENTER para retornar a tela inicial"<<std::endl;
        std::cin>>qualquer_coisa;
        tela_inicial();
    } 
    else{
        system("clear");
        std::cout<<"Digite uma senha"<<std::endl;
        std::cin >> senha;
        file.open(nome, std::ios::out);
        file << nome << std::endl;
        file << senha << std::endl;
        system("clear");
        std::cout<<"Usuário registrado com sucesso"<<std::endl<<std::endl;
        std::cout<<"Digite qualquer coisa e pressione ENTER para retornar a tela inicial"<<std::endl;
        std::cin>>qualquer_coisa;
        tela_inicial();
    }
}


void Menu::login_user(){
    system("clear");
    std::string qualquer_coisa;
    std::string nome, nome_aux;
    std::string senha, senha_aux;
    std::cout<<"Digite seu usuário"<<std::endl;
    std::cin>> nome;
    std::fstream file;
    file.open(nome, std::ios::in);
    if(file){
        getline(file, nome_aux);
        getline(file, senha_aux);
        system("clear");
        std::cout<<"Bem vindo "<<nome<<std::endl<<std::endl<<"Digite sua senha por favor:"<<std::endl;
        std::cin >> senha;
        if(senha==senha_aux){
            system("clear");
            std::cout<<"Usuário logado com sucesso"<<std::endl<<std::endl;
            std::cout<<"Digite qualquer coisa e pressione ENTER para ir a tela principal"<<std::endl;
            std::cin>>qualquer_coisa;
            show_menu();
        }
        system("clear");
        std::cout<<"Senha incorreta"<<std::endl<<std::endl;
        std::cout<<"Digite qualquer coisa e pressione ENTER para retornar a tela inicial"<<std::endl;
        std::cin>>qualquer_coisa;
        tela_inicial();
    }
    system("clear");
    std::cout<<"O usuário fornecido não existe"<<std::endl<<std::endl;
    std::cout<<"Digite qualquer coisa e pressione ENTER para retornar a tela inicial"<<std::endl;
    std::cin>>qualquer_coisa;
    tela_inicial();
} 

void Menu::tela_inicial(){
    system("clear");
    std::cout << "Bem vindo!" << std::endl << "1 - Logar" << std::endl;
    std::cout << "2 - Registrar novo usuario" << std::endl << "3 - Terminar o programa" << std::endl;;
    int x;
    std::cin >> x;
    system("clear");

    switch (x)
    {
    case 1:
        login_user();
        break;

    case 2:
        register_user();
        break;

    case 3:
        exit(0);
    
    default:
        break;
    }
}

void Menu::show_menu(){
    system("clear");
    std::cout << "Usuário logado" << std::endl << std::endl << "1 - Jogar" << std::endl; 
    std::cout << "2 - Mudar usuario" << std::endl << "3 - Terminar programa" << std::endl;
    int x;
    std::cin >> x;
    switch (x)
    {
    case 2:
        tela_inicial();
    case 3:
        exit(0);
        break;
    
    default:
        break;
    }
}