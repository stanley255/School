#include <stdio.h>
#include <stdlib.h>
#define N 10

void vypisPole(int pole[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%i ", pole[i]);
	}
	printf("\n");
}

void naplnPole(int pole[], int n) {
	for (int i = 0; i < n; i++) {
		pole[i] = rand() % (10);
	}
}
//Funkcia m· na vstupe 2 polia (poleA, poleB) a veækosù n. Polia ch·peme ako vektory hodnÙt. 
//Funkcia vypoËÌta skal·rny s˙Ëin vektorov poleA a poleB (t.j. s˙Ëet poleA[i]*poleB[i] cez vöetky i).
void skalarnySucin(int poleA[], int poleB[], int n) {
	printf("Skalarny sucin vektorov: ");
	for (int i = 0; i < n; i++) {
		printf("%i ", poleA[i]*poleB[i]);
	}
	printf("\n");
}
//Funkcia m· na vstupe 2 polia (poleA, poleB) a veækosù n. Polia ch·peme ako vektory hodnÙt. 
//Funkcia zistÌ, Ëi vektory poleA a poleB s˙ rovnakÈ (t.j. poleA[i] == poleB[i] pre vöetky i).
int rovnostPoli(void *poleA, void *poleB, int n) {
	char *pA = (char*)poleA, *pB = (char*)poleB;
	for (int i = 0; i < n; i++) {
		if (*pA != *pB) {
			return 0;
		}
	}
	return 1;
}
//Funkcia m· na vstupe 2 polia (poleIn a poleOut) a veækosù n. 
//Do poæa poleOut skopÌruje prvky z poæa poleIn. Predpokladajte, ûe polia sa neprekr˝vaj˙.
void kopirovanieNeprekryvajucich(int poleIn[], int poleOut[], int n) {
	for (int i = 0; i < n; i++) {
		poleOut[i] = poleIn[i];
	}
}

void kopirovaniePrekryvajucich(int poleIn[], int poleOut[], int n) {
	for (int i = n - 1; i >= 0; i--) {
		poleOut[i] = poleIn[i];
	}
}
//Funkcia m· na vstupe 2 polia (poleIn a poleOut) a veækosù n. Do poleOut zapÌöte prvky z poleIn usporiadane (poleIn nesmiete zmeniù). 
void f7part1(const int poleIn[], int poleOut[], int n) {
	int temp;
	for (int i = 0; i < n; i++) {
		poleOut[i] = poleIn[i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0; j--) {
			if (poleOut[j - 1] > poleOut[j]) {
				temp = poleOut[j - 1];
				poleOut[j - 1] = poleOut[j];
				poleOut[j] = temp;		
			}
			else {
				break;
			}
		}
	}
}
//Do poleOut zapÌöe vöetky prvky z poleIn v‰Ëöie ako x (v pÙvodnom poradÌ).
//Vr·ti nov˝ poËet prvkov poleOut.
void f7part2(const int poleIn[], int poleOut[], int *pN, int x) {
	int counter = 0;
	for (int i = 0; i < *pN; i++) {
		if (poleIn[i] < x) {
			poleOut[counter] = poleIn[i];
			counter++;
		}
	}
	*pN = counter;
}
//Funkcia m· na vstupe 3 polia (poleOut, poleA, poleB) a veækosù n. Polia ch·peme ako vektory hodnÙt. 
//Funkcia zapÌöe do poleOut s˙Ëet vektorov poleA a poleB (poleOut[i] = poleA[i]+poleB[i], pre vöetky i).
void sucetPoli(int poleOut[], int poleA[], int poleB[], int n) {
	for (int i = 0; i < n; i++) {
		poleOut[i] = poleA[i] + poleB[i];
	}
	printf("Sucet poli: ");
	vypisPole(poleOut, n);
}

//Funkcia m· na vstupe 2 polia (poleA, poleB) a veækosù n. Polia ch·peme ako vektory hodnÙt. 
//Funkcia pripoËÌta k-n·sobok vektora poleB do vektora poleA (poleA[i] = poleA[i]+k*poleB[i], pre vöetky i).
void kNasobok(int poleA[], int poleB[], int n, int k) {
	for (int i = 0; i < n; i++) {
		poleA[i] = poleA[i] + k * poleB[i];
	}
}

//Funkcia m· na vstupe 3 polia (poleOut, poleA, poleB), veækosti nA a nB. Pole poleOut musÌ maù dostatoËn˙ kapacitu, t.j. min(nA, nB). 
//Ch·peme poleA a poleB ako mnoûiny. 
//Do poleOut napÌöte ich prienik (t.j. bud˙ tam iba prvky, ktorÈ s˙ aj v poleA aj v poleB). Vr·ùte poËet prvkov poleOut.
int prienikPoli(int poleOut[], int poleA[], int poleB[], int n) {
	int counter = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (poleA[i] == poleB[j]) {
				poleOut[counter] = poleB[j];
				counter++;
				break;
			}
		}
	}
	return counter;
}
int main() {
	int poleA[N] = { 0 }, poleB[N] = {0}, poleOut[N];
	//float poleA[3] = { 1.5,3.8,3.2 }, poleB[3] = { 1.5,3.8,3.2 };
	int n = N;
	int n1 = sizeof(poleA) / sizeof(poleA[0]);
	int n2 = sizeof(poleB) / sizeof(poleB[0]);
	int minn = n1 < n2 ? n1 : n2;
	minn *= sizeof(poleA[0]);
	naplnPole(poleA, n);
	naplnPole(poleB, n);
	printf("Pole A: ");
	vypisPole(poleA, n);
	printf("Pole B: ");
	vypisPole(poleB, n);
	skalarnySucin(poleA, poleB, n);
	if (rovnostPoli(&poleA[0], &poleB[0], minn)) {
		printf("Polia sa rovnaju.\n"); 
	}
	else {
		printf("Polia sa nerovnaju.\n");
	}
	//sucetPoli(poleOut, poleA, poleB, n);
	//kNasobok(poleA,poleB,n,2);
	printf("Pole A: ");
	vypisPole(poleA, n);
	printf("Pole B: ");
	vypisPole(poleB, n);
	minn = prienikPoli(poleOut, poleA, poleB, n);
	printf("Prienik: ");
	vypisPole(poleOut, minn);


	/*f7part1(poleA, poleB, n);
	printf("Pole A: ");
	vypisPole(poleA, n);
	f7part2(poleA, poleB, &n, 5);
	printf("Pole B: ");
	vypisPole(poleB, n);
	kopirovanieNeprekryvajucich(poleA,poleB, n);
	int n = 4;
	int pole[7] = {1,2,3,4,5,6,7};
	int *poleA = &pole[0];
	int *poleB = &pole[3];
	printf("Pole A: ");
	vypisPole(poleA, n);
	printf("Pole B: ");
	vypisPole(poleB, n);
	kopirovaniePrekryvajucich(poleA, poleB,n);
	printf("Pole A: ");
	vypisPole(poleA, n);
	printf("Pole B: ");
	vypisPole(poleB, n);*/


	getchar();
	return 0;
}