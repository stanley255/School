//	POPIS:
//	Subor obsahujuci implementacie vasich funkcii.
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "helpers.h"

// TODO: sem idu implementacie vasich funkcii.

int inputProcessing(int argc, char* argv[], int ProcessingOutCome[]) {
	//Nedostacujuci minimalny pocet argumentov pre spracovanie vstupov
	if (argc < 5) {
		return -1;
	}
	else {
		for (int i = 2; i < argc; i++) {
			if ((strcmp(argv[i-1], "-i")==0)&&(!(i>=argc))) {
				if (read_file(argv[i]) == NULL)
					return -1;
				ProcessingOutCome[0] = i;
			}
			if ((strcmp(argv[i - 1], "-s") == 0) && (!(i >= argc))) {
				if (read_file(argv[i]) == NULL)
					return -1;
				ProcessingOutCome[1] = i;
			}
			if ((strcmp(argv[i - 1], "-o") == 0) && (!(i >= argc))) {
				ProcessingOutCome[2] = i;
			}
		}
	}
	if ((ProcessingOutCome[1] == 0)||(ProcessingOutCome[0] == 0)) {
		return -1;
	}
	return 0;
}

void printInputs(char* argv[], int ProcessingOutcome[]) {
	printf("\n[SUBSTITUTION FILE]\n");
	printf("%s\n", read_file(argv[ProcessingOutcome[1]]));
	printf("\n[ENCRYPTED FILE]\n");
	printf("%s\n", read_file(argv[ProcessingOutcome[0]]));
}

int numberOfEqSigns(char *subText) {
	char *ptr;
	int counter = 0;
	ptr = strchr(subText, '=');
	while (ptr != NULL) {
		ptr = strchr(ptr+1,'=');
		counter++;
	}
	return counter;
}

void FillSubDictionary(char *Keys[DLZKA_SLOVA], char *Values[DLZKA_SLOVA], char Text[]) {
	char *ptr = strtok(Text, "=");
	int counter = 0;
	do {	
		strcat(ptr,"\0");
		strcpy(Keys[counter], ptr);
		ptr = strtok(NULL,"\n");
		strcat(ptr, "\0");
		strcpy(Values[counter], ptr);
		ptr = strtok(NULL, "=");
		counter++;
	} while (ptr != NULL);
}

int isWordCoded(char *Keys[DLZKA_SLOVA], char *Values[DLZKA_SLOVA], char* word, int SizeOfArray) {
	for (int i = 0; i < SizeOfArray; i++) {
		if (strcmp(Keys[i], word) == 0) {
			printf("\n\nIdem odkodovat %s slovom %s\n",Keys[i], Values[i]);
			return i;
		}
	}
	return -1;
}

int isSurroundedByLetter(char *ptr, char *Text) {
	if (((ptr - 1) - Text) >= 0) {
		char ptrLeft = ptr[-1];
		if ((ptrLeft != ' ')&&(ptrLeft != '.')&&(ptrLeft != '\n'))
			return 0;
	}
	if (((ptr + 1) - Text) <= 0) {
		char ptrRight = ptr[1];
		if ((ptrRight != ' ') && (ptrRight != '.') && (ptrRight != '\n'))
			return 0;
	}	
	return 1;
}

void decodeWord(char oldWord[], char newWord[], char Text[], int lengthOfInputText) {
	char* restOfText = malloc(strlen(Text));
	if (isSurroundedByLetter(strstr(Text, oldWord),Text)) {
		strcpy(restOfText, strstr(Text, oldWord) + strlen(oldWord));
		strcpy(strstr(Text, oldWord), newWord);
	}
	else {
		char* novyUsek = NULL;
		novyUsek = strstr(strstr(Text, oldWord) + strlen(oldWord), oldWord);
		while (isSurroundedByLetter(novyUsek, Text) != 1) {
			novyUsek = strstr(strstr(novyUsek, oldWord) + strlen(oldWord), oldWord);
		}
		strcpy(restOfText, strstr(novyUsek, oldWord) + strlen(oldWord));
		strcpy(strstr(novyUsek, oldWord), newWord);
	}
	strcat(Text, restOfText);
	free(restOfText);
}

char* decodeInputText(char* argv[], int ProcessingOutcome[]) {
	char* InputText = read_file(argv[ProcessingOutcome[0]]);
	char* OutputText = read_file(argv[ProcessingOutcome[0]]);
	int lengthOfInputText = (int)strlen(InputText);
	char* subText = read_file(argv[ProcessingOutcome[1]]);
	int numberOfSubWords = numberOfEqSigns(subText);
	//DYNAMICKA ALOKACIA SUBSLOVNIKA
	char **subKeys = malloc(numberOfSubWords * sizeof(char*));
	char **subValues = malloc(numberOfSubWords * sizeof(char*));
	for (int i = 0; i < numberOfSubWords; i++) {
		subKeys[i] = malloc(DLZKA_SLOVA);
		subValues[i] = malloc(DLZKA_SLOVA);
	}
	//NAPLNENIE SUBSLOVNIKA
	FillSubDictionary(subKeys, subValues, subText);
	//ZAMENA SLOV
	char * ptr;
	ptr = strtok(InputText, " ,.-");
	do {	
		CLEAR_SCREEN();
		int indexOfCodedWord = isWordCoded(subKeys, subValues, ptr, numberOfSubWords);
		if (indexOfCodedWord != -1) {
			decodeWord(ptr, subValues[indexOfCodedWord], OutputText, lengthOfInputText);
			printf("\n[DECODED TEXT]\n\n");
			printf("%s", OutputText);
			getchar();
		}
		ptr = strtok(NULL, "\n\t ,.");
	} while (ptr != NULL);
	for (int i = 0; i < numberOfSubWords; i++) {
		free(subKeys[i]);
		free(subValues[i]);
	}
	return OutputText;
}