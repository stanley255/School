#include <iostream>
#include <string>
#include <functional>
using namespace std;
typedef void(*f)();
// Tema: C++11 lambda vyraz
// Zdroj: https://msdn.microsoft.com/en-us/library/dd293608.aspx

//  Anatomia lambda vyrazu - anonymnej/docasnej funkcie
//
//  [capture clause](parameters) -> return-type
//  {
//      lambda body
//  }

// funkcia fn
void fn() {
	cout << "Vykonala sa funkcia fn()" << endl;
}

// TODO 1: dokoncite funkciu 'callFunc' tak, aby na vstupe dostala smernik 'f' 
// na funkciu typu void() a nasledne ju zavolala
void callFunc(f fptr) {
	fptr();
}

// TODO 2: dokoncite funkciu 'callLambda' tak, aby na vstupe dostala lambda vyraz 'f' typu void()
// a nasledne ho zavolala .... pouzite triedu std::function .. z hlavickoveho suboru <functional>
void callLambda(function<void()> f) {
	f();
}

int main() {

	// TODO 3: do funkcie 'callFunc' odovzdajte taky parameter, aby sa po jej zavolani do konzoly
	// vypisal text "Vykonala sa funkcia fn()"
	callFunc(fn);

	// TODO 4: do funkcie 'callLambda' odovzdajte taky lambda vyraz, aby sa po jej zavolani vypisal do
	// konzoly text "Hello, this is lambda".
	callLambda([]() {cout << "Hello, this is lambda" << endl; });
	int value = 10;
	callLambda([value]() {cout << value << endl; });

	// TODO 5: ako by ste vysvetlili nasledujuci riadok?
	[]() {}();

	getchar();
	return 0;
}