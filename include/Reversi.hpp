#ifndef REVERSI_HPP
#define REVERSI_HPP

#include <iostream>
#include <vector>
#include "Peca.hpp"
#include "Jogo.hpp"


//enum class Peca { Vazia, Preto, Branco };

class Tabuleiro : public Jogo {
private:
    std::vector<std::vector<Peca>> grid;
    

public:
    Tabuleiro();// Construtor padrão da classe Tabuleiro. Inicializa o tabuleiro e define as peças iniciais.
    Peca operator()(int linha, int coluna) const;//Sobrecarga do operador de chamada de função. Permite acessar o valor da peça em uma posição específica do tabuleiro.
    void setPeca(int linha, int coluna, Peca peca);//Define a peça em uma posição específica do tabuleiro.
    void imprime() const override;//Imprime o estado atual do tabuleiro no console. Sobrescreve o método imprime da classe base Jogo.
    bool temMovimentoValido(Peca jogador) const;//Verifica se há algum movimento válido disponível para o jogador.
    bool movimentoValido(int linha, int coluna, Peca jogador) const;//Verifica se um movimento específico é válido para o jogador na posição indicada.
    void aplicarMovimento(int linha, int coluna, Peca jogador);//Aplica um movimento no tabuleiro e altera o estado das peças conforme as regras do jogo.
	std::pair<int, int> contarPecas() const;//Conta o número de peças pretas e brancas no tabuleiro e retorna essa contagem como um par de inteiros.
    void verificar_vencedor() override;//Verifica e imprime o vencedor do jogo com base na contagem final das peças. Sobrescreve o método verificar_vencedor da classe base Jogo.
    
};

#endif // REVERSI_HPP