#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP

#include <iostream>
#include <vector>


using namespace std;

class Tabuleiro {
    private:
    int linha, coluna;
    vector <vector <int>> matriz;

    public:
    Tabuleiro(int linha, int coluna);
    int getvalor_matrz();
    void setvalor(int linha, int coluna, string valor);
    void imprime();

};



#endif