#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  
#include "helpers.h"
#include <time.h>


int correctInput(int a, int b) {
	int cislo;
	do {
		printf("Zadaj cislo: ");
		scanf_s("%i", &cislo);
		getchar();
	} while ((cislo<a) || (cislo>b));
	return cislo;
}

void introMenu() {
	printf("*****************************\n");
	printf("********NAMORNA BITKA********\n");
	printf("*****************************\n");
	printf("Vitajte v hre namorna bitka verzia 2.0!\n");
}

void humanVShuman() {
	int counter = 0, row, col, hrac, pokus;
	do {
		drawAttackGrid();
		hrac = (counter % 2) + 1;
		printf("\n     Na rade je hrac c.%i\n\n", hrac);
		getPositionHuman(&row, &col);
		pokus = checkHit(row, col, hrac);
		if (pokus == 1) {
			printf("     Zasah!");
		}
		else if (pokus == 0) {
			printf("     Mimo!");
		}
		else {
			printf("     Zostrelil si lod!");
		}
		counter++;
		getchar();
		CLEAR_SCREEN();
	} while (skore_1 + skore_2<shipsTotal);
	//VYHODNOTENIE VITAZA
	if (skore_1 > skore_2) {
		printf("Zvitazil hrac 1 so skore: %i", skore_1);
	}
	else {
		printf("Zvitazil hrac 2 so skore: %i", skore_2);
	}
}

void humanVSAI() {
	int human[2], AI[2],counter = 1, pokus, hrac;
	do {
		drawAttackGrid();
		hrac = counter % 2;
		if ( hrac == 1) {
			printf("     Si na rade.\n");
			getPositionHuman(&human[0], &human[1]);
			pokus = checkHit(human[0], human[1], hrac);
		}
		else {
			printf("     Na rade je AI\n");
			getPositionAI(&AI[0], &AI[1]);
			printf("     AI striela na suradnice: [%i, %i]\n",AI[0],AI[1]);
			pokus = checkHit(AI[0], AI[1], 2);
		}
		if (pokus == 1) {
			printf("     Zasah!");
		}
		else if (pokus == 0) {
			printf("     Mimo!");
		}
		else {
			printf("     Zostrelil si lod!");
		}
		counter++;
		getchar();
		CLEAR_SCREEN();
	} while (skore_1 + skore_2<shipsTotal);
	//VYHODNOTENIE VITAZA
	drawAttackGrid();
	if (skore_1 > skore_2) {
		printf("\n     Zvitazil hrac 1 so skore: %i", skore_1);
	}
	else {
		printf("\n     Zvitazil hrac 2 so skore: %i", skore_2);
	}
}

void AIVSAI() {
	int AI1[2], AI2[2], counter = 1, pokus, hrac;
	
	do {
		drawAttackGrid();
		hrac = counter % 2;
		if (hrac == 1) {
			printf("     AI1 je na rade.\n");
			getPositionAI(&AI1[0], &AI1[1]);
			printf("     AI1 striela na suradnice: [%i, %i]\n", AI1[0], AI1[1]);
			pokus = checkHit(AI1[0], AI1[1], 1);
		}
		else {
			printf("     AI2 je na rade.\n");
			getPositionAI(&AI2[0], &AI2[1]);
			printf("     AI2 striela na suradnice: [%i, %i]\n", AI2[0], AI2[1]);
			pokus = checkHit(AI2[0], AI2[1], 2);
		}
		if (pokus == 1) {
			printf("     Zasah!");
		}
		else if (pokus == 0) {
			printf("     Mimo!");
		}
		else {
			printf("     Zostrelil si lod!");
		}
		counter++;
		getchar();
		CLEAR_SCREEN();
	} while (skore_1 + skore_2<shipsTotal);
	//VYHODNOTENIE VITAZA
	drawAttackGrid();
	if (skore_1 > skore_2) {
		printf("Zvitazil AI1 so skore: %i", skore_1);
	}
	else {
		printf("Zvitazil AI2 so skore: %i", skore_2);
	}
}

int skore_1 = 0, skore_2 = 0;
int main()
{
	int choice[2];
	srand(time(NULL));
	introMenu();
	printf("Chcete hrat na predpripravenom hracom poli (1) alebo na nahodne vygenerovanom? (2)\n");
	choice[0] = correctInput(1, 2);
	printf("Ponukame tri mody:\n(1) Human vs. Human\n(2) Human vs. AI\n(3) AI vs. AI\n");
	choice[1] = correctInput(1, 3);
	CLEAR_SCREEN();
	if (choice[0] == 2) {
		randomShips();
		print_deployment_grid();
	}
	switch (choice[1]) {
	case 1:
		humanVShuman();
		break;
	case 2:
		humanVSAI();
		break;
	case 3:
		AIVSAI();
		break;
	}
	getchar();
	return 0;
}