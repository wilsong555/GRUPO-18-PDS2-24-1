#include "../include/CadastroJogadores.hpp"

Gerenciamento_Jogadores::Gerenciamento_Jogadores(const string &nome_arquivo) {
  _nome_arquivo = nome_arquivo;
  _arquivo.open(_nome_arquivo, ios::in | ios::out | ios::app);
  if (!_arquivo.is_open()) {
    cout << "Erro ao abrir o arquivo!" << endl;
  }
}

Gerenciamento_Jogadores::~Gerenciamento_Jogadores() {
  if (_arquivo.is_open()) {
    _arquivo.close();
  }
}

bool Gerenciamento_Jogadores::procura_string(const string &apelido, string &mensagem) {
  if (_arquivo.is_open()) {
    string linhas_texto, procura_apl;
    while (getline(_arquivo, linhas_texto)) {
      stringstream info(linhas_texto);
      info >> procura_apl;
      if (procura_apl == apelido) {
        mensagem = "O jogador " + apelido + " já está cadastrado";
        return true; // jogador já existe
      }
    }
  }
  else {
     mensagem = "Erro de abertura no arquivo";
     return false;
   }
   mensagem = "Jogador não cadastrado";
   return false; // jogador não existe
}

string Gerenciamento_Jogadores::adicionar_jogadores(string nome, string apelido) {
  if (!_arquivo.is_open()) {
    return "Erro ao abrir arquivo";
  }
  string leitura_linha, procura_apl;
  while (getline(_arquivo, leitura_linha)) {
    stringstream leitura_frase(leitura_linha);
    leitura_frase >> procura_apl;
    if (procura_apl == apelido) {
      return "Jogador já cadastrado";
    }
  }
  _arquivo.clear(); // Limpa qualquer flag de erro
  _arquivo.seekp(0, std::ios::end);
  _arquivo << apelido << " " << nome << endl;
  _arquivo << "REVERSI - V: 0 D: 0" << endl;
  _arquivo << "LIG4 - V: 0 D: 0" << endl;
  return "O jogador " + apelido + " foi cadastrado";
}

string Gerenciamento_Jogadores::remover_jogador(const std::string &apelido) {
    bool apl_encontrado = false;
    fstream arquivo_temporario("arq_temp.txt", std::ios::out);
    if (!_arquivo.is_open() || !arquivo_temporario.is_open()) { return "Erro na abertura do arquivo";}
    string leitura_linha, procura_apl;
    while (getline(_arquivo, leitura_linha)) {
        stringstream leitura_frase(leitura_linha);
        leitura_frase >> procura_apl;
        if (procura_apl != apelido) {
            arquivo_temporario << leitura_linha << endl;
        } else if (procura_apl == apelido){
          apl_encontrado = true;
          getline(_arquivo, leitura_linha); //ignora reversi
          getline(_arquivo, leitura_linha); //ignora lig4
        }
    }
    arquivo_temporario.close();
    remove(_nome_arquivo.c_str());
    rename("arq_temp.txt", _nome_arquivo.c_str());
    _arquivo.open(_nome_arquivo, ios::in | ios::out | ios::app);
    if (!_arquivo.is_open()) { return "Erro ao reabrir o arquivo original.";}
    if (apl_encontrado) { return "O jogador " + apelido + " foi removido";}
    return "O jogador não existe";
}

// string Gerenciamento_Jogadores::remover_jogador(const string &apelido) {
//   string mensagem_retorno;
//   if (!procura_string(apelido, mensagem_retorno)) {
//     return mensagem_retorno;
//   }
//   string nome_arq_temp = "arq_temp.txt";
//   fstream arquivo_temporario(nome_arq_temp, ios::out);
//   if (!arquivo_temporario.is_open()) {
//     return "Erro de abertura no arquivo";
//   }

//   string leitura_linha, procura_apl;
//   while(getline(_arquivo, leitura_linha)) {
//     stringstream leitura_frase(leitura_linha);
//     leitura_frase >> procura_apl;
//     cout << procura_apl;
//     if (procura_apl != apelido) {
//       cout << procura_apl << endl;
//       arquivo_temporario << leitura_linha << endl;
//     }
//     else {
//       getline(_arquivo, leitura_linha); //apaga reversi
//       getline(_arquivo, leitura_linha); //apaga lig4
//     }
//   }
//   arquivo_temporario.close();
//   remove(_nome_arquivo.c_str());
//   rename(nome_arq_temp.c_str(), _nome_arquivo.c_str());
//   _arquivo.open(_nome_arquivo, ios::in | ios::out | ios::app);
//   return "Jogador " + apelido + " removido com sucesso";
// }


//  bool Cadastro::verificar_jogador(string nome, string apelido) {
//    fstream _arquivo("estatisticas.txt", ios::in);
//    if (_arquivo.is_open()) {
//      string linhas_texto, procura_apl, procura_nom;
//      while (getline(_arquivo, linhas_texto)) {
//        stringstream leitura(linhas_texto);
//        leitura >> procura_apl >> procura_nom;
//        if (procura_apl == apelido && procura_nom == nome) {
//          return true; // jogador já existe
//        }
//        else if (procura_apl == apelido || procura_nom == nome) {
//          cout << "Dados incorretos" << endl;
//          return false; // alguma informação incorreta
//        }
//        else {
//          if (!verificaStrings(apelido)) {
//            return false; // jogador não existe
//          }
//        }
//      }
//    }
//    cout << "Fim da verificação" << endl;
//    return false;
//  }

//  vector<Pessoa> LerArquivo (const string Arq_estatisticas) {
//      ifstream arquivo(Arq_estatisticas);
//      vector<Pessoa> jogadores;
//      string linha;
//      while (getline(arquivo, linha)) {
//          istringstream obj(linha);
//          Pessoa jogador;
//          obj >> jogador.apelido >> jogador.nome;
//          getline (arquivo, jogador.Reversi);
//          getline (arquivo, jogador.Lig4);
//          jogadores.push_back(jogador);
//      }
//      return jogadores;
//  }

//  string toLower(const string &str) {
//    string lowerStr = str;
//    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), [](unsigned char c) { return tolower(c); });
//    return lowerStr;
//  }

//  bool compararNome(const Pessoa &a, const Pessoa &b) {
//  return toLower(a.nome) < toLower(b.nome);
//  }

//  bool compararApelido(const Pessoa &a, const Pessoa &b) {
//  return toLower(a.apelido) < toLower(b.apelido);
//  }

// void Cadastro::listar_jogadores() {
//    cout << "Escolha a ordem (a ou n): ";
//    char ordem;
//    cin >> ordem;
//    string _arquivo = "estatisticas.txt";
//    vector<Pessoa> jogadores = LerArquivo(_arquivo);
//    if (ordem == 'a') {
//        sort(jogadores.begin(), jogadores.end(), compararApelido);
//        for (const auto &jogador : jogadores) {
//          cout << "-----------------------------" << endl;
//          cout << jogador.apelido << " " << jogador.nome << endl;
//          cout << jogador.Reversi << endl;
//          cout << jogador.Lig4 << endl;
//        }
//    }
//    else if (ordem == 'n') {
//        sort(jogadores.begin(), jogadores.end(), compararNome);
//        for (const auto &jogador : jogadores) {
//          cout << "-----------------------------" << endl;
//          cout << jogador.apelido << " " << jogador.nome << endl;
//          cout << jogador.Reversi << endl;
//          cout << jogador.Lig4 << endl;
//        }
//    }
//    cout << "-----------------------------" << endl;
//  }

// ------------------------------------------------------------------------------------------------
