#ifndef LINKEDLIST
#define LINKEDLIST

// --------ESTRUTURAS DA LISTA-------------
typedef struct {
	int value;
}Info;

typedef struct tnode{
	Info *info;
	struct tnode *next;
}Node;

typedef struct {
	int size;
	Node *first;
}List;

//---------ASSINATURAS DAS FUNCOES------------

//  Funcao que cria a lista
List* createList();

//  Funcao que cria o noh
Node* createNode(Info* valor);

//  Funcao que cria o valor no noh (info)
Info* createInfo(int valor);

//  Funcao que libera toda a lista
void freeList(List* lst);

//  Funcao que verifica se a lista eh vazia
bool isEmptyList(List* lst);

//  Funcao que devolve em qual posicao esta certo elemento
int posList(List* lst, Info* info);

//  Funcao que verifica se certo elemento esta na lista
Info* findList(List* lst, Info* inf);

//  Funcao que retorna o tamanho da lista
int lengthList(List* lst);

//  Funcao que imprime a lista
void printList(List* lst);

//  Funcao que insere no comeco da lista
List* insertFirstList(List* lst, Info* info);

//  Funcao que insere na ultima posicao
List* insertLastList(List* lst, Info* info);

//  Funcao que insere numa certa posicao
List* insertInPositionList(List* lst, Info* info, int pos);

//  Funcao que insere em ordem (considerando que a lista esta ordenada)
List* insertInOrderList(List* lst, Info* info);

//  Funcao que deleta o primeiro elemento
void deleteFirstList(List* lst);

//  Funcao que deleta o elemento numa certa posicao
void deletePositionList(List* lst, int pos);

//  Funcao que deleta certo elemento da lista
void deleteThisInfoList(List* lst, Info* info);

//  Funcao que deleta o ultimo elemento da lista
void deleteLastList(List* lst);

//  Funcao que inverte totalmente uma lista
void reverseList(List* lst);

//  Funcao que ordena uma lista
void sortList(List* lst);

#endif //LINKEDLIST
