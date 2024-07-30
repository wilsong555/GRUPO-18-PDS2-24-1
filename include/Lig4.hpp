#ifndef LIG4_HPP
#define LIG4_HPP

#include "Jogo.hpp"
#include <vector>

class Lig4 : public Jogo {
<<<<<<< HEAD
private:
    std::vector<std::vector<Peca>> grid;

public:
    Lig4();

    void exibir() const override;
    bool movimentoValido(int linha, int coluna) const override;
    void aplicarMovimento(int linha, int coluna, Peca jogador) override;
    bool verificarVitoria(Peca jogador) const override;
    void lerJogada(int& linha, int& coluna) const override;
=======
  public:
    Lig4(int num_linha, int num_coluna) : Jogo(num_linha, num_coluna) {}
    bool jogar(int coluna, string jogador);
    bool verifica_direcao(int linha, int coluna, int dir_linha, int dir_coluna);
    void verificar_vencedor() override;
    bool empate() const;
    void imprime() const override;
>>>>>>> 78fb2f205e2e98b6c7b0f7577a532248d0c26212
};

#endif // LIG4_HPP
