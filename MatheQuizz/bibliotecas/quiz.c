#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include "inicio.h"
#include "quiz.h"
#include "cores.h"

void delay(int ms){
    #ifdef _WIN32
    Sleep(ms);
    #else
    usleep(ms * 1000);
    #endif
}

void explicacaoGame(){
    printf(GRN "MatheQuizz é um jogo de perguntas baseado em equações matemáticas, voltado para pessoas que gostam de brincar com números. ");
    printf("Cada pergunta apresenta um desafio matemático, a cada resposta correta, a dificuldade aumenta, enquanto respostas erradas diminui. "); 
    printf("No final, o jogo fornece uma pontuação baseada no desempenho, refletindo o raciocínio matemático do jogador. ");
    printf("E aí? Já prepare o lápis e a borracha e vamos para o jogo!\n" COLOR_RESET);
}

void carregando(){
    for(int i=0; i<10; i++){
        limpa();
        abertura();
        explicacaoGame();
        tresPontos();
    }
}

void tresPontos(){
        printf(".");
        fflush(stdout);
        delay(600);

        printf(".");
        fflush(stdout);
        delay(600);

        printf(".");
        fflush(stdout);
        delay(600);
}

Pergunta leArquivo(FILE* f){
    Pergunta pergunta;

    char buffer[100];

    fscanf(f, "%d\n", &pergunta.id);
    fgets(buffer, sizeof(buffer), f);

    buffer[strcspn(buffer, "\n")] = 0;

    pergunta.equacao = malloc(strlen(buffer) + 1);

    strcpy(pergunta.equacao, buffer);

    fscanf(f, "%lf\n", &pergunta.resposta);

    return pergunta;
}

// Função para inserir um nó na árvore binária
void inserirArv(Arv** root, Pergunta pergunta){
    if(*root == NULL){
        // Se a raiz é nula, aloca memória para o novo nó
        *root = (Arv*)malloc(sizeof(Arv));
        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->quiz = pergunta;
    }else{
        // Insere o nó à esquerda se o ID da pergunta é menor, usando a chamada recursiva
        if(pergunta.id < (*root)->quiz.id){
            inserirArv(&(*root)->left, pergunta);
        }
        // Insere o nó à direita se o ID da pergunta é maior
        if(pergunta.id > (*root)->quiz.id){
            inserirArv(&(*root)->right, pergunta);
        }
    }
}

// Função para criar a árvore binária a partir de um arquivo
void criaArv(FILE* f, Arv** root){
    for(int i = 0; i < 31; i++){
        Pergunta pergunta = leArquivo(f); // Lê a pergunta do arquivo
        inserirArv(root, pergunta);  // Insere a pergunta na árvore
    }
}

int acertou(double a, double x){
    if(a == x){
        return 1;
    }
    return 0;
}

// Função para percorrer a árvore binária baseada na resposta
Arv* percorreArv(Arv* root, double a){
    Arv* aux = root;
    
    // Se a resposta está correta, retorna o nó à direita
    if(acertou(a, root->quiz.resposta)){
        return aux->right;
    }
    // Se a resposta está errada, retorna o nó à esquerda
    return aux->left;
}

// Função para imprimir a equação armazenada no nó
void imprimeEquacao(Arv* root){
    limpa();
    logo();
    printf("\n\n%s\n-> ", root->quiz.equacao);
}

int respostaValida(Arv* root, double* a){
    if(scanf("%lf", a) == 1){
        return 1;
    }
    printf("\nPor favor, digite um numero valido.\n");
    pausa(1.0);
    while(getchar() != '\n' && !feof(stdin));
    limpa();
    logo();
    imprimeEquacao(root);
    return 0;
}

double insereResposta(Arv* root){
    while(1){
        double a;
        if(respostaValida(root, &a)){
            return a;
        }
    }
}