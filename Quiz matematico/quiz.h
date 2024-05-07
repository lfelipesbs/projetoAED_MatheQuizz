typedef struct Usuario{
    char* nome;
    int pontos;
}Usuario;

typedef struct Pergunta{
    int id;
    char* equacao;
    double resposta;
}Pergunta;

typedef struct Arv{
    Pergunta quiz;
    struct Arv *left;
    struct Arv *right;
}Arv;

void explicacaoGame();
void carregando();
void tresPontos();

void delay(int ms);

Pergunta leArquivo(FILE* f);
void inserir(Arv** root, Pergunta pergunta);
void criaArv(FILE* f, Arv** root);