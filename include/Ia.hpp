/*#ifndef IA_HPP
#define IA_HPP

#include "Lig4.hpp"
#include <string>
using namespace std;

class IA {
private:
    string jogadorIA;
    string jogadorOponente;
public:
    IA(string jogadorIA, string jogadorOponente);
    int encontrarMelhorJogada(const Lig4& jogo);
    int avaliarTabuleiro(Lig4& jogo);
    int minimax(Lig4& jogo, int profundidade, bool isMaximizingPlayer);
};

#endif*/