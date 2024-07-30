// reversi.hpp
#ifndef REVERSE_HPP
#define REVERSE_HPP

#include <iostream>
#include <vector>

enum class Peca { Vazia, Preto, Branco };

class Tabuleiro {
private:
    std::vector<std::vector<Peca>> grid;

public:
    Tabuleiro();
    Peca operator()(int linha, int coluna) const;
    void setPeca(int linha, int coluna, Peca peca);
    void exibir() const;
    bool temMovimentoValido(Peca jogador) const;
    bool movimentoValido(int linha, int coluna, Peca jogador) const;
    void aplicarMovimento(int linha, int coluna, Peca jogador);
	std::pair<int, int> contarPecas() const; // Novo método
    void imprimirVencedor() const; // Novo método
};

#endif // REVERSI_HPP
