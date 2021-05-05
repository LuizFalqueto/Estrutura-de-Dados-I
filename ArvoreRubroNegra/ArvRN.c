/*
    Implementacao de algoritmo de Arvore Rubro-Negra
    Autor: Luiz Gustavo Falqueto Baptista & Eric Rabelo
    Data: 05/04/2021
    Arquivo: ArvRB.c
*/

#include "ArvRN.h"

#define RED 1
#define BLACK 0

//Função responsável por criar um nó Sentinela
NodeArvRB *createSentinelaRB()
{
    NodeArvRB *novo;
    if ((novo = (NodeArvRB *)malloc(sizeof(NodeArvRB)))) //Verifica se o novo nó foi alocado com sucesso
    {
        novo->cor = BLACK;                           //Sua cor é preta por definição
        novo->left = novo->right = novo->dad = NULL; //Aponta os campos para NULL mesmo não sendo usados
        return novo;                                 //Retorna o novo nó sentinela
    }
    else
        return NULL;
}

//Função responsável por criar um nó da arvore
NodeArvRB *createNodeRB(NodeArvRB *externo)
{
    NodeArvRB *novo;
    if ((novo = (NodeArvRB *)malloc(sizeof(NodeArvRB)))) //Verifica se o novo nó foi alocado com sucesso
    {
        novo->cor = RED;                                //Sua cor é vermelha por padrão
        novo->left = novo->right = novo->dad = externo; //Aponta os campos para externo (nó sentinela)
        return novo;                                    //Retorna o novo nó
    }
    else
        return NULL;
}

//Função que incializa a arvore
RaizRB *createRaiz(NodeArvRB *externo)
{
    RaizRB *ptr;
    if ((ptr = (RaizRB *)malloc(sizeof(RaizRB)))) //Verifica se a nova raiz foi alocada com sucesso
    {
        ptr->root = externo; //Raiz aponta para externo (nó sentinela)
        return ptr;          //Retorna a nova raiz
    }
    else
        return NULL;
}

//Função que retorna a cor do nó
int getColor(NodeArvRB *node)
{
    return node->cor;
}

//Fução que define uma cor para o nó
void setColor(NodeArvRB *node, int cor)
{
    if (!node)
        return;
    node->cor = cor;
}

//Função que calcula a altura da arvore
int heightRB(NodeArvRB *raiz)
{
    if (!raiz)
        return 0;

    int tam_esq, tam_dir; //Variaveis para armazenar o tamanho das subarvores

    tam_esq = 1 + heightRB(raiz->left);  //Variavel recebe 1 + a altura da subarvore esquerda
    tam_dir = 1 + heightRB(raiz->right); //Variavel recebe 1 + a altura da subarvore direita

    //Retorna a altura maior
    if (tam_dir > tam_esq)
        return tam_dir;
    else
        return tam_esq;
}

//Funçao de busca de uma chave na árvore
NodeArvRB *searchRB(RaizRB *raiz, void *chave, int(compararValores)(void *, void *), NodeArvRB *externo)
{
    if (raiz->root == externo)
        return NULL; //Não possui nenhum nó inserido
    NodeArvRB *aux = raiz->root, *node;

    while (aux != externo)
    {
        if (compararValores(aux->info, chave) == 0)
            return aux; //Se as chaves sao iguais
        else
        {
            node = aux;
            if (compararValores(node->info, chave) > 0)
            {                    //Funcao compararValores retorna 1
                aux = aux->left; //Chave buscada e menor
            }
            else
            {
                //Funcao compararValores retorna -1
                aux = aux->right; //Chave buscada e maior
            }
        }
    }

    return NULL;
}

//Função de rotação esquerda
void leftRotation(RaizRB *raiz, NodeArvRB **node, NodeArvRB *externo)
{
    NodeArvRB *v;
    v = (*node)->right;
    (*node)->right = v->left;

    if (v->left != externo)
    {
        v->left->dad = (*node);
    }

    v->dad = (*node)->dad;

    if ((*node)->dad == externo)
    {
        raiz->root = v;
    }
    else
    {
        if ((*node) == (*node)->dad->left)
            (*node)->dad->left = v;
        else
            (*node)->dad->right = v;
    }

    v->left = (*node);
    (*node)->dad = v;
}

//Função de rotação direita
void rightRotation(RaizRB *raiz, NodeArvRB **node, NodeArvRB *externo)
{
    NodeArvRB *v;
    v = (*node)->left;
    (*node)->left = v->right;

    if (v->right != externo)
    {
        v->right->dad = (*node);
    }

    v->dad = (*node)->dad;

    if ((*node)->dad == externo)
    {
        raiz->root = v;
    }
    else
    {
        if ((*node) == (*node)->dad->right)
            (*node)->dad->right = v;
        else
            (*node)->dad->left = v;
    }

    v->right = (*node);
    (*node)->dad = v;
}

//Função auxiliar de inserção de novo nó na árvore (sobe ajustando as rotações)
void RBinsertFixup(RaizRB *raiz, NodeArvRB *novo, NodeArvRB *externo)
{
    NodeArvRB *v, *w, *t, *q;
    q = novo;                       //q recebe o nó que foi inserido
    while (getColor(q->dad) == RED) //Enquanto a cor de q->pai for vermelha
    {
        v = q->dad;       //v recebe o pai de q
        w = v->dad;       //w recebe o pai de v
        if (v == w->left) //se v for o filho a esquerda de w
        {
            t = w->right;           //t recebe o filho a direita de w
            if (getColor(t) == RED) //Condição que representa o caso 2
            {
                setColor(v, BLACK); //v recebe a cor negro
                setColor(t, BLACK); //v recebe a cor negro
                setColor(w, RED);   //w recebe a cor rubro
                q = w;              //q recebe w
            }
            else //Condição que representa o caso 3
            {
                if (q == v->right) //se q for o filho a direita de v
                {
                    q = v;                           //q recebe v
                    leftRotation(raiz, &q, externo); //Rotação a esquerda tendo q como pivô
                }
                //Condição que representa o caso 4
                setColor(q->dad, BLACK);          //pai de q recebe cor negro
                setColor(w, RED);                 //w recebe cor vermelha
                rightRotation(raiz, &w, externo); //rotação a direita tendo w como pivô
            }
        }
        else //Processo simétrico ao anterior, substituindo left por right e vice versa
        {
            t = w->left;
            if (getColor(t) == RED)
            {
                setColor(v, BLACK);
                setColor(t, BLACK);
                setColor(w, RED);
                q = w;
            }
            else
            {
                if (q == v->left)
                {
                    q = v;
                    rightRotation(raiz, &q, externo);
                }
                setColor(q->dad, BLACK);
                setColor(w, RED);
                leftRotation(raiz, &w, externo);
            }
        }
    }
    setColor(raiz->root, BLACK); //a raiz recebe a cor negra
}

//Função de inserção de novo nó  //Por fim, a raiz recebe a cor negrona árvore
void insertRB(RaizRB *raiz, NodeArvRB *q, int(compararValores)(void *, void *), NodeArvRB *externo)
{
    NodeArvRB *x, *v;
    v = externo;
    x = raiz->root;
    while (x != externo) //Enquanto x nao for o nó externo
    {
        if (compararValores(x->info, q->info) == 0) //Se o elemento que desera inserir ja estiver presente na árvore
            return;
        v = x;
        if (compararValores(q->info, x->info) < 0) //Se o elemento que deseja ser inserido for menor que x
            x = x->left;                           //x recebe seu filho a esquerda
        else                                       //Se for maior
            x = x->right;                          //x recebe seu filho a direita
    }
    q->dad = v;         //q->pai recebe v
    if (v == externo)   //se v é o externo, quer dizer que a árvore é vazia.
        raiz->root = q; //logo a raiz se torna q
    else
    {
        if (compararValores(q->info, v->info) < 0) //se q for menor v
            v->left = q;                           //q é filho a esquerda
        else                                       //caso seja maior que v
            v->right = q;                          //q é filho a direita
    }
    q->left = externo;               //o filho a esquerda de q recebe externo
    q->right = externo;              //o filho a direita de q recebe externo
    setColor(q, RED);                //q recebe a cor vermelha
    RBinsertFixup(raiz, q, externo); //é chamada a RBinsertFixup pra corrigir alguma possível violação
}

//Função que encontra o nó sucessor do nó a ser removido
NodeArvRB *findSmallestRB(NodeArvRB *node, NodeArvRB *externo)
{
    if (node->left == externo)
        return node; //Encontrou ultimo elemento a esquerda
    else
        return findSmallestRB(node->left, externo); //Recursão à esquerda
}

//Função que troca apontamentos dos pais dos nós
void RBTransferePai(RaizRB *T, NodeArvRB *u, NodeArvRB *v, NodeArvRB *externo)
{
    if (u->dad == externo) //u é raiz da árvore
        T->root = v;       //raiz aponta pra v
    else
    {
        if (u == u->dad->left) //u é filho à esquerda
            u->dad->left = v;  //v vira filho à esquerda do pai de u
        else
            u->dad->right = v; //v vira filho à direita do pai de u
    }
    v->dad = u->dad; //pai de v recebe pai de u
}

void RBRemocao(RaizRB *T, NodeArvRB *z, NodeArvRB *externo)
{
    NodeArvRB *x, *y;
    int corDeY;
    //Para o caso 2 (Só tem 1 filho)
    y = z;
    corDeY = getColor(y); //variavel responsavel por guardar a cor de y

    if (z->left == externo) //Condição que representa o caso 2 com a raiz tendo filho à esquerda
    {
        x = z->right;                            //x recebe o filho a direita de z
        RBTransferePai(T, z, z->right, externo); //transferencia de pai entre z e seu filho a direita
    }
    else
    {
        if (z->right == externo) //Condição que representa o caso 2 com a raiz tendo filho à direita
        {
            x = z->left;                            //x recebe o filho a esquerda de z
            RBTransferePai(T, z, z->left, externo); //transferencia de pai entre z e seu filho a esquerda
        }
        else //Condição que representa o caso 3
        {
            y = findSmallestRB(z->right, externo); //y recebe o secessor do filho a direita de z
            corDeY = getColor(y);                  //corDeY recebe a cor de y
            x = y->right;                          //x recebe o filho à direita de y
            if (y->dad == z)                       //se o sucessor é filho da raiz
            {
                x->dad = y; //pai de x recebe y
            }
            else //Se o sucessor não é filho da raiz
            {
                RBTransferePai(T, y, y->right, externo); //transferencia de pai entre y e seu filho a direita
                y->right = z->right;                     //filho a direita de y recebe filho a direita de z
                y->right->dad = y;                       //pai do filho a direita de y recebe y
            }
            RBTransferePai(T, z, y, externo); //transferencia de pai entre z e y
            y->left = z->left;                //filho a esquerda de y recebe filho a esquerda de z
            y->left->dad = y;                 //pai do filho a esquerda de y recebe y
            setColor(y, getColor(z));         //y recebe a cor de z
        }
    }
    if (corDeY == BLACK)              //se a corDeY fornegra
        RBDeleteFixup(T, x, externo); //correcao de violacao
}

void RBDeleteFixup(RaizRB *raiz, NodeArvRB *x, NodeArvRB *externo)
{
    NodeArvRB *w;
    while (x != raiz->root && getColor(x) == BLACK) //Enquanto x for diferente da raiz e a cor de x for negra
    {
        if (x == x->dad->left) //se x for filho à esquerda de seu pai
        {
            w = x->dad->right;
            if (getColor(w) == RED) //Essa condição refere-se ao caso de violação 3.1
            {
                setColor(w, BLACK);                     //w recebe a cor negra
                setColor(x->dad, RED);                  //O pai de X recebe rubro
                leftRotation(raiz, &(x->dad), externo); //Rotação a esquerda tendo x->pai como pivô
                w = x->dad->right;                      //w recebe o filho a direita do pai de x
            }
            if (getColor(w->left) == BLACK && getColor(w->right) == BLACK) //Essa condição refere-se ao caso de violação 3.2
            {
                setColor(w, RED); //w recebe a cor rubro
                x = x->dad;       //x recebe seu pai
            }
            else //Essa condição refere-se aos casos de violação 3.3 e 3.4
            {
                if (getColor(w->right) == BLACK) //Se o filho a direita de w for negro
                {
                    setColor(w->left, BLACK);         //filho a esquerda de w recebe negro
                    setColor(w, RED);                 //w recebe rubro
                    rightRotation(raiz, &w, externo); //Rotação à direita tendo w como pivô
                    w = x->dad->right;                //w recebe o filho a direita do pai de x
                }
                setColor(w, getColor(x->dad));          //w recebe a cor do pai de x
                setColor(x->dad, BLACK);                //pai de x recebe a cor negro
                setColor(w->right, BLACK);              //o filho a direita de w recebe a cor negro
                leftRotation(raiz, &(x->dad), externo); //Rotação a esquerda tendo x->pai como pivô
                x = raiz->root;                         //x recebe a raiz
            }
        }
        else //Se x for filho à direita de seu pai, processo Simétrico ao anterior, trocando left por right e vice versa
        {
            w = x->dad->left;
            if (getColor(w) == RED)
            {
                setColor(w, BLACK);
                setColor(x->dad, RED);
                rightRotation(raiz, &(x->dad), externo);
                w = x->dad->left;
            }
            if (getColor(w->right) == BLACK && getColor(w->left) == BLACK)
            {
                setColor(w, RED);
                x = x->dad;
            }
            else
            {
                if (getColor(w->left) == BLACK)
                {
                    setColor(w->right, BLACK);
                    setColor(w, RED);
                    leftRotation(raiz, &w, externo);
                    w = x->dad->left;
                }
                setColor(w, getColor(x->dad));
                setColor(x->dad, BLACK);
                setColor(w->left, BLACK);
                rightRotation(raiz, &(x->dad), externo);
                x = raiz->root;
            }
        }
    }
    setColor(x, BLACK); //Por fim, x recebe a cor negro
}

//Função que imprime o nó da arvore
void printRB(NodeArvRB *raiz, int nivel, void(imprimeNo)(void *), NodeArvRB *externo)
{
    int i;
    if (raiz != externo) //Verifica se arvore é vazia
    {
        printRB(raiz->right, nivel + 1, imprimeNo, externo); //Recursão pela direita
        for (i = 0; i < nivel; i++)
            printf("\t");                                   //Imprime tabulação conforme o tamanho do nível
        imprimeNo(raiz);                                    //Funcao generica para impressao da informacao do no
        printRB(raiz->left, nivel + 1, imprimeNo, externo); //Recursão pela esquerda
    }
}

//Auxiliar de 'destroyRB' que libera nó por nó
void auxDestroyRB(NodeArvRB *node, NodeArvRB *externo, void(freeInfoNodeRB)(NodeArvRB *node))
{
    if (node == externo) //Não precisa liberar
        return;
    auxDestroyRB(node->left, externo, freeInfoNodeRB);  //Recursão pela esquerda
    auxDestroyRB(node->right, externo, freeInfoNodeRB); //Recursão pela direita
    freeInfoNodeRB(node);                               //Libera a informação do nó
    free(node);                                         //Libera o nó em si
    return;
}

//Destroi a arvore
void destroyRB(RaizRB *raiz, NodeArvRB *externo, void(freeInfoNodeRB)(NodeArvRB *node))
{
    auxDestroyRB(raiz->root, externo, freeInfoNodeRB); //Chamada da função auxiliar para liberar nó por nó
    free(raiz);                                        //Libera a raiz
    free(externo);                                     //libera o nó externo
}