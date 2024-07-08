#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include "Cadastro.hpp"

using namespace std;

int main() {
    string escolha, nome, apelido;
    while (escolha != "FS") {
            cout << "Faca a escolha" << endl;
            cin >> escolha;
            for (char& l : escolha) {
                l = toupper(l);
            }
            if (escolha == "CJ") {
                Cadastro();
            }
            else if (escolha == "RJ") {
                cout << "Vou remover um jogador" << endl;
                Cadastro::remover_jogador();
            }
            else if (escolha == "LJ") {
                Cadastro::listar_jogadores();
            }
            else if (escolha == "FS") {
                return 0;
            }
        
    }
    return 0;
}
