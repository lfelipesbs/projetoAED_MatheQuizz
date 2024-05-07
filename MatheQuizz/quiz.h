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
    struct Arv* left;
    struct Arv* right;
}Arv;

void explicacaoGame();
void carregando();
void tresPontos();

void delay(int ms);

Pergunta leArquivo(FILE* f);
void inserirArv(Arv** root, Pergunta pergunta);
void criaArv(FILE* f, Arv** root);

int acertou(double a, double x);
Arv* percorreArv(Arv* root, double a);
void imprimeEquacao(Arv* root);