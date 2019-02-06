#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inicializaciaVstupov(char *argv[], int argc, int outputArray[]) {
	int posI = -1, posO = -1;
	FILE * test;
	for (int i = 0; i < argc; i++) {
		if (strcmp("-i", argv[i]) == 0) {
			posI = i + 1;
		}
		if (strcmp("-o", argv[i]) == 0) {
			posO = i + 1;
		}
	}
	if (argv[posI] == NULL)
		return -1;
	if (posI != -1) {
		test = fopen(argv[posI], "rt");
		if (test == NULL)
			return -1;
		fclose(test);
	}
	if (argv[posO] == NULL)
		return -1;
	outputArray[0] = posI;
	outputArray[1] = posO;	
	return 1;
}

void loadData(Hrac *hrac, FILE* suborVojakov) {
	int temp = 0, c;
	//odingnorovanie 1. riadku
	while ((c = fgetc(suborVojakov)) != EOF) {
		if (c == '\n')
			temp++;
		if (temp == 1)
			break;
	}
	fscanf(suborVojakov,"%s",&hrac->meno);
	for (int i = 0; i < SIZEOFPLAYERARMY; i++) {
		fscanf(suborVojakov, "%s %i %i %i %s",
			&hrac->armadaHraca->vojisko[i].meno,
			&hrac->armadaHraca->vojisko[i].hp,
			&hrac->armadaHraca->vojisko[i].att,
			&hrac->armadaHraca->vojisko[i].def,
			&hrac->armadaHraca->vojisko[i].role
			);
		hrac->armadaHraca->pocet = i+1;
	}
}

void IOinicializaciaVojska(Hrac *hracA, Hrac *hracB, char* argv[], int vstupy[]) {
	FILE * suborVojakov = fopen(argv[vstupy[0]],"r");
	if (suborVojakov == NULL) {
		fprintf(stderr, "FAILED TO LOAD FILES.");
		exit(-1);
	}
	loadData(hracA, suborVojakov);
	loadData(hracB, suborVojakov);
	fclose(suborVojakov);
}

void IOvypisVojiskoHraca(Armada armadaHraca, FILE *fin) {
	fprintf(fin, " ID|       MENO     | HP|ATT|DEF|    CLASS|\n");
	fprintf(fin, "-------------------------------------------\n");
	for (int i = 0; i < SIZEOFPLAYERARMY; i++) {
		if (armadaHraca.vojisko[i].hp > 0) {
			fprintf(fin,"%2.i | ", i + 1);
			fprintf(fin,"%*s ", 14, armadaHraca.vojisko[i].meno);
			fprintf(fin, "|");
			fprintf(fin, "%2.i ", armadaHraca.vojisko[i].hp);
			fprintf(fin, "|");
			fprintf(fin, "%2.i ", armadaHraca.vojisko[i].att);
			fprintf(fin, "|");
			fprintf(fin, "%2.i", armadaHraca.vojisko[i].def);
			fprintf(fin, " | ");
			fprintf(fin, "%*s ", 7, armadaHraca.vojisko[i].role);
			fprintf(fin, "|\n");
		}
	}
	fprintf(fin,"\n");
}

void IOvypisKonkretnehoVojaka(Armada armadaHraca, int index, FILE *fin) {
	fprintf(fin, " ID|       MENO     | HP|ATT|DEF|    CLASS|\n");
	fprintf(fin, "-------------------------------------------\n");
	fprintf(fin, "%2.i | ", index + 1);
	fprintf(fin, "%*s ", 14, armadaHraca.vojisko[index].meno);
	fprintf(fin, "|");
	fprintf(fin, "%2.i ", armadaHraca.vojisko[index].hp);
	fprintf(fin, "|");
	fprintf(fin, "%2.i ", armadaHraca.vojisko[index].att);
	fprintf(fin, "|");
	fprintf(fin, "%2.i", armadaHraca.vojisko[index].def);
	fprintf(fin, " | ");
	fprintf(fin, "%*s ", 7, armadaHraca.vojisko[index].role);
	fprintf(fin, "|\n");
}