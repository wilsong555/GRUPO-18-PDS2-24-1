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

<<<<<<< HEAD
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
		string input; // Declara√ß√£o da vari√°vel 'input'
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
    Lig4 lig4(6, 7); // Tabuleiro padr√£o de 6 linhas e 7 colunas
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
=======
int listar_opcoes_menu_inicial() {

   
    int escolha;
    while(true) {
        cout << "--------MENU--------" << endl;
        cout << "(1) - Cadastrar jogador" << endl;
        cout << "(2) - Remover jogador" << endl;
        cout << "(3) - Listar jogadores" << endl;
        cout << "(4) - ComeÁar partida" << endl;
        cout << "(5) - Fechar sistema" << endl;
        cout << "Escolha uma das opÁıes: ";
>>>>>>> 6d0f8e66beb28406cb9ac6967290f1c0f7dcbdb1
        cin >> escolha;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nEntrada inv·lida." << endl;
        } else if (escolha < 1 || escolha > 5) {
            cout << "\nValor inv·lido. Digite um n˙mero de 1 a 5 de acordo com as opÁıes." << endl;
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
            cout << "Caractere inv·lido. Tente novamente" << endl;
        } else if (escolha_atribuida != opc1 && escolha_atribuida != opc2) {
            cout << "OpÁ„o inv·lida. Tente novamente" << endl;
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
<<<<<<< HEAD
        else if (escolha == "RJ") {
         
            cout << "Digite o apelido do jogador: ";
            cin >> apelido;
            if(novo_cadastro.remover_jogador(apelido)) {
                cout << "Jogador removido com sucesso!!!" << endl;
=======
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

            cout << "--------InformaÁıes do jogador 1---------" << endl;
            cout << "Digite o nome e o apelido: ";
            cin >> nome1 >> apl1;
            if (!Jogador::verificar_jogador(nome1, apl1, mensagem_retorno)) {
                erro_atribuicao = true;
                cout << mensagem_retorno << endl;
            }
            if (contraIA == 'N') {
                cout << "--------InformaÁıes do jogador 2---------" << endl;
                cout << "Digite o nome e o apelido: ";
                cin >> nome2 >> apl2;
                if (!Jogador::verificar_jogador(nome2, apl2, mensagem_retorno)) {
                    erro_atribuicao = true;
                    cout << mensagem_retorno << endl;
                }
>>>>>>> 6d0f8e66beb28406cb9ac6967290f1c0f7dcbdb1
            }
            else {
                apl2 = "IA";
            }
<<<<<<< HEAD
        }
        else if (escolha == "LJ") {
            Cadastro::listar_jogadores();
        }
        else if (escolha == "EP") {
            string apl1, nome1, apl2, nome2, jogo;
    
        cout << "Digite L para Lig4 ou R para Reversi: ";
        cin >> jogo;
        for (char& l : jogo) {
           l = toupper(l); // Ajustado para converter 'jogo' para mai√∫sculas
       }
       /*if (jogo == "L" || jogo == "R") {
            cout << "Digite o apelido do jogador 1: ";
            cin >> apl1;
            Jogador jogador1 = cadastro.verificar_jogador(apl1);
            if (jogador1 == nullptr) {
                cout << "Jogador 1 n√£o encontrado." << endl;
                return 1;
            }
            nome1 = jogador1.nome;

            cout << "Digite o apelido do jogador 2: ";
            cin >> apl2;
            Jogador jogador2 = cadastro.verificar_jogador(apl2);
            if (jogador2 == nullptr) {
                cout << "Jogador 2 n√£o encontrado." << endl;
                return 1;
            }
            nome2 = jogador2.nome;

            cout << "Iniciando partida entre " << apl1 << " (" << nome1 << ") e " << apl2 << " (" << nome2 << ") no jogo ";


        if (jogo == "L") {
        // L√≥gica para iniciar uma partida de Lig4
       } else if (jogo == "R") {
        // L√≥gica para iniciar uma partida de Reversi
       } else {
        cout << "Escolha inv√°lida!" << endl;
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
=======
            
            if (erro_atribuicao == false) {
            Partida nova_partida(jogo, apl1, apl2, contraIA);
            nova_partida.iniciar_jogo();

            } else { cout << "Erro. Tente novamente" << endl; }
        }  
        else if (escolha == 5) {
            return 0;
        }
    }
>>>>>>> 6d0f8e66beb28406cb9ac6967290f1c0f7dcbdb1
    return 0;
}