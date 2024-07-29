#include "../include/Lig4.hpp"
#include "../include/Jogo.hpp"

#include <iostream>
using namespace std;

bool Lig4::empate() const {
    for (int i = 0; i < this->get_linhas(); i++) {
        for (int c = 0; c < this->get_colunas(); c++) {
            if (this->getvalor_matriz(i, c) == " "){
                return false;
            }
        }
    }
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
    return false;
}



bool Lig4::verifica_direcao(int linha, int coluna, int dir_linha, int dir_coluna) {
    string valor = this->getvalor_matriz(linha, coluna);
    for (int i = 1; i < 4; ++i) {
        int nova_linha = linha + i * dir_linha;
        int nova_coluna = coluna + i * dir_coluna;
        if (nova_linha < 0 || nova_linha >= this->get_linhas() || 
            nova_coluna < 0 || nova_coluna >= this->get_colunas() || 
            this->getvalor_matriz(nova_linha, nova_coluna) != valor) {
            return false;
        }
    }
    return true;
}

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


