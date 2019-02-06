#include <stdio.h>
#define MAXPOLE 100
#include <stdlib.h>
void vypisPola(int pole[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%i ",pole[i]);
	}
	printf("\n");
}

//Funkcia inicializuje pole hodnotami od 0 po n-1 (parameter funkcie n urèuje ve¾kos po¾a).
void f1(int pole[], int n) {
	for (int i = 0; i < n; i++) {
		pole[i] = i;
	}
}
//Funkcia inicializuje pole hodnotami od 1 po n.
void f2(int pole[], int n) {
	for (int i = 1; i <= n; i++) {
		pole[i-1] = i;
	}
}
//Funkcia inicializuje pole hodnotami od n po 1 (zostupne).
void f3(int pole[], int n) {
	for (int i = 0; i < n; i++) {
		pole[i] = n - i;
	}
}
//Funkcia inicializuje pole n náhodnými hodnotami. Použite knižniènú funkciu rand() (deklarácia v stdlib.h).
void f4(int pole[], int n) {
	for (int i = 0; i < n; i++) {
		pole[i] = rand() % (10+1);
	}
}
//Funkcia inicializuje pole hodnotami rovnými k-násobku indexu ().
void f5(int pole[], int n, int k) {
	for (int i = 0; i < n; i++) {
		pole[i] = k*i;
	}
}
//Funkcia inicializuje pole n párnymi èíslami väèšími alebo rovnými parametru a.
void f6(int pole[], int n, int a) {
	for (int i = 0; i < n; i++) {
		pole[i] = (i+1)*a;
	}
}

int main() {
	int pole[MAXPOLE];
	f1(pole,10);
	vypisPola(pole, 10);
	f2(pole, 10);
	vypisPola(pole, 10);
	f3(pole, 10);
	vypisPola(pole, 10);
	f4(pole, 10);
	vypisPola(pole, 10);
	f5(pole, 10, 3);
	vypisPola(pole, 10);
	f6(pole, 10, 2);
	vypisPola(pole, 10);

	getchar();
	return 0;
}