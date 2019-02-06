#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

int main()
{
	// TODO 1: 'default'-inicializujte premennu s nazvom 'a' (typ 'int')
	int a{};
	//int a = int();
	cout << "Default int a: " << a << endl;
	// TODO 2: 'default'-inicializujte pointer s nazvom 'ptr' (typ 'int*')
	int* ptr{};
	//int* ptr = nullptr;
	//int* ptr = new int();
	// TODO 3: 'default'-inicializujte 'pole' s 10 prvkami (typ 'int[]')
	int pole[10]{};
	cout << "Default pole: ";
	for (int i = 0; i < 10; i++)
		cout << pole[i] << " ";
	cout << endl;
	// TODO 4: 'default'-inicializujte dynamicky alokovane 'dyn_pole' s 10 prvkami (typ 'int*')
	int* dyn_pole = new int[10]{};
	cout << "Default dyn_pole: ";
	for (int i = 0; i < 10; i++)
		cout << dyn_pole[i] << " ";
	cout << endl;

	delete ptr;
	delete[] dyn_pole;
	return 0;
}