#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linkedList.c"

int main() {

	List *lst=createList();
	Info *tempInfo;

	double soma = 123.23;
    printf("Lista encadeada!");
	printf("%f\n", soma);
	printf("%8f\n", soma);
	printf("%012f\n", soma);
	getchar();

	tempInfo=createInfo(5);
	insertFirstList(lst,tempInfo);

   	tempInfo=createInfo(125);
	insertFirstList(lst,tempInfo);

	tempInfo=createInfo(45);
	insertFirstList(lst,tempInfo);

   	tempInfo=createInfo(56);
	insertFirstList(lst,tempInfo);

   	tempInfo=createInfo(9);
	insertFirstList(lst,tempInfo);

   	tempInfo=createInfo(25);
	insertFirstList(lst,tempInfo);

   	tempInfo=createInfo(7);
	insertFirstList(lst,tempInfo);

	tempInfo=createInfo(1);
	insertFirstList(lst,tempInfo);

	tempInfo=createInfo(2);
	insertFirstList(lst,tempInfo);

	tempInfo=createInfo(3);
	insertFirstList(lst,tempInfo);

	tempInfo=createInfo(200);
	insertLastList(lst,tempInfo);

	tempInfo=createInfo(500);
	insertInPositionList(lst,tempInfo,5);

    printf("Original List: ");

    //print list
    printList(lst);

    printf("\nOrdered List: ");
    //ordena
    sortList(lst);
    //print sorted list
    printList(lst);

    printf("\nInsert 50 in orderList: List ");
    tempInfo = createInfo(0);
    insertInOrderList(lst,tempInfo);
    printList(lst);

    //lenght list
    printf("\nLength list: ");
    printf("%d\n",lengthList(lst));

    printf("\nOrdered List: ");
    //ordena
    sortList(lst);
    //print sorted list
    printList(lst);

    printf("\nReversed List: ");
    //inverte
    reverseList(lst);
    //print reversed list
    printList(lst);

	printf("\nFirst Deleted List: ");
	//deleta primeiro
	deleteFirstList(lst);
	printList(lst);

	printf("\nFirst Deleted List: ");
    //deleta primeiro
    deleteFirstList(lst);
    printList(lst);

	printf("\nPosition 20 Deleted List: ");
    //deleta posicao 20
    deletePositionList(lst,20);

	printf("\nPosition 3 Deleted List: ");
    //deleta posicao 2
    deletePositionList(lst,3);
    printList(lst);

	printf("\nLast Deleted List: ");
	//deleta último
    deleteLastList(lst);
    printList(lst);

    //Encontra elemento
    tempInfo=createInfo(8);
    printf("\nFind Info in List: %d ",tempInfo->value);
    tempInfo = findList(lst,tempInfo);
    if(tempInfo != NULL)
    {
    	printf("\nEncontrou=%d",tempInfo->value);
    	int posicao = posList(lst,tempInfo);
    	printf("\nPosicao=%d",posicao);
    }
    else {printf("\nNAO Encontrou!");}

   //Encontra elemento
   tempInfo=createInfo(9);
   printf("\nFind Info in List: %d ",tempInfo->value);
   tempInfo=findList(lst,tempInfo);
   if(tempInfo)
    {
        printf("\nEncontrou=%d",tempInfo->value);
        printf("\nPosicao=%d",posList(lst,tempInfo));
   }
   else printf("\nNAO Encontrou!");

	printf("\nList: ");
    printList(lst);

    //inverte
	printf("\nReversed List: ");
    reverseList(lst);
    //print reversed list
    printList(lst);

    freeList(lst);
    printf("\n Free List!!!");

     getchar();


   return 1;
}
