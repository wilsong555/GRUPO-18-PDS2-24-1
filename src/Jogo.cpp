#include "Jogo.hpp"
#include "../include/Jogo.hpp"

using namespace std;

//Jogo::Jogo() : linha(0), coluna(0) {}

Jogo::Jogo(int numlinha, int numcoluna) : linha(numlinha), coluna(numcoluna) {
if (linha <= 0 || coluna <= 0 || linha > 1000 || coluna > 1000) { // Limite arbitrário para evitar problemas
        std::cerr << "Erro: Linhas e colunas devem ser maiores que zero e menores que 1000." << std::endl;
        exit(1);
    }
    
     matriz.resize(linha, vector<string>(coluna));
    for (int i = 0; i < linha; ++i) {
        for (int j = 0; j < coluna; ++j) {
            matriz[i][j] = "0";
        }
    }

};

string Jogo::getvalor_matrz(int linha, int coluna) const {
    return matriz[linha][coluna];
};

void Jogo::setvalor(int lnha, int coluna, string valor) {
    if (lnha >= 0 && lnha < linha && coluna >= 0 && coluna < this->coluna) {
        matriz[lnha][coluna] = valor;
    } else {
        std::cerr << "Erro: Posição inválida." << std::endl;
    }
}

void Jogo::imprime() {
    for (int i = 0; i < linha; ++i) {
        for (int j = 0; j < coluna;++j) {
            cout << matriz[i][j] << " "; // Corrigido para usar índices corretos
        }
        cout << endl;
    }

};