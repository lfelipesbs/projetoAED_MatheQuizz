#include <stdio.h>
#include <stdlib.h>
#include "ranking.h"

void inserirNo(Node** head, Usuario p){
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