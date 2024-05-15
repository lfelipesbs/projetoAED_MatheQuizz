#include <stdio.h>
#include <time.h>
#include "./bibliotecas/inicio.c"
#include "./bibliotecas/quiz.c"
#include "./bibliotecas/ranking.c"
#include "./bibliotecas/cores.h"
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
    printf("->");
}

void escolheOpcao(){
    int escolha;
    
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
            time_t current_time;
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