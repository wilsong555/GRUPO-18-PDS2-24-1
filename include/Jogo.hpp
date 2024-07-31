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
    char _status;
    //comentario

    public:
    Jogo(int linha, int coluna);
    string getvalor_matriz(int linha, int coluna) const;
    int get_linhas() const;
    int get_colunas() const;
    char get_status() const;
    void set_status(char n_status);
    void setvalor(int linha, int coluna, string valor);
    virtual void verificar_vencedor() = 0;
    virtual void imprime() const = 0;

};



#endif