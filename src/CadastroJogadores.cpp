#include "../include/CadastroJogadores.hpp"

// ------------------------------ Informações pessoais -------------------------

vector<Informacoes_pessoais> LerArquivo(const string &nome_arquivo) { 
  ifstream arquivo(nome_arquivo, ios::in);
  vector<Informacoes_pessoais> dados;
  string nome, apelido, reversi, lig4, residuo;
  if (!arquivo.is_open()) {
    cerr << "Erro na abertura do arquivo" << endl;
  }
  else {
    while (arquivo >> apelido >> nome) {
      getline(arquivo, residuo);
      getline(arquivo, reversi);
      getline(arquivo, lig4);
      dados.push_back({apelido, nome, reversi, lig4});
    }
    arquivo.close();
  }
  return dados;
}

string normalizar(const string &str_p_modificar) {
  string nova_versao;
  for (char c : str_p_modificar) {
    nova_versao.push_back(tolower(c));
  }
  return nova_versao;
}

bool compararApelido(const Informacoes_pessoais &a, const Informacoes_pessoais &b) {
  return normalizar(a._apelido) < normalizar(b._apelido);
}

bool compararNome(const Informacoes_pessoais &a, const Informacoes_pessoais &b) {
  return normalizar(a._nome) < normalizar(b._nome);
}

//-----------------------------Tratamento de exceções---------------------------

char tipo_ordernacao() {
  char ordem_escolhida;
  while(true) {
    cout << "(N) - ordenar por nome. \n(A) - ordenar por apelido. \nDigite uma das opções acima: ";
    cin >> ordem_escolhida;
    ordem_escolhida = toupper(ordem_escolhida);
    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Entrada inválida. Digite uma letra." << endl;
    } else if (ordem_escolhida != 'N' && ordem_escolhida != 'A') {
      cout << "Valor inválido! Tente novamente." << endl;
    } else {
      break;
    }
  }
  return ordem_escolhida;
}

//-----------------------------Gerenciamento de Jogadores------------------------

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

string Gerenciamento_Jogadores::adicionar_jogadores(string nome, string apelido) {
  if (!_arquivo.is_open()) {
    return "Erro ao abrir arquivo";
  }
  //reposicionando o ponteiro
  _arquivo.clear();
  _arquivo.seekg(0, ios::beg);

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

  _arquivo.close();
  _arquivo.open(_nome_arquivo, ios::in | ios::out | ios::app);

  return "O jogador " + apelido + " foi cadastrado";
}

string Gerenciamento_Jogadores::remover_jogador(const std::string &apelido) {
    bool apl_encontrado = false;
    
    fstream arquivo_temporario("arq_temp.txt", ios::out);
    if (!_arquivo.is_open() || !arquivo_temporario.is_open()) { 
        return "Erro na abertura do arquivo";
    }
    _arquivo.clear();
    _arquivo.seekg(0, ios::beg);

    string leitura_linha, procura_apl;
    while (getline(_arquivo, leitura_linha)) {
        stringstream leitura_frase(leitura_linha);
        leitura_frase >> procura_apl;
        if (procura_apl != apelido) {
            arquivo_temporario << leitura_linha << std::endl;
        } else {
            apl_encontrado = true;
            getline(_arquivo, leitura_linha); // ignora reversi
            getline(_arquivo, leitura_linha); // ignora lig4
        }
    }

    _arquivo.close();
    arquivo_temporario.close();

    if (apl_encontrado) {
        // Remover o arquivo original e renomear o temporário
        if (remove(_nome_arquivo.c_str()) != 0 || rename("arq_temp.txt", _nome_arquivo.c_str()) != 0) {
            return "Erro ao atualizar o arquivo original.";
        }
        // Reabrir o arquivo original
        _arquivo.open(_nome_arquivo, ios::in | ios::out | ios::app);
        if (!_arquivo.is_open()) { 
            return "Erro ao reabrir o arquivo original.";
        }
        return "O jogador " + apelido + " foi removido";
    } else {
        // Arquivo temporário foi criado mas não precisamos mais dele
        remove("arq_temp.txt");
        _arquivo.open(_nome_arquivo, ios::in | ios::out | ios::app);
        if (!_arquivo.is_open()) { 
            return "Erro ao reabrir o arquivo original.";
        }
        return "O jogador não existe";
    }
}

void Gerenciamento_Jogadores::listar_jogadores() const {
  char ordem;
  try {
    ordem = tipo_ordernacao();
  } catch (const runtime_error &e) {
    cout << "Erro: " << e.what() << endl;
  } catch (...) {
    cout << "Erro desconhecido" << endl;
  }
  vector<Informacoes_pessoais> jogadores = LerArquivo(this->_nome_arquivo);
  if (ordem == 'A') {
    sort(jogadores.begin(), jogadores.end(), compararApelido);
  }
  else if (ordem == 'N') {
    sort(jogadores.begin(), jogadores.end(), compararNome);
  }
  
  for (const auto &jogador : jogadores) {
      cout << "-----------------------------" << endl;
      cout << jogador._apelido << " " << jogador._nome << endl;
      cout << jogador._Reversi << endl;
      cout << jogador._Lig4 << endl;
  }
}
