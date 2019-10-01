#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.c"

int main()
{
	Stack *stack = createStack();

	Info *tempInfo;

	printStack(stack);

	tempInfo=createInfo(5);
	printf("\n insert Stack: %d ", tempInfo->value);
	push(stack,tempInfo);
	printStack(stack);

	tempInfo=createInfo(125);
	printf("\n insert Stack: %d ", tempInfo->value);
	push(stack,tempInfo);
	printStack(stack);

	tempInfo=createInfo(45);
	printf("\n insert Stack: %d ", tempInfo->value);
	push(stack,tempInfo);
	printStack(stack);

	tempInfo=createInfo(56);
	printf("\n insert Stack: %d ", tempInfo->value);
	push(stack,tempInfo);
	printStack(stack);

	tempInfo=createInfo(9);
	printf("\n insert Stack: %d ", tempInfo->value);
	push(stack,tempInfo);
	printStack(stack);

	tempInfo=createInfo(25);
	printf("\n insert Stack: %d ", tempInfo->value);
	push(stack,tempInfo);
	printStack(stack);

	tempInfo=createInfo(7);
	printf("\n insert Stack: %d ", tempInfo->value);
	push(stack,tempInfo);
	printStack(stack);

	tempInfo=createInfo(1);
	printf("\n insert Stack: %d ", tempInfo->value);
	push(stack,tempInfo);
	printStack(stack);

	tempInfo=createInfo(2);
	printf("\n insert Stack: %d ", tempInfo->value);
	push(stack,tempInfo);
	printStack(stack);

	tempInfo=createInfo(3);
	printf("\n insert Stack: %d ", tempInfo->value);
	push(stack,tempInfo);
	printStack(stack);

    printf("\nLength Stack: %d\n", lengthStack(stack));

    printf("\nPOP: ");
    tempInfo=pop(stack);
   	printStack(stack);

    printf("\nLength Stack: %d\n", lengthStack(stack));

	printf("\nPOP: ");
    tempInfo=pop(stack);
   	printStack(stack);

    printf("\nLength Stack: %d\n", lengthStack(stack));	

	printf("\nPOP: ");
    tempInfo=pop(stack);
   	printStack(stack);

    printf("\nLength Stack: %d\n", lengthStack(stack));

    printf("\nPOP: ");
    tempInfo=pop(stack);
   	printStack(stack);

    printf("\nLength Stack: %d\n", lengthStack(stack));

   	printf("\nPOP: ");
    tempInfo=pop(stack);
   	printStack(stack);

   	printf("\nLength Stack: %d\n", lengthStack(stack));

   	printf("\nPOP: ");
    tempInfo=pop(stack);
   	printStack(stack);

    printf("\nLength Stack: %d\n", lengthStack(stack));

    printf("\nPOP: ");
    tempInfo=pop(stack);
   	printStack(stack);

    printf("\nLength Stack: %d\n", lengthStack(stack));

    printf("\nPOP: ");
    tempInfo=pop(stack);
   	printStack(stack);

    printf("\nLength Stack: %d\n", lengthStack(stack));

    printf("\nPOP: ");
    tempInfo=pop(stack);
   	printStack(stack);

    printf("\nLength Stack: %d\n", lengthStack(stack));

    printf("\nPOP: ");
    tempInfo=pop(stack);
   	printStack(stack);

    printf("\nLength Stack: %d\n", lengthStack(stack));

	printStack(stack);
   	printf("\nFree Stack");

    freeStack(stack);

    getchar();

	return 1;
}
