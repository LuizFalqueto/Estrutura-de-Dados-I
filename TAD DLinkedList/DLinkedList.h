#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

// --------ESTRUTURAS DA LISTA-------------
typedef struct {
	int value;
}Info;

typedef struct tnode{
	Info *info;
	struct tnode *next,*prev;
}Node;

typedef struct {
	int size;
	Node *first;
}DList;

//---------ASSINATURAS DAS FUNCOES------------

//  Funcao que cria a lista
DList* createDList();

//  Funcao que cria o noh
Node* createNode(Info* valor);

//  Funcao que cria o valor no noh (info)
Info* createInfo(int valor);

//  Funcao que libera toda a lista
void freeDList(DList* dlst);

//  Funcao que verifica se a lista eh vazia
bool isEmptyDList(DList* dlst);

//  Funcao que devolve em qual posicao esta certo elemento
int posDList(DList* dlst, Info* info);

//  Funcao que verifica se certo elemento esta na lista
bool findDList(DList* dlst, Info* inf);

//  Funcao que retorna o tamanho da lista
int lengthDList(DList* dlst);

//  Funcao que imprime a lista
void printDList(DList* dlst);

//  Funcao que insere no comeco da lista
DList* insertFirstDList(DList* dlst, Info* info);

//  Funcao que insere na ultima posicao
DList* insertLastDList(DList* dlst, Info* info);

//  Funcao que insere numa certa posicao
DList* insertInPositionDList(DList* dlst, Info* info, int pos);

//  Funcao que insere em ordem (considerando que a lista esta ordenada)
DList* insertInOrderDList(DList* dlst, Info* info);

//  Funcao que deleta o primeiro elemento
void deleteFirstDList(DList* dlst);

//  Funcao que deleta o elemento numa certa posicao
void deletePositionDList(DList* dlst, int pos);

//  Funcao que deleta certo elemento da lista
void deleteThisInfoDList(DList* dlst, Info* info);

//  Funcao que deleta o ultimo elemento da lista
void deleteLastDList(DList* dlst);

//  Funcao que inverte totalmente uma lista
void reverseDList(DList* dlst);

//  Funcao que ordena uma lista
void sortDList(DList* dlst);

#endif // DLINKEDLIST_H
