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

typedef struct _vojak{
	char *meno;
	int hp;
	int att;
	int def;
	char *role;
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
void vojnaHracov(Hrac *hracA, Hrac *hracB);

// makro na premazanie obsahu konzoly
#ifdef _WIN32
#define CLEAR_SCREEN()	system("cls")
#else
#define CLEAR_SCREEN()	printf("\x1b[2J");
#endif

#endif // HELPERS_H_INCLUDED