typedef struct Node{
    Jogador pessoa;
    struct Node* next;
}Node;

void inserirNo(Node **head, Jogador p);
int comparaNos(Node *a, Node *b, time_t horaAtual);
void ordenaNo(Node **head, time_t horaAtual);
void deletaLista(Node** head);