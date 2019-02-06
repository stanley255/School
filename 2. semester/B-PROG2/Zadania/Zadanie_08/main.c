//	POPIS:
//	Hlavny subor obsahujuci funkciu main().
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "helpers.h"

int main(int argc, char* argv[])
{
	int ProcessingOutcome[3] = {0};
	char * decodedText;
	inputProcessing(argc, argv, ProcessingOutcome);
	if (inputProcessing(argc, argv, ProcessingOutcome) == -1) {
		printf("Chyba, pri nacitani vstupu! Ukoncujem aplikaciu...");
		return 0;
	}

	printInputs(argv, ProcessingOutcome);
	getchar();
	decodedText = decodeInputText(argv,ProcessingOutcome);
	CLEAR_SCREEN();
	printf("\n[DECODED TEXT]\n\n");
	if (ProcessingOutcome[2] == 0) {
		printf("%s", decodedText);
	}
	else {
		write_file(argv[ProcessingOutcome[2]], decodedText);
		printf("In the file: %s", argv[ProcessingOutcome[2]]);
	}
	
	getchar();
    return 0;
}
