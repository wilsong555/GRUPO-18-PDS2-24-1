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
    //Jogo();
    Jogo(int linha, int coluna);
    string getvalor_matrz(int linha, int coluna) const;
    void setvalor(int linha, int coluna, string valor);
    void imprime();

};



#endif