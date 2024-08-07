#ifndef CADASTROJOGADORES_HPP
#define CADASTROJOGADORES_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio> 
using namespace std;

struct Informacoes_pessoais {
  string _apelido;
  string _nome;
  string _Reversi;
  string _Lig4;

  bool compararApelido(const Informacoes_pessoais &jogador1, const Informacoes_pessoais &jogador2);
  bool compararNome(const Informacoes_pessoais &jogador1, const Informacoes_pessoais &jogador2);
  string normalizar(const string &str_p_modificar);
  vector<Informacoes_pessoais> LerArquivo(const string &nome_arquivo);
};

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
    void listar_jogadores() const;
};


#endif
