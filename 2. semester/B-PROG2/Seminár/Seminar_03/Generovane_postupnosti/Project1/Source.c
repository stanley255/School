#include <stdio.h>
#define _CRT_SECURE_NO_DEPRECATE

void A3(int n)
{
	int x1 = 1, x2 = 1, temp;
	for (int i = 0; i < n; i++)
	{
		printf("%i\n",x1);
		temp = x2;
		x2 += x1;
		x1 = temp;
	}
}

void B3(int n, int x1, int x2)
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		printf("%i\n", x1);
		temp = x2;
		x2 += x1;
		x1 = temp;
	}
}

int A4(int x1)
{
	int x2;
	if (x1 % 2 == 0)
	{
		x2 = x1 / 2;
	}
	else 
	{
		x2 = 3 * x1 + 1;
	}
	return x2;
}

void B4(int x1)
{
	int x2 = 10;
	printf("%i\n",x1);
	while (x2 > 1)
	{
		if (x1 % 2 == 0)
		{
			x2 = x1 / 2;
		}
		else
		{
			x2 = 3 * x1 + 1;
		}
		printf("%i\n",x2);
		x1 = x2;
	}
}

int C4(int x1)
{
	int x2 = 10, counter = 1;
	while (x2 > 1)
	{
		if (x1 % 2 == 0)
		{
			x2 = x1 / 2;
		}
		else
		{
			x2 = 3 * x1 + 1;
		}
		x1 = x2;
		counter++;
	}
}

int main()
{
	//A3(4);
	//B3(7,-5,10);
	//printf("%i",A4(14));
	B4(14);
	printf("Pocet prvkov: %i",C4(14));

	getchar();
	return 0;
}