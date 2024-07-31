#include "../include/Partida.hpp"
#include "../include/Ia.hpp"
#include <limits>


void Partida::iniciar_jogo() { 
  //inicialização de variaveis gerais
  char escolha_padrao;
  int n_linha, n_coluna;
  
  //jogo LIG4
  if (_t_jogo == "l") { 
    cout << "Deseja o tabuleiro padrão(6x7)? (S/N): " << endl;
    cin >> escolha_padrao;
    if (escolha_padrao == 'N') {
      cout << "Tamanho personalizado\nDigite o nº de linhas: ";
      cin >> n_linha;
      cout << "Digite o nº de colunas: ";
      cin >> n_coluna;
      cout << endl;
    }
    else {
      n_linha = 6;
      n_coluna = 7;
    }
    
    char contraIA;
    cout << "Deseja jogar contra a IA? (S/N): ";
    cin >> contraIA;
    
    _contraIA = (contraIA == 'S');
    Lig4 nova_partida(n_linha, n_coluna);
    partida_lig4(nova_partida);

  }
  else if (_t_jogo == "r") {
    partida_reversi();
  }
}

int define_coluna(const string& jogador_atual) {
    int col;
    while (true) {
        cout << "Turno de jogador " << jogador_atual << ". Escolha a coluna para jogar: ";
        
        if (cin >> col) {
            // Verifica se a coluna está dentro do intervalo permitido (1 a 7)
            if (col >= 1 && col <= 7) {
                return col - 1; // Ajusta para o índice baseado em zero
            } else {
                cout << "Valor inválido. Digite um número entre 1 e 7.\n";
            }
        } else {
            cout << "Entrada inválida. Digite um número inteiro.\n";
            cin.clear(); // Limpa o estado de erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora o restante da linha
        }
    }
}

void Partida::partida_lig4(Lig4 nova_partida) {
  bool jogador_turno = true; //jogador 1 e true, jogador 2 e false
  nova_partida.set_status('i');
  int coluna;

  IA ia("X", "Y");

    while (nova_partida.get_status() == 'i') {
      if (_contraIA && !jogador_turno) {
        coluna = ia.encontrarMelhorJogada(nova_partida);
        if (coluna != -1) {
          cout << "IA jogou na coluna " << coluna + 1 << endl;
          nova_partida.jogar(coluna, "Y");
        }
        else {
          cout << "IA não encontrou jogada válida" << endl;
          break;
        }
      }
      else {
        string jogador_atual = (jogador_turno ? this->get_apl1() : this->get_apl2());
        coluna = define_coluna(jogador_atual);
        if (nova_partida.jogar(coluna, (jogador_turno ? "X" : "Y"))) { //se a jogada não for o laço se reinicia sem alterar o turno
          nova_partida.imprime(); 
          nova_partida.verificar_vencedor(); 
          jogador_turno = (jogador_turno ? false : true); //se o jogador atual for true então o proximo deve ser false, tendo assim a troca de turno
        }
      }
    }

    if (nova_partida.get_status() == 'v') {
      cout << "O jogador " << (jogador_turno ? this->get_apl1() : this->get_apl2()) << " venceu!" << endl;
      Jogador V, P;
      V.set_informacoes((jogador_turno ? this->get_apl1() : this->get_apl2()), true, _t_jogo); //vencedor
      V.mudar_estatistica_atual();
      P.set_informacoes((!jogador_turno ? this->get_apl1() : this->get_apl2()), false, _t_jogo);
      P.mudar_estatistica_atual();
    }
    else if (nova_partida.get_status() == 'e') {
      cout << "Empates não gera pontos" << endl;
    }
}

void Partida::partida_reversi() {
    cout << "iniciou partida" << endl;
    Tabuleiro tabuleiro;
    Peca jogadorAtual = Peca::Preto;

    while (true) {
        tabuleiro.imprime();

        if (!tabuleiro.temMovimentoValido(jogadorAtual)) {
            cout << "Jogador " << (jogadorAtual == Peca::Preto ? "Preto" : "Branco") << " nao tem movimentos validos. Passando a vez.\n";
            jogadorAtual = (jogadorAtual == Peca::Preto) ? Peca::Branco : Peca::Preto;
            if (!tabuleiro.temMovimentoValido(jogadorAtual)) {
                cout << "Nenhum jogador tem movimentos validos.\n O jogo acabou.\n";
                break;
            }
        }

        int linha, coluna;
        cout << "Jogador " << (jogadorAtual == Peca::Preto ? "Preto" : "Branco") << ", insira sua jogada (linha coluna): ";
        cin >> linha >> coluna;

        linha -= 1;
        coluna -= 1;

        if (tabuleiro.movimentoValido(linha, coluna, jogadorAtual)) {
            tabuleiro.aplicarMovimento(linha, coluna, jogadorAtual);
            jogadorAtual = (jogadorAtual == Peca::Preto) ? Peca::Branco : Peca::Preto;
        } else {
            cout << "Movimento invalido. Tente novamente.\n";
        }
    }
    tabuleiro.verificar_vencedor();
}


string Partida::get_apl1() const {
  return _apl1;
}

string Partida::get_apl2() const {
  return _apl2;
}
