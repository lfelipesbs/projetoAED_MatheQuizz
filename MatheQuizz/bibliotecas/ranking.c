#include <stdio.h>
#include <stdlib.h>
#include "ranking.h"

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
    if(difftime(horaAtual, a->pessoa.hora) != difftime(horaAtual, b->pessoa.hora)){
        return difftime(horaAtual, a->pessoa.hora) - difftime(horaAtual, b->pessoa.hora);
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