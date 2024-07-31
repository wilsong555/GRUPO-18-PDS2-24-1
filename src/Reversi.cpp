#include "../include/Reversi.hpp"
#include "../include/Jogo.hpp"
#include <iostream>


Tabuleiro::Tabuleiro() : Jogo(8, 8), grid(8, std::vector<Peca>(8, Peca::Vazia)) {
    // Configuração inicial
    grid[3][3] = Peca::Branco;
    grid[3][4] = Peca::Preto;
    grid[4][3] = Peca::Preto;
    grid[4][4] = Peca::Branco;
}


Peca Tabuleiro::operator()(int linha, int coluna) const {
    return grid[linha][coluna];
}

void Tabuleiro::setPeca(int linha, int coluna, Peca peca) {
    grid[linha][coluna] = peca;
}

void Tabuleiro::imprime() const {
    std::cout << "  1 2 3 4 5 6 7 8\n"; // Cabeçalho das colunas
    for (int i = 0; i < 8; ++i) {
        std::cout << i + 1 << ' '; // Cabeçalho das linhas
        for (int j = 0; j < 8; ++j) {
            char display = '.';
            if (grid[i][j] == Peca::Preto) display = 'P';
            else if (grid[i][j] == Peca::Branco) display = 'B';
            std::cout << display << ' ';
        }
        std::cout << '\n';
    }
}

bool Tabuleiro::temMovimentoValido(Peca jogador) const {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (movimentoValido(i, j, jogador)) {
                return true;
            }
        }
    }
    //comentario
    return false;
}

bool Tabuleiro::movimentoValido(int linha, int coluna, Peca jogador) const {
    if (grid[linha][coluna] != Peca::Vazia) return false;

    int direcoes[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    Peca adversario = (jogador == Peca::Preto) ? Peca::Branco : Peca::Preto;

    for (auto& direcao : direcoes) {
        int dx = direcao[0], dy = direcao[1];
        int x = linha + dx, y = coluna + dy;
        bool encontrouAdversario = false;

        while (x >= 0 && x < 8 && y >= 0 && y < 8) {
            if (grid[x][y] == adversario) {
                encontrouAdversario = true;
            } else if (grid[x][y] == jogador) {
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

void Tabuleiro::aplicarMovimento(int linha, int coluna, Peca jogador) {
    setPeca(linha, coluna, jogador);

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
                        setPeca(p.first, p.second, jogador);
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
std::pair<int, int> Tabuleiro::contarPecas() const {
    int contagemPreto = 0;
    int contagemBranco = 0;

    for (const auto& linha : grid) {
        for (const auto& peca : linha) {
            if (peca == Peca::Preto) {
                ++contagemPreto;
            } else if (peca == Peca::Branco) {
                ++contagemBranco;
            }
        }
    }

    return {contagemPreto, contagemBranco};
}

void Tabuleiro::verificar_vencedor() {
    std::pair<int, int> contagem = contarPecas();
    int contagemPreto = contagem.first;
    int contagemBranco = contagem.second;
    std::cout << "Pontuacao final:\n";
    std::cout << "Preto: " << contagemPreto << "\n";
    std::cout << "Branco: " << contagemBranco << "\n";

    if (contagemPreto > contagemBranco) {
        std::cout << "Jogador Preto venceu!\n";
    } else if (contagemBranco > contagemPreto) {
        std::cout << "Jogador Branco venceu!\n";
    } else {
        std::cout << "O jogo terminou empatado!\n";
    }
}