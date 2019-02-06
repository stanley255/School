//	Nazov tohto suboru premenujte na meno_priezvisko_ID_bonus_01.c
//	(meno, priezvisko a ID nahradte vasimi udajmi).


// ***********************************
// ******                      *******
// ******   POKYNY K ZADANIU   *******
// ******                      *******
// ***********************************

// 1.	DOLEZITE: Odovzdajte tento zdrojovy subor, ktory musi byt kompilovatelny. 
// 2.	Funkcia main() musi v tomto subore zostat ako posledna (za nou uz nenasleduje ziadny zdrojovy kod).
// 3.	Ulohy vypracujte na miestach oznacenych slovom TODO.
// 4.	Mozete si napisat aj vlastne pomocne funkcie, do main() mozete doplnit svoj testovaci kod.
// 5.	Tento subor sa ako jediny odovzdava na prislusne miesto odovzdania.
// 6.	DOLEZITE: V ziadnom pripade nemente deklaraciu funkcie, ktoru mate za ulohu naprogramovat.
//		Zmente len jej definiciu.
//		Nemente ani definicie zadanych datovych typov.
// 7.	Globalne premenne su ZAKAZANE !!!

// *****************************************************

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// Definicia struktury DATA, ktora sa pouziva v zadani
typedef struct data {
	int value;
	float average;
}DATA;

// [ZADANIE]:
// ..........
//
//	Dokoncite funkciu arrayConvert(), ktorej vstupom bude pole celych cisel s nazvom 'input' s dlzkou 'n' prvkov.
//
//	Doprogramujte telo funkcie nasledovne:
//		TODO 1: Dynamicky alokujte pamat pre pole s nazvom 'output', 
//				ktore bude obsahovat prvky typu DATA (vid definiciu struktury)
//				a bude mat rovnaku dlzku ako vstupne pole 'input'.
//		TODO 2:	Naplnte pole 'output' nasledovne (znazornenie je na obrazku):
//			a)	Do clenov 'value' prekopirujte hodnoty z pola 'input'
//				(1. prvok pola 'input' bude prekopirovany do clena 'value' 1. prvku pola 'output', a tak dalej)
//			b)	V poli 'output' sa hodnota clena 'average' nastavi ako priemer z laveho a praveho suseda v poli 'input'
//				Hodnoty clenov 'average' prveho a posledneho prvku pola 'output' nastavte na -1.
//		TODO 3: Z funkcie vratte smernik na zaciatok takto naplneneho pola 'output'.
//
//	Uvazujeme, ze vstupne pole 'input' moze obsahovat lubovolne kladne aj zaporne cele cisla.
//
// [PARAMETRE FUNKCIE]:
// ....................
//		'input'	- vstupne celociselne pole
//		'n'		- dlzka pola 'input'
//
// [NAVRATOVA HODNOTA FUNKCIE]:
// ............................
//		DATA*	- smernik na zaciatok vysledneho pola struktur
//
// ..................................................................................


DATA* arrayConvert(int *input, int n) {
	DATA* output = (DATA*) malloc(n * sizeof(DATA));
	for (int i = 0; i < n; i++){
		output[i].value = input[i];
		output[i].average = ((i == 0) || (i == n-1)) ? -1 : ((input[i-1]+input[i+1])/2.0);
	}
	return output;
}


// ***************************************************************************
// *****                        !!! FUNKCIA MAIN !!!					 *****
// *****     (funkcia main() musi ostat v tomto subore ako posledna)     *****
// ***************************************************************************

int main()
{
	int x_pole[6]={1,3,9,-3,4,5};	
	int n = (sizeof(x_pole)/sizeof(int));
	DATA* y_pole = arrayConvert(x_pole,n);
	printf("|");
	for (int i = 0; i < n; i++){
		printf("%5.i|",y_pole[i].value);
	}
	printf("\n|");
	for (int i = 0; i < n; i++){
		printf("%5.1f|",y_pole[i].average);
	}
	return 0;
}
