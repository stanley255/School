#include <stdio.h>

//Napíšte funkciu, ktorá do zadaného po¾a naèítava znaky, a pokım sa nenaèíta znak '\n' (ten sa do po¾a neuloí),
//prièom naèíta maximálne max-1 znakov (kde max je zadanı parameter). 
//Na koniec po¾a zapíše znak konca reazca '\0'. Vıstupom funkcie je poèet znakov, ktoré sa naèítali. 
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