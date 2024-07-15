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
    //  int linha, coluna;
    //  string valor_tabuleiro = "1";
    // Tabuleiro obj(linha, coluna);
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

    //              else if (escolha == "T") {
    //                 cout << "digite a lnha" << endl;
    //                 cin >> linha;
    //                 cout << "agora digite a coluna";
    //                 cin >> coluna;
    //                   if (linha <= 0 || coluna <= 0 || linha > 1000 || coluna > 1000) { // Limite arbitrário para evitar problemas
    //     cout << "Erro: Linhas e colunas devem ser maiores que zero e menores que 1000." << endl;
    //     return 1;
    // }

    //                  cout<< "escolha a linha e a coluna :";
    //                 cin >> linha >> coluna;
    //                 obj.setvalor(linha, coluna , valor_tabuleiro);
    //                 obj.imprime();
            
    // }

         }
        

    return 0;
}
