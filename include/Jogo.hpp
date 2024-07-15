#ifndef JOGO_HPP
#define JOGO_HPP

#include <iostream>
#include <vector>


using namespace std;

class Jogo {
    private:
    int linha, coluna;
    vector <vector <int>> matriz;

    public:
    Jogo(int linha, int coluna);
    int getvalor_matrz();
    void setvalor(int linha, int coluna, string valor);
    void imprime();

};



#endif