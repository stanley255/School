#include <stdio.h>
#define _CRT_SECURE_NO_DEPRECATE

void A1(int n)
{
	for (int i = 1; i <= n; i++)
	{
		printf("%i\n", i);
	}
}

void B1(int n)
{
	for (int i = 2; i <= n; i += 2)
	{
		printf("%i\n",i);
	}
}

void C1(int x, int n)
{
	for (int i = x; i <= n; i += x)
	{
		printf("%i\n", i);
	}
}

void D1(int x, int a, int b)
{
	int zaciatok = a;
	while (1)
	{
		if (zaciatok%x == 0 && zaciatok >= a)
		{
			break;
		}
		zaciatok++;
	}
	for (int i = zaciatok; i <= b; i += x)
	{
		printf("%i\n", i);
	}
}

void E1(int x, int a, int b)
{
	int zaciatok = a;
	while (1)
	{
		if (zaciatok%x == 0 && zaciatok >= a)
		{
			break;
		}
		zaciatok++;
	}
	zaciatok /= x;
	for (int k = zaciatok; k*x < b; k++)
	{
		printf("%i  %i\n",k,k*x);
	}
}

int main()
{
	//A1(5);
	//B1(12);
	//C1(5,100);
	//D1(3,7,22);
	E1(3,7,22);
	getchar();
	return 0;
}