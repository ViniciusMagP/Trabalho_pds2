#include "login.hpp"

void Login::tela_inicial(){
    // system("CLS");
    std::cout << "Bem vindo!" << std::endl << "1 - Logar" << std::endl;
    std::cout << "2 - Registrar novo usuario" << std::endl << "3 - Terminar o programa" << std::endl;;
    int x;
    std::cin >> x;
    // system("CLS");

    switch (x)
    {
    case 1:
        login_user();
        break;

    case 2:
        register_user();
        break;

    case 3:
        system("CLS");
        exit(0);
    
    default:
        break;
    }
}

void Login::show_menu(){
    // system("CLS");
    std::cout << "Usuario logado" << std::endl << std::endl << "1 - Jogar" << std::endl; 
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
void Login::register_user(){
    //std::string qualquer_coisa;
    //std::string nome;
    //std::string senha;
    std::cout<<"Digite um usuario"<<std::endl;
    std::cin >> nome;
    // std::fstream file;
    arq.open(nome, std::ios::in);
    if(arq){

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
        arq.open(nome + ".txt", std::ios::out);
        arq << nome << std::endl;
        arq << senha << std::endl;
        system("CLS");
        std::cout<<"Usuario registrado com sucesso"<<std::endl<<std::endl;
        //std::cout<<"Digite qualquer coisa e pressione ENTER para retornar a tela inicial"<<std::endl;
        // std::cin>>qualquer_coisa;
        tela_inicial();

        arq.close();
    }
}


void Login::login_user(){
    // system("CLS");
    // std::string qualquer_coisa;
    std::string nome_aux;
    std::string senha_aux;
    std::cout<<"Digite seu usuario"<<std::endl;
    std::cin>> nome;
    std::fstream file;
    file.open(nome + ".txt", std::ios::in);
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
