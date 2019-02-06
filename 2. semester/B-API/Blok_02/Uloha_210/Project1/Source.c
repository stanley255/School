#include <stdio.h>
#define _CRT_SECURE_NO_DEPRECATE

int faktorial(int cislo)
{
	int f = 1;
	for (int i = cislo; i > 0; i--)
	{
		f *= i;
	}
	return f;
}

double exponencia(double cislo, int exp)
{
	double sum = 1;
	for (int i = 0; i < exp; i++)
	{
		sum *= cislo;
	}
	return sum;
}

double polynom(double x)
{
	double sum = 0;
	int counter = 1;
	for (int i = 1; i < 50; i += 2)
	{
		if (i % 2 == 1)
		{
			sum += exponencia(x, i) / faktorial(i);
		}
		else
		{
			sum -= exponencia(x, i) / faktorial(i);
		}
		printf("Taylorov polynom %i. stupna: %32.32lf\n", counter, sum);
		counter++;

	}
	return sum;
}

int main()
{
	double x = 0;
	polynom(x);
	getchar();
	return 0;
}