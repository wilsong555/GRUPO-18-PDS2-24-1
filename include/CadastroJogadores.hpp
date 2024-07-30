/*#ifndef CADASTROJOGADORES_HPP
#define CADASTROJOGADORES_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Pessoa {
  string nome;
  string apelido;
  string Reversi;
  string Lig4;

  bool compararApelido(const Pessoa &jogador1, const Pessoa &jogador2);
  bool compararNome(const Pessoa &jogador1, const Pessoa &jogador2);
  vector<Pessoa> LerArquivo(const string Arq_estatisticas);
};

class Cadastro {
  public:
    Cadastro();
    string adicionar_jogador(string nome, string apelido);
    bool remover_jogador(string apelido);
    static void listar_jogadores();
    bool verificar_jogador(string nome, string apelido);

  private:
    static bool verificaStrings(const string &apelido);
};

#endif*/
