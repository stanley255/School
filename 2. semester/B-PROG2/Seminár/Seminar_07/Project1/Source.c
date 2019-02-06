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
	//Vytvorte funkciu, ktorej vstupom je pole cel�ch ��sel a jeho d�ka.
	//Funkcia dynamicky alokuje pole dostato�nej ve�kosti a prekop�ruje do� obsah vstupn�ho po�a
	//(m��ete vyu�i� �tandardn� funkciu memcpy).Vr�ti smern�k na alokovan� pole.

int * F1(int pole[], int n) {
	int *tempPole = (int *)malloc(n*sizeof(int));
	for (int i = 0; i < n; i++) {
		tempPole[i] = pole[i];
	}
	return &tempPole[0];
}
//2.
	//Nap�te a otestujte funkciu, ktor� na��tava zo vstupu ��sla do po�a typu double, 
	//ktor� dynamicky alokuje a postupne zv��uje.Funkcia sa zastav�, ke� na��ta ��slo 0, 
	//t�to 0 ale neuklad� do po�a.Funkcia vr�ti smern�k na alokovan� pole a ve�kos� po�a(nepriamo, pomocou smern�ka).

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
	//Nap�te a otestujte funkciu, ktorej vstupom je pole ��sel.
	//Funkcia pole rozdel� na �seky, pri�om ka�d� �sek je ukon�en� nulou.
	//Smern�ky na za�iatky jednotliv�ch �sekov ulo�� do dynamick�ho po�a smern�kov, ktor� pod�a potreby roz�iruje.
	//Na koniec po�a smern�kov ulo�� smern�k NULL.
	//Vr�ti smern�k na dynamick� pole smern�kov(ukazuj�cich na za�iatky slov).
	//Nap�te si zvl᚝ funkciu, ktor� postupnosti ��sel z takto zadan�ho po�a smern�kov vyp�e
	//(viete, �e ka�d� postupnos� kon�� nulou), ka�d� na in� riadok.

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
	//Nap�te funkciu, ktor� vytvor� dynamicky dvojrozmern� pole po�adovanej ve�kosti n riadkov a m st�pcov.
	//Pole napln� nulami a vr�ti.
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