typedef struct Usuario{
    char* nome;
    int pontos;
}Usuario;

typedef struct Quiz{
    int id;
    char* equacao;
    double resposta;
}Quiz;

typedef struct Arv{
    Quiz quiz;
    struct Arv *left;
    struct Arv *right;
}Arv;