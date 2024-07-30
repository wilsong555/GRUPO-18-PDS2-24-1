#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include "../include/CadastroJogadores.hpp"
#include "../include/Partida.hpp"
#include "../include/Jogo.hpp"
#include "../include/Reversi.hpp"
#include "../include/Lig4.hpp"

using namespace std;

void jogarReversi() {
    Tabuleiro tabuleiro;
    Peca jogadorAtual = Peca::Preto;

    while (true) {
        tabuleiro.exibir();

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

    tabuleiro.imprimirVencedor();
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
}

