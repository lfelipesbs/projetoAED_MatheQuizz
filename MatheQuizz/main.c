#include <stdio.h>
#include "inicio.c"
#include "quiz.c"
#include "ranking.c"
#include "main.h"

Usuario jogador;
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
    insereNome(&jogador.nome);
    carregando();
}

void carregaArquivo(){
    f = fopen("equacoes.txt", "r");
    if(f == NULL){
        printf("\n\nNao foi possivel carregar o jogo, tente novamente mais tarde\n\n");
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
            jogador.pontos = root->quiz.id * 20;
            printf("Final de jogo, voce fez %d pontos!\n\n", jogador.pontos);
            inserirNo(&head, jogador);
        }
    }
}