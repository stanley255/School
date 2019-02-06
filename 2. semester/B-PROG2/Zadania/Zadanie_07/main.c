//	POPIS:
//	Hlavny subor obsahujuci funkciu main().

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

/*
POZNAMKA:
V tomto subore je predpripravena kostra vasho programu, ktoru nie je nutne menit,
staci len naprogramovat uvedene funkcie a odovzdat do nich namiesto "TODO" spravne parametre.
*/

int main() {
	// vypis osemsmerovky
	printf("\n    Osemsmerovka:\n");
	zobraz(osemsmerovka);

	// vypis zoznamu slov
	zobrazZoznamSlov(zoznamSlov, POCET_SLOV,-1);
	getchar();
	// vylustenie celej osemsmerovky ... bude vo vnutri iterativne volat funkciu  najdiSlovo()
	vylusti(osemsmerovka, zoznamSlov, POCET_SLOV);

	// precitanie a vypis tajnicky
	tajnicka(osemsmerovka, VYSKA, SIRKA);

	printf("\n\n    ");
	getchar();
	return 0;
}