/*#include "../include/CadastroJogadores.hpp"

 bool Cadastro::verificaStrings(const string &apelido) {
   fstream arquivo_base("estatisticas.txt", ios::in);
   if (arquivo_base.is_open()) {
     string linhas_texto, procura_apl;
     while (getline(arquivo_base, linhas_texto)) {
         stringstream info(linhas_texto);
         info >> procura_apl;
         if (procura_apl == apelido) {
             return true; // jogador já existe
         }
     }
   }
   arquivo_base.close();
   return false; // jogador não existe
 }

 Cadastro::Cadastro() {
   //inicialização de obj
 }

 string Cadastro::adicionar_jogador(string nome, string apelido) {
   if(verificaStrings(apelido)) {
     return "Jogador já existe";
   }
   ofstream arquivo_base( "estatisticas.txt", ios::app);
   if (!arquivo_base.is_open()) {
     return "Erro ao abrir arquivo";
   }
   arquivo_base << apelido << " " << nome << endl;
   arquivo_base << "REVERSI - V: 0 D: 0" << endl;
   arquivo_base << "LIG4 - V: 0 D: 0" << endl;
   arquivo_base.close();
   return "Jogador cadastrado com sucesso";
 }

 bool Cadastro::remover_jogador(string apelido) {
   if(!verificaStrings(apelido)) {
     return false; // jogador não existe
   }
   fstream arquivo_base("estatisticas.txt", ios::in);
   fstream arquivo_temporario("temp.txt", ios::app);
   if (arquivo_base.is_open() && arquivo_temporario.is_open()) {
     string linhas_texto, procura_apl;
     while (getline(arquivo_base, linhas_texto)) {
       stringstream leitura(linhas_texto);
       leitura >> procura_apl;
       if (procura_apl != apelido) {
         arquivo_temporario << linhas_texto << endl;
       }
       else {
         getline(arquivo_base, linhas_texto); //apaga reversi
         getline(arquivo_base, linhas_texto); //apaga lig4
       }
     }
   }
   arquivo_base.close();
   arquivo_temporario.close();
   remove("estatisticas.txt");
   rename("temp.txt", "estatisticas.txt");
   return true;
 }

 bool Cadastro::verificar_jogador(string nome, string apelido) {
   fstream arquivo_base("estatisticas.txt", ios::in);
   if (arquivo_base.is_open()) {
     string linhas_texto, procura_apl, procura_nom;
     while (getline(arquivo_base, linhas_texto)) {
       stringstream leitura(linhas_texto);
       leitura >> procura_apl >> procura_nom;
       if (procura_apl == apelido && procura_nom == nome) {
         return true; // jogador já existe
       }
       else if (procura_apl == apelido || procura_nom == nome) {
         cout << "Dados incorretos" << endl;
         return false; // alguma informação incorreta
       }
       else {
         if (!verificaStrings(apelido)) {
           return false; // jogador não existe
         }
       }
     }
   }
   cout << "Fim da verificação" << endl;
   return false;
 }

 vector<Pessoa> LerArquivo (const string Arq_estatisticas) {
     ifstream arquivo(Arq_estatisticas);
     vector<Pessoa> jogadores;
     string linha;
     while (getline(arquivo, linha)) {
         istringstream obj(linha);
         Pessoa jogador;
         obj >> jogador.apelido >> jogador.nome;
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

 bool compararNome(const Pessoa &a, const Pessoa &b) {
 return toLower(a.nome) < toLower(b.nome);
 }

 bool compararApelido(const Pessoa &a, const Pessoa &b) {
 return toLower(a.apelido) < toLower(b.apelido);
 }

void Cadastro::listar_jogadores() {
   cout << "Escolha a ordem (a ou n): ";
   char ordem;
   cin >> ordem;
   string arquivo_base = "estatisticas.txt";
   vector<Pessoa> jogadores = LerArquivo(arquivo_base);
   if (ordem == 'a') {
       sort(jogadores.begin(), jogadores.end(), compararApelido);
       for (const auto &jogador : jogadores) {
         cout << "-----------------------------" << endl;
         cout << jogador.apelido << " " << jogador.nome << endl;
         cout << jogador.Reversi << endl;
         cout << jogador.Lig4 << endl;
       }
   }
   else if (ordem == 'n') {
       sort(jogadores.begin(), jogadores.end(), compararNome);
       for (const auto &jogador : jogadores) {
         cout << "-----------------------------" << endl;
         cout << jogador.apelido << " " << jogador.nome << endl;
         cout << jogador.Reversi << endl;
         cout << jogador.Lig4 << endl;
       }
   }
   cout << "-----------------------------" << endl;
 }*/
