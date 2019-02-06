#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>

// TODO: upravte parametre funkcie 'fun' tak, aby ste mohli
// pouzit aj ine volania tejto funkcie v main-e
void fun(int a = 0, char b = 'A') {
	std::cout << "Cislo: " << a;
	std::cout << ", znak: '" << b << "'" << std::endl;
}

int main()
{
	// funkcia vypise "Cislo: 2, znak: 'R'"
	fun(2, 'R');

	// ked odkomentujete, musi vypisat "Cislo: 44, znak: 'A'"
	fun(44); 

	// ked odkomentujete, musi vypisat "Cislo: 0, znak: 'A'"
	fun();
	return 0;
}