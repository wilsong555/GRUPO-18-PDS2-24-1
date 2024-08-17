#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include "../include/CadastroJogadores.hpp"
#include "../include/Partida.hpp"
#include "../include/Jogo.hpp"


using namespace std;

int listar_opcoes_menu_inicial() {

   
    int escolha;
    while(true) {
        cout << "--------MENU--------" << endl;
        cout << "(1) - Cadastrar jogador" << endl;
        cout << "(2) - Remover jogador" << endl;
        cout << "(3) - Listar jogadores" << endl;
        cout << "(4) - Começar partida" << endl;
        cout << "(5) - Fechar sistema" << endl;
        cout << "Escolha uma das opções: ";
        cin >> escolha;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nEntrada inválida." << endl;
        } else if (escolha < 1 || escolha > 5) {
            cout << "\nValor inválido. Digite um número de 1 a 5 de acordo com as opções." << endl;
        } else {
            break;
        }
    }
    return escolha;
}

char atribuir_char(string mensagem_cout, char opc1, char opc2) {
    char escolha_atribuida;
    while (true) {
        cout << mensagem_cout;
        cin >> escolha_atribuida;
        escolha_atribuida = toupper(escolha_atribuida);
        if (!isalpha(escolha_atribuida)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Caractere inválido. Tente novamente" << endl;
        } else if (escolha_atribuida != opc1 && escolha_atribuida != opc2) {
            cout << "Opção inválida. Tente novamente" << endl;
        } else {
            break;
        }
    }
    return escolha_atribuida;
}

int main() {
     setlocale(LC_ALL, "Portuguese");
    int escolha;
    string nome, apelido;
    string mensagem_retorno;
    Gerenciamento_Jogadores gerenciador("estatisticas.txt");
    
    while (true) {
        escolha = listar_opcoes_menu_inicial();
        if (escolha == 1) {
            cout << "Digite o nome e o apelido do novo jogador: ";
            cin >> nome >> apelido;
            cout << gerenciador.adicionar_jogadores(nome, apelido) << endl;
        }
        else if (escolha == 2) {
            cout << "Digite o apelido do jogador: ";
            cin >> apelido;
            cout << gerenciador.remover_jogador(apelido) << endl;
        }
        else if (escolha == 3) {
            gerenciador.listar_jogadores();
        }
        else if (escolha == 4) {
            string apl1, nome1, apl2, nome2, mensagem;
            char jogo, contraIA;
            bool erro_atribuicao = false;

            mensagem = "Digite L para Lig4 ou R para Reversi: ";
            jogo = atribuir_char(mensagem, 'R', 'L');
            
            mensagem = "Deseja jogar contra a IA? (S/N): ";
            contraIA = atribuir_char(mensagem, 'S', 'N');

            cout << "--------Informações do jogador 1---------" << endl;
            cout << "Digite o nome e o apelido: ";
            cin >> nome1 >> apl1;
            if (!Jogador::verificar_jogador(nome1, apl1, mensagem_retorno)) {
                erro_atribuicao = true;
                cout << mensagem_retorno << endl;
            }
            if (contraIA == 'N') {
                cout << "--------Informações do jogador 2---------" << endl;
                cout << "Digite o nome e o apelido: ";
                cin >> nome2 >> apl2;
                if (!Jogador::verificar_jogador(nome2, apl2, mensagem_retorno)) {
                    erro_atribuicao = true;
                    cout << mensagem_retorno << endl;
                }
            }
            else {
                apl2 = "IA";
            }
            
            if (erro_atribuicao == false) {
            Partida nova_partida(jogo, apl1, apl2, contraIA);
            nova_partida.iniciar_jogo();

            } else { cout << "Erro. Tente novamente" << endl; }
        }  
        else if (escolha == 5) {
            return 0;
        }
    }
    return 0;
}