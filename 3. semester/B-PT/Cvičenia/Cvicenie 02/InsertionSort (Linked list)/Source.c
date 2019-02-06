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

// funkcia, ktora vlozi uzol 'toInsert' pred uzol 'target'
void insertNodeBefore(LIST* list, NODE* toInsert, NODE* target) {
	// kontroly, pre istotu
	if (!list) {
		return;
	}
	if (!list->first || !toInsert || !target) {
		return;
	}
	if (toInsert == target) {
		return;
	}
	// ak je zoznam aspon 1-prvkovy
	NODE* predTarget = findPredecessor(list, target);
	toInsert->next = target;
	if (predTarget) {
		// vkladam niekde do stredu zoznamu
		predTarget->next = toInsert;
	}
	else {
		// vkladam pred prvy uzol zoznamu
		list->first = toInsert;
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

void insertionSortList(LIST* list) {
	// TODO 1: 
	// Dokoncite funkciu insertionSortList na zotriedenie zretazeneho zoznamu 'list' algoritmom Insertion Sort.
	// Nemente prototyp funkcie.
	// Pomozte si hore-uvedenymi funkciami na pracu so zoznamom
	NODE* current = list->first;
	// zoznam je prazdny
	if (!current) {
		return;
	}
	// zoznam je jednoprvkovy
	if (!current->next) {
		return;
	}
	current = current->next;
	// zoznam je aspon dvojprvkovy
	NODE* current2 = NULL;
	while (current) {
		current2 = list->first;
		while (current2!=current) {
			if (current2->data > current->data) {
				// odpojit current uzol
				NODE* predCurrent = findPredecessor(list, current);
				if (predCurrent) {
					predCurrent->next = current->next;
				} else {
					list->first = current->next;
				}
				// vloz na spravne miesto
				insertNodeBefore(list, current, current2);
				break;
			}
			current2 = current2->next;
		}
		current = current->next;
	}
}

int main()
{
	int n = 5;
	srand((unsigned int)time(NULL));

	printf("Insertion Sort: zretazeny zoznam\n-----------------------------\n");
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
	// Zavolajte funkciu insertionSortList, ktora zotriedi zretazeny zoznam 'list'
	insertionSortList(&list);
	// vypis usporiadaneho zoznamu
	printf("Usporiadany zoznam:\t");
	printList(&list);

	deleteList(&list);

	getchar();
	return 0;
}