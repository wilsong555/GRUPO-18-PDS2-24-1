#ifndef JOGADOR_HPP
#define JOGADOR_HPP
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;


/*class Jogador {
    public:
        Jogador();
        void set_informacoes(string apelido, bool situacao, char t_jogo);
        bool mudar_estatistica_atual();
        static bool verificar_jogador(const string &nome, const string &apelido, string &mensagem);
    private:
        string _apelido;
        bool _status; //true é vencedor
<<<<<<< HEAD
        string _jogo_atual;
};*/
class Jogador {
public:
    string apelido;
    string nome;
    int vitorias;
    int derrotas;

    Jogador(const string& apelido, const string& nome)
        : apelido(apelido), nome(nome), vitorias(0), derrotas(0) {}
=======
        char _jogo_atual;
>>>>>>> 6d0f8e66beb28406cb9ac6967290f1c0f7dcbdb1
};

#endif