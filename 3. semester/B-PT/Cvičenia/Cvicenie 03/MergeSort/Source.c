#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define min(a,b) ((a)<(b)?(a):(b))

// funkcia, ktora vypise pole do konzoly
void printArray(int* arr, int n) {
	int i;
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

/*********************** MERGE ***************************/
// implementacia bez pouzitia pomocneho pola
//
// POPIS: 
//      Funkcia, ktora spoji 2 mensie usporiadane polia do 
//      jedneho velkeho usporiadaneho pola. Mensie usporiadane
//      polia su urcene hranicami [left, middle] a [middle+1,right].
//      Po spojeni vznikne jedno velke usporiadane pole, ktore ma hranice
//      [left, right]. Funkcia pocas svojej prace nebude potrebovat 
//      pomocne pole. 
// PARAMETRE:
//      arr - vstupne pole 
//      left - index lavej hranice pola
//      middle - index stredneho prvku v poli
//      right - index pravej hranice pola
// NAVRATOVA HODNOTA:
//      void
//
/************************************************************/

void merge(int *arr, int left, int middle, int right) {
	// TODO 1: dokoncite implementaciu funkcie
	// lave pole [left...middle]
	// prave pole[middle + 1...right]
	// 1. krok - vytvorenie markerov
	int li = left;
	int ri = middle + 1;
	int save;
	// 2. krok
	while (li <= middle && ri <= right) {
		// je arr[li] > arr[ri]
		if (arr[li] > arr[ri]) {
			// presun arr[ri] tesne pred arr[li]
				// odloz si arr[ri] do premennej
			save = arr[ri];
				// preposuvaj pole
			for (int i = ri - 1; i >= li; i--) {
				arr[i+1] = arr[i];
			}
			arr[li] = save;
			middle++;
			ri++;
		}
		li++;
	}
}

void mergeSortRecursive(int *arr, int left, int right) {
	if (left < right) {
		int middle = (left + right) / 2;
		// rekurzia do lavej polovice
		mergeSortRecursive(arr, left, middle);
		// rekurzia do pravej polovice
		mergeSortRecursive(arr, middle + 1, right);
		// zmerguj
		merge(arr, left, middle, right);
	}
}

void mergeSort(int *arr, int n) {
	// TODO 1: dokoncite implementaciu funkcie
	// REKURZIVNA VERZIA TOP-BOTTOM
	// mergeSortRecursive(arr, 0, n - 1); 
	// NEREKURZIVNA BOTTOM-UP
	int len;
	for (int len = 1; len < n; len = len * 2) {
		// Prejdi celym polom a spajaj susediace dvojice poli pricom kazde pole ma dlzku len
		for (int i = 0; i < n; i = i + 2 * len) {
			merge(arr, i, min(n-1, i + len - 1), min(n-1, i + 2 * len - 1));
		}
	}
}

int main()
{
	int left = 0;
	int middle = 3;
	int right = 8;
	int n = 5;
	// Prve usporiadane pole sa nachadza v arr[left...middle]
	// Druhe usporiadane pole sa nachadza v arr[middle+1,right]
	int arr[] = {3,0,7,1,-4}; // vyskusajte si aj vlastne polia

	printf("Operacia Merge: pole\n-----------------\n");

	printf("\nPred:\t");
	printArray(arr, sizeof(arr) / sizeof(arr[0]));

	// TODO 2: zavolajte funkciu, ktora vykona operaciu Merge
	mergeSort(arr, n);
	// -1, 1, 1, 2, 3, 8, 8, 10, 30
	printf("\nPo:\t");
	printArray(arr, sizeof(arr) / sizeof(arr[0]));

	printf("\n");

	getchar();
	return 0;
}