 #include "../include/Partida.hpp"
#include "../include/Lig4.hpp"

void Partida::iniciar_jogo() { 
  cout << "Deseja o tabuleiro padrão(6x7)? (S/N): ";
  char escolha_padrao;
  cin >> escolha_padrao;
  bool vencedor = false;
  bool rodada = true; //ou seja, o jogador 1 começa as rodadas
  int coluna;
  if (_t_jogo == "L") {
    
    if (escolha_padrao == 'S') {
      Lig4 nova_partida(6, 7);
      while (vencedor == false) {
        if (rodada == true) {
          cout << "Turno de jogador " << _apl1 << ": \nEscolha a coluna para jogar: ";
          cin >> coluna;
          nova_partida.jogar(coluna - 1, "X");
          nova_partida.imprime();
          vencedor = nova_partida.verificar_vencedor();
          rodada = false;
        }
        else {
          cout << "Rodada: " << _apl2 << ": \nEscolha a coluna para jogar: ";
          cin >> coluna;
          nova_partida.jogar(coluna - 1, "Y");
          nova_partida.imprime();
          vencedor = nova_partida.verificar_vencedor();
          rodada = true;
        }
      }
      cout << "Alguem venceu" << endl;
    }
    //crio o objeto LIG4 e começo o jogo
  }
  else if (_t_jogo == "R") {
    //crio o objeto REVERSI e começo o jogo
  }
}

string Partida::get_apl1() const {
  return _apl1;
}

string Partida::get_apl2() const {
  return _apl2;
}
