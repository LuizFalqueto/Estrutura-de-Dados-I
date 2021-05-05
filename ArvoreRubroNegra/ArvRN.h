/*
    Implementacao de algoritmo de Arvore Rubro-Negra
    Autor: Luiz Gustavo Falqueto Baptista & Eric Rabelo
    Data: 05/04/2021
    Arquivo: ArvRB.h
*/

#ifndef ARVRN_H
#define ARVRN_H

#include <stdlib.h>
#include <stdio.h>

typedef struct nodeArvRB
{
    void *info;                           //Chave genérica. Deve ser implementada no arquivo teste!
    int cor;                              //Campo referente à cor do nó
    struct nodeArvRB *left, *right, *dad; //Ponteiros para os filhos e para o pai do nó
} NodeArvRB;

typedef struct rootArvRB
{
    NodeArvRB *root; //Raiz da arvore rubro-negra
} RaizRB;

NodeArvRB *createSentinelaRB();

//Função responsável por criar um nó da arvore
NodeArvRB *createNodeRB(NodeArvRB *externo);

//Função que incializa a arvore
RaizRB *createRaiz(NodeArvRB *externo);

//Função que retorna a cor do nó
int getColor(NodeArvRB *node);

//Fução que troca as cores do nó
void setColor(NodeArvRB *node, int cor);

//Função de rotação esquerda
void leftRotation(RaizRB *raiz, NodeArvRB **node, NodeArvRB *externo);

//Função de rotação direita
void rightRotation(RaizRB *raiz, NodeArvRB **node, NodeArvRB *externo);

//Função que calcula a altura da arvore
int heightRB(NodeArvRB *raiz);

//Funçao de busca de uma chave na árvore
NodeArvRB *searchRB(RaizRB *raiz, void *chave, int(compararValores)(void *, void *), NodeArvRB *externo);

//Função auxiliar de inserção de novo nó na árvore (sobe ajustando as rotações)
void RBinsertFixup(RaizRB *raiz, NodeArvRB *novo, NodeArvRB *externo);

//Função de inserção de novo nó na árvore
void insertRB(RaizRB *raiz, NodeArvRB *q, int(compararValores)(void *, void *), NodeArvRB *externo);

NodeArvRB *findSmallestRB(NodeArvRB *node, NodeArvRB *externo);

//Função de remoção de um nó na árvore
//NodeArvRB *deleteRN(RaizRB *raiz, NodeArvRB *remove);

//Função que imprime o nó da arvore
void printRB(NodeArvRB *raiz, int nivel, void(imprimeNo)(void *), NodeArvRB *externo);

void destroyRB(RaizRB *raiz, NodeArvRB *externo, void(freeInfoNodeRB)(NodeArvRB *node)); //Destroi a arvore

void auxDestroyRB(NodeArvRB *node, NodeArvRB *externo, void(freeInfoNodeRB)(NodeArvRB *node)); //Auxiliar de 'destroyAvl' que libera nó por nó

void RBDeleteFixup(RaizRB *T, NodeArvRB *x, NodeArvRB *externo);

void RBRemocao(RaizRB *T, NodeArvRB *z, NodeArvRB *externo);

void RBTransferePai(RaizRB *T, NodeArvRB *u, NodeArvRB *v, NodeArvRB *externo);

#endif //ARVRN_H