#include <stdio.h>

//Nap�te funkciu, ktor� do zadan�ho po�a na��tava znaky, a� pok�m sa nena��ta znak '\n' (ten sa do po�a neulo��),
//pri�om na��ta maxim�lne max-1 znakov (kde max je zadan� parameter). 
//Na koniec po�a zap�e znak konca re�azca '\0'. V�stupom funkcie je po�et znakov, ktor� sa na��tali. 
int nacitajRetazec(char * pole, int max) {
	char c;
	do {
		c = getchar();
		//getchar();
	} while (c != '\n');
}


int main(int argc, char* argv[]) {
	int max = 5, dlzka;
	char* retazec[5];
	dlzka = nacitajRetazec(retazec, max);

	return 0;
}