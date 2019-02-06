#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

// TODO: postupne odkomentujte vsetky ulohy ... ked budu vsetky odkomentovane
// program musi spravne fungovat

void printSum(int a, double b) {
	cout << a + b << endl;
}

void printSum(float f1, float f2, float f3) {
	cout << f1 + f2 + f3 << endl;
}

void printSum(int* pole, int n) {
	for (int i = 0; i < n; i++)
		cout << pole[i] << " ";
	cout << endl;
}

int main()
{
	int a = 8;
	double b = 6.918;
	// TODO 1: definujte adekvatnu pretazenu funkciu 'printSum', odkomentujte nasledovny riadok
	// a musi vypisat sucet 'a'+'b'

	printSum(a,b); 

	float f1 = 1.00;
	float f2 = 2.50;
	float f3 = 3.55;
	// TODO 2: definujte adekvatnu pretazenu funkciu 'printSum', odkomentujte nasledovny riadok
	// a musi vypisat sucet 'f1'+'f2'+'f3'

	printSum(f1,f2,f3);

	int pole[3]{ 10,20,30 };
	// TODO 3: definujte adekvatnu pretazenu funkciu 'printSum', odkomentujte nasledovny riadok
	// a musi vypisat sucet vsetkych prvkov v poli 'pole'

	printSum(pole, sizeof(pole)/sizeof(pole[0]));

	return 0;
}