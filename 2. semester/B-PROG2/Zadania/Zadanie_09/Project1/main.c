#include <stdio.h>
#include "helpers.h"

int main() {
	//DEKLARACIE
	Armada armadaHracaA = { 0, NULL }, armadaHracaB = { 0, NULL};
	Hrac hracA = {"A",&armadaHracaA}, hracB = { "B",&armadaHracaB };
	//INICIALIZACIA
	inicializaciaHraca(&hracA);
	inicializaciaVojska(&hracA);
	inicializaciaHraca(&hracB);
	inicializaciaVojska(&hracB);
	//VOJNA
	vojnaHracov(&hracA, &hracB);

	return 0;
}