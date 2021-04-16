/*
    Implementacao de algoritmo de Arvore Rubro-Negra
    Autor: Luiz Gustavo Falqueto Baptista
    Data: 29/03/2021
    Arquivo: ArvRB.c
*/

#include "ArvRN.h"

#define RED 1
#define BLACK 0

//Função responsável por criar um nó da arvore
NodeArvRB *createNodeRB(){
    NodeArvRB *novo;
    if(novo = (NodeArvRB*)malloc(sizeof(NodeArvRB))){
        novo->cor = RED;
        novo->left = novo->right = novo->dad = NULL;
        return novo;
    }else return NULL;
}

//Função que incializa a arvore
RaizRN *createRaiz(){
    RaizRN *ptr;
    if(ptr = (RaizRN*)malloc(sizeof(RaizRN))){
        ptr->root = NULL;
        return ptr;
    }else return NULL;
}

//Função que retorna a cor do nó
int getColor(NodeArvRB *node){
    if(node == NULL) return BLACK;
    else return node->cor;
}

//Fução que troca as cores do nó
void setColor(NodeArvRB *node, int cor){
    if(!node) return;
    node->cor = cor;
}

//Função retorna o avô de um nó
// NodeArvRB *avo(NodeArvRB *node){
//     if(node && node->dad) return node->dad->dad;
//     else return NULL;
// }

//Função retorna o tio de um nó
// NodeArvRB *tio(NodeArvRB *node){
//     NodeArvRB *tAvo = avo(node);
//     if(tAvo){ //Tem avô
//         if(node->dad == tAvo->left) return tAvo->right;
//         else return tAvo->left;
//     }else return NULL; //Não tem avô
// }

//Função retorna o irmão de um nó
// NodeArvRB *irmao(NodeArvRB *node){
//     if(node && node->dad){
//         if(node == node->dad->right) return node->dad->left;
//         else return node->dad->right;
//     }else return NULL;
// }

//Função que calcula a altura da arvore
int heightAvl(NodeArvRB *raiz){
    if(!raiz) return 0; //-1 para compensar a contagem da raiz

    int tam_esq, tam_dir;

    tam_esq = 1 + heightAvl(raiz->left);
    tam_dir = 1 + heightAvl(raiz->right);

    if(tam_dir > tam_esq) return tam_dir;
    else return tam_esq;
}

//Funçao de busca de uma chave na árvore
NodeArvRB* searchRN(RaizRN *raiz, void *chave, int (compararValores)(void*, void*)){
    if(!raiz->root) return NULL;
    NodeArvRB *aux = raiz->root, *node;

    while(aux != NULL){
        if(compararValores(aux->info, chave) == 0) return aux; //Se as chaves sao iguais
        else{
            node = aux;
            if(compararValores(node->info, chave) > 0){ //Funcao compararValores retorna 1
                aux = aux->left; //Chave buscada e menor
            }else{
                //Funcao compararValores retorna -1
                aux = aux->right; //Chave buscada e maior
            }
        }
    }

    return NULL;
}

//Função de rotação esquerda
void leftRotation(RaizRN *raiz, NodeArvRB **node){
    NodeArvRB *v;
    v = (*node)->right;
    (*node)->right = v->left;

    if(v->left != NULL){
        v->left->dad = (*node);
    }

    v->dad = (*node)->dad;

    if((*node)->dad == NULL){
        raiz->root = v;
    }else{
        if((*node) == (*node)->dad->left) (*node)->dad->left = v;
        else (*node)->dad->right = v;
    }

    v->left = (*node);
    (*node)->dad = v;
}

//Função de rotação direita
void rightRotation(RaizRN *raiz, NodeArvRB **node){
    NodeArvRB *v;
    v = (*node)->left;
    (*node)->left = v->right;

    if(v->right != NULL){
        v->right->dad = (*node);
    }

    v->dad = (*node)->dad;

    if((*node)->dad == NULL){
        raiz->root = v;
    }else{
        if((*node) == (*node)->dad->right) (*node)->dad->right = v;
        else (*node)->dad->left = v;
    }

    v->right = (*node);
    (*node)->dad = v;
}

//Função auxiliar de inserção de novo nó na árvore (sobe ajustando as rotações)
void ajustaInsertRN(RaizRN *raiz, NodeArvRB *novo){
    NodeArvRB *v, *w, *t, *q;
    q = novo;
    while(getColor(q->dad)==RED){
        v = q->dad;
        w = v->dad;

        if(w==NULL){
            break;
        }

        if(v == w->left){
            t = w->right;
            if(t && getColor(t)==RED){
                setColor(v,BLACK);
                setColor(t,BLACK);
                setColor(w,RED);
                q = w;
            }else{
                if(q == v->right){
                    q = v;
                    leftRotation(raiz,&q);
                }
                setColor(q->dad,BLACK);
                setColor(w,RED);
                rightRotation(raiz,&w);
            }
        }else{
            t = w->left;
            if(t && getColor(t)==RED){
                setColor(v,BLACK);
                setColor(t,BLACK);
                setColor(w,RED);
                q = w;
            }else{
                if(q == v->left){
                    q = v;
                    rightRotation(raiz,&q);
                }
                setColor(q->dad,BLACK);
                setColor(w,RED);
                leftRotation(raiz,&w);
            }
        }
    }
    setColor(raiz->root,BLACK);
}

//Função de inserção de novo nó na árvore
int insertRN(RaizRN *raiz, NodeArvRB *novo, int (compararValores)(void*, void*)){
    NodeArvRB *aux, *auxDad;
    aux = raiz->root;

    if(!aux){
        raiz->root = novo;
        return 1;
    }

    while(aux != NULL){
        if(compararValores(aux->info,novo->info)==0) return 0;
        auxDad = aux;
        if(compararValores(aux->info,novo->info)<0) aux = aux->right;
        else aux = aux->left;
    }

    novo->dad = auxDad;
    if(compararValores(auxDad->info,novo->info)>0) auxDad->left = novo;
    else auxDad->right = novo;

    ajustaInsertRN(raiz,novo);

    return 1;
}

//Função que encontra o nó sucessor do nó a ser removido
NodeArvRB *findSmallestRN(NodeArvRB *node){
    if(!node->left) return node; //Encontrou ultimo elemento a esquerda
    else return findSmallestRN(node->left);
}

//Funcão que troca valores de dois nós
void swapContents(NodeArvRB *remove,NodeArvRB *sucessor){
    void *aux;
    aux = remove->info;
    remove->info = sucessor->info;
    sucessor->info = aux;
}

//Função de remoção de um nó na árvore
NodeArvRB *deleteRN(RaizRN *raiz, NodeArvRB *remove){

    NodeArvRB *sucessor = findSmallestRN(remove->right);
    swapContents(remove,sucessor);

    //Caso 1 (nó excluido é vermelho, nao precisa fazer nenhuma verificação)
    if(getColor(sucessor)==RED){
        sucessor->dad->left = sucessor->right;
        return sucessor;
    }else{
        if(sucessor->right && getColor(sucessor->right)==RED){
            setColor(sucessor->right,BLACK);
            sucessor->dad->left = sucessor->right;
            return sucessor;
        }
    }
}

//Função que imprime o nó da arvore
void printARN(NodeArvRB *raiz, int nivel,void (imprimeNo)(void*)){
    int i;
    if(raiz!=NULL){
        printARN(raiz->right, nivel+1, imprimeNo);
        for(i=0; i<nivel; i++) printf("\t");
        imprimeNo(raiz); //Funcao generica para impressao da informacao do no
        printARN(raiz->left, nivel+1, imprimeNo);
    }
}

//Auxiliar de 'destroyAvl' que libera nó por nó
void auxDestroyARN(NodeArvRB *node){
    if (!node) return;
    auxDestroyARN(node->left);
    auxDestroyARN(node->right);
    free(node);
    return;
}

//Destroi a arvore
void destroyARN(RaizRN *raiz){
    auxDestroyARN(raiz->root);
    free(raiz);
}