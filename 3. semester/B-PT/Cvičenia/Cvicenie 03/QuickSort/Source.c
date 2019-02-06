#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// funkcia, ktora vypise pole do konzoly a specialne oznaci pivota
void printArray(int* arr, int n, int pivot_index) {
	int i;
	for (i = 0; i < n; i++)
		if (i != pivot_index) {
			printf("%d ", arr[i]);
		}
		else {
			printf("[%d] ", arr[i]);
		}
	printf("\n");
}

// funkcia, ktora vyplni pole 'arr' nahodnymi cislami
void fillArray(int* arr, int n) {
	int i;
	for (i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}
}

// funkcia, ktora zameni obsahy na adresach 'a' a 'b'
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/*********************** PARTITION ***************************/
//
// POPIS: 
//      Funkcia, ktora vyberie pivota, mensie prvky ako pivot zaradi
//      vlavo od neho a vacsie prvky zaradi vpravo od neho. Funkcia
//      nakoniec vrati finalnu poziciu pivota v poli
// PARAMETRE:
//      arr - vstupne pole 
//      left - index lavej hranice pola
//      right - index pravej hranice pola
// NAVRATOVA HODNOTA:
//      int - finalna pozicia pivota
//
/************************************************************/

int partition(int *arr, int left, int right) {
	// TODO: dopiste funkciu partition
	// 1. krok - nahodny vyber pivota
	int pivot_index = rand() % (right - left + 1) + left;
	// 2. krok - presun pivot dolava
	swap(arr + pivot_index, arr + left);
	// 3. krok - vytvorenie left&right markov
	int leftmark = left + 1;
	int rightmark = right;
	// 4. krok - posuvanie lm a rm pokial sa neprekrizia
	while (leftmark <= rightmark) {
		if (arr[leftmark] <= arr[left]) {
			leftmark++;
		}
		else if (arr[rightmark] > arr[left]) {
			rightmark--;
		}
		else {
			swap(arr+leftmark,arr+rightmark);
		}
	}
	swap(arr + left, arr + rightmark);
	return rightmark; // vratim poziciu pivota
}

void quickSortArrayRecursive(int * arr, int left, int right) {
	// TODO 1: dokoncite implementaciu tejto funkcie.
	if (left < right) {
		// 1. vykonaj partition
		int pivot_index = partition(arr, left, right);
		// 2. rekurzia do lavej casti pola
		quickSortArrayRecursive(arr, left, pivot_index - 1);
		// 3. rekurzia do pravej casti
		quickSortArrayRecursive(arr, pivot_index + 1, right);
	}
}

int main()
{
	int n = 20;
	srand((unsigned int)time(NULL));

	printf("Partition: Pole\n-----------------\n");
	int *arr = (int*)calloc(n, sizeof(int));
	fillArray(arr, n); // napln pole

	printf("\nPred:\t");
	printArray(arr, n, -1);

	quickSortArrayRecursive(arr, 0, n - 1); // zavolame funkciu partition

	/*printf("\nPivot index: %i", pivot_index);
	printf("\nPivot value: %i\n", arr[pivot_index]);*/

	printf("\nPo:\t");
	printArray(arr, n, -1);
	printf("\n");

	free(arr);
	arr = NULL;

	getchar();
	return 0;
}