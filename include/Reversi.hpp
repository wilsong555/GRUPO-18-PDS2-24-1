#ifndef REVERSI_HPP
#define REVERSI_HPP

#include <iostream>
#include <vector>

enum class Peca { Vazia, Preto, Branco };

class Tabuleiro : public Jogo{
private:
    std::vector<std::vector<Peca>> grid;

public:
    Tabuleiro();
    Peca operator()(int linha, int coluna) const;
    void setPeca(int linha, int coluna, Peca peca);
    void imprime() const override;
    bool temMovimentoValido(Peca jogador) const;
    bool movimentoValido(int linha, int coluna, Peca jogador) const;
    void aplicarMovimento(int linha, int coluna, Peca jogador);
	std::pair<int, int> contarPecas() const; // Novo método
    void verificar_vencedor() override; //subst. imprimirVencedor
    //void imprimirVencedor() const; // Novo método
    //comentario
};

#endif // REVERSI_HPP