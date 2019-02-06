#include <stdio.h>
#define _CRT_SECURE_NO_DEPRECATE

void dvojkova(int cislo)
{
	int d[25];
	int zvysok, temp, i;
	i = 0;
	temp = cislo;
	while (temp != 0)
	{
		zvysok = temp % 2;
		temp = temp / 2;
		d[i] = zvysok;
		i++;
	}
	i--;
	for (i; i>-1; i--)
	{
		printf("%i", d[i]);
	}
}

void sesnastkova(int cislo)
{
	int d[25], znaky[] = {'A','B','C','D','E','F'};
	int i, temp, zvysok;
	for (i = 0; i < 26; i++)
	{
		d[i] = 0;
	}
	i = 0;
	temp = cislo;
	while (temp != 0)
	{
		zvysok = temp % 16;
		temp = temp / 16;
		d[i] = zvysok;
		i++;
	}
	i--;
	for (i; i>-1; i--)
	{
		if (d[i] < 10)
		{
			printf("%i", d[i]);
		}
		else
		{
			printf("%c", znaky[d[i] - 10]);
		}
	}
}

int main()
{
	int a, b;	

	a = 29127;
	b = 'F';
	printf("Vstupy: %i, %i\n",a,b);
	
	//Desiatkova sustava
	printf("Desiatkova sustava: %i, %i\n",a,b);
	
	//Dvojkova sustava
	printf("Dvojkova sustava: ");
	dvojkova(a);
	printf(", ");
	dvojkova(b);
	printf("\n");

	//Sesnastkova sustava
	printf("Sestnastkova sustava: ");
	sesnastkova(a);
	printf(", ");
	sesnastkova(b);

	getchar();
	return 0;
}