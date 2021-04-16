/*
    Implementacao de algoritmo de Arvore Rubro-Negra
    Autor: Luiz Gustavo Falqueto Baptista
    Data: 29/03/2021
    Arquivo: ArvRB.c
*/

#include "ArvRN.c"
#include <string.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_BLACK "\e[0;37m"
#define ANSI_COLOR_RESET "\033[0m"
#define BOLD "\033[1m"
#define BG_BLACK "\033[40m"

//Estrutura para armazenamento da informação do artigo
typedef struct infoArtigo{
    int id;
    int ano;
    char autor[200];
    char titulo[200];
    char revista[200];
    char DOI[20];
    char palavraChave[200];
}Artigo;

Artigo *createArtigo(){
    int _id, _ano;
    char _autor[200], _titulo[200], _revista[200], _DOI[20], _palavraChave[200];

    Artigo *art;

    if(art = (Artigo*)malloc(sizeof(Artigo))){
        printf("Informe o ID da revista: ");
        scanf("%d",&_id);
        // printf("Informe o ano de publicacao do artigo: ");
        // scanf("%d",&_ano);
        // setbuf(stdin, 0);
        // printf("Informe o autor do artigo: ");
        // fgets(_autor,200,stdin);
        // printf("Informe o titulo do artigo: ");
        // fgets(_titulo,200,stdin);
        // printf("Informe o nome da revista: ");
        // fgets(_revista,200,stdin);
        // printf("Informe o DOI do artigo: ");
        // fgets(_DOI,200,stdin);
        // printf("Informe uma palavra chave para o artigo: ");
        // fgets(_palavraChave,200,stdin);

        art->id = _id;
        // art->ano = _ano;
        // strcpy(art->autor,_autor);
        // strcpy(art->DOI,_DOI);
        // strcpy(art->palavraChave,_palavraChave);
        // strcpy(art->revista,_revista);
        // strcpy(art->titulo,_titulo);
        
        return art;
    }else return NULL;    
}

NodeArvRB *auxCreateNode(Artigo *inf){
    if(inf){
        NodeArvRB *ptr = createNodeRB();
        if(ptr){
            ptr->info = inf;
            return ptr;
        }
    }
}

//Comparacao dos valores (usada na Insercao, Remocao e Busca na arvore)
int compararValores(void *val1, void *val2){
    int *value1 = (int*)val1;
    int *value2 = (int*)val2;

    if(*value1 == *value2) return 0;
    else if(*value1 > *value2) return 1;
    else return -1;
}

void imprimeNo(void* node){
    NodeArvRB *ptr = (NodeArvRB*)node;
    int *chave = (int*)ptr->info;
    if(ptr->cor == RED){
        printf(BG_BLACK BOLD ANSI_COLOR_RED "[(%d):%s]\n" ANSI_COLOR_RESET,*chave,"RED");
    }else{
        printf(BG_BLACK BOLD ANSI_COLOR_BLACK "[(%d):%s]\n" ANSI_COLOR_RESET,*chave,"BLACK");
    }
}

void imprimeInfoArtigoRN(Artigo *art){
    if(art){
        printf(" Identificacao: [%d] -> %s. %s. %d, %s. %s Palavra-chave: %s.\n",art->id,art->autor,art->titulo,art->ano,art->revista,art->DOI,art->palavraChave);
    }
}

void freeInfoArtigo(void *info){
    Artigo *infoArt = (Artigo*)info;
    
    free(infoArt->autor);
    free(infoArt->palavraChave);
    free(infoArt->titulo);
    free(infoArt->revista);
    free(infoArt->DOI);
}

void menu(){
    system("cls||clear");
    printf("\n ============================= MENU INICIAL ======================\n\n");
    int insert, continuar;
    float opcao=1.0;
    int valor;

    RaizRN *raiz = createRaiz();

    while(opcao > 0 && opcao < 4.1){
        printf("\nDeseja: Inserir(1) - Deletar(2) - Pesquisar(3) - Imprimir(4) - Sair(0) ? \n");
        printf("Resposta: ");
        scanf("%f",&opcao);

        switch ((int)opcao)
        {
            case 1:
                system("cls||clear");
                printf("\nInserindo\n");

                Artigo *art = createArtigo();
                NodeArvRB *novo = auxCreateNode(art);
                printf("\n");

                insert = insertRN(raiz,novo,compararValores);
                
                printARN(raiz->root,heightAvl(raiz->root),imprimeNo);
                break;
            case 2:
                system("cls||clear");
                printf("\nDeletando\n");

                printf("Informe o valor que deseja inserir na arvore RN: ");
                scanf("%d",&valor);

                NodeArvRB *remove = searchRN(raiz, &valor, compararValores), *delete;

                if(remove){
                    delete = deleteRN(raiz,remove);
                    // freeInfoArtigo(delete->info);
                    free(delete);
                }
                else printf("\nNó inexistente!\n");

                printARN(raiz->root,heightAvl(raiz->root),imprimeNo);
                break;
            case 3:
                system("cls||clear");
                printf("\nPesquisando\n");

                printf("Informe o ID da publicacao: ");
                scanf("%d",&valor);

                NodeArvRB *busca = searchRN(raiz,&valor,compararValores);

                if(busca) imprimeInfoArtigoRN((Artigo*)busca->info);
                else printf("Publicacao inexistente!\n");

                break;
            case 4:
                system("cls||clear");
                printf("\nImprimindo\n\n");
                if(raiz->root == NULL) printf("Arvore Vazia!\n");
                else printARN(raiz->root,heightAvl(raiz->root),imprimeNo);
                break;
            default:
                system("cls||clear");
                printf("\nFinalizando programa!\n");                
                break;
        }
    }
    destroyARN(raiz);
}

int main(void)
{
    menu();

    printf("\n");
    return 0;
}