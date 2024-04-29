#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include "inicio.h"

void alocaNome(char **nome){
    char buffer[100];
    printf("Digite seu nome: ");
    scanf("%99s", buffer);
    
    *nome = malloc(strlen(buffer)+1);
    if(*nome == NULL){
        printf("Falha ao inserir o nome.\n");
        return;
    }
    strcpy(*nome, buffer);
}

int nomeValido(char *nome){
    bool nome_valido = true;
    for(int i=0; nome[i] != '\0'; i++){
        if(!isalpha(nome[i])){
            nome_valido = false;
            break;
        }
        nome[i] = toupper(nome[i]); 
    }
    if(!nome_valido){
        printf("Por favor, digite um nome válido apenas com letras do alfabeto.\n");
        pausa(3);
        free(nome);
        return 0;
    }else{
        limpa();
        abertura();
        printf("Bem-vindo, %s!\n", nome);
        return 1;
    }
}

void insereNome(char **nome){
    *nome = NULL;
    do{
        limpa();
        abertura();
        alocaNome(nome);
    }while(!nomeValido(*nome));
}

void limpa(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void abertura(){
    printf("******************************\n");
    printf("*                            *\n");
    printf("*     BEM VINDO AO QUIZ      *\n");
    printf("*                            *\n");
    printf("******************************\n");
    printf("\n");
}

void pausa(int segundos){
    #ifdef _WIN32
        Sleep(segundos * 1000);
    #else
        sleep(segundos);
    #endif
}