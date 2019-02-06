#include <stdio.h>
#include <stdlib.h>

//Uvažujme polia prefixované dåžkou: Polia majú na zaèiatku jeden prvok, ktorý hovorí o dåžke zvyšku po¾a. Napr. {3,2,5,7} znamená, že v poli sú platné 3 prvky:2,5,7. Najmenšie možné pole je teda {0}.
	//Vytvorte funkciu na výpis takéhoto po¾a(dåžku nevypisujte).
void vypisPrefixPole(int pole[]) {
	for (int i = 0; i < pole[0]; i++) {
		printf("%i ",pole[i+1]);
	}
	printf("\n");
}
	//Vytvorte funkciu na vytvorenie takéhoto po¾a zo štandardného po¾a.
		//Parametrom funkcie je pole a poèet platných prvkov.Funkcia vráti dynamicky alokované pole prefixované dåžkou s rovnakým obsahom ako pôvodné pole.
int* vytvoreniePrefixPola(int pole[], int n) {
	int * result = (int *)malloc((n+1)*sizeof(int));
	result[0] = n;
	for (int i = 0; i < result[0];i++) {
		result[i + 1] = pole[i];
	}
	return result;
}
	//Vytvorte funkciu na pridanie prvku do prefixového po¾a.Využite realloc.
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
	//Vytvorte funkciu na spojenie dvoch prefixových polí.Vstupom funkcie sú dve prefixové polia 
		//a výstup je novo - alokované pole, kde budú prvky z oboch spájaných polí uložené za sebou.
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
	//Vytvorte funkciu na prienik dvoch prefixových polí.Vstupom funkcie sú dve prefixové polia 
		//a výstup je novo - alokované pole, kde budú prvky, ktoré sa nachádzajú v oboch vstupných poliach.
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