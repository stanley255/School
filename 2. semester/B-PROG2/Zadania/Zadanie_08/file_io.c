//	POPIS:
//	Subor obsahujuci implementacie funkcii, ktore sluzia na citanie/zapis
//  retazca zo/do suboru.
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "helpers.h"

//  POPIS read_file():
//      Funkcia, ktora precita obsah suboru (fname) do C retazca
//      a vrati pointer na jeho zaciatok.
//  IN:
//      fname   - retazec obsahujuci nazov suboru
//  OUT:
//      char*   - pointer na retazec, ktory obsahuje
//              precitany text zo suboru

char* read_file(char* fname)
{
	FILE * f;
	size_t len,pos;
	char c;
	char* out;
	f = fopen(fname, "rt"); // otvarame subor v textovom rezime
	if (f == NULL) // kontrolujeme, ci otvaranie prebehlo OK
		return NULL;

	pos = ftell(f);    // aktualna pozicia
    fseek(f, 0, SEEK_END);    // presunieme sa na koniec suboru
    len = ftell(f); // zistenie aktualnej pozicie v subore
    fseek(f, pos, SEEK_SET);  // vratenie sa na zaciatok suboru

	out = malloc(len+1); // alokujeme pamat pre retazec + 1 ukoncovaci znak
	if(out == NULL){
        fprintf(stderr, "Alokacia pamate zlyhala.\n");
	}

	// nacitanie suboru do retazca
	len=0;
	while((c=fgetc(f)) !=EOF){
        out[len++] = c;
	}
	out[len] = '\0'; // vlozime ukoncovaci znak a tak vytvorime platny C retazec
	fclose(f); // zavrieme subor
	return out;
}

//  POPIS write_file():
//      Funkcia, ktora zapise obsah C retazca (text) do suboru (fname)
//      a vrati 0/1 ak sa nepodarilo/podarilo operaciu zrealizovat.
//  IN:
//      fname   - retazec obsahujuci nazov suboru
//      text    - retazec, ktory sa chystame zapisat do suboru
//  OUT:
//      int     - ciselna hodnota signalizujuca uspesne/neuspesne
//              dokoncenie funkcie

int write_file(char* fname, char* text)
{
	FILE * f;
	f = fopen(fname, "wt"); // otvarame subor
	if (f == NULL) // kontrolujeme uspesnost otvorenia
		return 0;

	fprintf(f, "%s", text); // zapiseme retazec do suboru
	fclose(f); // zavrieme subor

	return 1;
}


