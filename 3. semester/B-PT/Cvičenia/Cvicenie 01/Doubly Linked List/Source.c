#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int value;
	struct node* next;
	struct node* prev;
} NODE;

typedef struct list {
	NODE* first;
	NODE* last;
} LIST;

void prependNode(LIST* list, int value) {
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->value = value;
	if (list->first) {
		newNode->prev = NULL;
		newNode->next = list->first;
		list->first = newNode;
	}
	else {
		newNode->prev = NULL;
		newNode->next = NULL;
		list->first = newNode;
		list->last = newNode;
	}
}

void appendNode(LIST* list, int value) {
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->value = value;
	if (list->first) {
		newNode->next = NULL;
		newNode->prev = list->last;
		list->last->next = newNode;
		list->last = newNode;
	}
	else {
		newNode->next = NULL;
		newNode->prev = NULL;
		list->first = newNode;
		list->last = newNode;
	}
}

NODE* findNode(LIST* list, int value) {
	NODE* toFind = list->first;
	while (toFind) {
		if (toFind->value == value) {

			break;
		}
		toFind = toFind->next;
	}
	return toFind;
}

void deleteNode(LIST* list, int value) {
	NODE* toDelete = findNode(list, value);
	if (toDelete) {
		if (toDelete->prev) {
			toDelete->prev->next = toDelete->next;
		}
		else {
			list->first = toDelete->next;
		}
		if (toDelete->next) {
			toDelete->next->prev = toDelete->prev;
		}
		else {
			list->last = toDelete->prev;
		}
		free(toDelete);
	}
}

void printList(LIST* list) {
	NODE* tmp = list->first;
	while (tmp) {
		printf("%i ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

int main() {
	LIST* list = (LIST*)calloc(1, sizeof(LIST));
	list->first = NULL;
	list->last = NULL;
	prependNode(list, 2);
	prependNode(list, 1);
	prependNode(list, 0);
	appendNode(list, 3);
	appendNode(list, 4);
	appendNode(list, 5);
	printList(list);

	deleteNode(list, 3);
	printList(list);

	getchar();
	return 0;
}