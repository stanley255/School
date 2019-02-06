#include <stdio.h>
#include "helpers.h"

int main(int argc, char* argv[]) {
	int vstupy[2];
	Armada armadaHracaA = { 0, NULL }, armadaHracaB = { 0, NULL};
	Hrac hracA = {"A",&armadaHracaA}, hracB = { "B",&armadaHracaB };
	//INICIALIZACIA
	if (inicializaciaVstupov(argv, argc, vstupy) == -1) {
		printf("\nCHYBA VSTUPU!!!\n");
		return 0;
	}		
	if (vstupy[0] == -1) {
		inicializaciaHraca(&hracA);
		inicializaciaHraca(&hracB);
		inicializaciaVojska(&hracA);
		inicializaciaVojska(&hracB);
	}
	else {
		IOinicializaciaVojska(&hracA, &hracB, argv, vstupy);
	}		
	//VOJNA
	vojnaHracov(&hracA, &hracB,argv, vstupy);
	return 0;
}