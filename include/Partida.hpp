#ifndef PARTIDA_HPP
#define PARTIDA_HPP

#include <iostream>
#include <string>
#include "CadastroJogadores.hpp"
#include "Jogador.hpp"
using namespace std;

class Partida {
  public:
    Partida(string t_jogo, string apl1, string apl2) : _t_jogo(t_jogo), _apl1(apl1), _apl2(apl2) {}
    void iniciar_jogo();
    string get_apl1() const;
    string get_apl2() const;

  private:
    string _t_jogo, _apl1, _apl2;
};

#endif