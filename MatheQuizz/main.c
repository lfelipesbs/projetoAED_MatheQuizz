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
    printf(GRN "\n1" COLOR_RESET " - " GRN "Iniciar o jogo\n" COLOR_RESET);
    printf(GRN "2" COLOR_RESET " - " GRN "Ver o ranking\n" COLOR_RESET);
    printf(GRN "3" COLOR_RESET " - " GRN "Apagar o ranking\n" COLOR_RESET);
    printf(RED "4" COLOR_RESET " - " RED "Sair\n" COLOR_RESET);
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
            continua(3.0);
        case 2:
            time(&current_time);

            limpa();
            logo();
            ordenaNo(&head, current_time);
            imprimeNo(head);
            continua(7.0);
        case 3:
            limpa();
            logo();
            printf(RED "Apagando o ranking...\n\n" COLOR_RESET);
            pausa(1.5);
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
            printf("\nInsira uma opcao valida!\n");
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
            if(acertou(respTemp, root->quiz.resposta)){
                printf(GRN "\n\nParabens, voce acertou! Vamos para a proxima pergunta...\n" COLOR_RESET);
                pausa(1.0);
            }else{
                printf(RED "\n\nEita, resposta errada! Vamos para a proxima pergunta...\n" COLOR_RESET);
                pausa(1.0);
            }
            root = percorreArv(root, respTemp);
        }else{
            time_t rawtime;

            time(&rawtime);
            usuario.hora = malloc(sizeof(struct tm));

            *usuario.hora = *localtime(&rawtime);

            if(acertou(respTemp, root->quiz.resposta)){
                usuario.pontos = root->quiz.id * 20;
            }else{
                usuario.pontos = root->quiz.id * 18;
            }

            printf("Final de jogo, voce fez " CYN "%d" COLOR_RESET " pontos!\n\n", usuario.pontos);
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