// Inclua os cabeçalhos necessários do Doctest
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"

// Inclua seus cabeçalhos
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <cstdlib>
#include "login.hpp"
#include "Game.hpp"
#include "Tabuleiro.hpp"

TEST_CASE("Testando a função Peao") {
    Game game;

    CHECK(game.PeaoB(2, 2, 3, 2 ) == true); // Movimento válido
    CHECK(game.PeaoB(1, 2, 3, 3) == false); // Movimento inválido
    CHECK(game.PeaoB(2, 2, 4, 2) == false); // Movimento inválido
}

TEST_CASE("Testando a função Torre") {
    Game game;
    CHECK(game.Torre(1, 1, 1, 3) == false); // Movimento inválido
    CHECK(game.Torre(1, 2, 1, 3) == true);  //Movimento válido
}

TEST_CASE("Testando a função Cavalo") {
    Game game;

    CHECK(game.Cavalo(0, 0, 2, 1) == true);  // Movimento válido
    CHECK(game.Cavalo(0, 0, 3, 3) == false); // Movimento inválido
}

TEST_CASE("Testando a função Bispo") {
    Game game;

    CHECK(game.Bispo(3, 1, 4, 2) == true);  // Movimento válido
    CHECK(game.Bispo(1, 1, 2, 3) == false); // Movimento inválido
}

TEST_CASE("Testando a função Rainha") {
    Game game;

    CHECK(game.Queen(5, 1, 6, 2) == true);   // Movimento válido
    CHECK(game.Queen(1, 2, 1, 3) == true);   // Movimento inválido
    CHECK(game.Queen(1, 1, 2, 7) == false);  // Movimento válido
    CHECK(game.Queen(1, 1, 2, 3) == false);  // Movimento válido
}

TEST_CASE("Testando a função Rei") {
    Game game;

    CHECK(game.King(4, 1, 4, 2) == true);  // Movimento válido
    CHECK(game.King(4, 1, 5, 2) == true);  // Movimento inválido
}

