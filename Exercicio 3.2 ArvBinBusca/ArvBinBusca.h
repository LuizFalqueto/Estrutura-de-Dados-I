#ifndef __ARVBINBUSCA_H__
#define __ARVBINBUSCA_H__

typedef struct noh {
    int info;
    struct noh *right;
    struct noh *left;
}Node;

typedef struct {
    Node *raiz;
}BST;

BST *createBST (); // cria a raiz de uma arvore
Node *createNodeBST(int valor); //cria no da arvore

void liberaBST(BST *raiz); // libera a arvore

int isEmptyBST(BST *raiz); //arvore vazia?

int heightBST (Node *atual); //altura da arvore

int totalNohBST(Node *atual); //total de nos da arvore

void searchBST (Node *atual, int valor); // procura um elemento informado na arvore

void insertBST (BST *raiz, int valor); // insere um elemento informado na arvore

void findLargestElementBST (Node *atual); // Busca o maior elemento da arvore (mais a direita)

void findSmallestElmentBST (Node *atual); // Busca o menor elemento da arvore (mais a esquerda)

void deleteElementBST (BST *raiz, int valor); //Elimina um elemento informado

void printInOrderBST(Node *atual); // imprime arvore com percurso em ordem

#endif // __ARVBINBUSCA_H__
