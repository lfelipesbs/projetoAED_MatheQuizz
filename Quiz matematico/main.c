#include <stdio.h>
#include "inicio.c"
#include "quiz.c"
#include "main.h"

Usuario jogador;

int main(void){
    while(1){
        inicio();
        break;
    }
}

void inicio(){
    abertura();
    insereNome(&jogador.nome);
    carregando();
}