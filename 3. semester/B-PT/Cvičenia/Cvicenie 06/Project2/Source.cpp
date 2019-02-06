#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

int main()
{
	// TODO 1: dynamicky alokujte pamat pre jedno cele cislo pomocou operatora 'new'
	// int* jeden_int = ???
	int* jeden_int = new int();
	*jeden_int = 5;
	cout << "Adresa:  " << jeden_int << endl;
	cout << "Hodnota: " << *jeden_int << endl;
	// TODO 2: dealokujte pamat pre jedno cele cislo
	delete jeden_int;
	// TODO 3: vytvorte dynamicky alokovane pole s 10 prvkami
	// pomocou operatora 'new[]'
	// int* pole = ???
	int* pole = new int[10]();
	pole[1] = 5;
	cout << pole[1] << endl;
	// TODO 4: dealokujte pamat celeho pola
	delete[] pole;

	return 0;
}