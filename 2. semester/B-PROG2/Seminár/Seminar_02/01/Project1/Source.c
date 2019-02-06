#include <stdio.h>
#define _CRT_SECURE_NO_DEPRECATE
//Napíšte program v jazyku C, ktorý naèíta dve reálne premenné a vypíše ich súèet, rozdiel, súèin a podiel.
int main()
{
	float a, b;
	float sucet, rozdiel, sucin, podiel;
	//1. NACITANIE
	//scanf_s("%f", &a);
	//scanf_s("%f", &b);
	a = 1.8;
	b = 2.4;
	//2. VYPOCET
	sucet = a + b;
	rozdiel = a - b;
	sucin = a * b;
	podiel = a / b;
	//3. VYPIS
	printf("%f + %f = %f\n", a, b, sucet);
	printf("%f - %f = %f\n", a, b, rozdiel);
	printf("%f * %f = %f\n", a, b, sucin);
	printf("%f / %f = %f\n", a, b, podiel);

	getchar();
	return 0;
}