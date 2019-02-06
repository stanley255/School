//	POPIS:
//	Hlavickovy subor obsahujuci:
//		* deklaracie premennych
//		* deklaracie funkcii, ktore su implementovane v file_io.c a functions.c
//		* pomocne makra

#ifndef HELPERS_H_INCLUDED
#define HELPERS_H_INCLUDED

// deklaracie premennych

// deklaracie funkcii zo suboru file_io.c
char* read_file(char* fname);
int write_file(char* fname, char* text);

// deklaracie funkcii zo suboru functions.c
// TODO: sem idu deklaracie vasich funkcii...
int inputProcessing(int argc, char * argv[], int ProcessingOutCome[]);
void printInputs(char* argv[], int ProcessingOutcome[]);
char* decodeInputText(char* argv[], int ProcessingOutcome[]);
// makra
#define DLZKA_SLOVA 30
// Podmieneny preklad: verzia pre WINDOWS sa lisi od LINUX verzie
// makro na premazanie obsahu konzoly
#ifdef _WIN32
#define CLEAR_SCREEN()	system("cls")
#else
#define CLEAR_SCREEN()	printf("\x1b[2J");
#endif

#endif // HELPERS_H_INCLUDED
