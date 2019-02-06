#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*POLE S TYPMI VOJAKOV, KTORYCH SI MOZE HRAC VOLIT*/
extern Vojak TypyVojakov[] = {
	{"Sermiar",       3,3,4,"warrior"},
	{"Lukostrelec",   4,4,3,"rogue"},
	{"Kopijnik",      5,3,3,"tank"},
	{"Rytier",        5,3,3,"warrior" },
	{"Vlajkonos",     3,2,6,"priest"},
	{"Kusostrelec",   3,5,3,"rogue"},
	{"Jazdec",        4,3,4,"warrior"},
	{"Obrneny jazdec",7,2,4,"tank"},
	{"Mag",           4,4,3,"priest"}
};
/*FUNKCIA NA ZOBRAZENIE TABULKY S TYPMI VOJAKOV*/
void vypisTypyVojakov() {
	printf(" ID|       MENO     | HP|ATT|DEF|    CLASS|\n");
	printf("-------------------------------------------\n");
	for (int i = 0; i < SIZEOFTYPESOFSOLDIERS; i++) {
		printf("%2.i | ",i+1);
		printf("%*s ",14,TypyVojakov[i].meno);
		printf("|");
		printf("%2.i ", TypyVojakov[i].hp);
		printf("|");
		printf("%2.i ", TypyVojakov[i].att);
		printf("|");
		printf("%2.i", TypyVojakov[i].def);
		printf(" | ");
		printf("%*s ", 7, TypyVojakov[i].role);
		printf("|\n");
	}
}

void vypisVojiskoHraca(Armada armadaHraca) {
	printf(" ID|       MENO     | HP|ATT|DEF|    CLASS|\n");
	printf("-------------------------------------------\n");
	for (int i = 0; i < SIZEOFPLAYERARMY; i++) {
		if (armadaHraca.vojisko[i].hp > 0) {
			printf("%2.i | ", i + 1);
			printf("%*s ", 14, armadaHraca.vojisko[i].meno);
			printf("|");
			printf("%2.i ", armadaHraca.vojisko[i].hp);
			printf("|");
			printf("%2.i ", armadaHraca.vojisko[i].att);
			printf("|");
			printf("%2.i", armadaHraca.vojisko[i].def);
			printf(" | ");
			printf("%*s ", 7, armadaHraca.vojisko[i].role);
			printf("|\n");
		}
	}
}

void vypisKonkretnehoVojaka(Armada armadaHraca, int index) {
	printf(" ID|       MENO     | HP|ATT|DEF|    CLASS|\n");
	printf("-------------------------------------------\n");
	printf("%2.i | ", index + 1);
	printf("%*s ", 14, armadaHraca.vojisko[index].meno);
	printf("|");
	printf("%2.i ", armadaHraca.vojisko[index].hp);
	printf("|");
	printf("%2.i ", armadaHraca.vojisko[index].att);
	printf("|");
	printf("%2.i", armadaHraca.vojisko[index].def);
	printf(" | ");
	printf("%*s ", 7, armadaHraca.vojisko[index].role);
	printf("|\n");
}

void zapisVojakaDoArmady(Armada *armadaHraca, int typVojaka, int pocet) {
	strcpy(armadaHraca->vojisko[pocet].meno, TypyVojakov[typVojaka].meno);
	armadaHraca->vojisko[pocet].hp = TypyVojakov[typVojaka].hp;
	armadaHraca->vojisko[pocet].att = TypyVojakov[typVojaka].att;
	armadaHraca->vojisko[pocet].def = TypyVojakov[typVojaka].def;
	strcpy(armadaHraca->vojisko[pocet].role, TypyVojakov[typVojaka].role);
}

void vypisTipyKuRoliam() {
	printf("|-----------------------------------------------------------------------------------------|\n");
	printf("| Priest  - po boji dvoch vojakov nahodne vylieci/prida zivot niekomu z team-u            |\n");
	printf("| Tank    - po narocnom boji (5+tahov) si zvysi obranu o jedna                            |\n");
	printf("| Rogue   - pokial su v team-e aspon 2 rogue, tak po kazdom boji sa jednemu zvysi atk o 1 |\n");
	printf("| Warrior - ked nastupi warrior do boja, zvysi si atk alebo def o 1 (vybrane nahodne)     |\n");
	printf("|-----------------------------------------------------------------------------------------|\n");
}

int nacitajVstup(int a, int b) {
	int vstup;
	do {
		vstup = getchar();
		vstup -= '0';
	} while (vstup<a||vstup>b);
	getchar();
	return vstup-1;
}

void vyberVojiska(Armada *armadaHraca) {
	int volba;
	for (int i = 0; i < SIZEOFPLAYERARMY; i++) {
		volba = nacitajVstup(1, SIZEOFTYPESOFSOLDIERS);
		printf("%s zverbovany do tvojej armady\n", TypyVojakov[volba].meno);
		zapisVojakaDoArmady(armadaHraca, volba, i);
		armadaHraca->pocet += 1;
	}
	CLEAR_SCREEN();
}

void inicializaciaHraca(Hrac *hrac) {
	printf("---------HRAC %s---------\nProsim, zadaj svoje meno (aspon 3 znaky): ",hrac->meno);
	do {
		fgets(hrac->meno, 30, stdin);
		hrac->meno[strlen(hrac->meno) - 1] = '\0';
	} while (strlen(hrac->meno) < 3);
	
	printf("\nVitaj, %s!\n", hrac->meno);
	getchar();
	CLEAR_SCREEN();
}

void inicializaciaVojska(Hrac *hrac) {
	//VYBER VOJISKA HRACA A
	printf("---------VOJISKO HRACA %s---------\n", hrac->meno);
	vypisTypyVojakov();
	vypisTipyKuRoliam();
	printf("\n%s, vyber si %i vojakov:\n",hrac->meno,SIZEOFPLAYERARMY);
	vyberVojiska(hrac->armadaHraca);
	printf("---------VOJISKO HRACA %s---------\n", hrac->meno);
	vypisVojiskoHraca(*hrac->armadaHraca);
	getchar();
	CLEAR_SCREEN();
}
