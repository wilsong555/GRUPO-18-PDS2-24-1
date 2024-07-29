#ifndef LIG4_HPP
#define LIG4_HPP

#include "Jogo.hpp"
#include <vector>

class Lig4 : public Jogo {
private:
    std::vector<std::vector<Peca>> grid;

public:
    Lig4();

    void exibir() const override;
    bool movimentoValido(int linha, int coluna) const override;
    void aplicarMovimento(int linha, int coluna, Peca jogador) override;
    bool verificarVitoria(Peca jogador) const override;
    void lerJogada(int& linha, int& coluna) const override;
};

#endif // LIG4_HPP
