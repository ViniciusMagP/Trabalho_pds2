#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

class Menu{
public:
//registra um usuario no sistema
void register_user();

//loga um usuario no sistema
void login_user();

//mostra a tela inicial
void tela_inicial();

//mostra o menu
void show_menu();

};