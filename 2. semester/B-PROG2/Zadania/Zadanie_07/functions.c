//	POPIS:
//	Subor obsahujuci implementacie pouzivatelskych funkcii.

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "helpers.h"

int najdeneSlova[VYSKA][SIRKA] = { 0 };

void vypisTabulkuNajdenychSlov(int pole[][SIRKA]) {
	for (int i = 0; i < VYSKA; i++) {
		for (int j = 0; j < SIRKA; j++) {
			printf("%i ", pole[i][j]);
		}
		printf("\n");
	}
}

void zobraz(char tajnicka[][SIRKA]) {
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < VYSKA; i++) {
		printf("    ");
		for (int j = 0; j < SIRKA; j++) {
			if (najdeneSlova[i][j] == 0) {
				SetConsoleTextAttribute(hConsole, 15);
			}
			else if (najdeneSlova[i][j] == 1) {
				SetConsoleTextAttribute(hConsole, 10);
			}
			else {
				SetConsoleTextAttribute(hConsole, 12);
			}
			printf("%c ", tajnicka[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void zobrazZoznamSlov(char zoznam[][MAX_DLZKA_SLOVA], int pocetSlov, int pocetFarebnych) {
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
	printf("    Zoznam slov:\n");
	printf("    ");
	for (int i = 0; i < pocetSlov; i++) {
		if (i == pocetFarebnych) {
			SetConsoleTextAttribute(hConsole, 12);
		}
		else {
			SetConsoleTextAttribute(hConsole, 15);
		}
		printf("%s", zoznam[i]);
		if (i != pocetSlov - 1) {
			printf(", ");
		}
	}
	printf("\n\n");
}

int vertikalneHore(int X, int Y, char slovo[], int length, char tajnicka[][SIRKA]) {
	if (X + 1 - length < 0) {
		return 0;
	}
	else {
		int counter = 0;
		for (int i = X; i > X - length; i--) {
			if (tajnicka[i][Y] != slovo[counter]) {
				return 0;
			}
			counter++;
		}
		for (int i = X; i > X - length; i--) {
			najdeneSlova[i][Y] = 2;
		}
		return 1;
	}
}

int vertikalneDole(int X, int Y, char slovo[], int length, char tajnicka[][SIRKA]) {
	if (X + length > VYSKA) {
		return 0;
	}
	else {
		int counter = 0;
		for (int i = X; i < X + length; i++) {
			if (tajnicka[i][Y] != slovo[counter]) {
				return 0;
			}
			counter++;
		}
		for (int i = X; i < X + length; i++) {
			najdeneSlova[i][Y] = 2;
		}
		return 1;
	}
}

int horizontalneVlavo(int X, int Y, char slovo[], int length, char tajnicka[][SIRKA]) {
	if (Y + 1 - length < 0) {
		return 0;
	}
	else {
		int counter = 0;
		for (int i = Y; i > Y - length; i--) {
			if (tajnicka[X][i] != slovo[counter]) {
				return 0;
			}
			counter++;
		}
		for (int i = Y; i > Y - length; i--) {
			najdeneSlova[X][i] = 2;
		}
		return 1;
	}
}

int horizontalneVpravo(int X, int Y, char slovo[], int length, char tajnicka[][SIRKA]) {
	if (Y + length > SIRKA) {
		return 0;
	}
	else {
		int counter = 0;
		for (int i = Y; i < Y + length; i++) {
			if (tajnicka[X][i] != slovo[counter]) {
				return 0;
			}
			counter++;
		}
		for (int i = Y; i < Y + length; i++) {
			najdeneSlova[X][i] = 2;
		}
		return 1;
	}
}

int diagonalneHoreVlavo(int X, int Y, char slovo[], int length, char tajnicka[][SIRKA]) {
	if ((X + 1 - length < 0) || (Y + 1 - length < 0)) {
		return 0;
	}
	else {
		int counter = 0;
		for (int i = X, j = Y; i > X - length; i--, j--) {
			if (tajnicka[i][j] != slovo[counter]) {
				return 0;
			}
			counter++;
		}
		for (int i = X, j = Y; i > X - length; i--, j--) {
			najdeneSlova[i][j] = 2;
		}
		return 1;
	}
}

int diagonalneHoreVpravo(int X, int Y, char slovo[], int length, char tajnicka[][SIRKA]) {
	if ((X + 1 - length < 0) || (Y + length > SIRKA)) {
		return 0;
	}
	else {
		int counter = 0;
		for (int i = X, j = Y; i > X - length; i--, j++) {
			if (tajnicka[i][j] != slovo[counter]) {
				return 0;
			}
			counter++;
		}
		for (int i = X, j = Y; i > X - length; i--, j++) {
			najdeneSlova[i][j] = 2;
		}
		return 1;
	}
}

int diagonalneDoleVlavo(int X, int Y, char slovo[], int length, char tajnicka[][SIRKA]) {
	if ((X + length > VYSKA) || (Y + 1 - length < 0)) {
		return 0;
	}
	else {
		int counter = 0;
		for (int i = X, j = Y; i < X + length; i++, j--) {
			if (tajnicka[i][j] != slovo[counter]) {
				return 0;
			}
			counter++;
		}
		for (int i = X, j = Y; i < X + length; i++, j--) {
			najdeneSlova[i][j] = 2;
		}
		return 1;
	}
}

int diagonalneDoleVpravo(int X, int Y, char slovo[], int length, char tajnicka[][SIRKA]) {
	if ((X + length > VYSKA) || (Y + length > SIRKA)) {
		return 0;
	}
	else {
		int counter = 0;
		for (int i = X, j = Y; i < X + length; i++, j++) {
			if (tajnicka[i][j] != slovo[counter]) {
				return 0;
			}
			counter++;
		}
		for (int i = X, j = Y; i < X + length; i++, j++) {
			najdeneSlova[i][j] = 2;
		}
		return 1;
	}
}

void vypisVysledok(char pole[], int dlzka) {
	for (int i = 0; i < dlzka; i++) {
		printf("%c", pole[i]);
	}
	printf("\n");
}

void najdiSlovo(char slovo[], char tajnicka[][SIRKA]) {
	int coordX = 0, coordY = 0;
	size_t dlzkaSlova = strlen(slovo);
	while (1) {
		if ((vertikalneHore(coordX, coordY, slovo, dlzkaSlova, tajnicka))      ||
			(vertikalneDole(coordX, coordY, slovo, dlzkaSlova, tajnicka))      ||
			(horizontalneVlavo(coordX, coordY, slovo, dlzkaSlova, tajnicka))   ||
			(horizontalneVpravo(coordX, coordY, slovo, dlzkaSlova, tajnicka))  ||
			(diagonalneHoreVlavo(coordX, coordY, slovo, dlzkaSlova, tajnicka)) ||
			(diagonalneHoreVpravo(coordX, coordY, slovo, dlzkaSlova, tajnicka))||
			(diagonalneDoleVlavo(coordX, coordY, slovo, dlzkaSlova, tajnicka)) ||
			(diagonalneDoleVpravo(coordX, coordY, slovo, dlzkaSlova, tajnicka))) {
			break;
		}
		if (coordY < SIRKA - 1) {
			coordY++;
		}
		else {
			coordX++;
			coordY = 0;
		}
	}
}

void normalizaciaPola() {
	for (int i = 0; i < VYSKA; i++) {
		for (int j = 0; j < SIRKA; j++) {
			if (najdeneSlova[i][j] == 2) {
				najdeneSlova[i][j] = 1;
			}
		}
	}
}

void vylusti(char tajnicka[][SIRKA], char zoznam[][MAX_DLZKA_SLOVA], int pocetSlov) {
	for (int i = 0; i < pocetSlov; i++) {
		CLEAR_SCREEN();
		normalizaciaPola();
		najdiSlovo(zoznam[i], tajnicka);
		printf("\n    Osemsmerovka:\n");
		zobraz(tajnicka);
		zobrazZoznamSlov(zoznam, pocetSlov,i);
		getchar();
	}
}

void tajnicka(char tajnicka[][SIRKA], int vyska, int sirka) {
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	char vysledokTajnicky[20];
	int counter = 0;
	SetConsoleTextAttribute(hConsole, 15);
	printf("    Tajnicka: ");
	for (int i = 0; i < vyska; i++) {
		for (int j = 0; j < sirka; j++) {
			if (najdeneSlova[i][j] == 0) {
				vysledokTajnicky[counter] = tajnicka[i][j];
				counter++;
			}
		}
	}
	vypisVysledok(vysledokTajnicky, counter);
}