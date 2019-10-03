#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "DLinkedList.c"

int main() {

	DList *dlst=createDList();
	Info *tempInfo;

	double soma = 123.23;
	printf("%f\n", soma);
	printf("%8f\n", soma);
	printf("%012f\n", soma);
	getchar();

	tempInfo=createInfo(5);
	insertFirstDList(dlst,tempInfo);
	printDList(dlst);

   	tempInfo=createInfo(125);
	insertFirstDList(dlst,tempInfo);
	printDList(dlst);

	tempInfo=createInfo(45);
	insertFirstDList(dlst,tempInfo);
	printDList(dlst);

   	tempInfo=createInfo(56);
	insertFirstDList(dlst,tempInfo);
	printDList(dlst);

   	tempInfo=createInfo(9);
	insertFirstDList(dlst,tempInfo);
	printDList(dlst);

   	tempInfo=createInfo(25);
	insertFirstDList(dlst,tempInfo);
	printDList(dlst);

   	tempInfo=createInfo(7);
	insertFirstDList(dlst,tempInfo);
	printDList(dlst);

	tempInfo=createInfo(1);
	insertFirstDList(dlst,tempInfo);
	printDList(dlst);

	tempInfo=createInfo(4);
	insertFirstDList(dlst,tempInfo);
	printDList(dlst);

	tempInfo=createInfo(74);
	insertFirstDList(dlst,tempInfo);
	printDList(dlst);

	tempInfo=createInfo(200);
	insertLastDList(dlst,tempInfo);
	printDList(dlst);

	tempInfo=createInfo(500);
	insertInPositionDList(dlst,tempInfo,5);

    printf("\nOriginal DList: ");

    //print list
    printDList(dlst);

    printf("\nOrdered DList: ");
    //ordena
    sortDList(dlst);
    //print sorted list
    printDList(dlst);

    printf("\nInsert 258 in orderDList: DList ");
    tempInfo = createInfo(258);
    insertInOrderDList(dlst,tempInfo);
    printDList(dlst);

    //lenght list
    printf("\nLength list: ");
    printf("%d\n",lengthDList(dlst));

    printf("\nOrdered DList: ");
    //ordena
    sortDList(dlst);
    //print sorted list
    printDList(dlst);

    printf("\nReversed DList: ");
    //inverte
    reverseDList(dlst);
    //print reversed list
    printDList(dlst);

	printf("\nFirst Deleted DList: ");
	//deleta primeiro
	deleteFirstDList(dlst);
	printDList(dlst);

	printf("\nFirst Deleted DList: ");
    //deleta primeiro
    deleteFirstDList(dlst);
    printDList(dlst);

	printf("\nPosition 20 Deleted DList: ");
    //deleta posicao 20
    deletePositionDList(dlst,20);
    printDList(dlst);

	printf("\nPosition 3 Deleted DList: ");
    //deleta posicao 2
    deletePositionDList(dlst,3);
    printDList(dlst);

	printf("\nLast Deleted DList: ");
	//deleta último
    deleteLastDList(dlst);
    printDList(dlst);

    tempInfo=createInfo(200);
    printf("\nDelete Info %d in DList: ", tempInfo->value);
	//deleta último
    deleteThisInfoDList(dlst,tempInfo);
    printDList(dlst);

    //Encontra elemento
    tempInfo=createInfo(8);
    printf("\n\nFind Info in DList: %d ",tempInfo->value);
    if(findDList(dlst,tempInfo))
    {
        if(tempInfo != NULL)
        {
            printf("\nEncontrou=%d",tempInfo->value);
            int posicao = posDList(dlst,tempInfo);
            printf("\nPosicao=%d",posicao);
        }
    }else {printf("\nNAO Encontrou!");}

    //Encontra elemento
    tempInfo=createInfo(9);
    printf("\n\nFind Info in DList: %d ",tempInfo->value);
    if(findDList(dlst,tempInfo))
    {
        if(tempInfo)
         {
             printf("\nEncontrou=%d",tempInfo->value);
             printf("\nPosicao=%d",posDList(dlst,tempInfo));
        }
    }else printf("\nNAO Encontrou!");

    printf("\n\nDList: ");
    printDList(dlst);

    //inverte
	printf("\nReversed DList: ");
    reverseDList(dlst);
    //print reversed list
    printDList(dlst);

    freeDList(dlst);
    printf("\n Free DList!!!");

     getchar();


   return 1;
}

