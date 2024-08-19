#include "doctest.h"
#include "../include/Reversi.hpp"

TEST_CASE("Testando Tabuleiro::movimentoValido") {
    Tabuleiro tabuleiro;

    CHECK(tabuleiro.movimentoValido(2, 3, Peca::Preto) == true); // Movimento válido
    CHECK(tabuleiro.movimentoValido(3, 3, Peca::Preto) == false); // Posição já ocupada
    CHECK(tabuleiro.movimentoValido(0, 0, Peca::Preto) == false); // Movimento inválido
}

TEST_CASE("Testando Tabuleiro::aplicarMovimento") {
    Tabuleiro tabuleiro;
    
    tabuleiro.aplicarMovimento(2, 3, Peca::Preto);
    CHECK(tabuleiro(2, 3) == Peca::Preto); // Verifica se a peça foi colocada corretamente
    CHECK(tabuleiro(3, 3) == Peca::Preto); // Verifica se a peça adversária foi virada
}

TEST_CASE("Testando Tabuleiro::temMovimentoValido") {
    Tabuleiro tabuleiro;

    CHECK(tabuleiro.temMovimentoValido(Peca::Preto) == true);
    CHECK(tabuleiro.temMovimentoValido(Peca::Branco) == true);
}

TEST_CASE("Testando Tabuleiro::contarPecas") {
    Tabuleiro tabuleiro;

    std::pair<int, int> contagem = tabuleiro.contarPecas();
    CHECK(contagem.first == 2); // Contagem inicial de peças pretas
    CHECK(contagem.second == 2); // Contagem inicial de peças brancas
}

TEST_CASE("Testando Tabuleiro::verificar_vencedor") {
    Tabuleiro tabuleiro;

    // Simulando um cenário de vitória
    tabuleiro.aplicarMovimento(2, 3, Peca::Preto);
    tabuleiro.aplicarMovimento(2, 4, Peca::Preto);
    tabuleiro.aplicarMovimento(2, 5, Peca::Preto);
    tabuleiro.aplicarMovimento(2, 6, Peca::Preto);

    // Contagem final
    tabuleiro.verificar_vencedor(); // Deveria indicar que o jogador preto venceu
}
