#include <stdio.h>
#include <math.h>
int main(void)
{
	double cislo = 1.23456789;
	int presnost = 5;
	double temp;
	int vysledok;
	presnost++;
	printf("%i.", (int)cislo);
	temp = cislo;
	for (int i = 1; i < presnost; i++)
	{
		temp *= 10;
		vysledok = (int)temp % 10;
		temp -= vysledok;
		printf("%i", vysledok);
	}

	getchar();
	return 0;
}