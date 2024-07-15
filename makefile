# Definições do compilador e flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude

# Diretivas
all: bin/main.exe

# Diretórios
OBJ_DIR = obj
BIN_DIR = bin

# Arquivos objeto
OBJ = $(OBJ_DIR)/Jogo.o $(OBJ_DIR)/Reversi.o $(OBJ_DIR)/Lig4.o $(OBJ_DIR)/Jogador.o $(OBJ_DIR)/CadastroJogadores.o $(OBJ_DIR)/Partida.o $(OBJ_DIR)/main.o

# Verificar se os diretórios obj e bin existem, se não, criá-los
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Regra para compilar o programa principal
bin/main.exe: $(OBJ) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o bin/main.exe $(OBJ)

# Regras para compilar arquivos objeto
$(OBJ_DIR)/main.o: src/main.cpp include/Jogo.hpp include/Reversi.hpp include/Lig4.hpp include/Jogador.hpp include/CadastroJogadores.hpp include/Partida.hpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/Jogo.o: src/Jogo.cpp include/Jogo.hpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c src/Jogo.cpp -o $(OBJ_DIR)/Jogo.o

$(OBJ_DIR)/Reversi.o: src/Reversi.cpp include/Reversi.hpp include/Jogo.hpp  | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c src/Reversi.cpp -o $(OBJ_DIR)/Reversi.o

$(OBJ_DIR)/Lig4.o: src/Lig4.cpp include/Lig4.hpp include/Jogo.hpp  | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c src/Lig4.cpp -o $(OBJ_DIR)/Lig4.o

$(OBJ_DIR)/Jogador.o: src/Jogador.cpp include/Jogador.hpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c src/Jogador.cpp -o $(OBJ_DIR)/Jogador.o

$(OBJ_DIR)/CadastroJogadores.o: src/CadastroJogadores.cpp include/CadastroJogadores.hpp include/Jogador.hpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c src/CadastroJogadores.cpp -o $(OBJ_DIR)/CadastroJogadores.o

$(OBJ_DIR)/Partida.o: src/Partida.cpp include/Partida.hpp include/Jogo.hpp include/Jogador.hpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c src/Partida.cpp -o $(OBJ_DIR)/Partida.o

# Limpar arquivos objeto e executável
clean:
	-del /Q $(OBJ_DIR)\*.o
	
	-del /Q $(BIN_DIR)\main.exe

# Diretiva personalizada para exibir mensagem
exibeMensagem:
	@echo "Exibe mensagem"

# Diretiva para declarar phony targets
.PHONY: all clean exibeMensagem
