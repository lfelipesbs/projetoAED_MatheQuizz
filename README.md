# Projeto AED 24.1

# MatheQuizz - Projeto de Quiz Matemático

## Introdução

MatheQuizz é um jogo de perguntas e respostas baseado em equações matemáticas, ideal para pessoas que gostam de desafios numéricos. A cada resposta correta, a dificuldade das questões aumenta, enquanto respostas erradas diminuem a dificuldade. O desempenho do jogador é avaliado no final com uma pontuação que reflete seu raciocínio matemático.

## Objetivo

Além de aprimorar conhecimentos gerais em matemática, o MatheQuizz visa explorar e compreender o conceito de árvores binárias e sua aplicação prática.

## Estruturas de Dados

### Árvore Binária
Será utilizada para armazenar as equações:
- **Esquerda:** Equação a ser respondida caso o usuário erre.
- **Direita:** Equação a ser respondida caso o usuário acerte.

### Lista Simplesmente Encadeada
Usada para implementar o ranking de pontuação. Essa escolha permite a aplicação direta do algoritmo de ordenação.

## Algoritmos de Ordenação

### BubbleSort
Escolhido pela sua flexibilidade e pela complexidade que depende do nível de ordenação prévia dos dados. Será utilizado para ordenar o ranking da rodada atual, considerando:
1. Pontuação
2. Horário da rodada
3. Ordem alfabética

## Funcionalidades Necessárias

1. **Funções de Inserção**
   - Inserção na árvore binária.
   - Inserção na lista encadeada.

2. **Função de Ordenação**
   - Ordenação da lista encadeada utilizando BubbleSort.

3. **Funções de Percurso**
   - Percorrer a árvore binária (para leitura ou exibição das equações).
   - Percorrer a lista encadeada (para leitura ou exibição do ranking).

4. **Funções Extras**
   - Organização estética do jogo.
   - Tratamento de erros e validações diversas.

## Como Executar

1. Clone o repositório:
    ```sh
    git clone https://github.com/seu-usuario/MatheQuizz.git
    ```

2. Navegue até o diretório do projeto:
    ```sh
    cd MatheQuizz
    ```

3. Compile e execute o projeto conforme as instruções do seu ambiente de desenvolvimento.

## Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou enviar pull requests.

## Paleta de Cores

As constantes de cor utilizadas no projeto podem ser encontradas neste [link](https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a).

---
