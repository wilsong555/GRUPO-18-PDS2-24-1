#ifndef CADASTRO_H_
#define CADASTRO_H_

#include <string> //sempre inclui aqui o que tiver que ser incluido lá
#include <vector>
using namespace std;

class Cadastro {
  public:
    Cadastro();
    static void remover_jogador(); //destrutor
    static void listar_jogadores();

  private:
    string _nome;
    string _apelido;
    int _rev_vitoria, _rev_derrota, _lig_vitoria, _lig_derrota;
};

struct Jogador {
  string nome;
  string apelido;
  string Reversi;
  string Lig4;

  bool compararApelido(const Jogador &jogador1, const Jogador &jogador2);
  bool compararNome(const Jogador &jogador1, const Jogador &jogador2);
  vector<Jogador> LerArquivo(const string Arq_estatisticas);
};


#endif