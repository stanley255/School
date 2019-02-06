#include <stdio.h>
#define MAXPOLE 100
#include <stdlib.h>
void vypisPola(int pole[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%i ", pole[i]);
	}
	printf("\n");
}

//Funkcia do zadan�ho po�a na��ta n ��sel zo �tandardn�ho vstupu (pomocou scanf).
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
//Na��tavajte do po�a zo �tandardn�ho vstupu (pomocou scanf) postupne ��sla, a� pok�m sa nena��ta 0, resp. pokia� sa nena��ta n ��sel. 
//Z�vere�n� nulu do po�a neukladajte.
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
//Na��tavajte do po�a zo �tandardn�ho vstupu (pomocou scanf) n kladn�ch ��sel, z�porn� preskakujte. 
//Predpoklad� sa, �e k dispoz�cii je dostatok vstupov).
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
//Na��tavajte do po�a zo �tandardn�ho vstupu (pomocou scanf) postupne kladn� ��sla, a� pok�m sa nena��ta 0, resp. pokia� sa nena��ta n ��sel. 
//Z�porn� ��sla preskakujte. Z�vere�n� nulu do po�a neukladajte.
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