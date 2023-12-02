#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <cstdlib>
#include "login.hpp"
#include "Game.hpp"

int main(){

    Login login;
    login.tela_inicial();
    Game a;
    a.GameStart(login.getNome());
}