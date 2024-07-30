#include "../include/Lig4.hpp"
#include "../include/Jogo.hpp"
#include <iostream>

Lig4::Lig4() : grid(6, std::vector<Peca>(7, Peca::Vazia)) {}

void Lig4::exibir() const {
    std::cout << "  1 2 3 4 5 6 7\n";
    for (int i = 0; i < 6; ++i) {
        std::cout << i + 1 << ' ';
        for (int j = 0; j < 7; ++j) {
            char display = '.';
            if (grid[i][j] == Peca::Amarelo) display = 'A';
            else if (grid[i][j] == Peca::Vermelho) display = 'V';
            std::cout << display << ' ';
        }
        std::cout << '\n';
    }
}

bool Lig4::movimentoValido(int, int coluna) const {
    return grid[0][coluna] == Peca::Vazia;
}

void Lig4::aplicarMovimento(int, int coluna, Peca jogador) {
    for (int i = 5; i >= 0; --i) {
        if (grid[i][coluna] == Peca::Vazia) {
            grid[i][coluna] = jogador;
            break;
        }
    }
}

bool Lig4::verificarVitoria(Peca jogador) const {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (grid[i][j] == jogador) {
                if (j + 3 < 7 && grid[i][j + 1] == jogador && grid[i][j + 2] == jogador && grid[i][j + 3] == jogador)
                    return true;
                if (i + 3 < 6 && grid[i + 1][j] == jogador && grid[i + 2][j] == jogador && grid[i + 3][j] == jogador)
                    return true;
                if (i + 3 < 6 && j + 3 < 7 && grid[i + 1][j + 1] == jogador && grid[i + 2][j + 2] == jogador && grid[i + 3][j + 3] == jogador)
                    return true;
                if (i + 3 < 6 && j - 3 >= 0 && grid[i + 1][j - 1] == jogador && grid[i + 2][j - 2] == jogador && grid[i + 3][j - 3] == jogador)
                    return true;
            }
        }
    }
<<<<<<< HEAD
=======
    return true;
}

bool Lig4::jogar(int coluna, string valor) {
    if(coluna >= 0 && coluna < this->get_colunas()) {
        for (int i = this->get_linhas() - 1; i >= 0; --i) {
          if (this->getvalor_matriz(i, coluna) == " ") {
            this->setvalor(i, coluna, valor);
            return true;
          }
        }    
    }
    else {
        cout << "Coluna inválida, tente outra." << endl;
        return false;
    }
    cout << "Coluna cheia, tente outra." << endl;
>>>>>>> 78fb2f205e2e98b6c7b0f7577a532248d0c26212
    return false;
}

void Lig4::lerJogada(int& linha, int& coluna) const {
    std::cout << "Insira sua jogada (coluna): ";
    std::cin >> coluna;
    linha = 0;
    coluna -= 1;
}
<<<<<<< HEAD
=======

void Lig4::verificar_vencedor() {
    for (int linha = 0; linha < this->get_linhas(); ++linha) {
        for (int coluna = 0; coluna < this->get_colunas(); ++coluna) {
            if (this->getvalor_matriz(linha, coluna) != " ") {
                // Verificação Horizontal
                if (coluna <= this->get_colunas() - 4 &&
                    verifica_direcao(linha, coluna, 0, 1)) {
                    this->set_status('v');
                    return;
                }
                // Verificação Vertical
                if (linha <= this->get_linhas() - 4 &&
                    verifica_direcao(linha, coluna, 1, 0)) {
                    this->set_status('v');
                    return;
                }
                // Verificação Diagonal Crescente
                if (linha <= this->get_linhas() - 4 && coluna <= this->get_colunas() - 4 &&
                    verifica_direcao(linha, coluna, 1, 1)) {
                    this->set_status('v');
                    return;
                }
                // Verificação Diagonal Decrescente
                if (linha >= 3 && coluna <= this->get_colunas() - 4 &&
                    verifica_direcao(linha, coluna, -1, 1)) {
                    this->set_status('v');
                    return;
                }
            }
        }
    }
    if (this->empate() == true) {
        this->set_status('e');
    }
    else {
        this->set_status('i');
    }
}

void Lig4::imprime() const{
    for (int i = 0; i < this->get_linhas(); i++) {
        for (int j = 0; j < this->get_colunas(); j++) {
            cout << "| " << this->getvalor_matriz(i, j) << " |"; // Corrigido para usar índices corretos
        }
        cout << endl;
    }
};


>>>>>>> 78fb2f205e2e98b6c7b0f7577a532248d0c26212
