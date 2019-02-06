#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void vypisPole(int pole[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%i ", pole[i]);
	}
	printf("\n");
}

//1.
	//Vytvorte funkciu, ktorej vstupom je pole celých èísel a jeho dåžka.
	//Funkcia dynamicky alokuje pole dostatoènej ve¾kosti a prekopíruje doò obsah vstupného po¾a
	//(môžete využi štandardnú funkciu memcpy).Vráti smerník na alokované pole.

int * F1(int pole[], int n) {
	int *tempPole = (int *)malloc(n*sizeof(int));
	for (int i = 0; i < n; i++) {
		tempPole[i] = pole[i];
	}
	return &tempPole[0];
}
//2.
	//Napíšte a otestujte funkciu, ktorá naèítava zo vstupu èísla do po¾a typu double, 
	//ktoré dynamicky alokuje a postupne zväèšuje.Funkcia sa zastaví, keï naèíta èíslo 0, 
	//túto 0 ale neukladá do po¾a.Funkcia vráti smerník na alokované pole a ve¾kos po¾a(nepriamo, pomocou smerníka).

void F2() {
	double input = 1;
	int currentSize = 10;
	double * pole = (double *)malloc(currentSize*sizeof(double));
	int n = 0;
	while (1){
		printf("Zadaj double: ");
		scanf_s("%lf",&input);
		getchar();
		if (input == 0) {
			break;
		}		
		if (n < currentSize) {
			pole[n] = input;
			n++;
		}
		else {
			currentSize *= 2;
			pole = (double *)realloc(pole, n * sizeof(double));
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%.2lf ",pole[i]);
	}
	printf("\n");
}
//3.
	//Napíšte a otestujte funkciu, ktorej vstupom je pole èísel.
	//Funkcia pole rozdelí na úseky, prièom každý úsek je ukonèený nulou.
	//Smerníky na zaèiatky jednotlivých úsekov uloží do dynamického po¾a smerníkov, ktoré pod¾a potreby rozširuje.
	//Na koniec po¾a smerníkov uloží smerník NULL.
	//Vráti smerník na dynamické pole smerníkov(ukazujúcich na zaèiatky slov).
	//Napíšte si zvláš funkciu, ktorá postupnosti èísel z takto zadaného po¾a smerníkov vypíše
	//(viete, že každá postupnos konèí nulou), každú na iný riadok.

int** F3(int postupnost[], int n) {
	int currentSize = 10;
	int counter = 0;
	int** poleSmernikov = (int**)malloc(currentSize*sizeof(int*));
	poleSmernikov[counter] = postupnost;
	counter++;
	for (int i = 1; i < n; i++) {
		if (counter == currentSize) {
			currentSize *= 2;
			poleSmernikov = (int**)realloc(poleSmernikov, currentSize * sizeof(int*));
		}
		if (postupnost[i-1] == 0) {
			poleSmernikov[counter] = &postupnost[i];
			counter++;
		}
	}
	poleSmernikov[counter] = NULL;
	//poleSmernikov = (int**)realloc(poleSmernikov, counter * sizeof(int*));
	return poleSmernikov;
}

void vypisPostupnost(int** poleSmernikov) {
	int i = 0, j;
	while (poleSmernikov[i] != NULL) {
		int * tempSmernik = poleSmernikov[i];
		j = 0;
		while (tempSmernik[j] != 0) {
			printf("%i ",tempSmernik[j]);
			j++;
		}
		i++;
		printf("\n");
	}
}

//4.
	//Napíšte funkciu, ktorá vytvorí dynamicky dvojrozmerné pole požadovanej ve¾kosti n riadkov a m ståpcov.
	//Pole naplní nulami a vráti.
int ** F4(int n, int m) {
	int ** pole = (int**)malloc(n*sizeof(int*));
	for (int i = 0; i < n; i++) {
		pole[i] = (int *)calloc(m, sizeof(int));
	}
	return pole;
}

int main() {
	int n = 10;
	int *pole = (int *)malloc(n*sizeof(int));
	int postupnost[] = {1,2,3,5,0,1,8,7,5,0,3,4,0,6,7,1,0};
	int * p;
	for (int i = 0; i < n; i++) {
		pole[i] = i;
	}
	vypisPole(pole,n);
	p = F1(pole,n);
	vypisPole(p, n);
	//F2();
	vypisPole(postupnost, 17);
	vypisPostupnost(F3(postupnost, 17));	
	int ** smernikNaVytvorenePole = F4(5,8);
	for (int i = 0; i < 5; i++) {
		int * tempRiadok = smernikNaVytvorenePole[i];
		for (int j = 0; j < 8; j++) {
			printf("%i ", tempRiadok[i]);
		}
		printf("\n");
	}
	free(pole);
	getchar();
	return 0;
}