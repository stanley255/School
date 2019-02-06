#include <stdio.h>
#define _CRT_SECURE_NO_DEPRECATE

int A2(int x)
{
	int cislo, counter = 0;
	do {
		scanf_s("%i",&cislo);
		counter++;
	} while (cislo != x);
	counter--;
	return counter;
}

int main()
{
	printf("Pocet nacitanych cisel: %i",A2(0));

	getchar();
	return 0;
}