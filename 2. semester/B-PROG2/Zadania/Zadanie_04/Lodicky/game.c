#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

int col_input() {
	int ch;
	do {
		printf("     Zadaj pismeno: ");
		ch = getchar();
		getchar();
	} while (((ch<97)||(ch>106)));
	return ch-97;
}

int row_input() {
	int cislo;
	do {
		printf("     Zadaj cislo: ");
		scanf_s("%i",&cislo);
		getchar();
	} while ((cislo<0)||(cislo>9));
	return cislo;
}

int skore_1 = 0, skore_2 = 0;
int main()
{
	int counter = 0, row, col, hrac;
	do {
		drawAttackGrid();
		hrac = (counter % 2) + 1;
		printf("\n     Na rade je hrac c.%i\n\n",hrac);
		col = col_input();
		row = row_input();
		if (checkHit(row, col, hrac) == 1) {
			printf("     Zasah!");
		}
		else {
			printf("     Mimo!");
		}
		counter++;
		getchar();
		CLEAR_SCREEN();
	} while (skore_1+skore_2<shipsTotal);
	//VYHODNOTENIE VITAZA
	if (skore_1 > skore_2) {
		printf("Zvitazil hrac 1 so skore: %i", skore_1);
	}
	else {
		printf("Zvitazil hrac 2 so skore: %i", skore_2);
	}
	getchar();
	return 0;
}
