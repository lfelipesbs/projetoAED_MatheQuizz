typedef struct Node{
    Jogador pessoa;
    struct Node* next;
}Node;

void inserirNo(Node **head, Jogador p);