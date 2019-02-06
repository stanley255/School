#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node* next;
} NODE;

typedef struct list {
	NODE* first;
} LIST;

void printList(LIST* list) {
	NODE* tmp = list->first;
	while (tmp){
			printf("%i -> ", tmp->value);
		tmp = tmp->next;
	}
	printf("NULL\n\n");
}

void printNode(NODE* toPrint) {
	if (toPrint) {
		printf("Node's addr:  %p\n", toPrint);
		printf("Node's value: %i\n", toPrint->value);
		printf("Node's next:  %p\n\n", toPrint->next);
	}
	else {
		printf("Node's value: NO_VALUE\n");
		printf("Node's next:  NO_NEXT\n\n");
	}
}

void prependNode(LIST* list, int value) {
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->value = value;
	newNode->next = list->first;
	list->first = newNode;
}

void appendNode(LIST* list, int value) {
	NODE* newNode  = (NODE*)malloc(sizeof(NODE));
	newNode->value = value;
	newNode->next  = NULL;
	if (list->first) {
		NODE* tmp = list->first;
		while (tmp->next) {
			tmp = tmp->next;
		}
		tmp->next = newNode;
	}
	else {
		list->first = newNode;
	}
}

NODE* findNode(LIST* list, int val) {
	NODE* tmp = list->first;
	while (tmp) {
		if (tmp->value == val) {
			break;
		}			
		tmp = tmp->next;
	}
	return tmp;
}

NODE* findPredecessor(LIST* list, NODE* a) {
	NODE* tmp = list->first;
	while (tmp) {
		if (tmp->next == a) {
			break;
		}
		tmp = tmp->next;
	}
	return tmp;
}

void deleteNode(LIST* list, int val) {
	NODE* toDelete = findNode(list, val);
	if (toDelete) {
		NODE* pred = findPredecessor(list, toDelete);
		if (pred) {
			pred->next = toDelete->next;
		}
		else {
			list->first = toDelete->next;
		}
		free(toDelete);
	}
}

void swapNodes(LIST* list, NODE *a, NODE *b) {
	if (!a || !b) {
		return;
	}
	NODE* predA = findPredecessor(list, a);
	NODE* predB = findPredecessor(list, b);
	if (predA) {
		predA->next = b;
	}
	else {
		list->first = b;
	}
	if (predB) {
		predB->next = a;
	}
	else {
		list->first = a;
	}
	void* tmp = a->next;
	a->next = b->next;
	b->next = tmp;
}

void deleteList(LIST* list) {
	NODE* tmp = NULL;
	while (list->first) {
		tmp = list->first->next;
		free(list->first);
		list->first = tmp;		
	}
}

int main() {
	LIST list;
	list.first = NULL;
	NODE* foundNode = NULL;

	for (int i = 0; i < 6; i++)
		appendNode(&list, i);
	
	foundNode = findNode(&list, 3);
	printf("findNode function:\n");
	printNode(foundNode);

	foundNode = findPredecessor(&list, foundNode);
	printf("findPredecessor function:\n");
	printNode(foundNode);

	deleteNode(&list, 1);
	swapNodes(&list, findNode(&list, 0), findNode(&list, 5));
	printList(&list);

	deleteList(&list);

	getchar();
	return 0;
}