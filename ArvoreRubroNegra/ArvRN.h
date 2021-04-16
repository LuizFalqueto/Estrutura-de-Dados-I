/*
    Implementacao de algoritmo de Arvore Rubro-Negra
    Autor: Luiz Gustavo Falqueto Baptista
    Data: 29/03/2021
    Arquivo: ArvRB.h
*/

#ifndef ARVRN_H
#define ARVRN_H

#include <stdlib.h>
#include <stdio.h>

typedef struct nodeArvRB {
    void* info;
    int cor;
    struct nodeArvRB *left, *right, *dad;
}NodeArvRB;

typedef struct rootArvRN{
    NodeArvRB *root;
}RaizRN;

//Função responsável por criar um nó da arvore
NodeArvRB *createNodeRB();

//Função que incializa a arvore
RaizRN *createRaiz();

//Função que retorna a cor do nó
int getColor(NodeArvRB *node);

//Fução que troca as cores do nó 
void setColor(NodeArvRB *node, int cor);

//Função para impressão da árvore
void printARN(NodeArvRB *raiz, int nivel,void (imprimeNo)(void*));

//Função retorna o avô de um nó
NodeArvRB *avo(NodeArvRB *node);

//Função retorna o tio de um nó
NodeArvRB *tio(NodeArvRB *node);

//Função retorna o irmão de um nó
NodeArvRB *irmao(NodeArvRB *node);

//Função de rotação esquerda
void leftRotation(RaizRN *raiz, NodeArvRB **node);

//Função de rotação direita
void rightRotation(RaizRN *raiz, NodeArvRB **node);

//Função que calcula a altura da arvore
int heightAvl(NodeArvRB *raiz);

//Funçao de busca de uma chave na árvore
NodeArvRB* searchRN(RaizRN *raiz, void *chave, int (compararValores)(void*, void*));

//Função auxiliar de inserção de novo nó na árvore (sobe ajustando as rotações)
void ajustaInsertRN(RaizRN *raiz, NodeArvRB *novo);

//Função de inserção de novo nó na árvore
int insertRN(RaizRN *raiz, NodeArvRB *novo, int (compararValores)(void*, void*));

//Função que encontra o nó sucessor do nó a ser removido
NodeArvRB *findSmallestRN(NodeArvRB *node);

//Funcão que troca valores de dois nós
void swapContents(NodeArvRB *remove,NodeArvRB *sucessor);

//Função de remoção de um nó na árvore
NodeArvRB *deleteRN(RaizRN *raiz, NodeArvRB *remove);

//Função que imprime o nó da arvore
void printARN(NodeArvRB *raiz, int nivel,void (imprimeNo)(void*));

void destroyARN(RaizRN *raiz); //Destroi a arvore

void auxDestroyARN(NodeArvRB *node) ;//Auxiliar de 'destroyAvl' que libera nó por nó

#endif //ARVRN_H