#ifndef CADASTROJOGADORES_HPP
#define CADASTROJOGADORES_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Gerenciamento_Jogadores {
  private:
    fstream _arquivo;
    string _nome_arquivo;
    bool procura_string(const string &apelido, string &mensagem);

  public:
    Gerenciamento_Jogadores(const string &nome_arquivo);
    ~Gerenciamento_Jogadores();
    string adicionar_jogadores(string nome, string apelido);
    string remover_jogador(const string &apelido);
    //static void listar_jogadores(char t_ordenacao) const;
};

// struct Pessoa {
//   string nome;
//   string apelido;
//   string Reversi;
//   string Lig4;

//   bool compararApelido(const Pessoa &jogador1, const Pessoa &jogador2);
//   bool compararNome(const Pessoa &jogador1, const Pessoa &jogador2);
//   vector<Pessoa> LerArquivo(const string Arq_estatisticas);
// };

// class Cadastro {
//   public:
//     Cadastro();
//     string adicionar_jogador(string nome, string apelido);
//     bool remover_jogador(string apelido);
//     static void listar_jogadores();
//     bool verificar_jogador(string nome, string apelido);

//   private:
//     static bool verificaStrings(const string &apelido);
// };

#endif
