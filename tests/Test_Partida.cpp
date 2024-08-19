#include "doctest.h"
#include "../include/Partida.hpp"
#include "../include/Lig4.hpp"
#include "../include/Reversi.hpp"
#include "../include/IA.hpp"

TEST_CASE("Testando Partida::iniciar_jogo com Lig4 IA") {
    Partida partida('L', "Jogador1", "Jogador2", 'N');
    // Verifique se o jogo inicia corretamente, sem erros
    CHECK_NOTHROW(partida.iniciar_jogo());
}

TEST_CASE("Testando Partida::iniciar_jogo com Lig4 com IA") {
    Partida partida('L', "Jogador1", "Jogador2", 'S');
    // Verifique se o jogo com IA inicia corretamente
    CHECK_NOTHROW(partida.iniciar_jogo());
}

TEST_CASE("Testando Partida::iniciar_jogo com Reversi") {
    Partida partida('R', "Jogador1", "Jogador2", 'N');
    // Verifique se o jogo Reversi inicia corretamente
    CHECK_NOTHROW(partida.iniciar_jogo());
}

