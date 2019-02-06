#include <stdio.h>
#include <math.h>
#define N 20
int faktorial(int x) {
	int vysledok = 1;
	if ((x == 1)||(x == 0)) {
		return 1;
	}
	vysledok = faktorial(x - 1) * x;
}

int kombinacne_cislo(int n, int k) {
	int result = faktorial(n);
	return result / (faktorial(k)*(faktorial(n - k)));
}

int pocet_cifier_cisla(int cislo) {
	return floor(log10(abs(cislo))) + 1;
}

int main() {
	int konstanta_posunu = 2;
	//DEKLARACIA POLA
	int pole[N][N] = { {0} };
	//NAPLNENIE JEDNOTIEK
	pole[0][0] = 1;
	for (int i = 1; i < N; i++) {
		pole[i][0] = 1;
		pole[i][i] = 1;
	}

	//VYPOCET CISIEL VNUTRI P.TROJUHOLNIKA
	for (int i = 2; i < N; i++) {
		for (int j = 0; j < i - 1; j++) {
			pole[i][j + 1] = pole[i-1][j]+pole[i-1][j+1];
		}
	}

	konstanta_posunu = pocet_cifier_cisla(pole[N - 1][N / 2]);
	konstanta_posunu += N <= 5 ? 3 : 6;
	
	//VYPIS TROJUHOLNIKA
	for (int i = 0; i < N; i++) {
		//medzery
		for (int j = 0; (j < (N - i - 1)); j++) {
			for (int k = 0;(k < (konstanta_posunu/2)); k++) {
				printf(" ");
			}
		}
		//prvky
		for (int j = 0; j < N; j++) {
			//printf("%*.i", konstanta_posunu,pole[i][j]);
			if ((pole[i][j] % 2 == 0)&&(pole[i][j]!=0)) {
				printf("%*.c", konstanta_posunu,'*');
			}
			else {
				printf("%*.i", konstanta_posunu, pole[i][j]);
			}
		}
		printf("\n");
	}

	getchar();
	return 0;
}