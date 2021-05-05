#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *lerArquivo(FILE *file, char *caracteresArquivo)
{
    int tam_caracteresArquivo = 1;
    caracteresArquivo = (char *)malloc(tam_caracteresArquivo * sizeof(char));

    int i = 0, j = 0;
    char aux;
    while (fscanf(file, "%c", &aux) != EOF)
    {
        if (aux != '\n')
        {
            // printf("%d >> %c\n", j, aux);
            caracteresArquivo = realloc(caracteresArquivo, tam_caracteresArquivo + 1);
            caracteresArquivo[j] = aux;
            tam_caracteresArquivo++;
            j++;
        }
    }

    // for (int i = 0; i < tam_caracteresArquivo; i++)
    // {
    //     printf("%c", caracteresArquivo[i]);
    // }
    // printf("\n");

    return caracteresArquivo;
}

char *verificaOcorrencia(char *vetorArquivo)
{
    int tam_caracteresVetor = 1;
    char *caracteresVetor;
    caracteresVetor = (char *)malloc(tam_caracteresVetor * sizeof(char));

    int tam = strlen(vetorArquivo);
    int j;
    for (int i = 0; i < tam; i++)
    {
        for (j = 0; j < tam_caracteresVetor; j++)
        {
            if (vetorArquivo[i] == caracteresVetor[j])
            {
                break;
            }
        }
        if (j == tam_caracteresVetor)
        {
            caracteresVetor[tam_caracteresVetor - 1] = vetorArquivo[i];
            tam_caracteresVetor++;
        }
    }

    return caracteresVetor;
}

int *verificaFrequencia(char *vetorA, char *vetorC)
{
    int tam = strlen(vetorC);
    int *frequencia;
    frequencia = (int *)malloc(tam * sizeof(int));

    for (int i = 0; i < tam; i++)
    {
        frequencia[i] = 0;
    }

    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < strlen(vetorA); j++)
        {
            if (vetorC[i] == vetorA[j])
            {
                frequencia[i]++;
            }
        }
    }
    return frequencia;
}

void organizaVetores(char *vetorC, int *vetorI)
{
    int i, j, auxI;
    char auxC;
    int tam = strlen(vetorC);
    for (i = 0; i < tam; i++)
    {
        for (j = i + 1; j < tam; j++)
        {
            if (vetorI[i] > vetorI[j])
            {
                auxI = vetorI[i];
                vetorI[i] = vetorI[j];
                vetorI[j] = auxI;

                auxC = vetorC[i];
                vetorC[i] = vetorC[j];
                vetorC[j] = auxC;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    FILE *pont_arq = fopen("arquivo.txt", "rb");
    if (!pont_arq)
    {
        printf("Erro ao ler arquivo!\n");
        fclose(pont_arq);
        exit(1);
    }
    else
    {
        printf("Arquivo lido com sucesso!\n\n");
    }

    //------------------------------------------ Vetor com caracteres do arquivo ---------------------------
    //------------------------------------------------------------------------------------------------------
    int tam_caracteresArquivo = 1;
    char *caracteresArquivo;
    caracteresArquivo = lerArquivo(pont_arq, caracteresArquivo);

    // for (int i = 0; i < strlen(caracteresArquivo); i++)
    // {
    //     printf("%c", caracteresArquivo[i]);
    // }
    // printf("\n");
    //--------------------------------------- Vetor com caracteres sem repetição ---------------------------
    //------------------------------------------------------------------------------------------------------

    char *caracteresVetor;
    caracteresVetor = verificaOcorrencia(caracteresArquivo);

    //-------------------------------------- Vetor com frequencia dos caracteres ---------------------------
    //------------------------------------------------------------------------------------------------------

    int *frequencia = verificaFrequencia(caracteresArquivo, caracteresVetor);
    int tamanho = strlen(caracteresVetor);
    free(caracteresArquivo);

    organizaVetores(caracteresVetor, frequencia);

    // for (int i = 0; i < tamanho; i++)
    // {
    //     printf("[%d][ %c ][ %d ]\n", i, caracteresVetor[i], frequencia[i]);
    // }
    // printf("\n");

    fclose(pont_arq);

    free(caracteresVetor);
    free(frequencia);
    return 0;
}
