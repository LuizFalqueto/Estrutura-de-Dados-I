#ifndef QUEUE_H
#define QUEUE_H

// --------ESTRUTURAS DA QUEUE -------------
typedef struct {
	int value;
}Info;

typedef struct tnode{
	Info *info;
	struct tnode *next;
}Node;

typedef struct {
	int size;
	Node *first, *last;
}Queue;

//---------ASSINATURAS DAS FUNCOES------------

//  Funcao que cria a queue
Queue* createQueue();

//  Funcao que cria o noh
Node* createNode(Info* valor);

//  Funcao que cria o valor no noh (info)
Info* createInfo(int valor);

//  Funcao que libera toda a queue
void freeQueue(Queue* queue);

//  Funcao que verifica se a queue eh vazia
bool isEmptyQueue(Queue* queue);

//  Funcao que retorna o tamanho da queue
int lengthQueue(Queue* queue);

//  Funcao que imprime a queue
void printQueue(Queue* queue);

//  Funcao que insere na queue
bool insertQueue(Queue* queue, Info* info);

//  Funcao que deleta um elemento da queue
Info* removeQueue(Queue* queue);

#endif // QUEUE_H
