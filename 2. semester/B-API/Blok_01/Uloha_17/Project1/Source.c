#include <stdio.h>
#define _CRT_SECURE_NO_DEPRECATE

char znaky[5] = { 'I','V','X','L','C' };
int hodnoty[5] = { 1,5,10,50,100 };

int zakl_hodnota(cislo)
{
	for (int i = 0; i < 6; i++)
	{
		if (cislo == hodnoty[i])
		{
			printf("%c", znaky[i]);
			return 1;
		}
	}
	return 0;
}

int vypis(cislo)
{
	int i, zvysok, temp, min, opakovanie,vypisane = 0;
	zvysok = cislo % 10;
	if (cislo < 10) { zvysok = 0; }
	temp = cislo - zvysok;
	min = 0;	
	for (i = 0; i<6; i++)
	{
		if (abs(temp - hodnoty[i]) <= (temp - hodnoty[min]))
		{
			min = i;
		}
	}
	
	if (temp == 3){min = 0;}
	if (temp == 30){min = 2;}
	if (temp == 8) { min = 1; }
	if (temp == 80) { min = 3; }

	//AK SA NAJBLIZSIE ZC == TEMPU
	if (temp == hodnoty[min])
	{
		printf("%c", znaky[min]);
		vypisane += hodnoty[min];
	}
	//AK JE NAJBLIZSIE ZC>TEMP
	if (hodnoty[min]>temp)
	{
		int znak;
		if (min == 2 || min == 1) { znak = 0; }
		else { znak = 2; }
		opakovanie = (hodnoty[min] / 10) - (temp / 10);		
		if (temp == 4) { opakovanie++; }
		for (i = 0; i < opakovanie; i++)
		{			
			printf("%c", znaky[znak]);
		}
		printf("%c", znaky[min]);
		vypisane = temp;
	}
	//INAK AK ZC<TEMP
	if (hodnoty[min]<temp)
	{
		opakovanie = temp / hodnoty[min];
		for (i = 0; i < opakovanie; i++)
		{
			printf("%c", znaky[min]);
			vypisane += hodnoty[min];
		}
	}
	cislo = cislo - vypisane;
	if (cislo > 0)
	{
		vypis(cislo);
	}
	else { return 1; }
}

int main() 
{
	int cislo;	
	//cislo =8;
	//printf("%i\n",cislo);
	/*
//OVERENIE, CI CISLO NIE JE ZAKLADNA HODNOTA
	if (zakl_hodnota(cislo) == 1)
	{
		getchar();
		return 0;
	}
//INAK
	vypis(cislo);*/
	for (int j = 1; j < 101; j++)
	{
		printf("\n%i\n", j);
		vypis(j);
	}
	getchar();
	return 0;
}