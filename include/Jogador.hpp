/*#ifndef JOGADOR_HPP
#define JOGADOR_HPP
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;


class Jogador {
    public:
        Jogador();
        void set_informacoes(string apelido, bool situacao, string t_jogo);
        bool mudar_estatistica_atual();
    private:
        string _apelido;
        bool _status; //true é vencedor
        string _jogo_atual;
};

#endif*/