#include <stdio.h>
#include <stdlib.h>
#include "ArvBinBusca.c"


int main(){

    BST *raiz;

    raiz = createBST();

    insertBST(raiz,10);
    insertBST(raiz,2);
    insertBST(raiz,15);
    insertBST(raiz,5);
    insertBST(raiz,50);

    Node *print = raiz->raiz;
    printInOrderBST(print);

    Node *alturap = raiz->raiz;
    int altura = heightBST(alturap);
    printf("\nAltura = %d.\n",altura);

    Node *totalNO = raiz->raiz;
    int total = totalNohBST(totalNO);
    printf("Total de nos: %d\n", total);

    findLargestElementBST(raiz->raiz);
    printf("\n");
    findSmallestElementBST(raiz->raiz);

    liberaBST(raiz);

    getchar();
    return 1;
}
