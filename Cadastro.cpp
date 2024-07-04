#include "Cadastro.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

bool VerificaStrings(const string apelido) { //verifica se um apelido já está cadastrado
    string arq_txt = "estatisticas.txt";
    ifstream arquivo(arq_txt);
    if (arquivo.is_open()) {
        string linha;
        string procura;
        while (getline(arquivo, linha)) {
            stringstream ss(linha);
            ss >> procura;
            if (procura == apelido) {
                arquivo.close();
                return false; //jogador já existe
            }
        }
    }
    return true; //jogador não existe
}

Cadastro::Cadastro() {
    string apelido, nome;
    string arq_txt = "estatisticas.txt";
    ofstream file(arq_txt, ios::app); //abre o arquivo para escrita sempre com o ponteiro no fim do arquivo
    if (file.is_open()) {
        cout << "Digite os dados: " << endl;
        cin >> apelido >> nome;
        bool verifica = VerificaStrings(apelido); //verifica se o apelido já existe
        if (verifica == true) {
            _rev_vitoria = 0;
            _rev_derrota = 0;
            _lig_vitoria = 0;
            _lig_derrota = 0;
            file << apelido << " " << nome << endl; //adiciona o jogador
            file << "REVERSI - V: " << _rev_vitoria << " D: " << _rev_derrota << endl;
            file << "LIG4 - V:" << _lig_vitoria << " D:" << _lig_derrota << endl;
            cout << "Jogador " << apelido << " cadastrado com sucesso" << endl;
        }
        else {
            cout << "jogador repetido" << endl;
        }
    }
    file.close(); 
} //implementação completa

void Cadastro::remover_jogador() {
    string apelido; 
    string remocao_apelido; 
    bool jogador = false; //determina se o apelido foi encontrado
    string linha; //usada para leitura do arquivo
    
    string arq_txt = "estatisticas.txt";
    string arq_temporario = "temp.txt";
    ifstream arquivo(arq_txt); //abertura do arquivo principal pra leitura
    ofstream temp(arq_temporario); //abertura do arquivo temporário pra escrita
    
    if (arquivo.is_open() && temp.is_open()) {
        cout << "Digite o apelido: ";
        cin >> apelido;
        while (getline(arquivo, linha)) { //leitura do arquivo principal
            stringstream ss(linha); //cria um fluxo de string
            ss >> remocao_apelido; //armazena a primeira palavra (apelido) da linha atual
            if (linha.find(apelido) == string::npos) { // linha não contem o apelido digitado
                temp << linha << endl;
            }
            else { //linha contem o apelido digitado
                jogador = true;
                getline(arquivo, linha); //apaga a linha do reversi
                getline(arquivo, linha); //apaga a linha do lig4
                cout << "Jogador " << apelido << " removido com sucesso" << endl;
            }
        }
    }
    if (jogador == false) {
        cout << "Jogador inexistente" << endl;
    }
    arquivo.close();
    temp.close();
    remove(arq_txt.c_str()); //remove o arquivo principal
    rename(arq_temporario.c_str(), arq_txt.c_str()); //renomeia o arquivo temporário com o nome do principal
} // implementação completa

vector<Jogador> LerArquivo (const string Arq_estatisticas) {
    ifstream arquivo(Arq_estatisticas);
    vector<Jogador> jogadores;
    string linha;
    while (getline(arquivo, linha)) {
        istringstream iss(linha);
        Jogador jogador;
        iss >> jogador.apelido >> jogador.nome;
        getline (arquivo, jogador.Reversi);
        getline (arquivo, jogador.Lig4);
        jogadores.push_back(jogador);
    }
    return jogadores;
}

string toLower(const string &str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), [](unsigned char c) { return tolower(c); });
    return lowerStr;
}

bool compararNome(const Jogador &a, const Jogador &b) {
    return toLower(a.nome) < toLower(b.nome);
}

bool compararApelido(const Jogador &a, const Jogador &b) {
    return toLower(a.apelido) < toLower(b.apelido);
}


void Cadastro::listar_jogadores() {
    cout << "Escolha a ordem: ";
    char ordem;
    cin >> ordem;
    string arq_txt = "estatisticas.txt";
    vector<Jogador> jogadores = LerArquivo(arq_txt);
    if (ordem == 'A') {
        sort(jogadores.begin(), jogadores.end(), compararApelido);
        for (const auto &jogador : jogadores) {
            cout << jogador.apelido << " " << jogador.nome << endl;
            cout << jogador.Reversi << endl;
            cout << jogador.Lig4 << endl;
        }
    }
    else if (ordem == 'N') {
        sort(jogadores.begin(), jogadores.end(), compararNome);
        for (const auto &jogador : jogadores) {
            cout << jogador.apelido << " " << jogador.nome << endl;
            cout << jogador.Reversi << endl;
            cout << jogador.Lig4 << endl;
        }
    }
}   