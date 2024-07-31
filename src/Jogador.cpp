#include "../include/Jogador.hpp"


int is_num(string &achar_num) {
    int numero;
    for (char c: achar_num) {
        if (!isdigit(c)) {
            return -1;
        }
        numero = stoi(achar_num);
        
    }
    return ++numero;
}

void achar_valor(string linha_p_analisar, vector<int> &add_valor, bool situacao) {
    string achar_num;
    stringstream analise(linha_p_analisar);
    while (getline(analise, achar_num, ' ')) {
        int num = is_num(achar_num);
        if (num != -1) {
            add_valor.push_back(num);
        }
    }
    add_valor[0] = (situacao == true ? add_valor[0] : add_valor[0] - 1);
    add_valor[1] = (situacao == true ? add_valor[1] - 1 : add_valor[1] - 1);
}


Jogador::Jogador() {
    //comentario
}

void Jogador::set_informacoes(string apelido, bool situacao, string t_jogo) {
    this->_apelido = apelido;
    this->_status = situacao;
    this->_jogo_atual = t_jogo;
}

bool Jogador::mudar_estatistica_atual() {
    fstream arquivo_base("estatisticas.txt", ios::in);
    ofstream arquivo_temporario("estat_temp.txt", ios::out);
    if (!arquivo_base.is_open() || !arquivo_temporario.is_open()) {
        cout << "Erro ao abrir arquivo" << endl;
        return false;
    }
    string linha_texto, procura_apelido, procura_num;
    while(getline(arquivo_base, linha_texto)) {
        stringstream leitura(linha_texto);
        leitura >> procura_apelido;
        if (procura_apelido != this->_apelido) {
            arquivo_temporario << linha_texto << endl;
        }
        else {
            vector<int> vetor_valores;
            arquivo_temporario << linha_texto << endl; //coloca a linha de info_nome
            if (this->_jogo_atual == "r") {
                achar_valor(linha_texto, vetor_valores, this->_status);
                arquivo_temporario << "REVERSI - V : " << vetor_valores[0] << " D : " << vetor_valores[1] << endl;
                getline(arquivo_base, linha_texto);
                arquivo_temporario << linha_texto << endl;
            } else if(this->_jogo_atual == "l") {
                getline(arquivo_base, linha_texto);
                arquivo_temporario << linha_texto << endl;
                getline(arquivo_base, linha_texto);
                achar_valor(linha_texto, vetor_valores, this->_status);
                arquivo_temporario << "LIG4 - V: " << vetor_valores[0] << " D : " << vetor_valores[1] << endl;
            }
        }
    }
    arquivo_base.close();
    arquivo_temporario.close();
    remove("estatisticas.txt");
    rename("estat_temp.txt", "estatisticas.txt");
    return true;
}
