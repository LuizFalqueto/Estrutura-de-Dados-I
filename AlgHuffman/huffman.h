#ifndef HUFFMAN_H
#define HUFFMAN_H

typedef struct noHuff
{
    char caracter;
    int freq;
    struct noHuff *left, *right, *next;
} NoHuff;

typedef struct heapHuff
{
    int sizeHeap;
    struct NoHuff *first;
} HeapMin;

NoHuff *createNohHuff(char *c, int frequencia);

HeapMin *createHeapMin();

void freeHeapMin(HeapMin *heap);

int isEmptyHeapMin(HeapMin *heap);

int findHeapMin(HeapMin *heap, char *c);

void insertHeapMin(HeapMin *heap, NoHuff *no);

NoHuff *deleteHeapMin(HeapMin *heap);

void printHeapMin(HeapMin *heap);

#endif //HUFFMAN_H