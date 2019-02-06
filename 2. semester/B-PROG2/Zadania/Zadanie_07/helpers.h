//	POPIS:
//	Subor obsahujuci:
//		* deklaracie premennych
//		* deklaracie pouzivatelskych funkcii, ktore su implementovane v functions.c
//		* pomocne makra

#ifndef HELPERS_H
#define HELPERS_H

#include "data_info.h"

// deklaracie premennych
extern char osemsmerovka[VYSKA][SIRKA];
extern char zoznamSlov[POCET_SLOV][MAX_DLZKA_SLOVA];
extern int najdeneSlova[VYSKA][SIRKA];
// deklaracie pouzivatelskych funkcii
void zobraz(char tajnicka[][SIRKA]);
void zobrazZoznamSlov(char zoznam[][MAX_DLZKA_SLOVA], int pocetSlov, int pocetFarebnych);
void najdiSlovo(char slovo[], char tajnicka[][SIRKA]);
void vylusti(char tajnicka[][SIRKA], char zoznam[][MAX_DLZKA_SLOVA], int pocetSlov);
void tajnicka(char tajnicka[][SIRKA], int vyska, int sirka);

// Podmieneny preklad: verzia pre WINDOWS sa lisi od LINUX verzie
// makro na premazanie obsahu konzoly
#ifdef _WIN32
#define CLEAR_SCREEN()	system("cls")
#else
#define CLEAR_SCREEN()	printf("\x1b[2J");
#endif


#endif /* HELPERS_H */
