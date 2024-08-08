#include "../include/Partida.hpp"
#include "../include/IA.hpp"
#include <limits>

void Partida::iniciar_jogo() { 
  //inicialização de variaveis gerais
  char escolha_padrao;
  int n_linha, n_coluna;

  //jogo LIG4
    if (_t_jogo == 'L') { 

        while (true) {
            cout << "Deseja o tabuleiro padrão(6x7)? (S/N): ";
            cin >> escolha_padrao;
            escolha_padrao = toupper(escolha_padrao);
            if (!isalpha(escolha_padrao)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Caractere inválido. Tente novamente" << endl;
            } else if (escolha_padrao != 'S' && escolha_padrao != 'N') {
                cout << "Opção inválida. Tente novamente" << endl;
            } else {
                break;
            }
        }

        if (escolha_padrao == 'N') {
            cout << "Nº de linhas - ";
            n_linha = tratamento_num(4, 20);
            cout << "Nº de colunas - ";
            n_coluna = tratamento_num(4, 20);
            cout << endl;
        } else {
            n_linha = 6;
            n_coluna = 7;
        }

        Lig4 nova_partida(n_linha, n_coluna);
        if (this->_contraIA == 'S') {
            partida_lig4_IA(nova_partida);
        }
        else {
            partida_lig4(nova_partida);
        }
    }
  else if (_t_jogo == 'R') {
    //precisa definir se vai ter tabuleiro personalizado aqui
    //precisa definir como funciona a função com ia aqui (caso use a mesma função para ambos os casos desconsiderar)
    partida_reversi();
  }
}

void Partida::partida_lig4_IA(Lig4 nova_partida) {
    bool jogador_turno = true;
    string vencedor;
    int coluna;
    nova_partida.set_status('i');
    IA ia("X", "Y"); // Definindo a IA como jogador 2

    while(nova_partida.get_status() == 'i') {
        if (jogador_turno) {
            try {
                cout << "Turno de jogador " << this->get_apl1() << ". Escolha a coluna para jogar. ";
                coluna = tratamento_num(1 ,nova_partida.get_colunas());
            } catch (const runtime_error& e) {
                cout << "Erro: " << e.what() << endl;
            } catch (...) {
                cout << "Erro desconhecido." << endl;
            }
            coluna--;
        }
        else {
            coluna = ia.encontrarMelhorJogada(nova_partida);
            cout << "IA jogou na coluna " << coluna + 1 << endl;
        }
        if (nova_partida.jogar(coluna, (jogador_turno ? "X" : "Y"))) {
            nova_partida.imprime();
            nova_partida.verificar_vencedor();
            jogador_turno = !jogador_turno; // Troca de turno
        }
        else {
            cout << "Problema na hora de jogar" << endl;
        }
    }

    if (nova_partida.get_status() == 'v') {
        if (!jogador_turno == true) { //o ultimo jogador a jogar for o 1 - humano
            cout << "O jogador " << this->get_apl1() << " venceu!" << endl;
            Jogador V;
            V.set_informacoes(this->get_apl1(), true, _t_jogo);
            V.mudar_estatistica_atual();
        }
        else {
            cout << "A maquina venceu o jogo" << endl;
            Jogador D;
            D.set_informacoes(this->get_apl1(), false, _t_jogo);
            D.mudar_estatistica_atual();
        }
    }
    if (nova_partida.get_status() == 'e') {
        cout << "Empates não geram pontos" << endl;
    }
}

void Partida::partida_lig4(Lig4 nova_partida) {
    bool jogador_turno = true; // Jogador 1 é true, jogador 2 é false
    int coluna;
    nova_partida.set_status('i');

    
    while (nova_partida.get_status() == 'i') {
            try {
                cout << "Turno de jogador " << this->get_apl1() << ". Escolha a coluna para jogar. ";
                coluna = tratamento_num(1, nova_partida.get_colunas());
            } catch (const runtime_error& e) {
                cout << "Erro: " << e.what() << endl;
            } catch (...) {
                cout << "Erro desconhecido." << endl;
            }
            coluna--;

        if (nova_partida.jogar(coluna, (jogador_turno ? "X" : "Y"))) {
            nova_partida.imprime();
            nova_partida.verificar_vencedor();
            jogador_turno = !jogador_turno; // Troca de turno
        }
    }
    if (nova_partida.get_status() == 'v') { // onde faz a mudança de estatisticas

        cout << "O jogador " << (!jogador_turno ? this->get_apl1() : this->get_apl2()) << " venceu!" << endl;
        Jogador V, P;
        V.set_informacoes((!jogador_turno ? this->get_apl1() : this->get_apl2()), true, _t_jogo);
        V.mudar_estatistica_atual();
        P.set_informacoes((jogador_turno ? this->get_apl1() : this->get_apl2()), false, _t_jogo);
        P.mudar_estatistica_atual();

    } else if (nova_partida.get_status() == 'e') {
        cout << "Empate! Não gera pontos." << std::endl;
    }
}

/*vou tentar conectar as funções de mudancas de estatisticas aqui, caso queira colocar de outra forma pode ficar a vontade*/

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

int Partida::tratamento_num(int min, int max) {
    int valor;
    while (true) {
        cout << "Digite um valor de " << min << " a " << max << " : ";
        cin >> valor;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Digite um valor inteiro." << endl;
        }
        else if (valor < min || valor > max) {
            cout << "Número fora do intervalo permitido. Tente novamente." << endl;
        }
        else {
            break;
        }
    }
    return valor;
}