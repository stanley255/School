#include <stdio.h>
#define _CRT_SECURE_NO_DEPRECATE
#include <math.h>
//1.vypocet obsahu trojuholnika z dlzok jeho stran
//2.dostrel pre sikmy vrh, zo zadanej pociatocnej rychlosti a uhlu v stupnoch (pozor, potrebne previest na rad pri vypocte)
//3.ako predosly pripad, ale pridajte parameter pociatocna vyska

double obsah(double a, double b, double c)
{
	double s, S, temp;
	s = (a + b + c) / 2;
	//printf("%f\n",s);
	temp = s * (s - a)*(s - b)*(s - c);
	//printf("%f\n", temp);
	S = sqrt (temp);
	//printf("%f\n", S);
	return S;
}

int main()
{
	// PRIKLAD 1
	/*
	double a, b, c, obs; //VSTUPNE PREMENNE
	a = 5.1;
	b = 2.9;
	c = 3.7;

	obs = obsah(a, b, c);
	printf("Obsah trojuholnika so stranami %f, %f, %f je %f.",a,b,c,obs);

	getchar();
	return 0;
	*/

	// PRIKLAD 2
	

}