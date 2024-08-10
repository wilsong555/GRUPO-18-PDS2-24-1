#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <stdexcept>
#include <limits>
#include "../include/CadastroJogadores.hpp"
#include "../include/Jogador.hpp"
#include "../include/Partida.hpp"
#include "../include/Jogo.hpp"


using namespace std;

/*void jogarReversi() {
    Tabuleiro tabuleiro;
    Peca jogadorAtual = Peca::Preto;

    while (true) {
        tabuleiro.imprime();

        if (!tabuleiro.temMovimentoValido(jogadorAtual)) {
            cout << "Jogador " << (jogadorAtual == Peca::Preto ? "Preto" : "Branco") << " nao tem movimentos validos. Passando a vez.\n";
            jogadorAtual = (jogadorAtual == Peca::Preto) ? Peca::Branco : Peca::Preto;
            if (!tabuleiro.temMovimentoValido(jogadorAtual)) {
                cout << "Nenhum jogador tem movimentos validos. O jogo acabou.\n";
                break;
            }
        }

        int linha, coluna;
		string input; // Declaração da variável 'input'
        cout << "Jogador " << (jogadorAtual == Peca::Preto ? "Preto" : "Branco") << ", insira sua jogada (linha coluna): ";
        //cin >> linha >> coluna;
        getline(cin, input);

        try {
            stringstream ss(input);
            if (!(ss >> linha) || !(ss >> coluna) || !ss.eof()) {
                throw invalid_argument("Formato de entrada invalido. Use o formato 'linha coluna'.");
            }

            if (linha < 1 || linha > 8 || coluna < 1 || coluna > 8) {
                throw out_of_range("Os valores de linha e coluna devem estar entre 1 e 8.");
            }

        linha -= 1;
        coluna -= 1;

        if (tabuleiro.movimentoValido(linha, coluna, jogadorAtual)) {
            tabuleiro.aplicarMovimento(linha, coluna, jogadorAtual);
            jogadorAtual = (jogadorAtual == Peca::Preto) ? Peca::Branco : Peca::Preto;
        } else {
            cout << "Movimento invalido. Tente novamente.\n";
        }
		} catch (const invalid_argument& e) {
            cout << "Entrada invalida: " << e.what() << "\n";
        } catch (const out_of_range& e) {
            cout << "Entrada fora do intervalo: " << e.what() << "\n";
        }
    }

    tabuleiro.verificar_vencedor();
}

void jogarLig4() {
    Lig4 lig4(6, 7); // Tabuleiro padrão de 6 linhas e 7 colunas
    string jogadorAtual = "X";

    while (lig4.get_status() == 'i') {
        lig4.imprime();

        int coluna;
        cout << "Jogador " << jogadorAtual << ", escolha uma coluna (0-6): ";
        cin >> coluna;

        if (lig4.jogar(coluna, jogadorAtual)) {
            lig4.verificar_vencedor();
            jogadorAtual = (jogadorAtual == "X") ? "O" : "X";
        } else {
            cout << "Jogada invalida. Tente novamente.\n";
        }
    }

    lig4.imprime();
    if (lig4.get_status() == 'v') {
        cout << "Jogador " << (jogadorAtual == "X" ? "O" : "X") << " venceu!\n";
    } else if (lig4.get_status() == 'e') {
        cout << "O jogo terminou empatado!\n";
    }
}

int main() {
    int escolha;
    cout << "Escolha um jogo:\n";
    cout << "1. Reversi\n";
    cout << "2. Lig4\n";
    cout << "Digite 1 ou 2: ";
    cin >> escolha;

    if (escolha == 1) {
        jogarReversi();
    } else if (escolha == 2) {
        jogarLig4();
    } else {
        cout << "Escolha invalida.\n";
    }

    return 0;
}*/
void showMenu() {
    cout << endl <<"  Comandos disponiveis:" << endl;
    cout << "  ----------------------"<< endl;
    cout << " 'CJ' <Apelido> <Nome> - Cadastrar Jogador" <<endl;
    cout << " 'RJ' <Apelido> - Remover Jogador" << endl;
    cout << " 'LJ' [A|N] - Listar Jogadores (A: Ordenar por Apelido, N: Ordenar por Nome)" << endl;
    cout << " 'EP' <Jogo: (R|L)> <Apelido Jogador 1> <Apelido Jogador 2> - Executar Partida" << endl;
    cout << " 'FS' - Finalizar Sistema" << endl;
}


int main() {
    showMenu();
    string escolha;
    string nome, apelido;
    Cadastro novo_cadastro;
    while (escolha != "FS") {
        cout << endl << "Faca a escolha:" << endl;
        cin >> escolha;
        for (char& l : escolha) {
            l = toupper(l);
        }
        if (escolha == "CJ") {
            cout << "Digite o nome e o apelido: ";
            cin >> nome >> apelido;
            cout << novo_cadastro.adicionar_jogador(nome, apelido) << endl;
        }
        else if (escolha == "RJ") {
         
            cout << "Digite o apelido do jogador: ";
            cin >> apelido;
            if(novo_cadastro.remover_jogador(apelido)) {
                cout << "Jogador removido com sucesso!!!" << endl;
            }
            else {
                cout << "Jogador não encontrado" << endl;
            }
        }
        else if (escolha == "LJ") {
            Cadastro::listar_jogadores();
        }
        else if (escolha == "EP") {
            string apl1, nome1, apl2, nome2, jogo;
    
        cout << "Digite L para Lig4 ou R para Reversi: ";
        cin >> jogo;
        for (char& l : jogo) {
           l = toupper(l); // Ajustado para converter 'jogo' para maiúsculas
       }
       /*if (jogo == "L" || jogo == "R") {
            cout << "Digite o apelido do jogador 1: ";
            cin >> apl1;
            Jogador jogador1 = cadastro.verificar_jogador(apl1);
            if (jogador1 == nullptr) {
                cout << "Jogador 1 não encontrado." << endl;
                return 1;
            }
            nome1 = jogador1.nome;

            cout << "Digite o apelido do jogador 2: ";
            cin >> apl2;
            Jogador jogador2 = cadastro.verificar_jogador(apl2);
            if (jogador2 == nullptr) {
                cout << "Jogador 2 não encontrado." << endl;
                return 1;
            }
            nome2 = jogador2.nome;

            cout << "Iniciando partida entre " << apl1 << " (" << nome1 << ") e " << apl2 << " (" << nome2 << ") no jogo ";


        if (jogo == "L") {
        // Lógica para iniciar uma partida de Lig4
       } else if (jogo == "R") {
        // Lógica para iniciar uma partida de Reversi
       } else {
        cout << "Escolha inválida!" << endl;
    }


            
           /* cout << "Digite L para Lig4 ou R para Reversi: ";
            cin >> jogo;
            for (char& l : escolha) {
            l = toupper(l);
            }
            // cout << "Digite o nick e o nome do jogador 1: " << endl;
            // cin >> apl1 >> nome1;
            // cout << "Digite o nick e nome do jogador 2: " << endl;
            // cin >> apl2 >> nome2;
            apl1 = "Lua";
            nome1 = "Luana";
            apl2 = "opio";
            nome2 = "Marcos";
            if (novo_cadastro.verificar_jogador(nome1, apl1) && novo_cadastro.verificar_jogador(nome2, apl2)) {
                Partida nova_partida(jogo, apl1, apl2);
                nova_partida.iniciar_jogo();
            }*/
        }
        else if (escolha == "FS") {
            return 0;
        }
    }

  
    //comentario
    return 0;
}