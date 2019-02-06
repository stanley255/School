#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "helpers.h"
#include <time.h>

// Mriezka s rozmiestnenymi lodami je dodana v subore "deployment_grid.c".
extern int deployment_grid[GRID_SIZE][GRID_SIZE];

// Popis:
// Hracie pole (budeme ho nazyvat "attack_grid") obsahuje informacie o strelach hracov.
// Znacenie suradnic hracieho pola:
//		0		- na danu z suradnicu doposial ani jeden hracov nestrielal ("unknown")
//		1/-1	- hrac 1 strielal na danu suradnicu a trafil lod/vodu
//		2/-2	- hrac 2 strielal na danu suradnicu a trafil lod/vodu
int attack_grid[GRID_SIZE][GRID_SIZE] = { {0} };
//Funkcia, ktora vrati pocet prvkov v okoli bodu [x,y]!=0 
int deploymentPointEnviroment(int x, int y) {
	int counter = 0;
	for (int i = x-1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			if ((i >= 0) && (i <= GRID_SIZE-1) && (j >= 0) && (j <= GRID_SIZE-1)) {
				counter += deployment_grid[i][j] != 0 ? 1 : 0;
			}
		}
	}
	return counter;
}
//Funkcia, ktora vrati pocet prvkov v okoli bodu [x,y]!=0
int attackPointEnviroment(int x, int y) {
	int counter = 0;
	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			if ((i >= 0) && (i <= GRID_SIZE - 1) && (j >= 0) && (j <= GRID_SIZE - 1)) {
				counter += attack_grid[i][j] != 0 ? 1 : 0;
			}
		}
	}
	return counter;
}
//funkcia vrati nahodne cislo z intervalu <a,b>
int randomNumber(int a, int b) {
	return rand() % (b - a + 1) + a;
}
//funkcia, ktora umiestni lodku danej velkosti a orientacie (0 - horizontalne, 1 - vertikalne) do gridu
int shipPlacement(int shipSize, int orientation) {
	int coordinates[] = { 0,0 };
	int result = 0;
	if (orientation == 0) {
		do {
			result = 0;
			coordinates[0] = randomNumber(0, GRID_SIZE-1);
			coordinates[1] = randomNumber(0, GRID_SIZE - shipSize-1);
			for (int i = 0; i < shipSize; i++) {
				if (deploymentPointEnviroment(coordinates[0], coordinates[1] + i) != 0) {
					result++;
				}
			}
		} while (result != 0);
		for (int i = 0; i < shipSize; i++) {
			deployment_grid[coordinates[0]][coordinates[1] + i] = 1;
		}
	}
	else {
		do {
			result = 0;
			coordinates[0] = randomNumber(0, GRID_SIZE - shipSize-1);
			coordinates[1] = randomNumber(0, GRID_SIZE-1);
			for (int i = 0; i < shipSize; i++) {
				if (deploymentPointEnviroment(coordinates[0] + i, coordinates[1]) != 0) {
					result++;
				}
			}
		} while (result != 0);
		for (int i = 0; i < shipSize; i++) {
			deployment_grid[coordinates[0] + i][coordinates[1]] = 1;
		}
	}
}

void randomShips() {
	int shipSize = 5;
	int orientation = randomNumber(0, 1);
	//VYNULOVANIE POLA
	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			deployment_grid[i][j] = 0;
		}
	}
	//UMIESTNENIE 5-kovej lode
	shipPlacement(shipSize, orientation);
	//UMIESTNENIE 4-kovych lodi
	shipSize--;
	for (int i = 0; i < 2; i++) {
		orientation = randomNumber(0, 1);
		shipPlacement(shipSize, orientation);
	}
	//UMIESTNENIE 3-kovych lodi
	shipSize--;
	for (int i = 0; i < 3; i++) {
		orientation = randomNumber(0, 1);
		shipPlacement(shipSize, orientation);
	}
	//UMIESTNENIE 2-kovych lodi
	shipSize--;
	for (int i = 0; i < 2; i++) {
		orientation = randomNumber(0, 1);
		shipPlacement(shipSize, orientation);
	}
	//UMIESTNENIE 1-notkovej lode
	shipSize--;
	shipPlacement(shipSize, 0);
}

void print_deployment_grid() {
	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			printf("%i ", deployment_grid[i][j]);
		}
		printf("\n");
	}
}

void guessedPosition(int *row, int *col) {
	int guessPosList[100][2] = { {0} };
	int counter = 0, a, b, result = -1,poloha,randomness;
	//naplnenie pola -1kami
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 2; j++) {
			guessPosList[i][j] = -1;
		}
	}
	//pridanie uz hadanych suradnic do pola
	for (int i = 0; i < (GRID_SIZE - 1); i++) {
		for (int j = 0; j < (GRID_SIZE - 1); j++) {
			if ((attack_grid[i][j] == 1) || (attack_grid[i][j] == 2)) {
				guessPosList[counter][0] = i;
				guessPosList[counter][1] = j;
				counter++;
			}
		}
	}
	counter = 0;
	while (guessPosList[counter][0] != -1) {
		a = guessPosList[counter][0];
		b = guessPosList[counter][1];
		if (shipAnalyser(a, b)==0) {
			int orientacia[4] = { 0 };
			//NAPLNI POLE ORIENTACIA
			if (((a - 1) < 0)) { orientacia[0] = -1; }
			if (((b + 1) > GRID_SIZE - 1)) { orientacia[1] = -1; }
			if (((a + 1) > GRID_SIZE - 1)) { orientacia[2] = -1; }
			if (((b - 1) < 0)) { orientacia[3] = -1; }
			//DOPLNENIE 0/1
			if (orientacia[0] != -1) { orientacia[0] = deployment_grid[a - 1][b] == 1 ? 1 : 0; }
			if (orientacia[1] != -1) { orientacia[1] = deployment_grid[a][b + 1] == 1 ? 1 : 0; }
			if (orientacia[2] != -1) { orientacia[2] = deployment_grid[a + 1][b] == 1 ? 1 : 0; }
			if (orientacia[3] != -1) { orientacia[3] = deployment_grid[a][b - 1] == 1 ? 1 : 0; }
			//poloha
			if ((orientacia[0] == 1) || (orientacia[2] == 1)) { poloha = 1; }
			else { poloha = 0; }
			result = -1;
			randomness = randomNumber(0, 1);
			if (poloha == 1) {
				if (randomness == 0) {
					if ((((orientacia[0] == 1)) || ((orientacia[0] == 0))) && (attack_grid[a - 1][b] == 0)) { 
						result = 0; 
						break; 
					}
					if ((((orientacia[2] == 1)) || ((orientacia[2] == 0))) && (attack_grid[a + 1][b] == 0)) { 
						result = 2; 
						break; 
					}
				}
				else {
					if ((((orientacia[2] == 1)) || ((orientacia[2] == 0))) && (attack_grid[a + 1][b] == 0)) { 
						result = 2; 
						break; 
					}
					if ((((orientacia[0] == 1)) || ((orientacia[0] == 0))) && (attack_grid[a - 1][b] == 0)) { 
						result = 0; 
						break; 
					}
				}
			}
			else {
				if (randomness == 0) {
					if ((((orientacia[1] == 1)) || ((orientacia[1] == 0))) && (attack_grid[a][b + 1] == 0)) { 
						result = 1; 
						break; 
					}
					if ((((orientacia[3] == 1)) || ((orientacia[3] == 0))) && (attack_grid[a][b - 1] == 0)) { 
						result = 3; 
						break; 
					}
				}
				else {
					if ((((orientacia[3] == 1)) || ((orientacia[3] == 0))) && (attack_grid[a][b - 1] == 0)) { 
						result = 3; 
						break; 
					}
					if ((((orientacia[1] == 1)) || ((orientacia[1] == 0))) && (attack_grid[a][b + 1] == 0)) { 
						result = 1; 
						break; 
					}					
				}
			
			}
		}
		counter++;
	}
	//ak je result !=-1, tak spravuj a vrat result, inak...TODO
	if (result == -1) {
		//TODO treba osetrit, aby nestrielal nahodne na odokryte policka
		do {
			*row = randomNumber(0, GRID_SIZE - 1);
			*col = randomNumber(0, GRID_SIZE - 1);
		} while (attack_grid[*row][*col] != 0);
	}
	else {
		switch (result) {
		case 0:
			*row = a - 1;
			*col = b;
			return;
		case 1:
			*row = a;
			*col = b + 1;
			return;
		case 2:
			*row = a + 1;
			*col = b;
			return;
		case 3:
			*row = a;
			*col = b - 1;
			return;
		}
	}
}

void getPositionHuman(int *row, int *col) {
	int cislo, ch;
	do {
		printf("     Zadaj pismeno: ");
		ch = getchar();
		getchar();
	} while (((ch<97) || (ch>106)));
	*col = ch - 97;
	do {
		printf("     Zadaj cislo: ");
		scanf_s("%i", &cislo);
		getchar();
	} while ((cislo<0) || (cislo>9));
	*row = cislo;
}

void getPositionAI(int *row, int *col) {
	guessedPosition(row, col);
}
//funkcia, ktora kde vrati 1, znamena, ze bola zostrelena lod
int shipAnalyser(int row, int col) {
	//PREMENNA ORIENTACIA ZNACI VZTAH S OKOLITYMI BODMI, IDE SA V SMERE HOD. RUCICIEK OD HORNEHO BODU
	//-1 = dany pokus je mimo pola, 0 = voda, 1 = lodka
	int orientacia[4] = {0};
	int zaciatok[2] = { row, col }, koniec[2] = { row, col };
	int poloha = 0;
	//NAPLNI POLE ORIENTACIA
		//KRAJNE SITUACIE
	if (((row - 1) < 0)) { orientacia[0] = -1; }
	if (((col + 1) > GRID_SIZE - 1)) { orientacia[1] = -1; }
	if (((row + 1) > GRID_SIZE - 1)) { orientacia[2] = -1; }
	if (((col - 1) < 0)) { orientacia[3] = -1; }
		//DOPLNENIE 0/1
	if (orientacia[0] != -1) { orientacia[0] = deployment_grid[row-1][col] == 1 ? 1 : 0; }
	if (orientacia[1] != -1) { orientacia[1] = deployment_grid[row][col+1] == 1 ? 1 : 0; }
	if (orientacia[2] != -1) { orientacia[2] = deployment_grid[row+1][col] == 1 ? 1 : 0; }
	if (orientacia[3] != -1) { orientacia[3] = deployment_grid[row][col-1] == 1 ? 1 : 0; }
	//ZISTI, CI JE LOD HORIZONTALNE(0)/VERTIKALNE(1)
	if ((orientacia[0] == 1) || (orientacia[2] == 1)) { poloha = 1; }
	else { poloha = 0; }
	if (poloha == 0) {			//HORIZONTALNE
		//skus ist dolava
		while (((zaciatok[1] - 1) >= 0) && (deployment_grid[row][zaciatok[1] - 1] == 1)) {
			zaciatok[1] -= 1;
		}
		//skus ist doprava
		while (((koniec[1] + 1) <= (GRID_SIZE-1)) && (deployment_grid[row][koniec[1] + 1] == 1)) {
			koniec[1] += 1;
		}
	}
	else {						//VERTIKALNE
		//skus ist hore
		while (((zaciatok[0] - 1) >= 0) && (deployment_grid[zaciatok[0] - 1][col] == 1)) {
			zaciatok[0] -= 1;
		}
		//skus ist dole
		while (((koniec[0] + 1) <= (GRID_SIZE - 1)) && (deployment_grid[koniec[0] + 1][col] == 1)) {
			koniec[0] += 1;
		}
	}
	//SAMOTNE POROVNAVANIE
	if (poloha == 0) {
		for (int i = zaciatok[1]; i <= koniec[1]; i++) {
			if ((attack_grid[zaciatok[0]][i] != 1) && (attack_grid[zaciatok[0]][i] != 2)) {
				return 0;
			}
		}
		return 1;
	}
	else {
		for (int i = zaciatok[0]; i <= koniec[0]; i++) {
			if ((attack_grid[i][zaciatok[1]] != 1) && (attack_grid[i][zaciatok[1]] != 2)) {
				return 0;
			}
		}
		return 1;
	}
}

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
		if (shipAnalyser(row, col) == 1) {
			return 2;
		}
		return 1;
	}
	else  {
		if (attack_grid[row][col] == 0) {
			attack_grid[row][col] = playerID * (-1);
		}
		return 0;
	}
}
