#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.c"

int main() {

	Queue *queue=createQueue();

	Info *tempInfo;

	printQueue(queue);

	tempInfo=createInfo(5);
	printf("\n insert Queue: %d ", tempInfo->value);
	insertQueue(queue,tempInfo);
	printQueue(queue);

   	tempInfo=createInfo(125);
   	printf("\n insert Queue: %d ", tempInfo->value);
	insertQueue(queue,tempInfo);
	printQueue(queue);

	tempInfo=createInfo(45);
	printf("\n insert Queue: %d ", tempInfo->value);
	insertQueue(queue,tempInfo);
	printQueue(queue);

   	tempInfo=createInfo(56);
   	printf("\n insert Queue: %d ", tempInfo->value);
	insertQueue(queue,tempInfo);
	printQueue(queue);

   	tempInfo=createInfo(9);
   	printf("\n insert Queue: %d ", tempInfo->value);
	insertQueue(queue,tempInfo);
	printQueue(queue);

   	tempInfo=createInfo(25);
   	printf("\n insert Queue: %d ", tempInfo->value);
	insertQueue(queue,tempInfo);
	printQueue(queue);

   	tempInfo=createInfo(7);
   	printf("\n insert Queue: %d ", tempInfo->value);
	insertQueue(queue,tempInfo);
	printQueue(queue);

	tempInfo=createInfo(1);
	printf("\n insert Queue: %d ", tempInfo->value);
	insertQueue(queue,tempInfo);
	printQueue(queue);

	tempInfo=createInfo(2);
	printf("\n insert Queue: %d ", tempInfo->value);
	insertQueue(queue,tempInfo);
	printQueue(queue);

	tempInfo=createInfo(3);
	printf("\n insert Queue: %d ", tempInfo->value);
	insertQueue(queue,tempInfo);
	printQueue(queue);

    int tam = lengthQueue(queue);
    printf("\nLength Queue: %d\n", tam);

	printf("\nremove Queue: ");
    tempInfo=removeQueue(queue);
   	printQueue(queue);

    tam = lengthQueue(queue);
    printf("\nLength Queue: %d\n", tam);

	tempInfo=createInfo(100);
    printf("\n insert Queue: %d", tempInfo->value);
	insertQueue(queue,tempInfo);
   	printQueue(queue);

    tam = lengthQueue(queue);
    printf("\nLength Queue: %d\n", tam);

	printf("\nremove Queue: ");
    tempInfo=removeQueue(queue);
   	printQueue(queue);

    tam = lengthQueue(queue);
    printf("\nLength Queue: %d\n", tam);

    tempInfo=createInfo(3333);
    printf("\n insert Queue: %d", tempInfo->value);
	insertQueue(queue,tempInfo);
   	printQueue(queue);

    tam = lengthQueue(queue);
    printf("\nLength Queue: %d\n", tam);

   	printf("\nremove Queue: ");
    tempInfo=removeQueue(queue);
   	printQueue(queue);

    tam = lengthQueue(queue);
    printf("\nLength Queue: %d\n", tam);

    tempInfo=createInfo(3122);
    printf("\n insert Queue: %d", tempInfo->value);
	insertQueue(queue,tempInfo);

	printQueue(queue);
   	printf("\nFree Queue");

    freeQueue(queue);

    getchar();

   return 1;
}


