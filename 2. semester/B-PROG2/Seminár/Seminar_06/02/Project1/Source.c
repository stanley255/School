#include <stdio.h>
#define MAXPOLE 100
#include <stdlib.h>
void vypisPola(int pole[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%i ", pole[i]);
	}
	printf("\n");
}

//Funkcia do zadaného po¾a naèíta n èísel zo štandardného vstupu (pomocou scanf).
void nacitajDoPola(int pole[], int *pN) {
	int n;
	do {
		printf("Zadaj pocet prvkov, ktore chces nacitat: ");
		scanf_s("%i", &n);
		getchar();
	} while (n > *pN);
	for (int i = 0; i < n; i++) {
		scanf_s("%i",&pole[i]);
		getchar();
	}
	*pN = n;
}
//Naèítavajte do po¾a zo štandardného vstupu (pomocou scanf) postupne èísla, až pokým sa nenaèíta 0, resp. pokia¾ sa nenaèíta n èísel. 
//Závereènú nulu do po¾a neukladajte.
void nacitajDoPola2(int pole[], int *pN) {
	int n, input;
	do {
		printf("Zadaj pocet prvkov, ktore chces nacitat: ");
		scanf_s("%i", &n);
		getchar();
	} while (n > *pN);
	for (int i = 0; i < n; i++) {
		scanf_s("%i", &input);
		getchar();
		if (input != 0) {
			pole[i] = input;
		}
		else {
			*pN = i;
			return;
		}
		
	}
	*pN = n;
}
//Naèítavajte do po¾a zo štandardného vstupu (pomocou scanf) n kladných èísel, záporné preskakujte. 
//Predpokladá sa, že k dispozícii je dostatok vstupov).
void nacitajDoPolaKladne(int pole[], int *pN) {
	int n, i = 0, input;
	do {
		printf("Zadaj pocet prvkov, ktore chces nacitat: ");
		scanf_s("%i", &n);
		getchar();
	} while (n > *pN);
	do {
		scanf_s("%i", &input);
		getchar();
		if (input > 0) {
			pole[i] = input;
			i++;
		}
	} while (i < n);
	*pN = n;
}
//Naèítavajte do po¾a zo štandardného vstupu (pomocou scanf) postupne kladné èísla, až pokým sa nenaèíta 0, resp. pokia¾ sa nenaèíta n èísel. 
//Záporné èísla preskakujte. Závereènú nulu do po¾a neukladajte.
void nacitajDoPolaKladnePoNulu(int pole[], int *pN) {
	int n, i = 0, input;
	do {
		printf("Zadaj pocet prvkov, ktore chces nacitat: ");
		scanf_s("%i", &n);
		getchar();
	} while (n > *pN);
	do {
		scanf_s("%i", &input);
		getchar();
		if (input > 0) {
			pole[i] = input;
			i++;
		}
		else if (input == 0) {
			*pN = i;
			return;
		}
	} while (i < n);
	*pN = n;
}
int main() {
	int pole[MAXPOLE];
	int n = 15;
	//nacitajDoPola(pole, &n);
	//nacitajDoPola2(pole, &n);
	nacitajDoPolaKladnePoNulu(pole, &n);
	vypisPola(pole, n);


	getchar();
	return 0;
}