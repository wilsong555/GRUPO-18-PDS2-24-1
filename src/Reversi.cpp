#include "../include/Reversi.hpp"
#include "../include/Jogo.hpp"
#include <iostream>

Reversi::Reversi() : grid(8, std::vector<Peca>(8, Peca::Vazia)) {
    // configuração inicial
    grid[3][3] = Peca::Branco;
    grid[3][4] = Peca::Preto;
    grid[4][3] = Peca::Preto;
    grid[4][4] = Peca::Branco;
}
Peca operator()(int linha, int coluna) const {
        return grid[linha][coluna];
}
void setPeca(int linha, int coluna, Peca peca) {
        grid[linha][coluna] = peca;
}

void Reversi::exibir() const {
    std::cout << "  1 2 3 4 5 6 7 8\n";
    for (int i = 0; i < 8; ++i) {
        std::cout << i + 1 << ' ';
        for (int j = 0; j < 8; ++j) {
            char display = '.';
            if (grid[i][j] == Peca::Preto) display = 'P';
            else if (grid[i][j] == Peca::Branco) display = 'B';
            std::cout << display << ' ';
        }
        std::cout << '\n';
    }
}

bool Reversi::movimentoValido(int linha, int coluna) const {
    if (grid[linha][coluna] != Peca::Vazia) return false;

    int direcoes[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    Peca adversario = (grid[linha][coluna] == Peca::Preto) ? Peca::Branco : Peca::Preto;

    for (auto& direcao : direcoes) {
        int dx = direcao[0], dy = direcao[1];
        int x = linha + dx, y = coluna + dy;
        bool encontrouAdversario = false;

        while (x >= 0 && x < 8 && y >= 0 && y < 8) {
            if (grid[x][y] == adversario) {
                encontrouAdversario = true;
            } else if (grid[x][y] == grid[linha][coluna]) {
                if (encontrouAdversario) {
                    return true;
                } else {
                    break;
                }
            } else {
                break;
            }

            x += dx;
            y += dy;
        }
    }

    return false;
}

void Reversi::aplicarMovimento(int linha, int coluna, Peca jogador) {
    grid[linha][coluna] = jogador;

    int direcoes[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    Peca adversario = (jogador == Peca::Preto) ? Peca::Branco : Peca::Preto;

    for (auto& direcao : direcoes) {
        int dx = direcao[0], dy = direcao[1];
        int x = linha + dx, y = coluna + dy;
        bool encontrouAdversario = false;
        std::vector<std::pair<int, int>> pecasParaVirar;

        while (x >= 0 && x < 8 && y >= 0 && y < 8) {
            if (grid[x][y] == adversario) {
                encontrouAdversario = true;
                pecasParaVirar.push_back({x, y});
            } else if (grid[x][y] == jogador) {
                if (encontrouAdversario) {
                    for (auto& p : pecasParaVirar) {
                        grid[p.first][p.second] = jogador;
                    }
                }
                break;
            } else {
                break;
            }

            x += dx;
            y += dy;
        }
    }
}

bool Reversi::verificarVitoria(Peca jogador) const {
    return false; // Stub implementation for Reversi victory check
}

void Reversi::lerJogada(int& linha, int& coluna) const {
    std::cout << "Insira sua jogada (linha coluna): ";
    std::cin >> linha >> coluna;
    linha -= 1;
    coluna -= 1;
}

bool Reversi::temMovimentoValido(Peca jogador) const {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (movimentoValido(i, j)) {
                return true;
            }
        }
    }
    return false;
}
