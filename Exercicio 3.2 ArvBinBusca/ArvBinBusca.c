#include <stdio.h>
#include <stdlib.h>
#include "ArvBinBusca.h"

// implementaçao das funçoes

BST *createBST (){ // cria a raiz de uma arvore
    BST *cria = (BST*)malloc(sizeof(BST));

    if(cria != NULL){
        cria->raiz = NULL;
        return cria;
    }
    return NULL;
}

Node *createNodeBST(int valor){
    Node *novo = (Node*)malloc(sizeof(Node));

    if (novo != NULL){
        novo->left = NULL;
        novo->right = NULL;
        novo->info = valor;
        return novo;
    }
    return NULL;
}

void liberaNoBST(Node *node){
    if(node == NULL) return;

    liberaNoBST(node->left);
    liberaNoBST(node->right);
    free(node);
    node = NULL;
}

void liberaBST(BST *raiz){ //libera a arvore
    if (raiz == NULL) return;

    liberaNoBST(raiz->raiz);
    free(raiz);
}

int isEmptyBST(BST* raiz){ //arvore vazia?
    if (raiz == NULL) return 1;
    if (raiz->raiz == NULL) return 1;
    return 0;
}

int heightBST (Node *atual){ //altura da arvore
    if(atual == NULL) return 0;

    Node *temp = atual;

    int left = 1 + heightBST(temp->left);
    int right = 1 + heightBST(temp->right);

    if (left > right) return left;
    else return right;
}

int totalNohBST(Node *atual){ //total de nos da arvore
    if(atual == NULL) return 0;

    Node *temp = atual;

    int left = heightBST(temp->left);
    int right = heightBST(temp->right);

    return left + right + 1;
}

void searchBST (Node *atual, int valor){ // procura um elemento informado na arvore
    if (atual == NULL) return;

    Node *temp = atual;

    if(temp->info == valor){
        printf("Elemento %d encontrado.", temp->info);
        return;
    }else{
        if(valor < temp->info){
            searchBST(temp->left,valor);
        }else{
            searchBST(temp->right,valor);
        }
    }
}

void insertBST (BST *raiz, int valor){ // insere um elemento informado na arvore
    if (raiz == NULL) return;

    Node *novo = createNodeBST(valor);

    if (raiz->raiz == NULL) raiz->raiz = novo;
    else{
        Node *atual = raiz->raiz;
        Node *ant = NULL;
        while (atual != NULL){
            ant=atual;

            if(valor == atual->info){
                printf("Elemento ja existe.");
                free(novo);
                return;
            }
            if (valor > atual->info){
                atual = atual->right;
            }else{
                atual = atual->left;
            }
        }
        if(valor > ant->info){
            ant->right = novo;
        }else{
            ant->left = novo;
        }
    }
}

void findLargestElementBST (Node *atual){ // Busca o maior elemento da arvore (mais a direita)
    if (atual ==NULL) return;

    Node *temp = atual;

    if (temp->right == NULL){
        printf("Maior elemento da arvore: %d", temp->info);
        return;
    }else{
        findLargestElementBST(temp->right);
    }
}

void findSmallestElementBST (Node *atual){ // Busca o menor elemento da arvore (mais a esquerda)
    if (atual == NULL) return;

    Node *temp = atual;

    if (temp->left == NULL){
        printf("Menor elemento da arvore: %d", temp->info);
        return;
    }else{
        findSmallestElementBST(temp->left);
    }
}

Node *removeAtual (Node *atual){ // função auxiliar para remoção do elemento (3 casos)
    Node *raiz1, *raiz2;
    if(atual->left == NULL){ // sem filho da esquerda
        raiz2 = atual->right;
        free(atual);
        return raiz2;
    }
    raiz1 = atual;
    raiz2 = atual->left;

    while(raiz2->right != NULL){ //procura filho mais a direita da sub-arvore esquerda
        raiz1 = raiz2;
        raiz2 = raiz2->right;
    }

    if(raiz1 != atual){ // copia o filho mais a direita na sub-arvore esquerda para o lugar do no removido
        raiz1->right = raiz2->left;
        raiz2->left = atual->left;
    }

    raiz2->right = atual->right;
    free(atual);
    return raiz2;
}

void deleteElementBST (BST *raiz, int valor){ //Funcao que encontra o no a ser removido
    if (isEmptyBST(raiz)){
        printf("Arvore vazia.");
        return;
    }

    Node *ant = NULL;
    Node *atual = raiz->raiz;

    while (atual != NULL){
        if (valor == atual->info){ // encontra o no a ser removido
            if(atual == raiz->raiz){
                raiz->raiz = removeAtual(atual);
            }else{
                if (ant->right == atual){
                    ant->right = removeAtual(atual);
                }else{
                    ant->left = removeAtual(atual);
                }
            }
            return;
        }

        ant=atual;
        if(valor > atual->info){
            atual=atual->right;
        }else{
            atual=atual->left;
        }
    }
}

void printInOrderBST(Node *atual){ //imprime arvore com percurso em ordem
    if (atual == NULL){
        //printf("Arvore vazia.");
        return;
    }

    Node *temp = atual;
    printInOrderBST(temp->left);
    printf(" %d ", temp->info);
    printInOrderBST(temp->right);
}









