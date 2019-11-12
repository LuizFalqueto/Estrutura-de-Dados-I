/*------------------------------------------------------------------------------------------------
Trabalho Pratico 1 - Skip List - Estrutura de Dados I - CEUNES - UFES
Autor:  Luiz Gustavo Falqueto Baptista
Matricula:  2017203673
Data de criação:    22/10/2019
Objetivo:   objetivo geral é a implementacao de uma estrutura de dados "Skip List".

Arquivo (skipList.c) - Implementacao das funcoes da estrutura
------------------------------------------------------------------------------------------------*/
#include  <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "skipList.h"

/*
    Funcao createNode(int key, int height) cria um novo no da estrutura
    Entrada: valor da chave a ser inserida, altura do noh
    Saida: ponteiro para o no criado
*/
Node* createNode(int key, int height)
{
    Node *novo = (Node*)malloc(sizeof(Node));//Alocando memoria para o novo noh

    if(!novo) return NULL;//Caso ocorra erro na alocacao

    novo->nivel = height;//Atribuindo a altura do noh
    novo->valor = key;//Atribuindo valor do noh

    novo->apontadores = malloc((height+1)*sizeof(Node*));//Alocando memoria para o vetor de apontadores do novo noh

    for(int i=0 ; i<(novo->nivel)+1; i++)
    {
        novo->apontadores[i]=NULL;//Setando todos apontadores para NULL
    }

    return novo;//Retornando o noh criado
}

/*
    Funcao createList(SkipList *lst) cria uma nova "cabeca" da estrutura
    Entrada: lista do tipo SkipList
    Saida: vazio
*/
SkipList* createList()
{
    SkipList *lst = (SkipList*)malloc(sizeof(SkipList));//Alocando memoria para a SkipList

    lst->first = createNode(-1,MAX_NIVEIS);//Atribuindo um novo noh ao primeiro elemento da SkipList
    lst->heigth = MAX_NIVEIS;//Atribuindo a altura da SkipList

    return lst;//Retornando a SkipList criada
}

/*
    Funcao isEmptyList(SkipList *lst) informa se a lista esta vazia ou nao
    Entrada: lista do tipo SkipList
    Saida: 1(vazio), 0(cheio)
*/
int isEmptyList(SkipList *lst)
{
    if(!lst) return 0;//Caso a SkipList seja nula

    if(lst->first == NULL)//Caso a SkipList seja vazia
    {
        return 0;
    }

    Node *ptr = lst->first;//Preparando o ptr para percorrer verificando se a SkipList esta vazia

    for(int i=0; i<MAX_NIVEIS+1 ; i++)
    {
        if(ptr->apontadores[i] != NULL)//Caso existe um elemento
        {
            return 0;
        }
    }
    return 1;
}

/*
    Funcao printListH(SkipList *lst, int h) imprime uma lista de ponteiros referente a certo nivel da estrutura
    Entrada: lista do tipo SkipList, nivel a ser impresso
    Saida: vazio
*/
void printListH(SkipList *lst, int h, FILE *saida)
{
    if(!lst || isEmptyList(lst))//Caso a SkipLis seja nula ou vazia
    {
        fprintf(saida,"false\n");//Insere "false" no arquivo de saida
        return;
    }

    if(h > (lst->first->nivel)-1)//Caso a altura informada seja maior que a altura da SkipList
                                //(nao foi tratado de atualizar a SkipList para uma outra altura)
    {
        fprintf(saida,"false\n");//Insere "false" no arquivo de saida
        return;
    }

    Node *ptr;
    ptr=lst->first->apontadores[h];//Prepara ptr no primeiro elemento da altura informada

    while(ptr != NULL)
    {
        fprintf(saida,"%d %d\n",ptr->valor,h);//Insere os valores dos nohs visitados no arquivo de saida
        ptr = ptr->apontadores[h];
    }
}

/*
    Funcao printList(SkipList *lst) imprime a lista
    Entrada: lista do tipo SkipList
    Saida: vazio
*/
void printList(SkipList *lst,FILE *saida)
{
    if(!lst || isEmptyList(lst))//Caso a SkipLis seja nula ou vazia
    {
        fprintf(saida,"false");//Insere "false" no arquivo de saida
        return;
    }

    Node *ptr = lst->first;

    for(int i= (ptr->nivel)-1 ; i>=0; i--)
    {
        ptr = lst->first->apontadores[i];//Prepara ptr no primeiro elemento da altura "i" do laco

        while(ptr != NULL)
        {
            fprintf(saida,"%d %d\n",ptr->valor,i);//Insere os valores dos nohs visitados no arquivo de saida
            ptr = ptr->apontadores[i];
        }
    }
}

/*
    Funcao searchList(int chave,  SkipList *lst, Node *ListaH[], int imprimir) procura um elemento na lista
    Entrada: chave a ser procurada, lista do tipo SkipList, lista de ponteiros, variavel para imprimir o valor das chaves
    Saida: valor da chave procurada
*/
int searchList(int chave,  SkipList *lst,FILE *saida)
{
    if(!lst)//Caso a SkipLis seja nula
    {
        fprintf(saida,"false\n");//Insere "false" no arquivo de saida
        return 0;
    }

    if(lst->first == NULL || lst->first->apontadores[0] == NULL)//Caso a SkipLis seja vazia
    {
        fprintf(saida,"false\n");//Insere "false" no arquivo de saida
        return 0;
    }

    Node *ptr = lst->first;

    for(int i = (ptr->nivel)-1; i>=0 ; i--)
    {
        while(ptr->apontadores[i] != NULL && ptr->apontadores[i]->valor < chave)
        {
            ptr = ptr->apontadores[i];
        }
    }

    if(ptr->apontadores[0] != NULL)
    {
        if(ptr->apontadores[0]->valor == chave)//Encontrou a chave
        {
            fprintf(saida,"true\n");//Insere "true" no arquivo de saida
            return 1;
        }else
        {
            fprintf(saida,"false\n");//Insere "false" no arquivo de saida
            return 0;
        }
    }else
    {
        fprintf(saida,"false\n");//Insere "false" no arquivo de saida
        return 0;
    }
}

/*
    Funcao insereList(int x, int h, SkipList *lst) insere um elemento na lista
    Entrada: valor da chave a ser inserida, nivel da estrutura a ser inserido, lista do tipo SkipList
    Saida: 1(feito), 0(nao feito)
*/
int insereList(int x, int h, SkipList *lst,FILE *saida)
{
    if(!lst)//Se a lista eh nula
    {
        fprintf(saida,"false\n");//Insere "false" no arquivo de saida
        return 0;
    }

    if(h >= lst->first->nivel)//Se altura informada eh maior que a altura da SkipList
    {
        fprintf(saida,"false\n");//Insere "false" no arquivo de saida
        return 0;
    }

    if(lst->first->apontadores[0] == NULL)//Se lista eh vazia
    {
        fprintf(saida,"false\n");//Insere "false" no arquivo de saida
        Node *novo = createNode(x,h);//Criando novo noh

        for(int k = 0 ; k<h+1 ; k++)//Procura local de insercao
        {
            lst->first->apontadores[k] = novo;
        }
        fprintf(saida,"true\n");//Insere "true" no arquivo de saida
        return 1;
    }

    int busca = searchList(x,lst,saida);//Verifica se o elemento existe na lista
    if(busca==1)//Existe na lista
    {
        fprintf(saida,"false\n");//Insere "true" no arquivo de saida
        return 0;

    }else{

        Node **ListaH = malloc((MAX_NIVEIS+1)*sizeof(Node*));//Aloca memoria para um vetor que aponta para os nohs visitados
        Node *novo = lst->first;

        for(int i = (novo->nivel)-1 ; i>= 0 ; i--)//Procura local de insercao
        {
            while(novo->apontadores[i] != NULL && novo->apontadores[i]->valor < x)
            {
                novo=novo->apontadores[i];
            }
            ListaH[i] = novo;//Armazena o vetor atual no vetor ListaH
        }

        if(novo->apontadores[0] == NULL || novo->apontadores[0]->valor != x)//Se o proximo noh eh nulo ou diferente da chave informada
        {
            int j;
            Node *ptr;

            if(ptr = createNode(x,h))//Se criacao do noh deu certo
            {
                for(j = 0 ; j <= h ; j++)//Insere o noh e atualiza apontamento dos nohs anteriores
                {
                    ptr->apontadores[j] = ListaH[j]->apontadores[j];
                    ListaH[j]->apontadores[j] = ptr;
                }
                fprintf(saida,"true\n");//Insere "true" no arquivo de saida
                return 1;
            }
        }
    }
}

/*
    Funcao removeList(int chave, SkipList *lst) remove um elemento da lista
    Entrada: valor da chave a ser removida, lista do tipo SkipList
    Saida: 1(feito), 0(nao feito)
*/
int removeList(int chave, SkipList *lst,FILE *saida)
{
    if(!lst || isEmptyList(lst))//Se a lista eh nula ou vazia
    {
        fprintf(saida,"false\n");//Insere "false" no arquivo de saida
        return 0;
    }

    int busca = searchList(chave,lst,saida);//verifica se a chave informada existe na lista

    if(busca==0)//Chave nao exista na lista
    {
        fprintf(saida,"false\n");//Insere "false" no arquivo de saida
        return 0;
    }else{
        int i;
        Node **ListaH = malloc((MAX_NIVEIS+1)*sizeof(Node*)), *ptr = lst->first;//Aloca memoria para um vetor que aponta para os nohs visitados

        for(i = (ptr->nivel)-1 ; i>= 0 ; i--)
        {
            while(ptr->apontadores[i] != NULL && ptr->apontadores[i]->valor < chave)
            {
                ptr=ptr->apontadores[i];
            }
            ListaH[i+1] = ptr;//Armazena o vetor atual no vetor ListaH
        }

        ptr=ptr->apontadores[0];

        if(ptr->valor == chave)//Encontrou a chave
        {
            for(i=0; i<=ptr->nivel ; i++)
            {
                ListaH[i+1]->apontadores[i] = ptr->apontadores[i];
            }

            free(ptr);//Libera a memoria do noh removido
            fprintf(saida,"true\n");//Insere "false" no arquivo de saida
            return 1;
        }
    }
}

/*
    Funcao readFile(FILE *entrada) manipula dados de um arquivo
    Entrada: ponteiro do tipo FILE
    Saida: 1(feito) ou 0(nao feito)
*/
int readFile(FILE *entrada)
{
   FILE *saida;

   saida = fopen("saida.txt","w");//Abre arquivo de saida

   if(saida == NULL)//Caso a abertura do arquivo deu erro
    {
        printf("\nFalha ao abrir o arquivo de saida!\n");
        printf("Favor verificar o diretorio do arquivo.\n");
        printf("Se necessario, altere o primeiro parametro de fopen(...).\n");
        return 0;
    }

    /*Inicializacao e criacao da estrutura SkipList*/
    SkipList *lst = createList();//Cria lista

    if(!lst)//Caso alocacao da memoria nao deu certo
    {
        printf("\n ERRRO: MEMORIA INSUFICIENTE.\n");
        return 0;
    }


    char comando;//Variavel para armazenar o primeiro caracter de cada linha da entrada
    int valor, altura; //Variaveis que recebem os valores a serem utilizados na estrutura
    int insere, busca, remove; //Variaveis que recebem vaalores retornados de funcoes

    while(!feof(entrada) && fscanf(entrada,"%c",&comando))
    {

        switch (comando)//Acoes exercidas de acordo com a leitura do primeiro caracter
        {
            case 'I': //Comando de inserir na estrutura
                fscanf(entrada,"%d", &valor);//Ler o proximo caracter do arquivo
                fscanf(entrada,"%d", &altura);//Ler o proximo caracter do arquivo

                insere = insereList(valor,altura,lst,saida);//Insercao da lista

                break;
            case 'B': //Comando de buscar na estrutura
                fscanf(entrada,"%d", &valor);//Ler o proximo caracter do arquivo

                busca = searchList(valor,lst,saida);//Busca na lista

                break;
            case 'P': //Comando de imprimir elementos de uma certa altura da estrutura
                fscanf(entrada,"%d", &altura);//Ler o proximo caracter do arquivo

                printListH(lst,altura,saida);//Impressao de elementos de uma certa altura da lista
                break;
            case 'R': //Comando que remove elementos da estrutura
                fscanf(entrada,"%d", &valor);//Ler o proximo caracter do arquivo

                remove = removeList(valor,lst,saida);//Remocao de um elemento da lista
                break;
            case 'A': //Comando que imprimi todos elementos da estrutura do nivel mais alto ate o mais baixo
                fscanf(entrada,"%c",&comando);//Ler o proximo caracter do arquivo

                printList(lst,saida);//Impressao da lista completa
            default:
                break;
        }
    }

    /*Fechando arquivo de saida*/
    fclose(saida);
    return 1;
}


