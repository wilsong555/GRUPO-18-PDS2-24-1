/*#include "../include/Jogo.hpp"

using namespace std;

//Jogo::Jogo() : linha(0), coluna(0) {}

Jogo::Jogo(int numlinha, int numcoluna) : linha(numlinha), coluna(numcoluna) {
    if (linha <= 0 || coluna <= 0 || linha > 1000 || coluna > 1000) { // Limite arbitrário para evitar problemas
        exit(1);
    }
    matriz.resize(linha, vector<string>(coluna, " "));
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

char Jogo::get_status() const{
    return _status;
}

void Jogo::set_status(char n_status) {
    this->_status = n_status;
}

void Jogo::setvalor(int linha_atual, int coluna_atual, string valor) {
    matriz[linha_atual][coluna_atual] = valor;
}

void Jogo::imprime() {
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            cout << "| " << matriz[i][j] << " |"; // Corrigido para usar índices corretos
        }
        cout << endl;
    }
};*/
