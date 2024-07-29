#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "Jogo.hpp"
#include <vector>

class Reversi : public Jogo {
private:
    std::vector<std::vector<Peca>> grid;

public:
    Reversi();

    void exibir() const override;
    bool movimentoValido(int linha, int coluna) const override;
    void aplicarMovimento(int linha, int coluna, Peca jogador) override;
    bool verificarVitoria(Peca jogador) const override;
    void lerJogada(int& linha, int& coluna) const override;
    bool temMovimentoValido(Peca jogador) const;
};

#endif // REVERSI_HPP
