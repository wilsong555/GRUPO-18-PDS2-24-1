#ifndef PARTIDA_HPP
#define PARTIDA_HPP

#include <iostream>
#include <string>
#include "CadastroJogadores.hpp"
#include "Jogador.hpp"
#include "Lig4.hpp"
#include "Reversi.hpp"
#include "IA.hpp"

using namespace std;

class Partida {
  public:
    Partida(string t_jogo, string apl1, string apl2) : _t_jogo(t_jogo), _apl1(apl1), _apl2(apl2), _contraIA(false) {}
    void iniciar_jogo();
    void partida_lig4(Lig4 nova_partida);
    void partida_reversi();

    //void setContraIA(bool contraIA) {_contraIA = _contraIA; }
    string get_apl1() const;
    string get_apl2() const;
    //comentario

  private:
    string _t_jogo, _apl1, _apl2;
    bool _contraIA;
};

#endif