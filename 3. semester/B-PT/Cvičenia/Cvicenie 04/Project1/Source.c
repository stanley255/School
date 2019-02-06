#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// funkcia, ktora vypise pole do konzoly
void printArray(int* arr, int n) {
	int i;
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// funkcia, ktora vyplni pole 'arr' nahodnymi cislami
void fillArray(int* arr, int n) {
	int i;
	for (i = 0; i < n; i++) {
		arr[i] = rand() % 201 - 100;
	}
}

// funkcia, ktora zameni obsahy na adresach 'a' a 'b'
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/*********************** HEAP SORT ***************************/
//
// POPIS:
//      Funkcia, ktora usporiada vstupne pole pomocou algoritmu
//      Heap Sort.
// PARAMETRE:
//      arr - vstupne pole
//      n   - dlzka vstupneho pola
// NAVRATOVA HODNOTA:
//      void
//
/************************************************************/

void siftDown(int* arr, int start, int end) {
	// Zisti, ci existuje lavy potom a ci nie je vacsi ako start
	int maxInd = start;
	if (2 * start + 1 < end && arr[start*2+1]>arr[start]) {
		maxInd = 2 * start + 1; // ulozim si index laveho potomka
	}
	// Zisti, ci existuje pravy potomok a ci nie je vacsi ako arr[maxInd]
	if (2 * start + 2 < end && arr[start * 2 + 2] > arr[maxInd]) {
		maxInd = 2 * start + 2; // ulozim si index praveho potomka
	}
	// Overim, ci mam ist swapnut
	if (maxInd != start) {
		swap(arr + maxInd, arr + start);
		siftDown(arr, maxInd, end);
	}
}

void buildHeapSiftDown(int *arr, int n) {
	// Loopuj od prvého prvku, ktorý nie je listom až po nulový prvok
	for (int i = n / 2 - 1; i >= 0; i--) {
		siftDown(arr, i, n - 1);
	}
}

void siftUp(int* arr, int start, int end) {
	// zistim index parenta
	int parent_index = (end -1) / 2;
	// ak existuje rodic a zaroven plati, ze arr[parent_index] < arr[end]
	if (parent_index >= start && arr[parent_index] < arr[end]) {
		swap(arr + parent_index, arr + end);
		siftUp(arr, start, parent_index);
	}
}

void buildHeapSiftUp(int *arr, int n) {
	// kazdy prvok od i=1 idem vlozit do Max-Heapu
	for (int i = 1; i < n; i++) {
		// aplikuj siftUp na prvok arr[i]
		siftUp(arr, 0, i);
	}
}

void heapSort(int *arr, int n) {
	// Vytovor z pola maxHeap/minHeap (bud pomocou siftUp/siftDown)
	buildHeapSiftDown(arr, n);
	//buildHeapSiftUp(arr, n);
	// pokial su v Max-heape aspon 2 prvky
	while (n >= 2) {
		// Odstran vrchol Max-Heapu
		swap(arr, arr + --n);
		// Zrekonstruuj Max-Heap
		siftDown(arr, 0, n - 1);
	}
}

int main()
{
	int arr[] = { 4,3,7,1,8,5 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Heap Sort: Pole\n-----------------\n");

	printf("\nPred:\t");
	printArray(arr, n);

	heapSort(arr, n);

	printf("\nPo:\t");
	printArray(arr, n);

	getchar();
	return 0;
}