/*------------------------------------------------------------------------------------------------
Trabalho Pratico 1 - Skip List - Estrutura de Dados I - CEUNES - UFES
Autor:  Luiz Gustavo Falqueto Baptista
Matricula:  2017203673
Data de criação:    22/10/2019
Objetivo:   objetivo geral é a implementacao de uma estrutura de dados "Skip List".

Arquivo (skipList.h) - Implementacao das estruturas e assinaturas das funcoes
------------------------------------------------------------------------------------------------*/

#define MAX_NIVEIS 5

/*-------- Implementacao das estruturas Node e SkipList -------------*/
typedef struct tno{
    int valor;
    int nivel;
    struct tno **apontadores;
}Node;

typedef struct {
    int heigth;
    Node *first;
}SkipList;
/*-------------------------------------------------------------------*/

/*--------------- Assinaturas das funcoes ---------------------------*/

/*
    Funcao void createList() cria uma nova instancia de Node como "cabeca" da estrutura
    Entrada: void
    Saida: lista do tipo SkipList
*/
SkipList* createList();

/*
    Funcao createNode(int key, int height) cria uma instancia de um Node para estrutura
    Entrada: valor da chave a ser inserida, altura do noh
    Saida: ponteiro para o no criado
*/
Node* createNode(int key, int height);

/*
    Funcao isEmptyList(SkipList *lst) informa se a lista esta vazia ou nao
    Entrada: lista do tipo SkipList
    Saida: 1(vazio) ou 0(cheio)
*/
int isEmptyList(SkipList *lst);

/*
    Funcao searchList(int chave,  SkipList *lst) procura um elemento na lista
    Entrada: chave a ser procurada, lista do tipo SkipList
    Saida: 1(existe) ou 0(nao existe)
*/
int searchList(int chave,  SkipList *lst,FILE *saida);

/*
    Funcao insereList(int x, int h, SkipList *lst) insere um elemento na lista
    Entrada: valor da chave a ser inserida, nivel da estrutura a ser inserido, lista do tipo SkipList
    Saida: 1(feito), 0(nao feito)
*/
int insereList(int x, int h, SkipList *lst, FILE *saida);

/*
    Funcao removeList(int chave, SkipList *lst) remove um elemento da lista
    Entrada: valor da chave a ser removida, lista do tipo SkipList
    Saida: 1(feito), 0(nao feito)
*/
int removeList(int chave, SkipList *lst, FILE *saida);

/*
    Funcao printListH(SkipList *lst, int h) imprime uma lista de ponteiros referente a certo nivel da estrutura
    Entrada: lista do tipo SkipList, nivel a ser impresso
    Saida: vazio
*/
void printListH(SkipList *lst, int h, FILE *saida);

/*
    Funcao printList(SkipList *lst) imprime a lista completa do nivel mais alto ao mais baixo
    Entrada: lista do tipo SkipList
    Saida: vazio
*/
void printList(SkipList *lst,FILE *saida);

/*
    Funcao readFile(FILE *file) manipula dados de um arquivo
    Entrada: ponteiro do tipo FILE
    Saida: 1(feito) ou 0(nao feito)
*/
int readFile(FILE *file);


/* ------------------------------------------------------------------------------------------------------------ */
