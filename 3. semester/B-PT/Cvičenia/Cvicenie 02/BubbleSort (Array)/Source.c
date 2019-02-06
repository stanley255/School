#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void* swap(int* p1, int* p2) {
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void bubbleSortArray(int * arr, int n) {
	// TODO 1: 
	// Dokoncite funkciu bubbleSortArray na zotriedenie pola 'arr'
	// algoritmom Bubble Sort, nemente prototyp funkcie
	int swap_tmp = 1;
	while (swap_tmp) {
		swap_tmp = 0;
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr+i, arr+i+1);
				swap_tmp = 1;
			}
		}
		n--;
	}
}

int main()
{
	int n = 10;
	srand((unsigned int)time(NULL));

	printf("Bubble Sort: pole\n-----------------\n");
	int *arr = (int*)calloc(n, sizeof(int));
	fillArray(arr, n); // napln pole

	printf("Neusporiadane:\t");
	printArray(arr, n); // vytlac neusporiadane pole

	// TODO 2: 
	// Zavolajte funkciu bubbleSortArray, ktora zotriedi pole 'arr'
	bubbleSortArray(arr, n);

	printf("Usporiadane:\t");
	printArray(arr, n); // vytlac usporiadane pole

	free(arr); // uvolni pamat pola
	arr = NULL;

	getchar();
	return 0;
}