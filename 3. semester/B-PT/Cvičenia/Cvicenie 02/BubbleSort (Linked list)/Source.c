#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// reprezentacia zretazeneho zoznamu
typedef struct node {
	int data;
	struct node* next;
}NODE;

typedef struct list {
	NODE* first;
}LIST;

// funkcia na vypis zretazeneho zoznamu
void printList(LIST* list) {
	NODE* tmp = list->first;
	while (tmp) {
		printf("%i ->", tmp->data);
		tmp = tmp->next;
	}
	printf(" NULL\n");
}

// funkcia, ktora prida novy uzol na zaciatok zoznamu
void prependNode(LIST* list, int value) {
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = value;
	newNode->next = list->first;
	list->first = newNode;
}

// funkcia, ktora najde predchodcu zadaneho uzla 'a'
NODE* findPredecessor(LIST* list, NODE* a) {
	NODE* tmp = list->first;
	while (tmp) {
		if (tmp->next == a) {
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}

// funkcia, ktora vymeni dva zadane uzly v zretazenom zozname
void swapNodes(LIST* list, NODE *a, NODE *b) {
	if (!a || !b) {
		return;
	}
	NODE* pred_a = findPredecessor(list, a);
	NODE* pred_b = findPredecessor(list, b);
	if (pred_a) {
		pred_a->next = b;
	}
	if (pred_b) {
		pred_b->next = a;
	}
	NODE* tmp = a->next;
	a->next = b->next;
	b->next = tmp;
	if (a == list->first) {
		list->first = b;
		return;
	}
	if (b == list->first) {
		list->first = a;
	}
}

// funkcia, ktora dealokuje cely zretazeny zoznam
void deleteList(LIST* list) {
	NODE* tmp = NULL;
	while (list->first) {
		tmp = list->first->next;
		free(list->first);
		list->first = tmp;
	}
}

void bubbleSortList(LIST* list) {
	// TODO 1: 
	// Dokoncite funkciu bubbleSortList na zotriedenie zretazeneho zoznamu 'list' algoritmom Bubble Sort.
	// Nemente prototyp funkcie.
	// Pomozte si hore-uvedenymi funkciami na pracu so zoznamom
	int swapped = 1;
	NODE* current = list->first;
	NODE* tmp = NULL;
	NODE* save = NULL;
	if (!current) {
		return;
	}
	while (swapped) {
		swapped = 0;
		current = list->first;
		while (current->next != tmp) {
			if (current->data > current->next->data) {
				save = current->next;
				swapNodes(list, current, current->next);
				current = save;
				swapped = 1;
			}
			current = current->next;
		}
		tmp = current;
	}

}

int main()
{
	int n = 10;
	srand((unsigned int)time(NULL));

	printf("Bubble Sort: zretazeny zoznam\n-----------------------------\n");
	LIST list;
	list.first = NULL;

	// pridanie n uzlov do zoznamu
	int i = 0;
	for (i; i < n; i++) {
		prependNode(&list, rand() % 100);
	}

	// vypis neusporiadaneho zoznamu
	printf("Neusporiadany zoznam:\t");
	printList(&list);

	// TODO 2: 
	// Zavolajte funkciu bubbleSortList, ktora zotriedi zretazeny zoznam 'list'
	bubbleSortList(&list);
	// vypis usporiadaneho zoznamu
	printf("Usporiadany zoznam:\t");
	printList(&list);

	deleteList(&list);

	getchar();
	return 0;
}