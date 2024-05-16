#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ranking.h"
#include "cores.h"

void inserirNo(Node** head, Jogador p){
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->pessoa = p;
    novo->next = NULL;

    if(*head == NULL){
        *head = novo;
    }else{
        Node* temp = *head;

        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = novo;
    }
}

int comparaNos(Node *a, Node *b, time_t horaAtual){
    if(a->pessoa.pontos != b->pessoa.pontos){
        return b->pessoa.pontos - a->pessoa.pontos;
    }

    double diffA = difftime(horaAtual, a->pessoa.hora);
    double diffB = difftime(horaAtual, b->pessoa.hora);

    if (diffA != diffB) {
        return (diffA > diffB) - (diffA < diffB);
    }
    return strcmp(a->pessoa.nome, b->pessoa.nome);
}

void ordenaNo(Node **head, time_t horaAtual){
    if(*head == NULL){
        return;
    }

    int trocou;
    Node *ptr1;
    Node *lptr = NULL;

    do{
        trocou = 0;
        ptr1 = *head;

        while(ptr1->next != lptr){
            if(comparaNos(ptr1, ptr1->next, horaAtual) > 0){
                Jogador tempUsuario;

                strcpy(tempUsuario.nome, ptr1->pessoa.nome);
                tempUsuario.pontos = ptr1->pessoa.pontos;
                tempUsuario.hora = ptr1->pessoa.hora;

                strcpy(ptr1->pessoa.nome, ptr1->next->pessoa.nome);
                ptr1->pessoa.pontos = ptr1->next->pessoa.pontos;
                ptr1->pessoa.hora = ptr1->next->pessoa.hora;

                strcpy(ptr1->next->pessoa.nome, tempUsuario.nome);
                ptr1->next->pessoa.pontos = tempUsuario.pontos;
                ptr1->next->pessoa.hora = tempUsuario.hora;

                trocou = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }while(trocou);
}

void imprimeNo(Node *head){
    if(head == NULL){
        printf(RED "Ranking vazio\n" COLOR_RESET);
        return;
    }

    int i = 1;

    while(head != NULL){
        char buffer[9];
    
        strftime(buffer, sizeof(buffer), "%H:%M:%S", head->pessoa.hora);

        printf(GRN "%d. %s" COLOR_RESET " - " CYN "%d " COLOR_RESET GRN "pontos" COLOR_RESET ".........." YEL "%s\n" COLOR_RESET, i, head->pessoa.nome, head->pessoa.pontos, buffer);
        
        head = head->next;
        i++;
    }
}

void deletaLista(Node **head){
    Node *current = *head;
    Node *next;

    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}