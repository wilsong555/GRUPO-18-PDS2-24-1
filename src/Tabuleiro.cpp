#include "Tabuleiro.hpp"
#include "../include/Tabuleiro.hpp"

using namespace std;

Tabuleiro::Tabuleiro(int numlinha, int numcoluna) : linha(numlinha), coluna(numcoluna) {
if (linha <= 0 || coluna <= 0 || linha > 1000 || coluna > 1000) { // Limite arbitrário para evitar problemas
        std::cerr << "Erro: Linhas e colunas devem ser maiores que zero e menores que 1000." << std::endl;
        exit(1);
    }
    
    matriz.resize(linha, vector<int> (coluna, 0));
};

int Tabuleiro::getvalor_matrz() {
    return matriz[linha][coluna];
};

void Tabuleiro::setvalor(int lnha, int coluna, string valor) {
 if (lnha >= 0 && lnha < linha && coluna >= 0 && coluna < this->coluna) {
        matriz[lnha][coluna] = stoi(valor);
    } else {
        std::cerr << "Erro: Índices fora do alcance." << std::endl;
    }}

void Tabuleiro::imprime() {
    for(int i = 0; i< linha; i++) {
        for(int j = 0; j < coluna; j++) {
            cout << matriz[linha][coluna] << " ";
            cout << endl;
        }
    }

};