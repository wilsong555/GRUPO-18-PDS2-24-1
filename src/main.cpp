#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include "../include/CadastroJogadores.hpp"
#include "../include/Partida.hpp"
#include "../include/Jogo.hpp"


using namespace std;

int main() {
    string escolha;
    string nome, apelido;
    Cadastro novo_cadastro;
    while (escolha != "FS") {
        cout << "Faca a escolha" << endl;
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
                cout << "Jogador removido com sucesso" << endl;
            }
            else {
                cout << "Jogador não encontrado" << endl;
            }
        }
        else if (escolha == "LJ") {
            Cadastro::listar_jogadores();
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
            if (novo_cadastro.verificar_jogador(nome1, apl1) && novo_cadastro.verificar_jogador(nome2, apl2)) {
                Partida nova_partida(jogo, apl1, apl2);
                nova_partida.iniciar_jogo();
            }
        }  
        else if (escolha == "FS") {
            return 0;
        }
    }
    return 0;
}
