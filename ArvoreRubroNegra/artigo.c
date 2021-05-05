/*
    Implementacao de algoritmo de Arvore Rubro-Negra
    Autor: Luiz Gustavo Falqueto Baptista & Eric Rabelo
    Data: 05/04/2021
    Arquivo: artigo.c
*/

#include "ArvRN.h"
#include <string.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_BLACK "\e[0;37m"
#define ANSI_COLOR_RESET "\033[0m"
#define BOLD "\033[1m"
#define BG_BLACK "\033[40m"

NodeArvRB *externo;

//Estrutura para armazenamento da informação do artigo
typedef struct infoArtigo
{
    int id;                 //Campo referente ao ID do artigo
    int ano;                //Campo referente ao ano de publicação do artigo
    char autor[200];        //Campo referente ao autor do artigo
    char titulo[200];       //Campo referente ao titulo do artigo
    char revista[200];      //Campo referente à revista de publicação do artigo
    char DOI[20];           //Campo referente ao DOI do artigo
    char palavraChave[200]; //Campo referente à uma plavara-chave do artigo
} Artigo;

Artigo *createArtigo()
{
    Artigo *art;

    if (art = (Artigo *)malloc(sizeof(Artigo))) //Verifica se alocação deu certo
    {
        //Recebendo os dados digitados nos campos da estrutura Artigo
        printf("Informe o ID da revista: ");
        scanf("%d", &art->id);
        printf("Informe o ano de publicacao do artigo: ");
        scanf("%d", &art->ano);
        setbuf(stdin, 0);
        printf("Informe o autor do artigo: ");
        fgets(art->autor, 200, stdin);
        printf("Informe o titulo do artigo: ");
        fgets(art->titulo, 200, stdin);
        printf("Informe o nome da revista: ");
        fgets(art->revista, 200, stdin);
        printf("Informe o DOI do artigo: ");
        fgets(art->DOI, 200, stdin);
        printf("Informe uma palavra chave para o artigo: ");
        fgets(art->palavraChave, 200, stdin);

        return art; //Retorna a estrutura em questão
    }
    else
        //Alcoção não deu certo
        return NULL;
}

NodeArvRB *auxCreateNode(Artigo *inf, NodeArvRB *externo)
{
    if (inf && externo) //Verifica se a estrutura e o nó externo entrados como parâmetros estão alocados
    {
        NodeArvRB *ptr = createNodeRB(externo); //Chamada da funcao createNodeRB para criar o novo nó e
                                                //apontar os campos para externo
        if (ptr)                                //Verifica se a criação do novo nó ocorreu com sucesso
        {
            ptr->info = inf; //Aponta o campo info para a estrutura que entrou como parâmetro
            return ptr;      //Retorna o nó criado
        }
    }
    else
    {
        //Algum parâmetro não foi alocado
        return NULL;
    }
}

//Comparacao dos valores (usada na Insercao, Remocao e Busca na arvore)
int compararValores(void *val1, void *val2) //Recebe dois valores quaisquer
{
    //FAz o cast para ponteiro de inteiro em ambos os parâmetros
    int *value1 = (int *)val1;
    int *value2 = (int *)val2;

    //Compara os dois valores
    if (*value1 == *value2) //Valores iguais
        return 0;
    else if (*value1 > *value2) //Primeiro valor maior
        return 1;
    else
        //Segundo valor maior
        return -1;
}

void printNodeRB(void *node) //Recebe um parâmetro do tipo void*
{
    NodeArvRB *ptr = (NodeArvRB *)node; //Faz cast para ponteiro para NodeArvRB
    int *chave = (int *)ptr->info;      //Faz cast da info para ponteiro para inteiro
    if (ptr->cor == 1)
    {
        //Imprime a chave formatada com a cor vermelha
        printf(BG_BLACK BOLD ANSI_COLOR_RED "[(%d):%s]\n" ANSI_COLOR_RESET, *chave, "RED");
    }
    else
    {
        //Imprime a chave formatada com a cor preta
        printf(BG_BLACK BOLD ANSI_COLOR_BLACK "[(%d):%s]\n" ANSI_COLOR_RESET, *chave, "BLACK");
    }
}

void printInfoNodeRB(Artigo *art)
{
    if (art) //Verifica se a etrutura entrada como parâmetor foi alocada
    {
        //Imprime os valores dos campos da estrutura
        printf(" Identificacao: [%d].\n", art->id);
        printf(" Autor: %s", art->autor);
        printf(" Titulo: %s", art->titulo);
        printf(" Ano: %d\n", art->ano);
        printf(" Revista: %s", art->revista);
        printf(" DOI: %s", art->DOI);
        printf(" Palavra-chave: %s", art->palavraChave);
    }
}

Artigo *fazerCastArtigo(NodeArvRB *node)
{ //Faz o cast do campo generico do no para o nomeCliente da estrutura
    return (Artigo *)node->info;
}

//Função responsável por apagar um nó liberando a memória
void freeInfoNodeRB(NodeArvRB *remove)
{
    Artigo *infoArt = fazerCastArtigo(remove); //Recebe o cast devido ao campo info do nó
    if (infoArt)
        free(infoArt); //Libera a memória ocupada pelo campo info caso o cast foi feito com
}

void menu() //Apresenta um menu para realizar as operaações
{
    system("cls||clear");
    printf("\n ============================= MENU INICIAL ======================\n\n");
    int insert, continuar;
    float opcao = 1.0;
    int valor;

    externo = createSentinelaRB();
    RaizRB *raiz = createRaiz(externo);

    while (opcao > 0 && opcao < 4.1)
    {
        printf("\nDeseja: Inserir(1) - Deletar(2) - Pesquisar(3) - Imprimir(4) - Sair(0) ? \n");
        printf("Resposta: ");
        scanf("%f", &opcao);

        switch ((int)opcao)
        {
        case 1:
            system("cls||clear");
            printf("\nInserindo\n");

            Artigo *art = createArtigo();
            NodeArvRB *novo = auxCreateNode(art, externo);
            printf("\n");

            insertRB(raiz, novo, compararValores, externo);

            printRB(raiz->root, heightRB(raiz->root), printNodeRB, externo);
            break;
        case 2:
            system("cls||clear");
            printf("\nDeletando\n");

            printRB(raiz->root, heightRB(raiz->root), printNodeRB, externo);

            printf("Informe o valor que deseja remover da arvore RN: ");
            scanf("%d", &valor);

            NodeArvRB *remove = searchRB(raiz, &valor, compararValores, externo);

            if (remove)
            {
                RBRemocao(raiz, remove, externo);
                system("cls||clear");
                printf("\nNó removido\n");

                printRB(raiz->root, heightRB(raiz->root), printNodeRB, externo);
                freeInfoNodeRB(remove);
                free(remove);
            }
            else
                printf("\nNó inexistente!\n");

            break;
        case 3:
            system("cls||clear");
            printf("\nPesquisando\n");
            printf("Informe o ID da publicacao: ");
            scanf("%d", &valor);

            NodeArvRB *busca = searchRB(raiz, &valor, compararValores, externo);

            if (busca)
                printInfoNodeRB((Artigo *)busca->info);
            else
                printf("Publicacao inexistente!\n");

            break;
        case 4:
            system("cls||clear");
            printf("\nImprimindo\n\n");
            if (raiz->root == externo)
                printf("Arvore Vazia!\n");
            else
                printRB(raiz->root, heightRB(raiz->root), printNodeRB, externo);
            break;
        default:
            system("cls||clear");
            printf("\nFinalizando programa!\n");
            break;
        }
    }
    destroyRB(raiz, externo, freeInfoNodeRB);
}

int main(void)
{
    menu();

    printf("\n");
    return 0;
}