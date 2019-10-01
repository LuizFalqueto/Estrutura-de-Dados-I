#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

// ------- IMPLEMENTACAO DAS FUNCOES -------

//  Funcao que cria a queue
Queue* createQueue()
{
	Queue *ptr = (Queue*)malloc(sizeof(Queue));

	if(ptr)
	{
		ptr->first = ptr->last = NULL;
		ptr->size = 0;
		return ptr;
	}
	return NULL;
}

//  Funcao que cria o noh
Node* createNode(Info* valor)
{
	Node *ptr = (Node*)malloc(sizeof(Node));

	if(ptr)
	{
		ptr->next = NULL;
		ptr->info = valor;
		return ptr;
	}
	return NULL;
}

//  Funcao que cria o valor no noh (info)
Info* createInfo(int valor)
{
	Info *ptr = (Info*)malloc(sizeof(Info));

	if(ptr)
	{
		ptr->value = valor;
		return ptr;
	}
	return NULL;
}

//  Funcao que libera toda a queue
void freeQueue(Queue* queue)
{
	if(!queue) return;

	Node *sai;

	while(queue->first)
	{
	    sai = queue->first->next;
		free(queue->first->info);
		free(queue->first);
		queue->first = sai;
	}
	getchar();
	printf("\nFree Queue successfully!\n");

	free(queue);
}

//  Funcao que verifica se a queue eh vazia
bool isEmptyQueue(Queue* queue)
{
	if(queue != NULL && queue->first == NULL && queue->last == NULL)
	{
		return true;
	}else
	{
		return false;
	}
}

//  Funcao que retorna o tamanho da queue
int lengthQueue(Queue* queue)
{
	if(!queue || isEmptyQueue(queue))
	{
		if(isEmptyQueue(queue))
		{
			return 0;
		}else
		{
			return -1;
		}
	}

	Node *ptr = queue->first;
	int cont = 1;

	while(ptr != queue->last)
	{
		ptr = ptr->next;
		cont++;
	}
	return cont;
}

//  Funcao que imprime a queue
void printQueue(Queue* queue)
{
	if(isEmptyQueue(queue))
	{
		printf("Fila vazia!\n");
		return;
	}

	if(!queue)
	{
		printf("Fila nula!\n");
		return;
	}

	Node *ptr = queue->first;

	printf("[ ");
	while(ptr != NULL)
	{
		printf("%d ", ptr->info->value);
		ptr = ptr->next;
	}
	printf("]\n");
}

//  Funcao que insere na queue
bool insertQueue(Queue* queue, Info* info)
{
    Node *novo = createNode(info);

	if(!queue || !novo) return false;

	if(isEmptyQueue(queue))
	{
		queue->first = novo;
	}else
	{
		queue->last->next = novo;
		
	}
	queue->last = novo;
	queue->size++;
	return true;
}

//  Funcao que deleta um elemento da queue
Info* removeQueue(Queue* queue)
{
	if(!queue || isEmptyQueue(queue)) return NULL;

	Node *sai = queue->first;

	queue->first = sai->next;
	Info *inf = sai->info;
	free(sai);
	queue->size--;
}
