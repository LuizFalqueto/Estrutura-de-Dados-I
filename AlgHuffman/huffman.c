#include <stdio.h>
#include <stdlib.h>

#include "huffman.h"

NoHuff *createNohHuff(char *c, int frequencia)
{
    NoHuff *ptr;
    if (ptr = (NoHuff *)malloc(sizeof(NoHuff)))
    {
        ptr->caracter = c;
        ptr->freq = frequencia;
        ptr->left = ptr->right = ptr->next = NULL;
        return ptr;
    }
    else
        return NULL;
}

//  Funcao que cria a lista
HeapMin *createHeapMin()
{
    HeapMin *heap = (HeapMin *)malloc(sizeof(HeapMin));

    if (heap)
    {
        heap->sizeHeap = 0;
        heap->first = NULL;
        return heap;
    }
    else
    {
        return NULL;
    }
}

//  Funcao que verifica se a lista eh vazia
int isEmptyHeapMin(HeapMin *heap)
{
    if (heap != NULL && heap->first == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//  Funcao que verifica se certo elemento esta na lista
int findHeapMin(HeapMin *heap, char *inf)
{
    NoHuff *ptr = heap->first;

    while (ptr->caracter != inf)
    {
        ptr = ptr->next;
        if (!ptr)
            return 0;
    }
    return 1;
}

//  Funcao que insere em ordem (considerando que a lista esta ordenada)
void insertHeapMin(HeapMin *heap, NoHuff *ptr)
{

    if (!heap || !ptr)
        return;

    if (isEmptyHeapMin(heap) == 1)
    {
        ptr->next = heap->first;
        heap->first = ptr;
        heap->sizeHeap++;
    }
    else
    {
        NoHuff *aux = heap->first;

        if (aux->freq > ptr->freq)
        {
            ptr->next = aux;
            heap->first = ptr;
            heap->sizeHeap++;
        }

        if (aux->freq == ptr->freq)
        {
            ptr->next = aux->next;
            aux->next = ptr;
            heap->sizeHeap++;
        }
        while (aux->next->freq < ptr->freq)
        {
            aux = aux->next;
            if (aux->next == NULL)
            {
                aux->next = ptr;
                heap->sizeHeap++;
            }
        }

        ptr->next = aux->next;
        aux->next = ptr;
        heap->sizeHeap++;
    }
}

//  Funcao que deleta o primeiro elemento
NoHuff *deleteHeapMin(HeapMin *heap)
{
    if (!heap || isEmptyHeapMin(heap) == 1)
        return NULL;

    NoHuff *aux = heap->first;
    heap->first = aux->next;
    heap->sizeHeap--;
    return aux;
}

//  Funcao que imprime a lista
void printHeapMin(HeapMin *heap)
{
    if (!heap || isEmptyHeapMin(heap) == 1)
    {
        if (isEmptyHeapMin(heap) == 1)
        {
            printf("Heap vazia!\n");
        }
        printf("Heap Nula\n");
    }

    NoHuff *ptr = heap->first;

    printf("[ ");
    while (ptr != NULL)
    {
        printf("%c ", ptr->caracter);
        ptr = ptr->next;
    }
    printf("]\n");
}