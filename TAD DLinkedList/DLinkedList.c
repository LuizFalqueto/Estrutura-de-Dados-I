#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "DLinkedList.h"

//---------IMPLEMENTACAO DAS FUNCOES------------

//  Funcao que cria a lista
DList* createDList()
{
	DList *dlst;
	if(dlst = (DList*)malloc(sizeof(DList)))
	{
		dlst->first = NULL;
		dlst->size = 0;
		return dlst;
	}else
	{
		return NULL;
	}
}

//  Funcao que cria o noh
Node* createNode(Info* valor)
{
	Node *novo;
	if(novo=(Node*)malloc(sizeof(Node)))
	{
		novo->info = valor;
		novo->next = NULL;
		novo->prev = NULL;
		return novo;
	}else
	{
		return NULL;
	}
}

//  Funcao que cria o valor no noh (info)
Info* createInfo(int valor)
{
	Info *inf;
	if(inf=(Info*)malloc(sizeof(Info)))
	{
		inf->value = valor;
		return inf;
	}else
	{
		return NULL;
	}
}

//  Funcao que verifica se a lista eh vazia
bool isEmptyDList(DList* dlst)
{
	if(!dlst) return false;
	if(dlst->first == NULL) return true;
	else return false;
}


//  Funcao que libera toda a lista
void freeDList(DList* dlst)
{
	if(!dlst) return;
	if(isEmptyDList(dlst)) return;

	Node *aux;

	while(aux)
	{
		aux=dlst->first;
		dlst->first=aux->next;
		free(aux);
	}
	free(dlst);
}

//  Funcao que devolve em qual posicao esta certo elemento
int posDList(DList* dlst, Info* info)
{
	if(!dlst)
	{
		printf("Lista Nula!\n");
		return -1;
	}

	if(isEmptyDList(dlst))
	{
		printf("Lista Vazia!\n");
		return -1;
	}

	int cont=1;

	Node *ptr = dlst->first;

	while(ptr->info->value != info->value)
	{
		cont++;
		ptr = ptr->next;
	}

	if(!ptr) return 0;

	return cont;
}

//  Funcao que verifica se certo elemento esta na lista
bool findDList(DList* dlst, Info* inf)
{
	if(!dlst) return false;
	if(isEmptyDList(dlst)) return false;

	Node *ptr = dlst->first;

	while(ptr->info->value != inf->value)
	{
		ptr = ptr->next;
		if(!ptr) return false;
	}
	return true;
}

//  Funcao que retorna o tamanho da lista
int lengthDList(DList* dlst)
{
	if(!dlst) return -1;
	if(isEmptyDList(dlst)) return 0;

	return dlst->size;
}

//  Funcao que imprime a lista
void printDList(DList* dlst)
{
	if(!dlst)
	{
		printf("Lista Nula!\n");
		return;
	}

	if(isEmptyDList(dlst))
	{
		printf("Lista Vazia!\n");
		return;
	}

	Node *ptr = dlst->first;

	printf("[ ");
	while(ptr != NULL)
	{
		printf("%d ", ptr->info->value);
		ptr = ptr->next;
	}
	printf("]\n");
}

//  Funcao que insere no comeco da lista
DList* insertFirstDList(DList* dlst, Info* info)
{
	if(!dlst) return NULL;

	Node *novo = createNode(info);

	if(isEmptyDList(dlst))
    {
        dlst->first = novo;
        dlst->size++;
        return dlst;
    }

	if(novo)
	{
		novo->next = dlst->first;
		dlst->first->prev = novo;
		dlst->first = novo;
		dlst->size++;
		return dlst;
	}else
	{
		return NULL;
	}
}

//  Funcao que insere na ultima posicao
DList* insertLastDList(DList* dlst, Info* info)
{
	if(!dlst) return NULL;
	if(isEmptyDList(dlst))
	{
		insertFirstDList(dlst,info);
		return dlst;
	}

	Node *aux=dlst->first, *new = createNode(info);

	if(new)
	{
		while(aux->next != NULL)
		{
			aux=aux->next;
		}

		aux->next=new;
		new->prev=aux;
		dlst->size++;
		return dlst;
	}
}

//  Funcao que insere numa certa posicao
DList* insertInPositionDList(DList* dlst, Info* info, int pos)
{
	if(!dlst) return NULL;
	if(isEmptyDList(dlst) || pos==0)
	{
		insertFirstDList(dlst,info);
		return dlst;
	}

	if(pos>dlst->size)
	{
		insertLastDList(dlst,info);
		return dlst;
	}

	int cont=1;
	Node *aux = dlst->first, *new=createNode(info);

	while(cont<pos-1)
	{
		aux=aux->next;
		cont++;
	}

	new->next=aux->next;
	new->prev=aux;
	aux->next->prev = new;
	aux->next=new;
	dlst->size++;
	return dlst;
}

//  Funcao que insere em ordem (considerando que a lista esta ordenada)
DList* insertInOrderDList(DList* dlst, Info* info)
{
	if(!dlst) return NULL;
	if(isEmptyDList(dlst))
	{
		insertFirstDList(dlst,info);
		return dlst;
	}

	Node *aux = dlst->first, *new=createNode(info);

	if(aux->info->value > new->info->value)
    {
        insertFirstDList(dlst,info);
		return dlst;
    }

	while(aux->info->value < info->value) aux=aux->next;

	aux=aux->prev;

	if(aux)
	{
		new->next=aux->next;
		new->prev=aux;
		aux->next->prev = new;
		aux->next=new;
		dlst->size++;
		return dlst;
	}else
	{
		insertLastDList(dlst,info);
		return dlst;
	}
}

//  Funcao que deleta o primeiro elemento
void deleteFirstDList(DList* dlst)
{
	if(!dlst) return;
	if(isEmptyDList(dlst)) return;

	Node *aux = dlst->first;

	dlst->first = aux->next;
	free(aux);
	dlst->size--;
	return;
}

//  Funcao que deleta o ultimo elemento da lista
void deleteLastDList(DList* dlst)
{
	if(!dlst) return;
	if(isEmptyDList(dlst)) return;

	Node *sai = dlst->first, *aux;

	while(sai->next != NULL)
	{
	    aux=sai;
		sai=sai->next;
	}

	aux->next=sai->next;
	free(sai);
	dlst->size--;
	return;
}

//  Funcao que deleta o elemento numa certa posicao
void deletePositionDList(DList* dlst, int pos)
{
	if(!dlst) return;
	if(isEmptyDList(dlst)) return;

	if(pos==0)
	{
		deleteFirstDList(dlst);
		return;
	}

	if(pos>dlst->size)
	{
		deleteLastDList(dlst);
		return;
	}

	int cont=1;
	Node *aux = dlst->first;

	while(cont < pos-1)
	{
		cont++;
		aux=aux->next;
	}

	aux=aux->next;

	aux->prev->next=aux->next;
	aux->next->prev=aux->prev;
	free(aux);
	dlst->size--;
	return;
}

//  Funcao que deleta certo elemento da lista
void deleteThisInfoDList(DList* dlst, Info* info)
{
	if(!dlst) return;
	if(isEmptyDList(dlst)) return;
	if(!findDList(dlst,info))
	{
		printf("\nValor nao encontrado!\n");
		return;
	}

	Node *aux = dlst->first;

	if(aux->info->value == info->value)
    {
        deleteFirstDList(dlst);
        return;
    }

	while(aux->next->info->value != info->value)
    {
        aux=aux->next;
        if(!aux) return;
    }

    Node *sai = aux->next;

    if(!sai->next)
    {
        deleteLastDList(dlst);
        return;
    }

    aux->next=sai->next;
    sai->next->prev=aux;

	free(sai);
	dlst->size--;
	return ;
}

//  Funcao que inverte totalmente uma lista
void reverseDList(DList* dlst)
{
	if(!dlst) return;

	if(isEmptyDList(dlst)) return;

	Node *prev = NULL, *current = dlst->first, *next;

	while(current != NULL)
	{
		next = current->next;
		current->next = prev;
		current->prev=next;
		prev = current;
		current = next;
	}
	dlst->first = prev;
}

//  Funcao que ordena uma lista
void sortDList(DList* dlst)
{
	if(!dlst) return;

	if(isEmptyDList(dlst)) return;

	int swap;
	Node *ptr, *aux;

	do{
		swap = 0;
		ptr = dlst->first;

		while(ptr->next != NULL)
		{
			if(ptr->info->value > ptr->next->info->value)
			{
				Info *temp = ptr->info;
				ptr->info = ptr->next->info;
				ptr->next->info = temp;

				swap=1;
			}
			ptr = ptr->next;
		}
		aux = ptr;
	}while(swap);
}
