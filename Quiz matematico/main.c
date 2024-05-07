#include <stdio.h>
#include "inicio.c"
#include "quiz.c"
#include "main.h"

Usuario jogador;
Arv* root = NULL;
FILE* f;

int main(void){
    while(1){
        carregaArquivo();
        inicio();
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