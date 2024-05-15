typedef struct Jogador{
    char* nome;
    int pontos;
    struct tm* hora;
}Jogador;

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
int respostaValida(Arv* root, double* a);
double insereResposta(Arv* root);