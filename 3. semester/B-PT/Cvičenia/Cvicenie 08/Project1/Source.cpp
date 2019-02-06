#include <iostream>
#include <string>
using namespace std;

// Tema: funkcia ako parameter do inej funkcie

// funkcia fn1
typedef void(*f)();
void fn1() {
	cout << "Vykonala sa funkcia fn1()" << endl;
}

// funkcia fn2
void fn2() {
	cout << "Vykonala sa funkcia fn2()" << endl;
}

// funkcia fn3
void fn3() {
	cout << "Vykonala sa funkcia fn3()" << endl;
}

// TODO 1: doplnte funkciu 'takeOneFunction' tak, aby jej parametrom bol:
//  'f' - smernik na funkciu typu void()
//
// Funkcia 'takeOneFunction' nasledne zavola funkciu 'f'.
void takeOneFunction(f fun_ptr) {
	fun_ptr();
}

// TODO 2: doplnte funkciu 'takeMoreFunctions' tak, aby jej parametrami boli:
//  'arr' - pole smernikov na funkciu typu void()
//  'n' - pocet prvkov pola 'arr'
//  Funkcia 'takeMoreFunctions' nasledne zavola vsetky funkcie v poli 'arr'.
void takeMoreFunctions(f* arr, int n) {
	for (int i = 0; i < n; i++)
		arr[i]();
}

int main() {
	// TODO 3: do funkcie 'takeOneFunction' odovzdajte taky parameter,
	// aby sa vypisal do konzoly text "Vykonala sa funkcia fn2()"
	takeOneFunction(fn2);
	cout << endl;
	// TODO 4: do funkcie 'takeMoreFunctions' odovzdajte take parametre,
	// aby sa vypisali do konzoly vypisy v tomto poradi:
	//
	//      "Vykonala sa funkcia fn1()"
	//      "Vykonala sa funkcia fn2()"
	//      "Vykonala sa funkcia fn3()"
	f arr[]{fn1, fn2, fn3};
	takeMoreFunctions(arr, sizeof(arr)/sizeof(arr[0]));

	getchar();
	return 0;
}