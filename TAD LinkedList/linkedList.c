#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedList.h"

// -------INMPLEMENTACAO DAS FUNCOES------------

//  Funcao que cria a lista
List* createList()
{
	List *lst = (List*)malloc(sizeof(List));

	if(lst)
	{
		lst->size = 0;
		lst->first = NULL;
		return lst;
	}else
	{
		return NULL;
	}
}


//  Funcao que cria o noh
Node* createNode(Info* valor)
{
	Node *ptr = (Node*)malloc(sizeof(Node));

	if(ptr)
	{
		ptr->info = valor;
		ptr->next = NULL;
		return ptr;
	}else
	{
		return NULL;
	}
}

//  Funcao que cria o valor no noh (info)
Info* createInfo(int valor)
{
	Info *inf = (Info*)malloc(sizeof(Info));

	if(inf)
	{
		inf->value = valor;
		return inf;
	}else
	{
		return NULL;
	}
}

//  Funcao que verifica se a lista eh vazia
bool isEmptyList(List* lst)
{
	if(lst != NULL && lst->first == NULL)
	{
		return true;
	}else
	{
		return false;
	}
}

//  Funcao que libera toda a lista
void freeList(List* lst)
{
	if(!lst || isEmptyList(lst)) return;

	Node *ptr = lst->first;

	while(ptr!=NULL)
	{
		lst->first = ptr->next;
		ptr->info = NULL;
		ptr->next = NULL;
		ptr = lst->first;
	}
	free(lst);
}

//  Funcao que devolve em qual posicao esta certo elemento
int posList(List* lst, Info* info)
{
	if(!lst || isEmptyList(lst)) return 0;

	int cont=1;

	Node *ptr = lst->first;

	while(ptr->info->value != info->value)
	{
		cont++;
		ptr = ptr->next;
	}

	if(!ptr) return 0;

	return cont;
}

//  Funcao que verifica se certo elemento esta na lista
Info* findList(List* lst, Info* inf)
{
	Node *ptr = lst->first;

	while(ptr->info->value != inf->value)
	{
		ptr = ptr->next;
		if(!ptr) return NULL;
	}
	return inf;
}

//  Funcao que retorna o tamanho da lista
int lengthList(List* lst)
{
	if(!lst || isEmptyList(lst))
	{
		if(isEmptyList(lst))
		{
			return 0;
		}else
		{
			return -1;
		}
	}

	Node *ptr = lst->first;
	int cont = 1;

	while(ptr->next != NULL)
	{
		ptr = ptr->next;
		cont++;
	}
	return cont;
}

//  Funcao que imprime a lista
void printList(List* lst)
{
	if(!lst || isEmptyList(lst))
	{
		if(isEmptyList(lst))
		{
			printf("Lista vazia!\n");
		}
		printf("Lista Nula\n");
	}

	Node *ptr = lst->first;

	printf("[ ");
	while(ptr != NULL)
	{
		printf("%d ", ptr->info->value);
		ptr = ptr->next;
	}
	printf("]\n");
}

//  Funcao que insere no comeco da lista
List* insertFirstList(List* lst, Info* info)
{
	Node *novo = (Node*)malloc(sizeof(Node));

	novo = createNode(info);

	if(!lst || !novo)
	{
		return NULL;
	}else
	{
		novo->next = lst->first;
		lst->first = novo;
		lst->size++;
		return lst;
	}
}

//  Funcao que insere na ultima posicao
List* insertLastList(List* lst, Info* info)
{
	Node *novo = (Node*)malloc(sizeof(Node));

	if(!lst || !novo) return NULL;

	novo = createNode(info);

	if(isEmptyList(lst))
	{
		lst->first = novo;
		lst->size++;
		return lst;
	}else
	{
		Node *aux = lst->first;
		while(aux->next != NULL)
		{
			aux =aux->next;
		}
		aux->next = novo;
		lst->size++;
		return lst;
	}
}

//  Funcao que insere numa certa posicao
List* insertInPositionList(List* lst, Info* info, int pos)
{
	Node *novo = (Node*)malloc(sizeof(Node));

	if(!lst || !novo) return NULL;

	novo = createNode(info);

	if(isEmptyList(lst) || pos == 1)
	{
		lst->first = novo;
		lst->size++;
		return lst;
	}else
	{
		int cont = 1;
		Node *aux = lst->first;
		while(cont<pos-1)
		{
			cont++;
			aux = aux->next;
		}
		novo->next = aux->next;
		aux->next = novo;
		lst->size++;
		return lst;
	}
}

//  Funcao que insere em ordem (considerando que a lista esta ordenada)
List* insertInOrderList(List* lst, Info* info)
{
	Node *novo = (Node*)malloc(sizeof(Node));

	if(!lst || !novo) return NULL;

	novo = createNode(info);

	if(isEmptyList(lst))
	{
		insertFirstList(lst,info);
		return lst;
	}else
	{
		Node *aux = lst->first;

        if(aux->info->value > novo->info->value)
        {
            novo->next = aux;
            lst->first = novo;
            lst->size++;
            return lst;
        }

		if(aux->info->value == info->value)
		{
			novo->next = aux->next;
			aux->next = novo;
			lst->size++;
			return lst;
		}
		while(aux->next->info->value < novo->info->value)
		{
			aux = aux->next;
			if (aux->next == NULL)
            {
                aux->next = novo;
                lst->size++;
                return lst;
            }
		}

		novo->next = aux->next;
		aux->next = novo;
		lst->size++;
		return lst;
	}
}

//  Funcao que deleta o primeiro elemento
void deleteFirstList(List* lst)
{
	if(!lst || isEmptyList(lst)) return;

	Node *aux = lst->first;
	lst->first = aux->next;
	free(aux);
	lst->size--;
}

//  Funcao que deleta o elemento numa certa posicao
void deletePositionList(List* lst, int pos)
{
	if(!lst || isEmptyList(lst)) return;

	if(pos > lengthList(lst) || pos <= 0)
	{
		printf("Position not exist!\n");
		return;
	}

	if(pos ==1){
		deleteFirstList(lst);
	}else{

		int cont = 1;

		Node *aux = lst->first;
		Node *sai;

		while(cont < pos-1)
		{
			aux = aux->next;
			cont++;
		}

		sai = aux->next;
		aux->next = sai->next;
		free(sai);
		lst->size--;
	}
}

//  Funcao que deleta certo elemento da lista
void deleteThisInfoList(List* lst, Info* info)
{
	if(!lst || isEmptyList(lst)) return;

	Node *aux = lst->first;

	if(aux->info->value == info->value)
	{
		deleteFirstList(lst);
		lst->size--;
	}

	while(aux->next->info->value != info->value)
	{
		aux = aux->next;
		if(!aux) return;
	}
	Node *sai = aux->next;
	aux->next = sai->next;
	free(sai);
	lst->size--;
}

//  Funcao que deleta o ultimo elemento da lista
void deleteLastList(List* lst)
{
	if(!lst || isEmptyList(lst)) return;

	Node *sai = lst->first, *aux;

	while(sai->next != NULL)
	{
		aux = sai;
		sai = aux->next;
	}

	aux->next = sai->next;
	free(sai);
	lst->size--;
}

//  Funcao que inverte totalmente uma lista
void reverseList(List* lst)
{
	if(lst == NULL) return;

	if(isEmptyList(lst)) return;

	Node *prev = NULL, *current = lst->first, *next;

	while(current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	lst->first = prev;
}

//  Funcao que ordena uma lista
void sortList(List* lst)
{
	int swap;
	Node *ptr, *aux;

	if(isEmptyList(lst)) return;

	do{
		swap = 0;
		ptr = lst->first;

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
