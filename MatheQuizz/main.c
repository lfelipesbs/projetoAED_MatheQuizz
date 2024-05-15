#include <stdio.h>
#include <time.h>
#include "./bibliotecas/inicio.c"
#include "./bibliotecas/quiz.c"
#include "./bibliotecas/ranking.c"
#include "main.h"

Jogador usuario;
Arv* root = NULL;
Node* head = NULL;
FILE* f;

int main(void){
    while(1){
        carregaArquivo();
        inicio();
        quiz();
        break;
    }
}

void inicio(){
    abertura();
    insereNome(&usuario.nome);
    carregando();
}

void carregaArquivo(){
    srand(time(NULL));
    int arquivo = (rand() % 5) + 1;

    switch(arquivo){
        case 1:
            f = fopen("./questoes/equacoes1.txt", "r");
            if(f == NULL){
                printf("\n\nNao foi possivel carregar o jogo, tente novamente mais tarde\n\n");
                exit(1);
            }
            break;
        case 2:
            f = fopen("./questoes/equacoes2.txt", "r");
            if(f == NULL){
                printf("\n\nNao foi possivel carregar o jogo, tente novamente mais tarde\n\n");
                exit(1);
            }
            break; 
        case 3:
            f = fopen("./questoes/equacoes3.txt", "r");
            if(f == NULL){
                printf("\n\nNao foi possivel carregar o jogo, tente novamente mais tarde\n\n");
                exit(1);
            }
            break;       
        case 4:
            f = fopen("./questoes/equacoes4.txt", "r");
            if(f == NULL){
                printf("\n\nNao foi possivel carregar o jogo, tente novamente mais tarde\n\n");
                exit(1);
            }
            break;
        case 5:
            f = fopen("./questoes/equacoes5.txt", "r");
            if(f == NULL){
                printf("\n\nNao foi possivel carregar o jogo, tente novamente mais tarde\n\n");
                exit(1);
            }
            break;
        default:
            printf("\n\nHouve algum problema ao iniciar o jogo, tente novamente mais tarde\n\n");
            exit(1);
    }

    criaArv(f, &root);

    fclose(f);
}

void quiz(){
    for(int i=0; i<5; i++){
        imprimeEquacao(root);
        double respTemp = insereResposta(root);
        if(i != 4){
            root = percorreArv(root, respTemp);
        }else{
            usuario.pontos = root->quiz.id * 20;
            printf("Final de jogo, voce fez %d pontos!\n\n", usuario.pontos);
            inserirNo(&head, usuario);
        }
    }
}