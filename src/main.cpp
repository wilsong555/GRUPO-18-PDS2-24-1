#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include "../include/CadastroJogadores.hpp"
#include "../include/Jogo.hpp"


using namespace std;

int main() {
    string escolha, nome, apelido;
     int linha, coluna;
     string valor_tabuleiro;
  
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
                Cadastro::remover_jogador();
            }
            else if (escolha == "LJ") {
                Cadastro::listar_jogadores();
            }
            else if (escolha == "FS") {
                return 0;
            }

                 else if (escolha == "T") {
                    cout << "digite  quantidade de lnhas: " << endl;
                    cin >> linha;
                    cout << "agora digite a quntidade de colunas: ";
                    cin >> coluna;

                     Jogo obj(linha, coluna);
                     cout<< "escolha a linha e a coluna desejada :";
                    cin >> linha >> coluna;
                    cout << "Digite X ou O";
                    cin >> valor_tabuleiro;
                    obj.setvalor(linha - 1, coluna - 1 , valor_tabuleiro);
                    obj.imprime();
            
    }

         }
        

    return 0;
}
