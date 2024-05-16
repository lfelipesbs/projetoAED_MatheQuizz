#include <stdio.h>
#include <time.h>
#ifdef _WIN32 
#include "bibliotecas\\inicio.c"
#include "bibliotecas\\quiz.c"
#include "bibliotecas\\ranking.c"
#include "bibliotecas\\cores.h"
#else
#include "bibliotecas/inicio.c"
#include "bibliotecas/quiz.c"
#include "bibliotecas/ranking.c"
#include "bibliotecas/cores.h"
#endif
#include "main.h"

Jogador usuario;
Arv* root = NULL;
Node* head = NULL;
FILE* f;

int main(void){
    menu();
    escolheOpcao();
}

void menu(){
    abertura();
    printf("\n1 - Iniciar o jogo\n");
    printf("2 - Ver o ranking\n");
    printf("3 - Apagar o ranking\n");
    printf("4 - Sair\n");
    printf("-> ");
}

void escolheOpcao(){
    int escolha;
    time_t current_time;
    
    scanf("%d", &escolha);

    switch(escolha){
        case 1:
            root = NULL;
            limpa();
            carregaArquivo();
            inicio();
            quiz();
            continua(1.0);
        case 2:
            time(&current_time);

            limpa();
            logo();
            ordenaNo(&head, current_time);
            imprimeNo(head);
            continua(5.0);
        case 3:
            limpa();
            logo();
            deletaLista(&head);
            imprimeNo(head);
            continua(2.5);
        case 4:
            limpa();
            logo();
            printf("\nSaindo do jogo...\n");
            pausa(2.0);
            exit(1);
        default:
            limpa();
            logo();
            printf("\nInsira uma opcao valida\n");
            continua(1.5);
    }
}

void inicio(){
    abertura();
    insereNome(&usuario.nome);
    carregando();
}

void carregaArquivo() {
    srand(time(NULL));
    int arquivo = (rand() % 5) + 1;

    char filepath[50];

    switch (arquivo) {
        case 1:
            #ifdef _WIN32
            snprintf(filepath, sizeof(filepath), "questoes\\equacoes1.txt");
            #else
            snprintf(filepath, sizeof(filepath), "questoes/equacoes1.txt");
            #endif
            break;
        case 2:
            #ifdef _WIN32
            snprintf(filepath, sizeof(filepath), "questoes\\equacoes2.txt");
            #else
            snprintf(filepath, sizeof(filepath), "questoes/equacoes2.txt");
            #endif
            break;
        case 3:
            #ifdef _WIN32
            snprintf(filepath, sizeof(filepath), "questoes\\equacoes3.txt");
            #else
            snprintf(filepath, sizeof(filepath), "questoes/equacoes3.txt");
            #endif
            break;
        case 4:
            #ifdef _WIN32
            snprintf(filepath, sizeof(filepath), "questoes\\equacoes4.txt");
            #else
            snprintf(filepath, sizeof(filepath), "questoes/equacoes4.txt");
            #endif
            break;
        case 5:
            #ifdef _WIN32
            snprintf(filepath, sizeof(filepath), "questoes\\equacoes5.txt");
            #else
            snprintf(filepath, sizeof(filepath), "questoes/equacoes5.txt");
            #endif
            break;
        default:
            printf("\n\nHouve algum problema ao iniciar o jogo, tente novamente mais tarde\n\n");
            exit(1);
    }

    f = fopen(filepath, "r");
    if (f == NULL) {
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
            time_t rawtime;

            time(&rawtime);
            usuario.hora = localtime(&rawtime);

            usuario.pontos = root->quiz.id * 20;
            printf("Final de jogo, voce fez %d pontos!\n\n", usuario.pontos);
            inserirNo(&head, usuario);
        }
    }
}

void continua(double sec){
    pausa(sec);
    limpa();
    menu();
    escolheOpcao();
}