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

string Jogo::getvalor_matriz(int linha, int coluna) const {
    return matriz[linha][coluna];
};

int Jogo::get_linhas() const{
    return linha;
}

int Jogo::get_colunas() const {
    return coluna;
}

void Jogo::setvalor(int linha_atual, int coluna_atual, string valor) {
    matriz[linha_atual][coluna_atual] = valor;
}

void Jogo::imprime() {
    for (int i = 0; i < linha; ++i) {
        for (int j = 0; j < coluna;++j) {
            cout << matriz[i][j] << " "; // Corrigido para usar índices corretos
        }
        cout << endl;
    }

};
