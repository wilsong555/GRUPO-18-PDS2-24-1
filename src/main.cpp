#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include "../include/CadastroJogadores.hpp"
#include "../include/Partida.hpp"
#include "../include/Jogo.hpp"


using namespace std;

void listar_opcoes_menu_inicial() {
    cout << "--------MENU--------" << endl;
    cout << "CJ - Cadastrar jogador" << endl;
    cout << "RJ - Remover jogador" << endl;
    cout << "LJ - Listar jogadores" << endl;
    cout << "CP - Começar partida" << endl;
    cout << "FS - Fechar sistema" << endl;
    cout << "Escolha uma das opções: ";
}

int main() {
    string escolha;
    string nome, apelido;
    string mensagem_retorno;
    Gerenciamento_Jogadores gerenciador("estatisticas.txt");
    while (escolha != "FS") {
        listar_opcoes_menu_inicial();
        cin >> escolha;
        for (char& l : escolha) {
            l = toupper(l);
        }
        if (escolha == "CJ") {
            cout << "Digite o nome e o apelido: ";
            cin >> nome >> apelido;
            cout << gerenciador.adicionar_jogadores(nome, apelido) << endl;
        }
        else if (escolha == "RJ") {
            cout << "Digite o apelido do jogador: ";
            cin >> apelido;
            cout << gerenciador.remover_jogador(apelido) << endl;
        }
        else if (escolha == "LJ") {
            //Cadastro::listar_jogadores();
        }
        else if (escolha == "CP") {
            string apl1, nome1, apl2, nome2, jogo;
            bool erro_atribuicao = false;
            cout << "Digite L para Lig4 ou R para Reversi: ";
            cin >> jogo;
            for (char& l : jogo) {
            l = toupper(l);
            }
            cout << "Digite o nick e o nome do jogador 1: ";
            cin >> apl1 >> nome1;
            if (!Jogador::verificar_jogador(nome1, apl1, mensagem_retorno)) {
                erro_atribuicao = true;
                cout << mensagem_retorno << endl;
            }
            cout << "Digite o nick e nome do jogador 2: ";
            cin >> apl2 >> nome2;
            if (!Jogador::verificar_jogador(nome2, apl2, mensagem_retorno)) {
                erro_atribuicao = true;
                cout << mensagem_retorno << endl;
            }
            if (erro_atribuicao == false) {
            Partida nova_partida(jogo, apl1, apl2);
            nova_partida.iniciar_jogo();
            } else { cout << "Erro. Tente novamente" << endl; }
        }  
        else if (escolha == "FS") {
            return 0;
        }
    }
    //comentario
    return 0;
}