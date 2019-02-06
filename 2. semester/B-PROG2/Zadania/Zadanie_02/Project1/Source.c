#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define M_PI 3.14159265358979323846

int generuj(int a, int b);
double stupne_na_radiany(int stupne);
int spravny_uder(int S, int vzdialenost);

double vzdialenost(double lx, double ly, double jx, double jy)
{
	return sqrt(pow((lx - jx), 2) + pow((ly - jy), 2));
}

int nepresnost_N1(int S)
{
	int temp;
	temp = ((pow(S, 2)) / (sqrt(S) + pow(S, 2) + 100)) * 45;
	temp = generuj(-temp, +temp);
	return temp;
}

int nepresnost_N2(int S)
{
	S = (S / 10);
	S = generuj(-S, S);
	return S;
}

int poziciaX(int x1, int y1, int S, int N1, int N2)
{
	return (x1 - (S + N2) * (cos(atan2(y1, x1)) + stupne_na_radiany(N1)));
}

int poziciaY(int x1, int y1, int S, int N1, int N2)
{
	return (y1 - (S  + N2) * (sin(atan2(y1, x1)) + stupne_na_radiany(N1)));
}

int main()
{
	srand(time(NULL));
	int lopticka[2], N1, N2, temp;
	int memory[2];
	int S, counter = 1, spravnost_uderu;
	//VYGENEROVANIE SURADNIC LOPTICKY
	lopticka[0] = generuj(-150, 150);
	lopticka[1] = generuj(-150, 150);
	while (vzdialenost(lopticka[0], lopticka[1], 0, 0)<10)
	{
		lopticka[0] = generuj(-150, 150);
		lopticka[1] = generuj(-150, 150);
	}
	//GOLF
	printf("Hra sa moze zacat!!!\n");
	printf("Do konzole pis silu svojho uderu v celych nezapornych cislach :)\n");
	while (vzdialenost(lopticka[0], lopticka[1], 0, 0) > 2)
	{
		printf("*******%2.0i. pokus *******\n",counter);
		printf("Suradnice lopticky: [%i, %i]\n", lopticka[0], lopticka[1]);
		printf("Vzdialenost od jamky: %.2lf\n", vzdialenost(lopticka[0], lopticka[1], 0, 0));
		//ZADANIE A OVERENIE SILY UDERU
		printf("Zadaj silu uderu: ");
		scanf_s("%i", &S);
		getchar();
		spravnost_uderu = spravny_uder(S, (int)vzdialenost(lopticka[0], lopticka[1], 0, 0));
		//OVERENIE ZADANIA SPRAVNEHO UDERU
		while (spravnost_uderu != 0)
		{
			printf("Zadaj silu uderu: ");
			scanf_s("%i", &S);
			getchar();
			spravnost_uderu = spravny_uder(S, (int)vzdialenost(lopticka[0], lopticka[1], 0, 0));
		}
		//ULOZENIE PREDOSLEJ POZICIA KVOLI VYPISU SKUTOCNEJ VZDIALENOSTI
		memory[0] = lopticka[0];
		memory[1] = lopticka[1];
		//PRIDELENIE PREMENNYM N1 A N2 PRISLUSNE VYCHYLKY 
		N1 = nepresnost_N1(S);
		printf("Vychylka v stupnoch: %i\n",N1);
		N2 = nepresnost_N2(S);
		printf("Vychylka vzdialenosti: %i\n",N2);
		//SAMOTNE ZAPOCITANIE UDERU S ULOZENIM MEDZI VYSLEDKU KVOLI KOREKTNEMU VYPOCITANIU NOVEJ SURADNICE
		temp = poziciaX(lopticka[0], lopticka[1], S, N1, N2);
		lopticka[1] = poziciaY(lopticka[0], lopticka[1], S, N1, N2);
		lopticka[0] = temp;
		printf("Realna vzdialenost(m): %.0lf\n", vzdialenost(lopticka[0], lopticka[1], memory[0], memory[1]));
		counter++;
	}
	counter--;
	//VYPISANIE POCTU POKUSOV PRI SKONCENI HRY
	printf("***********************\n");
	printf("Hura, trafil si jamku!!!\nPocet pokusov: %i", counter);

	getchar();
	return 0;
}

int generuj(int a, int b)
{
	if ((a == b)&&(a==1)) { a++; }
	return rand() % (b - a + 1) + a;
}

double stupne_na_radiany(int stupne)
{
	return (stupne)* M_PI / 180;
}

int spravny_uder(int S, int vzdialenost)
{
	if (S<1) { return 1; }
	if (S>vzdialenost) { return 1; }
	return 0;
}