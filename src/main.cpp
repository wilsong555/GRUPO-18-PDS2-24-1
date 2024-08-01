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
    cout << "Escolha uma das opções: " << endl;
    cout << "CJ - Cadastrar jogador" << endl;
    cout << "RJ - Remover jogador" << endl;
    cout << "LJ - Listar jogadores" << endl;
    cout << "CP - Começar partida" << endl;
    cout << "FS - Fechar sistema" << endl;
}

int main() {
    string escolha;
    string nome, apelido;
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
            
            cout << "Digite L para Lig4 ou R para Reversi: ";
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
            Partida nova_partida(jogo, apl1, apl2);
            nova_partida.iniciar_jogo();
        }  
        else if (escolha == "FS") {
            return 0;
        }
    }
    //comentario
    return 0;
}
