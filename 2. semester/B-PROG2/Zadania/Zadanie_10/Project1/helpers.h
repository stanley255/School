//	POPIS:
//	Hlavickovy subor obsahujuci:
//		* deklaracie premennych
//		* deklaracie funkcii, ktore su implementovane v file_io.c a functions.c
//		* pomocne makra

#ifndef HELPERS_H_INCLUDED
#define HELPERS_H_INCLUDED

// makra
#define SIZEOFPLAYERARMY 5
#define SIZEOFTYPESOFSOLDIERS 9
// deklaracie premennych
#include <stdio.h>
typedef struct _vojak{
	char meno[15];
	int hp;
	int att;
	int def;
	char role[15];
} Vojak;

typedef struct _armada {
	int pocet;
	Vojak vojisko[SIZEOFPLAYERARMY];
} Armada;

typedef struct _hrac {
	char meno[30];
	Armada *armadaHraca;
} Hrac;

// deklaracie funkcii zo suboru army_options.c
int nacitajVstup(int a, int b);
void inicializaciaHraca(Hrac *hrac);
void inicializaciaVojska(Hrac *hrac);
void vypisTypyVojakov();
void vypisKonkretnehoVojaka(Armada armadaHraca, int index);
void vypisVojiskoHraca(Armada armadaHraca);

// deklaracie funkcii zo suboru fight.c
void vojnaHracov(Hrac *hracA, Hrac *hracB, char *argv[], int vstupy[]);

//deklaracie funkcii zo suboru io_part
int inicializaciaVstupov(char *argv[], int argc, int outputArray[]);
void IOinicializaciaVojska(Hrac *hracA, Hrac *hracB, char* argv[], int vstupy[]);
void IOvypisVojiskoHraca(Armada armadaHraca, FILE *fin);
void IOvypisKonkretnehoVojaka(Armada armadaHraca, int index, FILE *fin);
// makro na premazanie obsahu konzoly
#ifdef _WIN32
#define CLEAR_SCREEN()	system("cls")
#else
#define CLEAR_SCREEN()	printf("\x1b[2J");
#endif

#endif // HELPERS_H_INCLUDED