/*------------------------------------------------------------------------------------------------
Trabalho Pratico 1 - Skip List - Estrutura de Dados I - CEUNES - UFES
Autor:  Luiz Gustavo Falqueto Baptista
Matricula:  2017203673
Data de criação:    22/10/2019

Arquivo (main.c) - leitura da "entrada.txt" e chamada das funcoes

 1 - Documentacao do trabalho:
    1.1 - Introducao:
        Esse trabalho tem como objetivo a resolucao da implementacao de uma lista de saltos (SkipList),
        com implementacao de funcoes que inserem, removem, busca e imprime dados na lista. Eh feita
        uma leitura de um arquivo de entrada e gera um arquivo de saida com os resutados das operacoes.
        O programa esta funcinando perfeitamente, gerando a saida esperada a partir da entrada tida como
        exemplo no enunciado do trabalho, por exemplo.
    1.2 - Implementacao:
        A estrutur da SkipList que doi adotada eh a seguinte:
                                typedef struct {
                                    int heigth;
                                    Node *first;
                                }SkipList;
        sendo a estrutura de cada noh da lista como:
                                typedef struct tno{
                                    int valor;
                                    int nivel;
                                    struct tno **apontadores;
                                }Node;.
        Quanto as principais funcoes do trabalho, adotei uma implementacao diferente ao que solicita o
        enunciado o trabalho, devido a algumas dificuldades (que serao explicadas brevemente) encontradas.
    1.3 - Conclusao:
        Como dito anteriormente, encontrei uma certa dificuldade quanto ao usar a ListaH como parametro da
        funcao Search, talvez algum erro de apontamanto, mas nao foi encontrado erros nesse caso. Para isso,
        usei a funcao Search apenas para verificar se o elemnto existe ou nao, para a realizacao das funcoes
        Insere e Remove. Quanto ao ListaH, criei dentro das funcoes a medida que foi necessario.
    1.4 - Bibliografia:
        Quanto a bibliografia, foram utilizados varios sites para satisfazer certas duvidas durantes a
        implementacao.
------------------------------------------------------------------------------------------------*/
#include  <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "skipList.c"

int main()
{
    FILE *entrada;
    entrada = fopen("entrada.txt","r"); //Abrindo o arquivo de teste
                                        //considerando que "entrada.txt" esta no mesmo diretorio que o arquivo "main.c"

    if(entrada == NULL)//Caso deu erro na abertura do arquivo
    {
        printf("\nFalha ao abrir o arquivo de entrada!\n");
        printf("Favor verificar o diretorio do arquivo.\n");
        printf("Se necessario, altere o primeiro parametro de fopen(...).\n");
        return 0;
    }

    int manipulaFile = readFile(entrada);//Chamada da funcao que executa as acoes na SkipList

    if(manipulaFile == 0)//Ocorreu erro na manipulacao do arquivo de entrada, de saida ou nas acoes
    {
        printf("\nOps! Ocorreu algum erro...\n");
    }else//Sem erro ocorrido
    {
      printf("\nOperacao realizada com sucesso!");
      printf("\nArquivo de saida criado e preenchido.\n");
    }

    //Fechando o arquivo de teste
    fclose(entrada);
    getchar();
    return 1;
}
