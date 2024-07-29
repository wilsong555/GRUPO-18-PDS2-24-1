/*#ifndef JOGO_HPP
#define JOGO_HPP

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Jogo {
    private:
    int linha, coluna;
    vector <vector <string>> matriz;
    char _status;

    public:
    Jogo(int linha, int coluna);
    string getvalor_matriz(int linha, int coluna) const;
    int get_linhas() const;
    int get_colunas() const;
    char get_status() const;
    void set_status(char n_status);
    void setvalor(int linha, int coluna, string valor);
    virtual void verificar_vencedor() = 0;
    void imprime();

};



#endif*/
#ifndef JOGO_HPP
#define JOGO_HPP

enum class Peca { Vazia, Preto, Branco, Amarelo, Vermelho };

class Jogo {
public:
    virtual ~Jogo() = default;

    virtual void exibir() const = 0;
    virtual bool movimentoValido(int linha, int coluna) const = 0;
    virtual void aplicarMovimento(int linha, int coluna, Peca jogador) = 0;
    virtual bool verificarVitoria(Peca jogador) const = 0;
    virtual void lerJogada(int& linha, int& coluna) const = 0;
};

#endif // JOGO_HPP

