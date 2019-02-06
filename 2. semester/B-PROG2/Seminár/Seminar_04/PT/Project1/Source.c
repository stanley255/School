#include <stdio.h>
#include <math.h>
int faktorial(int cislo) {
	int result;
	if ((cislo == 0)||(cislo == 1)) { return 1; }
	result = faktorial(cislo - 1)*cislo;
	return result;
}

int kombinacne_cislo(int n, int k) {
	int result = 0;
	if ((k == 0) || (k == n)) { return 1; }
	//result = (faktorial(n)/(faktorial(n-k)*faktorial(k)));
	return result;
}

int C2(int n, int k) {
	int citatel = 1, menovatel = 1, i;
	if (n - k < k) {
		k = n - k;
	}
	for (i = 1; i <= k; i++) {
		menovatel *= i;
	}
	for (int i = 0; i < k; i++) {
		citatel *= (n - i);
	}
	return citatel / menovatel;
}

int pocet_miest(int x) {
	return floor(log10(abs(x))) + 1;
}

int main() {
	//PASCALOV TROJUHOLNIK
	int pocet_riadkov = 13, pocet_medzier = pocet_miest(kombinacne_cislo(pocet_riadkov, pocet_riadkov / 2))*2;
	for (int i = 0; i <= pocet_riadkov; i++) {
		for (int k = 0; k < pocet_riadkov - i; k++) {
			printf("   ");
		}
		for (int j = 0; j < i + 1; j++) {
			printf("%*.i",pocet_medzier,C2(i,j));
		}
		printf("\n");
	}
	getchar();
	return 0;
}