#ifndef JOGADOR_HPP
#define JOGADOR_HPP
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Peca.hpp"


using namespace std;


//enum class Peca { Vazia, Preto, Branco };
class Jogador {
    public:
        Jogador();
        void set_informacoes(string apelido, bool situacao, char t_jogo, Peca peca);
        bool mudar_estatistica_atual();
        static bool verificar_jogador(const string &nome, const string &apelido, string &mensagem);
        Peca getPeca() const; // Novo método para obter a peça do jogador
    private:
        string _apelido;
        bool _status; //true é vencedor
        char _jogo_atual;
        Peca _peca;// Novo atributo para a peça do jogador
};

#endif // JOGADOR.HPP