#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

// ------- IMPLEMENTACAO DAS FUNCOES -------

//  Funcao que cria a stack
Stack* createStack()
{
	Stack *stk = (Stack*)malloc(sizeof(Stack));

	if(stk)
	{
		stk->size = 0;
		stk->top = NULL;
		return stk;
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

// retorna se vazia ou nao
bool isEmptyStack(Stack* stack)
{
	if(!stack) return false;
	if(!stack->top) return true;
	else
	{
		return false;
	}
}


// funcao que libera a pilha
bool freeStack(Stack* stack)
{
	if(!stack) return false;
	if(isEmptyStack(stack)) return false;

	Node *aux;

	while(stack->top != NULL)
	{
		aux = stack->top;
		stack->top = aux->next;
		free(aux);
	}
	free(stack);
	return true;
}

// retorna tamanho da pilha
int lengthStack(Stack* stack)
{
	if(!stack) return -1;
	if(isEmptyStack(stack)) return 0;

	return stack->size;
}

// imprime a pilha
void printStack(Stack* stack)
{
	if(isEmptyStack(stack))
	{
		printf("Pilha vazia!\n");
		return;
	}

	if(!stack)
	{
		printf("Pilha nula!\n");
		return;
	}

	Node *ptr = stack->top;

	printf("[ ");
	while(ptr != NULL)
	{
		printf("%d ", ptr->info->value);
		ptr = ptr->next;
	}
	printf("]\n");
}

// insere elemento na pilha
bool push(Stack* stack, Info* info)
{
	Node *novo = (Node*)malloc(sizeof(Node));

	novo = createNode(info);

	if(!stack || !novo)
	{
		return false;
	}else
	{
		novo->next = stack->top;
		stack->top = novo;
		stack->size++;
		return true;
	}
}

// retira um elemento da pilha
Info* pop(Stack* stack)
{
	if(!stack || isEmptyStack(stack)) return NULL;

	Node *aux = stack->top;
	stack->top = aux->next;
	Info* inf = aux->info;
	free(aux);
	stack->size--;
}
