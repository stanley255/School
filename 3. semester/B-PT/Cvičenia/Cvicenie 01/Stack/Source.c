#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node* lower;
} NODE;

typedef struct stack {
	NODE* top;
} STACK;

void push(STACK* stack, int value) {
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->value = value;
	newNode->lower = stack->top;
	stack->top = newNode;
}

int pop(STACK* stack) {
	int result = NULL;
	if (stack->top) {
		void* tmpPointer = stack->top->lower;
		result = stack->top->value;
		free(stack->top);
		stack->top = tmpPointer;
	}
	return result;
}

void printStack(STACK* stack) {
	NODE* tmp = stack->top;
	while (tmp) {
		printf("%i|",tmp->value);
		tmp = tmp->lower;
	}
	printf("\n");
}

int main() {
	STACK* stack = (STACK*) malloc(sizeof(STACK));
	stack->top = NULL;

	int tmp;

	push(stack, 1);
	push(stack, 2);
	push(stack, 3);

	printStack(stack);

	tmp = pop(stack);
	printStack(stack);

	tmp = pop(stack);
	printStack(stack);

	tmp = pop(stack);
	printStack(stack);

	tmp = pop(stack);
	printStack(stack);

	getchar();
	return 0;
}