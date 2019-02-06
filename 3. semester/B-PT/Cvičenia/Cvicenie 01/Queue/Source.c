#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int value;
	struct node* frwrd;
} NODE;

typedef struct queue {
	NODE* rear;
	NODE* front;
} QUEUE;

NODE* findPred(QUEUE* queue, NODE* currentNode) {
	NODE* tmp = queue->rear;
	while (tmp) {
		if (tmp->frwrd == currentNode) {
			break;
		}
		tmp = tmp->frwrd;
	}
	return tmp;
}

void enqueue(QUEUE* queue, int value) {
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->value = value;
	if (queue->front) {
		newNode->frwrd = queue->rear;
	}
	else {
		newNode->frwrd = NULL;
		queue->front = newNode;
	}
	queue->rear = newNode;
}

int dequeue(QUEUE* queue) {
	int value;
	NODE* currFront = queue->front;
	NODE* predFront = findPred(queue, queue->front);
	if (predFront) {
		value = currFront->value;
		queue->front = predFront;
		predFront->frwrd = NULL;
		free(currFront);
	}
	else {
		queue->rear  = NULL;
		queue->front = NULL;
		if (currFront) {
			value = currFront->value;
			free(currFront);
		}
		else {
			return NULL;
		}		
	}	
	return value;
}

void printQueue(QUEUE* queue) {
	NODE* tmp = queue->rear;
	while (tmp) {
		printf("%i|",tmp->value);
		tmp = tmp->frwrd;
	}
	printf("\n");
}

int main() {
	QUEUE* queue = (QUEUE*) malloc(sizeof(QUEUE));
	queue->front = NULL;
	queue->rear = NULL;

	enqueue(queue, 1);
	enqueue(queue, 2);
	enqueue(queue, 3);
	printQueue(queue);

	dequeue(queue);
	printQueue(queue);
	dequeue(queue);
	printQueue(queue);
	dequeue(queue);
	printQueue(queue);
	dequeue(queue);
	printQueue(queue);

	getchar();
	return 0;
}