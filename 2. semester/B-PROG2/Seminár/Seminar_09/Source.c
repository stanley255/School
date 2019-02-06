#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
void vypisZnak() {
	char c;
	do {
		scanf("%c",&c);
		putchar(c);
	} while (c != '\n');
}

void vypisInfo() {
	char c;
	scanf("%c", &c);
	getchar();
	printf("Znak: %c\n",c);
	printf("ASCII znaku: %i\n", c);
	printf("isalpha: %i\n",isalpha(c));
	printf("isdigit: %i\n", isdigit(c));
	printf("islower: %i\n",islower(c));
	printf("isupper: %i\n", isupper(c));
}

void lowerLine() {
	char c;
	do {
		scanf("%c", &c);
		putchar(toupper(c));
	} while (c != '\n');
}

void printASCII() {
	for (int i = 0; i < 256; i++) {
		if (isprint(i))
			printf("[%i] : %c\n", i,i);
	}
}

void nacitaj(char* pole, int velkost) {
	int i = 0;
	char c;
	do {
		scanf("%c",&c);
		pole[i] = c;
		i++;
	} while ((i != velkost - 1)&&(c != '\n'));
	pole[i] = '\0';
	printf("Nacitany retazec: %s\n", pole);
}

char* mystrchr(char* inputString, char c) {
	while (*inputString) {
		if (*inputString == c)
			return inputString;
		inputString++;
	}
	return NULL;
}

int myindexstrchr(char* inputString, char c) {
	char * base = inputString;
	while (*inputString) {
		if (*inputString == c)
			return inputString - base;
		inputString++;
	}
	return NULL;
}

void randomSymbols(char* pole, int length) {
	int i;
	for (i = 0; i < length - 1; i++) {
		if (rand()%2)
			pole[i] = rand() % 26 + 'A';
		else 
			pole[i] = rand() % 26 + 'a';
	}
	pole[i] = '\0';
}

int howManyCharsInString(char * pole, char c) {
	int counter = 0;
	while (*pole) {
		if (*pole == c)
			counter++;
		pole++;
	}
	return counter;
}

void switchSize(char* pole) {
	while (*pole) {
		if (isupper(*pole))
			*pole = tolower(*pole);
		else if (islower(*pole))
			*pole = toupper(*pole);
		pole++;
	}
}

void removeForwardDuplicates(char* pole) {
	int length = strlen(pole)+1;
	int i = 1;
	while (i != length - 1) {
		if (pole[i] == pole[i - 1]) {
			for (int j = i; j < length; j++) {
				pole[j] = pole[j + 1];
			}
			length--;
		}
		else {
			i++;
		}
	}
}

void printStringBackwards(char *ptr) {
	for (int i = strlen(ptr)-1; i>=0; i--) {
		printf("%c",ptr[i]);
	}
}

void saveStringBackwards(char *ptr) {
	int dlzka = strlen(ptr);
	char temp;
	for (int i = 0; i < dlzka / 2; i++) {
		temp = ptr[dlzka - i - 1];
		ptr[dlzka - i - 1] = ptr[i];
		ptr[i] = temp;
	}
	printStringBackwards(ptr);
}

char* combineTwoString(char*myArray, char* subArray) {
	char* outputArray = malloc(strlen(subArray));
	int counter = 0;
	int i;
	for (i = 0; i < strlen(subArray); i++) {
		if (subArray[i] != '*') {
			outputArray[i] = subArray[i];
		}
		else {
			outputArray[i] = myArray[counter];
			counter++;
		}
	}
	outputArray[i] = '\0';
	printf("\n%s\n",outputArray);
}

void nazovMesiaca(int cisloMesiaca) {
	const char * nazovMesiaca[] = {"Januar","Februar","Marec","April","Maj","Jun","Jul","August","September","Oktober","November","December"};
	printf("%s",nazovMesiaca[cisloMesiaca-1]);
}

int main(int argc, char * argv[]) {
	//vypisZnak();
	//vypisInfo();
	//lowerLine();
	//printASCII();
	char pole[MAX] = "Ahoj";
	char pole2[MAX] = "aaabbcc";
	//randomSymbols(pole, MAX);
	/*printf("%s\n",pole);
	printf("Vyskyt 'a': %i",howManyCharsInString(pole,'a'));
	switchSize(pole);
	printf("\n%s\n", pole2);
	removeForwardDuplicates(pole2);
	printf("\n%s\n",pole2);*/
	//printStringBackwards(pole);
	saveStringBackwards(pole);
	char* myArray = "ABC", * subArray = "*-*-*";
	combineTwoString(myArray, subArray);
	nazovMesiaca(12);
	printf("\n\nPress ENTER to exit...");
	getchar();
	return 0;
}
