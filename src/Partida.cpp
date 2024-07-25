#include "../include/Partida.hpp"
#include "../include/Lig4.hpp"

void Partida::iniciar_jogo() { 
  //inicialização de variaveis gerais
  char escolha_padrao;
  bool jogador_turno = true; //jogador 1 e true, jogador 2 e false
  int coluna;
  
  cout << "\nDeseja o tabuleiro padrão(6x7)? (S/N): " << endl;
  // cin >> escolha_padrao;
  escolha_padrao = 'S';
  
  //jogo LIG4
  if (_t_jogo == "l") {
    if (escolha_padrao == 'S') {
      Lig4 nova_partida(4, 4);
      nova_partida.set_status('i');
      while (nova_partida.get_status() == 'i') {
        cout << "Turno de jogador " << (jogador_turno ? this->get_apl1() : this->get_apl2()) << ". Escolha a coluna para jogar: "; //usei ternario para evitar gastar espaço com ifs
        cin >> coluna;
        if (nova_partida.jogar(--coluna, (jogador_turno ? "X" : "Y"))) { //se a jogada não for o laço se reinicia sem alterar o turno
          nova_partida.imprime();
          nova_partida.verificar_vencedor();
          jogador_turno = (jogador_turno ? false : true); //se o jogador atual for true então o proximo deve ser false, tendo assim a troca de turno
        }
      }
      if (nova_partida.get_status() == 'v') {
        cout << "O jogador " << (jogador_turno ? this->get_apl1() : this->get_apl2()) << " venceu!" << endl;
        Jogador V, P;
        V.set_informacoes((jogador_turno ? this->get_apl1() : this->get_apl2()), true, _t_jogo); //vencedor
        P.set_informacoes((!jogador_turno ? this->get_apl1() : this->get_apl2()), false, _t_jogo);
        V.mudar_estatistica_atual();
        P.mudar_estatistica_atual();
      }
      else if (nova_partida.get_status() == 'e') {
        cout << "Empates não gera pontos" << endl;
      }
    }
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
