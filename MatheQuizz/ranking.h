#include "quiz.h"

typedef struct Node{
    Usuario pessoa;
    struct Node* next;
}Node;

void inserirNo(Node **head, Usuario p);