#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// funkcia na vypis pola
void printArray(int* arr, int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%i ", arr[i]);
	printf("\n");
}

// funkcia na naplnenie pola nahodnymi cislami
void fillArray(int* arr, int n) {
	int i;
	for (i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}
}

void insertionSortArray(int *arr, int n) {
	// TODO 1: 
	// Dokoncite funkciu insertionSortArray na zotriedenie pola 'arr' algoritmom Insertion Sort
	// nemente prototyp funkcie

	// cez for
	/*
	for (int j = i; i >= 0 ; j--) {
		if (arr[j] < arr[j - 1]) {
			swap(arr+j,arr+j-1);
		} else {
			break;
		}
	}
	*/
	int j;
	for (int i = 1; i < n; i++) {
		j = i;
		while (arr[j] < arr[j - 1]) {
			swap(arr + j, arr + j - 1);
		}
	}
}

void insertionSortSomeOfArray(int *arr, int start, int end) {
	int j;
	for (int i = start; i <= end; i++) {
		for (int j = i; i > start; j--) {
			if (arr[j] < arr[j - 1]) {
				swap(arr + j, arr + j - 1);
			}
			else {
				break;
			}
		}
	}
}

int main()
{
	int n = 10;
	srand((unsigned int)time(NULL));

	printf("Insertion Sort: pole\n-----------------\n");
	int *arr = (int*)calloc(n, sizeof(int));
	fillArray(arr, n); // napln pole

	printf("Neusporiadane:\t");
	printArray(arr, n); // vytlac neusporiadane pole
	// TODO 2: 
	// Zavolajte funkciu insertionSortArray, ktora zotriedi pole 'arr'
	insertionSortArray(arr, n);
	insertionSortSomeOfArray(arr, n-6, n-1);
	printf("Usporiadane:\t");
	printArray(arr, n); // vytlac usporiadane pole

	free(arr); // uvolni pamat pola
	arr = NULL;

	getchar();
	return 0;
}