#include "../include/Ia.hpp"

IA::IA(std::string jogadorIA, std::string jogadorOponente)
    : jogadorIA(jogadorIA), jogadorOponente(jogadorOponente) {}

int IA::avaliarTabuleiro(Lig4& jogo) {
    // Avaliar o tabuleiro considerando o status do jogo
    if (jogo.get_status() == 'v') {
        // Se o jogo terminou com vitória, verificar quem venceu
        // Aqui, assumimos que a IA é "X" e o oponente é "O"
        if (jogo.getvalor_matriz(0, 0) == jogadorIA) {
            return 1000;
        } else {
            return -1000;
        }
    }
    // Caso o jogo esteja em andamento ou empatado
    return 0;
}

int IA::minimax(Lig4& jogo, int profundidade, bool isMaximizingPlayer) {
    int score = avaliarTabuleiro(jogo);

    if (score == 1000 || score == -1000 || jogo.get_status() == 'e')
        return score;

    if (isMaximizingPlayer) {
        int melhorValor = -10000;

        for (int i = 0; i < jogo.get_colunas(); i++) {
            if (jogo.getvalor_matriz(0, i) == " ") {
                jogo.jogar(i, jogadorIA);
                jogo.verificar_vencedor();
                melhorValor = std::max(melhorValor, minimax(jogo, profundidade + 1, false));
                jogo.removerjogada(i);  // Reverte a jogada
            }
        }
        return melhorValor;
    } else {
        int melhorValor = 10000;

        for (int i = 0; i < jogo.get_colunas(); i++) {
            if (jogo.getvalor_matriz(0, i) == " ") {
                jogo.jogar(i, jogadorOponente);
                jogo.verificar_vencedor();
                melhorValor = std::min(melhorValor, minimax(jogo, profundidade + 1, true));
                jogo.removerjogada(i);  // Reverte a jogada
            }
        }
        return melhorValor;
    }
}

int IA::encontrarMelhorJogada(const Lig4& jogo) {
    for (int coluna = 0; coluna < jogo.get_colunas(); ++coluna) {
        if (jogo.getvalor_matriz(0, coluna) == " ") {
            return coluna;
        }
    }
    return -1; // Retorna -1 se nenhuma jogada válida for encontrada
}