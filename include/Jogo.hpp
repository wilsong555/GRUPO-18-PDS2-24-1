#ifndef JOGO_HPP
#define JOGO_HPP

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Jogo {
    private:
    int linha, coluna;
    vector <vector <string>> matriz;

    public:
    Jogo(int linha, int coluna);
    string getvalor_matriz(int linha, int coluna) const;
    int get_linhas() const;
    int get_colunas() const;
    void setvalor(int linha, int coluna, string valor);
    virtual bool verificar_vencedor() = 0;
    void imprime();

};



#endif
