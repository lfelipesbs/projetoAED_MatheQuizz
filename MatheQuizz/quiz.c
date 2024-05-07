#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include "inicio.h"
#include "quiz.h"

void delay(int ms){
    #ifdef _WIN32
    Sleep(ms);
    #else
    usleep(ms * 1000);
    #endif
}
void explicacaoGame(){
    // coloquem os prints aqui
    printf("Lorem ipsum dolor sit amet. Eum dolorem ipsa aut iste Quis est impedit dolores est error nobis.");
    printf("Ut aliquam voluptate et exercitationem beatae ea reprehenderit repudiandae rem quisquam voluptatem aut rerum exercitationem."); 
    printf("Et magni suscipit est quae asperiores ut itaque eius eum fugit itaque in inventore ipsam aut tempora dolore et officia dolores.");
    printf("Et mollitia omnis sit omnis fugiat sed nisi numquam?\n"); // print de teste
}

void carregando(){
    for(int i=0; i<5; i++){
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

void inserirArv(Arv** root, Pergunta pergunta){
    if(*root == NULL){
        *root = (Arv*)malloc(sizeof(Arv));
        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->quiz = pergunta;
    }else{
        if(pergunta.id < (*root)->quiz.id){
            inserirArv(&(*root)->left, pergunta);
        }
        if(pergunta.id > (*root)->quiz.id){
            inserirArv(&(*root)->right, pergunta);
        }
    }
}

void criaArv(FILE* f, Arv** root){
    for(int i = 0; i < 31; i++){
        Pergunta pergunta = leArquivo(f);
        inserirArv(root, pergunta);
    }
}

int acertou(double a, double x){
    if(a == x){
        return 1;
    }
    return 0;
}

Arv* percorreArv(Arv* root, double a){
    Arv* aux = root;
    
    if(acertou(a, root->quiz.resposta)){
        return aux->right;
    }
    return aux->left;
}

void imprimeEquacao(Arv* root){
    limpa();
    logo();
    printf("\n\n%s\n-> ", root->quiz.equacao);
}