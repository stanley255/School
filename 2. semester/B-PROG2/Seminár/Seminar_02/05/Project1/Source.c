#include <stdio.h>
#define _CRT_SECURE_NO_DEPRECATE

double odmocnina(double cislo)
{
	double a, b, stred;
	if (cislo <= 1.0)
	{
		a = cislo;
		b = 1.0;
	}
	else
	{
		a = 1.0;
		b = cislo;
	}
	double c_last;
	while (cislo!= c_last)							//while (b-a > 0.01)
	{
		c_last = cislo;
		stred = (a + b) / 2;
		if ((stred*stred) > cislo)
		{
			b = stred;
		}
		else 
		{
			a = stred;
		}
	}
	return stred;
}

int main()
{
	double cislo;
	cislo = 2;
	printf("Odmocnina z cisla %0.0lf je priblizne %lf.",cislo,odmocnina(cislo));

	getchar();
	return 0;
}