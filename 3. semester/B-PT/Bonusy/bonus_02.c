//	Nazov tohto suboru premenujte na meno_priezvisko_ID_bonus_02.c
//	(meno, priezvisko a ID nahradte vasimi udajmi).


// ***********************************
// ******                      *******
// ******   POKYNY K ZADANIU   *******
// ******                      *******
// ***********************************

// 1.	Tento subor sa ako jediny odovzdava na prislusne miesto odovzdania.
// 2.	DOLEZITE: Odovzdany zdrojovy subor musi byt kompilovatelny. 
// 3.	Funkcia main() musi v tomto subore zostat ako posledna (za nou uz nenasleduje ziadny zdrojovy kod).
// 4.	Mozete si napisat aj vlastne pomocne funkcie.
//		Do main() mozete doplnit svoj testovaci kod.
// 5.	DOLEZITE: V ziadnom pripade nemente deklaraciu funkcie, ktoru mate za ulohu naprogramovat. 
//		Zmente len jej implementaciu.
//		Nemente ani definicie zadanych datovych typov.
// 6.	Globalne premenne su ZAKAZANE !!!
// 7.	TODO oznacuje miesto na dopracovanie.

// *****************************************************

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// Reprezentacia jedneho uzla zretazeneho zoznamu
typedef struct _node {
	int data;            // hodnota uzla
	struct _node * next; // dalsi uzol zoznamu
} NODE;

// Reprezentacia zretazeneho zoznamu
typedef struct {
	NODE * first; // prvy uzol
} LIST;

// Reprezentacia uspesnosti vykonania 
typedef enum {
	FAILURE, // = 0
	SUCCESS  // = 1
} RESULT;



// [ZADANIE]:
// ..........
//
//	Implementujte funkciu findLastButOne(), ktora hlada hodnotu predposledneho uzla zretazeneho zoznamu.
//	Funkcia musi spravne pracovat pre lubovolny pocet uzlov v zozname.
//
// [PARAMETRE FUNKCIE]:
// ....................
//		'list'	- zretazeny zoznam, v ktorom funkcia hlada hodnotu predposledneho uzla
//		'value	- adresa, na ktoru funkcia skopiruje hodnotu predposledneho uzla, ak existuje
//
// [NAVRATOVA HODNOTA FUNKCIE]:
// ............................
//		SUCCESS - ak predposledny uzol existuje (zoznam ma aspon 2 uzly)
//		FAILURE - ak predposledny uzol neexistuje (zoznam ma menej ako 2 uzly)
//
// ..................................................................................
RESULT findLastButOne(LIST * list, int * value)
{
	if (!(list) || !(value)) {
		return FAILURE;
	}
	NODE* tmp = list->first;
	if (tmp) {
		while (tmp->next) {
			if (tmp->next->next == NULL) {
				*value = tmp->data;
				return SUCCESS;
			}
			tmp = tmp->next;
		}
		return FAILURE;
	}
	else {
		return FAILURE;
	}
}

int main()
{
	LIST* list = (LIST*)malloc(sizeof(LIST));
	//list->first = NULL;

	NODE n3;
	n3.data = 3;
	n3.next = NULL;

	NODE n2;
	n2.data = 2;
	n2.next = &n3;

	NODE n1;
	n1.data = 1;
	n1.next = &n2;

	list->first = &n1;

	int result;

	if (findLastButOne(list, &result)) {
		printf("SUCCESS: %i", result);
	}
	else {
		printf("FAILURE");
	}

	free(list);
	return 0;
}
