#include <iostream>
using namespace std;

// Tema: zaklady pouzivania vynimiek

int main() {

	// TODO 1: 
	//      a) definujte 'try' blok, v ktorom vznikne vynimka typu 'int' s hodnotou 5
	try {
		throw "String";
	}
	//      b) definujte 'catch' blok, ktory obsluzi vzniknutu vynimku typu 'int' a vypise jej hodnotu
	catch (int exception) {
		cout << exception << endl;
	}
	//      c) definujte dalsi 'catch' blok, ktory obsluzi vsetky ostatne typy vynimiek
	catch (...) {
		cout << "Ina vynimka";
	}
	// Program riadne otestujte.

	return 0;
}