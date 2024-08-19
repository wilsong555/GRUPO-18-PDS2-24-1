#include "doctest.h"
#include "../include/Lig4.hpp"

TEST_CASE("Teste inicial de jogar") {
    Lig4 jogo(6, 7);
    
    SUBCASE("Jogada válida em uma coluna vazia") {
        CHECK(jogo.jogar(0, "X") == true);
        CHECK(jogo.getvalor_matriz(5, 0) == "X");
    }

    SUBCASE("Jogada em coluna cheia") {
        for (int i = 0; i < 6; ++i) {
            jogo.jogar(0, "X");
        }
        CHECK(jogo.jogar(0, "Y") == false);  // A coluna está cheia, deve retornar false
    }
}

TEST_CASE("Teste de verificação de empate") {
    Lig4 jogo(6, 7);

    // Preencher o tabuleiro sem formar uma sequência de 4
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            jogo.jogar(j, (i + j) % 2 == 0 ? "X" : "Y");
        }
    }

    CHECK(jogo.empate() == true);
}

TEST_CASE("Teste de verificar vencedor") {
    Lig4 jogo(6, 7);

    SUBCASE("Vencedor horizontal") {
        for (int i = 0; i < 4; ++i) {
            jogo.jogar(i, "X");
        }
        jogo.verificar_vencedor();
        CHECK(jogo.get_status() == 'v');
    }

    SUBCASE("Vencedor vertical") {
        for (int i = 0; i < 4; ++i) {
            jogo.jogar(0, "X");
        }
        jogo.verificar_vencedor();
        CHECK(jogo.get_status() == 'v');
    }

    SUBCASE("Vencedor diagonal crescente") {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < i; ++j) {
                jogo.jogar(i, "Y");
            }
            jogo.jogar(i, "X");
        }
        jogo.verificar_vencedor();
        CHECK(jogo.get_status() == 'v');
    }

    SUBCASE("Vencedor diagonal decrescente") {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < i; ++j) {
                jogo.jogar(3 - i, "Y");
            }
            jogo.jogar(3 - i, "X");
        }
        jogo.verificar_vencedor();
        CHECK(jogo.get_status() == 'v');
    }
}

TEST_CASE("Teste de remover jogada") {
    Lig4 jogo(6, 7);

    jogo.jogar(0, "X");
    jogo.removerjogada(0);

    CHECK(jogo.getvalor_matriz(5, 0) == " ");
}
