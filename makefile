# Compilador
CC = g++

# Diretórios
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj

# Flags do compilador
CXXFLAGS = -Wall -I$(INCLUDE_DIR) -g

# Arquivos fonte
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Arquivos objeto (gerados a partir dos arquivos fonte)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Regra padrão
all: $(OBJS)

# Regras para construir os arquivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | create_dirs
	$(CC) $(CXXFLAGS) -c $< -o $@

# Regra para criar os diretórios necessários
create_dirs:
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)

# Regra para limpar os arquivos objeto
clean:
	-del /Q $(OBJ_DIR)\*.o

# Regra para compilar e executar o main
run_main: $(OBJ_DIR)/main.o $(OBJS)
	$(CC) $(CXXFLAGS) $^ -o main
	.\main.exe

# Regra para garantir que `clean` e `create_dirs` não sejam interpretados como arquivos
.PHONY: all clean create_dirs run_main
