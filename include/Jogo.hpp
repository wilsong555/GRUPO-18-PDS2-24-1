#ifndef JOGO_HPP
#define JOGO_HPP

#include <vector>
#include <string>
using namespace std;

class Jogo {
private:
    int linhas, colunas;
    vector<vector<string>> matriz;
    char status; // 'i' para em andamento, 'v' para vencedor, 'e' para empate

public:
    Jogo(int linhas, int colunas) : linhas(linhas), colunas(colunas), matriz(linhas, vector<string>(colunas, " ")), status('i') {}

    int get_linhas() const { return linhas; }
    int get_colunas() const { return colunas; }
    string getvalor_matriz(int linha, int coluna) const { return matriz[linha][coluna]; }
    void setvalor(int linha, int coluna, string valor) { matriz[linha][coluna] = valor; }
    char get_status() const { return status; }
    void set_status(char novo_status) { status = novo_status; }
    virtual void verificar_vencedor() = 0;
    virtual void imprime() const = 0;
};

#endif
