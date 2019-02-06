#include <stdio.h>
#include <memory.h>
//Vytvorte èo najrýchlejšiu funkciu, ktorá vymaže z po¾a duplikáty.
//VSTUP: ¾ubovo¾né, neusporiadané pole n èísel : {1, 4, 2, 2, 1, 5, 4, 3}
//VÝSTUP: pôvodné pole, kde každý prvok bude už len raz : {1, 4, 2, 5, 3}

int isIn(int data[], int n, int x) {
	for (int i = 0; i < n; i++) {
		if (data[i] == x) {
			return 1;
		}
	}
	return 0;
}

void deleteDuplicates(int pole[], int *pN) {
	int pomocne[8]; //tuto by malo byt *pN
	int nove_platne = 0;

	for (int i = 0; i < *pN; i++) {
		if (!isIn(pomocne, nove_platne, pole[i])) {
			pomocne[nove_platne] = pole[i];
			nove_platne++;
		}
	}
	memcpy(pole,pomocne, nove_platne*sizeof(int));
	*pN = nove_platne;
}

int main() {
	int pole[] = { 1, 4, 2, 2, 1, 5, 4, 3 };
	int n = sizeof(pole)/sizeof(pole[0]);
	printf("1 4 2 2 1 5 4 3\n");
	deleteDuplicates(pole, &n);
	for (int i = 0; i < n; i++) {
		printf("%i ",pole[i]);
	}
	getchar();
	return 0;
}