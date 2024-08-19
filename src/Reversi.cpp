#include "../include/Reversi.hpp"
#include "../include/Peca.hpp"// Cabeçalho da classe Tabuleiro.
#include "../include/Jogo.hpp"//Cabeçalho da classe base Jogo, que Tabuleiro herda.
#include <iostream>

/*Jogo(8, 8): Chama o construtor da classe base Jogo para inicializar um tabuleiro de 8x8.
grid(8, std::vector<Peca>(8, Peca::Vazia)): Cria uma matriz 8x8 onde cada posição é inicializada com Peca::Vazia.
As quatro linhas seguintes configuram as peças iniciais do jogo Reversi no centro do tabuleiro.*/
Tabuleiro::Tabuleiro() : Jogo(8, 8), grid(8, std::vector<Peca>(8, Peca::Vazia)) {
    // Configuração inicial
    grid[3][3] = Peca::Branco;
    grid[3][4] = Peca::Preto;
    grid[4][3] = Peca::Preto;
    grid[4][4] = Peca::Branco;
}

/*Método operator(): Permite acessar a peça no tabuleiro usando a notação tabuleiro(linha, coluna).
    Retorna a peça (Peca) na posição especificada.*/
Peca Tabuleiro::operator()(int linha, int coluna) const {
    return grid[linha][coluna];
}

/*Método setPeca: Define a peça na posição especificada do tabuleiro.
    Altera o valor na matriz grid para o tipo de peça especificado.*/
void Tabuleiro::setPeca(int linha, int coluna, Peca peca) {
    grid[linha][coluna] = peca;
}

/*Método imprime: Imprime o estado do tabuleiro no console.
    Imprime um cabeçalho com números de coluna.
    Para cada linha do tabuleiro, imprime o número da linha seguido por uma representação das peças (P para Preto, B para Branco, . para Vazio).*/
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

/*Método temMovimentoValido: Verifica se há algum movimento válido para o jogador.
    Percorre todas as posições do tabuleiro e usa movimentoValido para verificar se a posição é válida para o jogador. 
    Retorna true se algum movimento válido for encontrado.*/
bool Tabuleiro::temMovimentoValido(Peca jogador) const {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (movimentoValido(i, j, jogador)) {
                return true;
            }
        }
    }
    return false;
}

/*Método movimentoValido: Verifica se um movimento é válido para um jogador em uma posição específica.

    Se a posição não estiver vazia, retorna false.
    Verifica todas as 8 direções possíveis (horizontal, vertical e diagonal) para ver se há uma sequência válida de peças adversárias seguidas pela peça do jogador.*/
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

/*Método aplicarMovimento: Aplica um movimento no tabuleiro e vira as peças adversárias.
    Primeiro, coloca a peça do jogador na posição especificada.
    Verifica todas as 8 direções para encontrar peças adversárias que podem ser viradas e armazena suas posições.
    Vira as peças adversárias encontradas na mesma direção se houver uma peça do jogador no final da linha.*/
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
/*Método contarPecas: Conta o número de peças pretas e brancas no tabuleiro.

    Percorre todo o tabuleiro e conta as peças de cada tipo.*/
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
/*Método verificar_vencedor: Verifica e imprime o vencedor com base na contagem final das peças.

    Obtém a contagem de peças pretas e brancas.
    Compara as contagens e imprime o resultado final do jogo.*/
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