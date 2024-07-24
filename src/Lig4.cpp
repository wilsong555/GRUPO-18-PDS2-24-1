#include "../include/Lig4.hpp"
#include "../include/Jogo.hpp"

#include <iostream>
using namespace std;

bool Lig4::jogar(int coluna, string jogador) {
    if(coluna >= 0 && coluna < this->get_colunas()) {
        for (int i = this->get_linhas() - 1; i >= 0; --i) {
          if (this->getvalor_matriz(i, coluna) == " ") {
            this->setvalor(i, coluna, jogador);
            return true;
          }
        }    
    }
    cout << "Coluna cheia, tente outra." << endl;
    return false;
}

bool Lig4::verificar_vencedor() {
    // Verificar todas as direções para cada célula do tabuleiro
    for (int linha = 0; linha < this->get_linhas(); ++linha) {
        for (int coluna = 0; coluna < this->get_colunas(); ++coluna) {
            if (this->getvalor_matriz(linha, coluna) != " ") {
                string jogador = this->getvalor_matriz(linha, coluna);
                // Verificação Horizontal
                if (coluna <= this->get_colunas() - 4 && 
                    this->getvalor_matriz(linha, coluna) == jogador &&
                    this->getvalor_matriz(linha, coluna + 1) == jogador &&
                    this->getvalor_matriz(linha, coluna + 2) == jogador &&
                    this->getvalor_matriz(linha, coluna + 3) == jogador) {
                    return true;
                }
                // Verificação Vertical
                if (linha <= this->get_linhas() - 4 &&
                    this->getvalor_matriz(linha, coluna) == jogador &&
                    this->getvalor_matriz(linha + 1, coluna) == jogador &&
                    this->getvalor_matriz(linha + 2, coluna) == jogador &&
                    this->getvalor_matriz(linha + 3, coluna) == jogador) {
                    return true;
                }
                // Verificação Diagonal Crescente
                if (linha <= this->get_linhas() - 4 && coluna <= this->get_colunas() - 4 &&
                    this->getvalor_matriz(linha, coluna) == jogador &&
                    this->getvalor_matriz(linha + 1, coluna + 1) == jogador &&
                    this->getvalor_matriz(linha + 2, coluna + 2) == jogador &&
                    this->getvalor_matriz(linha + 3, coluna + 3) == jogador) {
                    return true;
                }
                // Verificação Diagonal Decrescente
                if (linha >= 3 && coluna <= this->get_colunas() - 4 &&
                    this->getvalor_matriz(linha, coluna) == jogador &&
                    this->getvalor_matriz(linha - 1, coluna + 1) == jogador &&
                    this->getvalor_matriz(linha - 2, coluna + 2) == jogador &&
                    this->getvalor_matriz(linha - 3, coluna + 3) == jogador) {
                    return true;
                }
            }
        }
    }
    return false;
}

