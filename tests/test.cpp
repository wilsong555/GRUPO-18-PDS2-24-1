#include <iostream>
#include <vector>

void Tabuleiro::exibir() const {
    for (const auto& linha : grid) {
        for (const auto& celula : linha) {
            char display = '.';
            if (celula == Peca::Preto) display = 'P';
            else if (celula == Peca::Branco) display = 'B';
            std::cout << display << ' ';
        }
        std::cout << '\n';
    }
}

enum class Peca { Vazia, Preto, Branco };

class Tabuleiro {
private:
    std::vector<std::vector<Peca>> grid;

public:
    Tabuleiro() : grid(8, std::vector<Peca>(8, Peca::Vazia)) {
        // Configuração inicial
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

    void exibir() const {
        for (const auto& linha : grid) {
            for (const auto& celula : linha) {
                char display = '.';
                if (celula == Peca::Preto) display = 'P';
                else if (celula == Peca::Branco) display = 'B';
                std::cout << display << ' ';
            }
            std::cout << '\n';
        }
    }
};

bool movimentoValido(const Tabuleiro& tabuleiro, int linha, int coluna, Peca jogador) {
    if (tabuleiro(linha, coluna) != Peca::Vazia) return false;

    int direcoes[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

    Peca adversario = (jogador == Peca::Preto) ? Peca::Branco : Peca::Preto;

    for (auto& direcao : direcoes) {
        int dx = direcao[0], dy = direcao[1];
        int x = linha + dx, y = coluna + dy;
        bool encontrouAdversario = false;

        while (x >= 0 && x < 8 && y >= 0 && y < 8) {
            if (tabuleiro(x, y) == adversario) {
                encontrouAdversario = true;
            } else if (tabuleiro(x, y) == jogador) {
                if (encontrouAdversario) return true;
                else break;
            } else break;

            x += dx;
            y += dy;
        }
    }

    return false;
}

void aplicarMovimento(Tabuleiro& tabuleiro, int linha, int coluna, Peca jogador) {
    tabuleiro.setPeca(linha, coluna, jogador);

    int direcoes[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

    Peca adversario = (jogador == Peca::Preto) ? Peca::Branco : Peca::Preto;

    for (auto& direcao : direcoes) {
        int dx = direcao[0], dy = direcao[1];
        int x = linha + dx, y = coluna + dy;
        bool encontrouAdversario = false;

        while (x >= 0 && x < 8 && y >= 0 && y < 8) {
            if (tabuleiro(x, y) == adversario) {
                encontrouAdversario = true;
            } else if (tabuleiro(x, y) == jogador) {
                if (encontrouAdversario) {
                    int rx = linha + dx, ry = coluna + dy;
                    while (tabuleiro(rx, ry) == adversario) {
                        tabuleiro.setPeca(rx, ry, jogador);
                        rx += dx;
                        ry += dy;
                    }
                    break;
                } else break;
            } else break;

            x += dx;
            y += dy;
        }
    }
}

int main() {
    Tabuleiro tabuleiro;
    Peca jogadorAtual = Peca::Preto;

    while (true) {
        tabuleiro.exibir();

        int linha, coluna;
        std::cout << "Jogador " << (jogadorAtual == Peca::Preto ? "Preto" : "Branco") << ", insira sua jogada (linha coluna): ";
        std::cin >> linha >> coluna;

        if (movimentoValido(tabuleiro, linha, coluna, jogadorAtual)) {
            aplicarMovimento(tabuleiro, linha, coluna, jogadorAtual);
            jogadorAtual = (jogadorAtual == Peca::Preto) ? Peca::Branco : Peca::Preto;
        } else {
            std::cout << "Movimento inválido. Tente novamente.\n";
        }
    }

    return 0;
}
