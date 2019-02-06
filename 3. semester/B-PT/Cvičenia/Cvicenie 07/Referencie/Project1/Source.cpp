#include <iostream>
using namespace std;

// Tema: referencia ako parameter funkcie

// TODO 1: dokoncite funkciu 'incrementRef' nasledovne:
//  a) doplnte parameter funkcie s nazvom 'ref', ktory bude typu referencia na int
//  b) funkcia zvysi hodnotu 'ref' o 1

void incrementRef(int& ref) {
	ref++;
}

// TODO 2: dokoncite funkciu 'incrementPtr' nasledovne:
//  a) doplnte parameter funkcie s nazvom 'ptr', ktory bude typu smernik na int
//  b) funkcia zvysi hodnotu na adrese 'ptr' o 1

void incrementPtr(int* ptr) {
	(*ptr)++;
}

class SomeClass {
	int a;
	int b;
	int c;
public:
	SomeClass(int a = 0, int b = 0, int c = 0) :
		a(a), b(b), c(c)
	{
	}

	SomeClass(const SomeClass &old_obj) {
		std::cout << "Kopirovaci konstruktor zavolany." << std::endl;
		this->a = old_obj.a;
		this->b = old_obj.b;
		this->c = old_obj.c;
	}

	void setA(int newA) { this->a = newA; }
	void setB(int newB) { this->b = newB; }
	void setC(int newC) { this->c = newC; }
};

// TODO 1: Zavola sa pri vzniku objektu 'sc' jeho kopirovaci konstruktor? Ak ano,
// zmente parameter funkcie 'fn' tak, aby sa nezavolal kopirovaci konstruktor parametra 'sc'.

void fn(SomeClass& sc) {
	sc.setA(5);
}


int main() {
	//***A1***
	/*
	int value = 8;

	// TODO 1: definujte referenciu s nazvom 'ref',
	// ktora bude odkazovat na premennu 'value'
	int& ref = value; // REFERENCIA MUSI BYT OKAMZITE INICIALIZOVANA A NEMOZEM JU POUZIT NA ODKAZOVANIE INEJ PREMENNEJ
	// TODO 2: inkrementujte premennu 'ref' o 1
	ref++;
	std::cout << value << std::endl;
	// TODO 3: vypiste 'value' aj 'ref'.... ake budu ich hodnoty?

	// TODO 4: definujte novu referenciu s nazvom 'ref2' a neinicializujte ju
	// Co sa stane?
	//int& ref2;
	*/

	/*int value = 50;


	//***A2***
	// TODO 1: Definujte referenciu 'ref' odkazujucu na premennu 'value'
	int& ref = value;
	// TODO 2: Vytvorte smernik 'ptr' ukazujuci na premennu 'value'
	int* ptr = &value;
	// TODO 3: nastavte hodnotu na adrese 'ptr' na cislo 100
	*ptr = 100;
	// TODO 4: vypiste obsah referencie 'ref'
	cout << ref;
	*/

	//***A3***
	/*int value = 77;
	int value2 = 33;

	// TODO 1: definujte referenciu 'ref' odkazujucu na premennu 'value'
	int& ref = value;
	// TODO 2: priradte do 'ref' premennu 'value2'
	ref = value2;
	// TODO 3: vypiste obsah premennej 'value' ... ake cislo bude obsahovat?
	cout << value;*/

	//***A4***
	int value{}; // nainicializovana premenna na hodnotu 0

	// TODO 1: definujte referenciu 'ref' odkazujucu na 'value'
	int& ref = value;
	// TODO 2: definujte smernik 'ptr' ukazujuci na 'value'
	int* ptr = &value;
	// TODO 3: vypiste hodnotu premennej 'v' pouzitim referencie 'ref'
	// vypise sa 0
	cout << ref << endl;
	// TODO 4: vypiste hodnotu premennej 'v' pouzitim smernika 'ptr'
	// vypise sa 0
	cout << *ptr << endl;

	int a = 3;

	// TODO 3: zavolajte funkciu 'incrementRef' a odovzdajte do nej premennu 'a', vypiste 'a'
	incrementRef(a);
	cout << a << endl;
	// TODO 4: zavolajte funkciu 'incrementPtr' a odovzdajte do nej adresu premennej 'a', vypiste 'a'
	incrementPtr(&a);
	cout << a;

	SomeClass sc{};
	fn(sc);

	return 0;
}