#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int prevod(int pole[], int k, int m);
int nahodneCislo(int a, int b) {
	return rand() % (b - a + 1) + a;
}

void generujPole(int pole[], int n, int m) {
	for (int i = 0; i < n; i++) {
		pole[i] = nahodneCislo(0,m-1);
	}
}

void vypisPole(int pole[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%i ", pole[i]);
	}
	printf("\n");
}

void vypisPocetnost(double pole[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%9.2lf", pole[i]);
	}
	printf("\n");
}

void vypisHodnoty(int n, int m, int k, int d) {
	printf("   N = %i\n",n);
	printf("   M = %i\n", m);
	printf("   K = %i\n", k);
	printf("   D = %i\n", d);
}

void vsetkyMozneSkupiny(int pole[], int tlac, int m, int k, int s) {
	//int mozneSkupiny[S][K];
	int** mozneSkupiny = (int**)malloc(s*sizeof(int *));
	for (int i = 0; i < s; i++) {
		mozneSkupiny[i] = (int *)malloc(k * sizeof(int));
	}
	int *poleZnakov = (int*)malloc(m*sizeof(int)), cislo = 0, koeficient = 1, pocetOpakovani1, pocetOpakovani2, pocetRiadkov;
	pocetOpakovani2 = (int)pow(m, k - 1);
	//VYTVORENIE POLA ZNAKOV
	for (int i = 0; i < m; i++) {
		poleZnakov[i] = i;
	}
	for (int i = 0; i < k; i++) {
		int counter = 0;
		int znak = 0;
		pocetOpakovani1 = (int)pow(m, k + i - 2);
		pocetOpakovani2 = (int)pow(m, k - i - 1);
		for (int j = 0; j < pocetOpakovani1; j++) {
			if (znak == m) {
				znak = 0;
			}
			for (int k = 0; k < pocetOpakovani2; k++) {
				mozneSkupiny[counter][i] = poleZnakov[znak];
				counter++;
			}
			znak++;
		}
	}
	if (tlac == 1) {
		printf("  ");
		for (int i = 0; i < s; i++) {
			for (int j = 0; j < k; j++) {
				printf(" %i",mozneSkupiny[i][j]);
			}
			printf(" | ");
		}
		printf("\n");
	}
	//PRIRADENIE DECIMALNYCH HODNOT VSTUPNEMU POLU
	for (int i = 0; i < s; i++) {
		pole[i] = prevod(mozneSkupiny[i], k, m);
	}
	free(mozneSkupiny);
	free(poleZnakov);
}

int prevod(int pole[], int k, int m) {
	int result = 0;
	for (int i = 0; i < k; i++) {
		result += pole[i] * (int)pow(m, i);
	}
	return result;
}

int zistiIndex(int cislo, int mozneSkupiny[], int s) {
	for (int i = 0; i < s; i++) {
		if (cislo == mozneSkupiny[i]) {
			return i;
		}
	}
}

void pocetnost(int myArray[], int mozneSkupiny[], double outputPole[] ,int n, int k, int m,int s) {
	int *tempArray = (int*)malloc(k*sizeof(int)), index = 0;
	for (int i = 0; i < (n - k + 1); i++) {
		for (int j = 0; j < k; j++) {
			tempArray[j] = myArray[i+j];
		}
		index = zistiIndex(prevod(tempArray, k, m), mozneSkupiny, s);
		outputPole[index] += 1;
	}
	for (int i = 0; i < s; i++) {
		outputPole[i] /= (n - k + 1);
	}
}

void decimacia(int *myArray, int *pN, int d) {
	int konstanta = d-1;
	if (d == 1) {
		*pN = 0;
		return;
	}
	for (int i = 0; i < *pN; i++) {
		if (i == konstanta) {
			for (int j = i; j < *pN-1; j++) {
				myArray[j] = myArray[j+1];
			}
			konstanta += d;
			konstanta--;						
			*pN =*pN -1;
		}
	}
}

void vypocetDelta(double arrayOne[], double arrayTwo[], double resultArray[],int s) {
	for (int i = 0; i < s; i++) {
		resultArray[i] = fabs(arrayOne[i] - arrayTwo[i]);
	}
}

void maxDelta(double deltaArray[], double *dV, int s) {
	int max = 0;
	for (int i = 1; i < s; i++) {
		if (deltaArray[i] > deltaArray[max]) {
			max = i;
		}
	}
	*dV = deltaArray[max];
}

int main() {
//DEKLARACIA PREMENNYCH
	int n = 60;
	int m = 2;
	int k = 3;
	int d = 3;
	int s = (int)pow(m, k);
//DEKLARACIA POLI
	int *myArray = (int *)malloc(n*sizeof(int));
	double *pocetnostMyArray = (double *)calloc(s,sizeof(double));
	double *pocetnostDecArray = (double *)calloc(s, sizeof(double));
	double *delta = (double *)calloc(s,sizeof(double)), maxDeltaValue;
	int* mozneSkupiny = (int*)malloc(s*sizeof(int));  //OBSAHUJE VSETKY MOZNE VARIACIE BEZ OPAKOVANIA V DECMILNYCH H.
	
	srand(time(NULL));

	generujPole(myArray, n, m);
	printf("\n");
	vypisHodnoty(n,m,k,d);
//MYARRAY CAST
	printf("\n   Povodna postupnost(dlzka=%i):\n   ",n);
	vypisPole(myArray, n);
	printf("   Frekvencia pred decimaciou: \n");
	vsetkyMozneSkupiny(mozneSkupiny,1, m , k ,s);
	pocetnost(myArray, mozneSkupiny, pocetnostMyArray, n, k, m, s);
	vypisPocetnost(pocetnostMyArray,s);
//POST-DECIMACNA CAST
	decimacia(myArray, &n, d);
	pocetnost(myArray,mozneSkupiny,pocetnostDecArray,n,k, m, s);
	printf("\n   Zdecimovana postupnost(dlzka=%i):\n   ", n);
	vypisPole(myArray, n);
	printf("   Frekvencia po decimacii: \n");
	vsetkyMozneSkupiny(mozneSkupiny, 1, m, k, s);	
	vypisPocetnost(pocetnostDecArray, s);
//DELTA CAST
	vypocetDelta(pocetnostMyArray, pocetnostDecArray, delta, s);
	printf("\n   Delta:\n");
	vypisPocetnost(delta, s);
	maxDelta(delta, &maxDeltaValue, s);
	printf("\n   Max delta = %.2lf",maxDeltaValue);

	free(myArray);
	free(pocetnostMyArray);
	free(pocetnostDecArray);
	free(delta);
	free(mozneSkupiny);
	getchar();
	return 0;
}