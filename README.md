# Projeto Final - Jogos de Tabuleiro

**Universidade Federal de Minas Gerais**  
**Instituto de Ciências Exatas**  
**Departamento de Ciência da Computação**  
**DCC 204 - PDS II**  
**1º Semestre de 2024**  
**Professores: Luiz Chaimowicz**
**Grupo 18**
**Alunos:** 
**Gabriel Wilson dos Santos Silva**
**Natália Gonçalves Barreto**
**Sérgio Eustáquio Faria Castro**

## Introdução

O objetivo deste projeto feito pelo grupo é desenvolver um sistema para a implementação de jogos de tabuleiro, focando nos jogos Reversi (Othello) e Lig 4. O sistema deve utilizar o paradigma de orientação a objetos, oferecendo uma estrutura modular e reutilizável. O projeto envolve a criação de uma hierarquia de classes para representar os jogos, um módulo para o cadastro de jogadores e um módulo para a execução das partidas.

## Link GitHub

https://github.com/wilsong555/GRUPO-18-PDS2-24-1.git

## Descrição Geral

O sistema é dividido em três partes principais:

1. **Hierarquia de Classes para os Jogos**  
   Uma classe abstrata representando jogos de tabuleiro, com métodos comuns e especializados para cada jogo (Reversi e Lig 4).

2. **Cadastro de Jogadores**  
   Módulo para cadastrar, remover e listar jogadores. As estatísticas dos jogadores são armazenadas e mantidas entre execuções.

3. **Execução de Partidas**  
   Módulo para executar partidas entre dois jogadores, gerenciar jogadas, atualizar o estado do jogo e imprimir o tabuleiro.

## Funcionalidades

### Lig4

1. **Empate**:
   - Verifica se o jogo terminou em empate, ou seja, se todas as posições da matriz estão preenchidas e nenhum jogador ganhou.

2. **Jogar**:
   - Permite ao jogador fazer uma jogada em uma coluna específica. A peça é inserida na linha mais baixa disponível da coluna.

3. **Verificar Vencedor**:
   - Verifica se há um vencedor, verificando quatro direções possíveis (horizontal, vertical e diagonais) para encontrar quatro peças consecutivas do mesmo jogador.

4. **Imprimir**:
   - Exibe o estado atual do tabuleiro no console.

5. **Remover Jogada**:
   - Remove a peça da coluna especificada, revertendo a última jogada.

### Reversi

1. **Inicialização do Tabuleiro**:
   - O tabuleiro é inicializado com um tamanho de 8x8, e as peças iniciais são configuradas no centro do tabuleiro.

2. **Acesso ao Tabuleiro**:
   - Permite acessar e modificar o estado das peças no tabuleiro usando notação de linha e coluna.

3. **Imprimir**:
   - Exibe o estado atual do tabuleiro no console, com peças representadas por 'P' (Preto), 'B' (Branco) e '.' (Vazio).

4. **Movimento Válido**:
   - Verifica se há movimentos válidos para o jogador. Um movimento é válido se pode capturar peças adversárias.

5. **Aplicar Movimento**:
   - Aplica um movimento no tabuleiro, coloca a peça do jogador e vira as peças adversárias conforme necessário.

6. **Contar Peças**:
   - Conta o número de peças pretas e brancas no tabuleiro.

7. **Verificar Vencedor**:
   - Verifica e exibe o vencedor do jogo com base na contagem final das peças.

## Instruções para Jogar

1. **Iniciar o Sistema**:
   - Execute o programa. Você verá um menu inicial com as seguintes opções:
     - (1) Cadastrar jogador
     - (2) Remover jogador
     - (3) Listar jogadores
     - (4) Começar partida
     - (5) Fechar sistema

2. **Cadastrar Jogador**:
   - Escolha a opção 1 para adicionar um novo jogador. Insira o nome e o apelido do jogador quando solicitado.

3. **Remover Jogador**:
   - Escolha a opção 2 para remover um jogador. Forneça o apelido do jogador que deseja remover.

4. **Listar Jogadores**:
   - Escolha a opção 3 para exibir a lista de jogadores cadastrados.

5. **Começar Partida**:
   - Escolha a opção 4 para iniciar uma nova partida. Você será solicitado a fornecer as seguintes informações:
     - Tipo de jogo (Lig4 ou Reversi)
     - Se deseja jogar contra a IA (Sim ou Não)
     - Informações dos jogadores (nome e apelido)
   - Após fornecer essas informações, a partida será iniciada, e o jogo será exibido conforme o tipo escolhido.

6. **Fechar o Sistema**:
   - Escolha a opção 5 para encerrar o programa.

## Detalhes do Jogo

### Lig4

- **Objetivo**: Alinhar quatro peças do mesmo tipo horizontalmente, verticalmente ou diagonalmente para vencer.
- **Como Jogar**:
  - Escolha uma coluna para inserir sua peça. A peça será colocada na linha mais baixa disponível da coluna.
  - O jogo continua até que um jogador ganhe (alinhando quatro peças) ou o tabuleiro esteja cheio (empate).

### Reversi

- **Objetivo**: Capturar o maior número possível de peças adversárias virando-as para a cor do seu jogador.
- **Como Jogar**:
  - Escolha uma posição no tabuleiro onde você deseja colocar sua peça.
  - O movimento deve ser válido, capturando peças adversárias ao redor.
  - O jogo continua até que não haja movimentos válidos restantes para nenhum jogador ou o tabuleiro esteja cheio.

---

## Estrutura do Diretório

- `bin/` - Executáveis gerados pela compilação.
- `include/` - Arquivos de cabeçalho (.hpp).
- `obj/` - Arquivos objeto (.o).
- `src/` - Arquivos de código-fonte (.cpp).
- `tests/` - Arquivos de teste.
- `.gitignore` - Arquivos e pastas a serem ignorados pelo Git.
- `estat_temp.txt`- Arquivo temporário.
- `estatísticas.txt` - Arquivo.
- `Makefile` - Instruções para compilação.
- `README.md` - Documentação do projeto.

## Testes

Utilizamos a biblioteca `doctest` para criar testes unitários e garantir o funcionamento correto dos métodos. Exemplos de testes estão localizados na pasta `tests/`.

## Documentação

A documentação do código é gerada usando o Doxygen. Para visualizar a documentação, execute o comando `doxygen` após configurar o arquivo `Doxyfile`.

## Dificuldades Encontradas

Durante o desenvolvimento, enfrentamos desafios relacionados à implementação correta dos jogos, como a validação das jogadas e a manutenção do estado do jogo. Também houve dificuldades na integração entre os módulos e na criação de uma interface intuitiva para o usuário, assim mudamos as entradas para números para facilitar a compreensão. 

## Funcionalidades Extras

- **Interface Gráfica:** Planejamos implementar uma interface gráfica para uma melhor experiência do usuário.(Não executado)
- **Inteligência Artificial:** Consideramos a inclusão de um agente inteligente para jogar contra o usuário.(Executado parcialmente)


##Instruções sobre como compilar e executar o jogo.


cd exec
make
./bin/main

---
