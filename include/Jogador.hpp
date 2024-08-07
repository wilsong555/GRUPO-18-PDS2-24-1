#ifndef JOGADOR_HPP
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
        void set_informacoes(string apelido, bool situacao, char t_jogo);
        bool mudar_estatistica_atual();
        static bool verificar_jogador(const string &nome, const string &apelido, string &mensagem);
    private:
        string _apelido;
        bool _status; //true é vencedor
        char _jogo_atual;
};

#endif