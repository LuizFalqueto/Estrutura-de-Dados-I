#ifndef STACK_H
#define STACK_H

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
	Node *top;
}Stack;

//---------ASSINATURAS DAS FUNCOES------------

// funcoes que criam os elementos da estrutura
Stack* createStack(); //cria a pilha
Node* createNode(Info* valor); // cria o noh
Info* createInfo(int valor); // cria o valor informacao armazenado

// retorna se vazia ou nao
bool isEmptyStack(Stack* stack);

// funcao que libera a pilha
bool freeStack(Stack* stack);

// retorna tamanho da pilha
int lengthStack(Stack* satck);

// imprime a pilha
void printStack(Stack* stack);

// insere elemento na pilha
bool push(Stack* satck, Info* info);

// retira um elemento da pilha
Info* pop(Stack* stack);

#endif // STACK_H
