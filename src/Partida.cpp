#include "../include/Partida.hpp"
#include "../include/IA.hpp"
#include <limits>


void Partida::iniciar_jogo() { 
  //inicialização de variaveis gerais
  char escolha_padrao;
  int n_linha, n_coluna;
  
  //jogo LIG4
  if (_t_jogo == "L") { 
    cout << "Deseja o tabuleiro padrão(6x7)? (S/N): " << endl;
    cin >> escolha_padrao;
    escolha_padrao = toupper(escolha_padrao);
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
    contraIA = toupper(contraIA);
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
    bool jogador_turno = true; // Jogador 1 é true, jogador 2 é false
    int coluna;
    nova_partida.set_status('i');

    IA ia("Y", "X"); // Definindo a IA como jogador 2

    while (nova_partida.get_status() == 'i') {
        if (_contraIA && !jogador_turno) {
            // Turno da IA
            coluna = ia.encontrarMelhorJogada(nova_partida);
            std::cout << "IA jogou na coluna " << coluna + 1 << std::endl;
        } else {
            // Turno de um jogador humano
            std::cout << "Turno de jogador " << (jogador_turno ? this->get_apl1() : this->get_apl2()) << ". Escolha a coluna para jogar: ";
            std::cin >> coluna;
            coluna--; // Ajuste para índice baseado em zero
        }

        if (nova_partida.jogar(coluna, (jogador_turno ? "X" : "Y"))) {
            nova_partida.imprime();
            nova_partida.verificar_vencedor();
            jogador_turno = !jogador_turno; // Troca de turno
        }
    }

    if (nova_partida.get_status() == 'v') {
        std::cout << "O jogador " << (!jogador_turno ? this->get_apl1() : this->get_apl2()) << " venceu!" << std::endl;
        // Jogador V, P;
        // V.set_informacoes((!jogador_turno ? this->get_apl1() : this->get_apl2()), true, _t_jogo);
        // V.mudar_estatistica_atual();
        // P.set_informacoes((jogador_turno ? this->get_apl1() : this->get_apl2()), false, _t_jogo);
        // P.mudar_estatistica_atual();
    } else if (nova_partida.get_status() == 'e') {
        std::cout << "Empate! Não gera pontos." << std::endl;
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
