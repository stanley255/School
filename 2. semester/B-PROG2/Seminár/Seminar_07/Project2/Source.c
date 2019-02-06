#include <stdio.h>
#include <stdlib.h>

//Uva�ujme polia prefixovan� d�kou: Polia maj� na za�iatku jeden prvok, ktor� hovor� o d�ke zvy�ku po�a. Napr. {3,2,5,7} znamen�, �e v poli s� platn� 3 prvky:2,5,7. Najmen�ie mo�n� pole je teda {0}.
	//Vytvorte funkciu na v�pis tak�hoto po�a(d�ku nevypisujte).
void vypisPrefixPole(int pole[]) {
	for (int i = 0; i < pole[0]; i++) {
		printf("%i ",pole[i+1]);
	}
	printf("\n");
}
	//Vytvorte funkciu na vytvorenie tak�hoto po�a zo �tandardn�ho po�a.
		//Parametrom funkcie je pole a po�et platn�ch prvkov.Funkcia vr�ti dynamicky alokovan� pole prefixovan� d�kou s rovnak�m obsahom ako p�vodn� pole.
int* vytvoreniePrefixPola(int pole[], int n) {
	int * result = (int *)malloc((n+1)*sizeof(int));
	result[0] = n;
	for (int i = 0; i < result[0];i++) {
		result[i + 1] = pole[i];
	}
	return result;
}
	//Vytvorte funkciu na pridanie prvku do prefixov�ho po�a.Vyu�ite realloc.
int * pridanieDoPrefixPola(int pole[]) {
	int prvok;
	int * result;
	printf("Zadaj prvok, ktory chces do pola pridat: ");
	scanf_s("%i", &prvok);
	getchar();
	result = (int *)realloc(pole,(pole[0]+1)*sizeof(int));
	result[0]++;
	result[result[0]] = prvok;
	return result;
}
	//Vytvorte funkciu na spojenie dvoch prefixov�ch pol�.Vstupom funkcie s� dve prefixov� polia 
		//a v�stup je novo - alokovan� pole, kde bud� prvky z oboch sp�jan�ch pol� ulo�en� za sebou.
int * spojeniePrefixPoli(int pole1[], int pole2[]) {
	int * result;
	result = malloc((pole1[0]+pole2[0]+1)*sizeof(int));
	result[0] = pole1[0] + pole2[0];
	for (int i = 0; i < pole1[0]; i++) {
		result[i + 1] = pole1[i + 1];
	}
	for (int j = (pole1[0]+1); j < ((pole1[0] + pole2[0])+1); j++) {
		result[j] = pole2[j - pole1[0]];
	}
	return result;
}
	//Vytvorte funkciu na prienik dvoch prefixov�ch pol�.Vstupom funkcie s� dve prefixov� polia 
		//a v�stup je novo - alokovan� pole, kde bud� prvky, ktor� sa nach�dzaj� v oboch vstupn�ch poliach.
int * prienikPrefixPoli(int pole1[], int pole2[]) {
	int * result;
	int counter = 0;
	result = (int *)malloc((pole1[0] + pole2[0] + 1) * sizeof(int));
	for (int i = 1; i < (pole1[0]+1); i++) {
		for (int j = 1; j < (pole2[0] + 1); j++) {
			if (pole1[i] == pole2[j]) {
				result[counter + 1] = pole1[i];
				counter++;
				break;
			}
		}
	}
	result = (int *)realloc(result,(counter+1)*sizeof(int));
	result[0] = counter;
	return result;
}
int main() {
	int pole1[] = { 2,3,4,5 }, pole2[] = {3,5,8,9,6};
	int* prefixPole1, *prefixPole2,*joinedPrefixPole,*prienikPrefixPole;

	prefixPole1 = vytvoreniePrefixPola(pole1,sizeof(pole1)/sizeof(int));
	vypisPrefixPole(prefixPole1);
	prefixPole2 = vytvoreniePrefixPola(pole2, sizeof(pole1) / sizeof(int));
	vypisPrefixPole(prefixPole2);

	//prefixPole = pridanieDoPrefixPola(prefixPole);
	//vypisPrefixPola(prefixPole);

	joinedPrefixPole = spojeniePrefixPoli(prefixPole1,prefixPole2);
	vypisPrefixPole(joinedPrefixPole);

	prienikPrefixPole = prienikPrefixPoli(prefixPole1, prefixPole2);
	vypisPrefixPole(prienikPrefixPole);

	getchar();
	return 0;
}