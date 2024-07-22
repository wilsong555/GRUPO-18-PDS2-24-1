#ifndef CADASTROJOGADORES_HPP
#define CADASTROJOGADORES_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Jogador {
  string nome;
  string apelido;
  string Reversi;
  string Lig4;

  bool compararApelido(const Jogador &jogador1, const Jogador &jogador2);
  bool compararNome(const Jogador &jogador1, const Jogador &jogador2);
  vector<Jogador> LerArquivo(const string Arq_estatisticas);
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

#endif
