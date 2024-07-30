#ifndef LIG4_HPP
#define LIG4_HPP

#include <iostream>
#include <string>
#include "Jogo.hpp"

using namespace std;

class Lig4 : public Jogo {
public:
    Lig4(int num_linha, int num_coluna) : Jogo(num_linha, num_coluna) {}
    bool jogar(int coluna, std::string jogador);
    bool verifica_direcao(int linha, int coluna, int dir_linha, int dir_coluna);
    void verificar_vencedor() override;
    bool empate() const;
    void imprime() const override;
};

#endif
