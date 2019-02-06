#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "helpers.h"
 
// Mriezka s rozmiestnenymi lodami je dodana v subore "deployment_grid.c".
extern int deployment_grid[GRID_SIZE][GRID_SIZE];

// Popis:
// Hracie pole (budeme ho nazyvat "attack_grid") obsahuje informacie o strelach hracov.
// Znacenie suradnic hracieho pola:
//		0		- na danu z suradnicu doposial ani jeden hracov nestrielal ("unknown")
//		1/-1	- hrac 1 strielal na danu suradnicu a trafil lod/vodu
//		2/-2	- hrac 2 strielal na danu suradnicu a trafil lod/vodu
int attack_grid[GRID_SIZE][GRID_SIZE] = { {0} };

// Funkcia na vykreslenie aktualnej situacie v hernom poli ("attack_grid").
// Pri vypise cisla v "attack_grid" nahradte vhodnymi symbolmi. 
// Napriklad zasah do vody znazornite symbolom '~'.
void drawAttackGrid() {
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("\n\n       a b c d e f g h i j\n");
	for (int i = 0; i < GRID_SIZE; i++) {
		printf("     %i",i);
		for (int j = 0; j < GRID_SIZE; j++) {
			if (attack_grid[i][j] == 0) {
				printf("%2.c",'.');
			}
			else if (attack_grid[i][j] < 0) {
				SetConsoleTextAttribute(hConsole, 11);
				printf(" ~");
			}
			else {
				if (attack_grid[i][j] == 1) {
					SetConsoleTextAttribute(hConsole, 10);
				}
				else {
					SetConsoleTextAttribute(hConsole, 14);
				}
				printf("%2.i", attack_grid[i][j]);
			}
			SetConsoleTextAttribute(hConsole, 7);
		}
		if (i == 5) {
			printf("        Pocet zasahov hraca 1: %i",skore_1);
		}
		if (i == 6) {
			printf("        Pocet zasahov hraca 2: %i", skore_2);
		}
		printf("\n");
	}
}

// Funkcia, ktora zisti, ci doslo k zasahu lode na zadanych suradniciach (row,col) hracom s cislom playerID.
int checkHit(int row, int col, int playerID) {
	if ((deployment_grid[row][col] == 1)&&(attack_grid[row][col] == 0)) {
		attack_grid[row][col] = playerID;
		if (playerID == 1) { skore_1++; }
		else { skore_2++; }
		return 1;
	}
	else  {
		if (attack_grid[row][col] == 0) {
			attack_grid[row][col] = playerID * (-1);
		}
		return 0;
	}
}
