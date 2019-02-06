#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

// Tema: std::vector
// Odporucany zdroj: 'http://www.cplusplus.com/reference/vector/vector/?kw=vector'

// TODO 1: definujte vlastnu triedu s nazvom 'Product',
// ktora bude mat tieto privatne atributy:
//  * string name
//  * double price
// Trieda bude mat default konstruktor s implicitnymi hodnotami 
// parametrov a adekvatne 'get' metody na ziskanie hodnot privatnych atributov
class Product {
private:
	string name;
	double price;
public:
	Product(string name = "no_name", double price = 0.0) {
		this->name = name;
		this->price = price;
	}
	string getName() {
		return name;
	}
	double getPrice() {
		return price;
	}
};


int main() {

	// TODO 1: definujte vektor celych cisel s nazvom 'v'
	// a inicializujte na postupnost: 1,2,3,4,5,6
	vector<int> v{ 1,2,3,4,5,6 };
	// TODO 2: vypiste do konzoly kolko ma vektor 'v' prvkov
	cout << "Size of vector: " << v.size() << endl;
	// TODO 3: zistite, ci je vektor 'v' prazdny
	//string isEmpty = v.empty() ? "Empty" : "Not-empty";//
	// TODO 4: vypiste do konzoly vektor 'v' po jednotlivych prvkoch
	// pouzite na to jeho funkciu 'at'
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << " ";
	}
	cout << endl;
	// TODO 5: pridajte na koniec vektora 'v' cisla 100,101,102,103
	// pouzite na to jeho funkciu 'push_back'
	for (int i = 0; i < 4; i++) {
		v.push_back(100 + i);
	}
	// TODO 6: pomocou iteratora vypiste vsetky prvky vektora 'v'
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	// TODO 7: pomocou reverzneho iteratora vypiste vsetky prvky 
	// vektora 'v' v obratenom poradi
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	// TODO 8: pomocou tzv. 'range-based' for cyklu vypiste
	// vsetky prvky vektora 'v'
	for (int& item : v) {
		cout << item << " ";
	}
	cout << endl;
	// TODO 9: do vektora 'v' vlozte na 2. poziciu cislo 1000
	// pouzite na to jeho funkciu 'insert'
	vector<int>::iterator it;
	it = v.begin();
	v.insert(it + 2, 1000);
	for (int& item : v) {
		cout << item << " ";
	}
	cout << endl;
	// TODO 10: z vektora 'v' vymazte druhy az predposledny prvok
	// pouzite na to jeho funkciu 'erase'
	v.erase(it + 1, it + v.size() - 1);
	for (int& item : v) {
		cout << item << " ";
	}
	cout << endl;
	// TODO 2: vytvorte 3 objekty p1, p2 a p3, ktore budu typu 'Product'
	Product p1{ "Maslo",2.34 }, p2{ "Salam",3.45 }, p3{ "Banan",0.93 };
	// TODO 3: vytvorte vektor s nazvom 'products' a inicializujte ho tak, aby obsahoval
	// postupnost objektov p1,p2,p3
	vector<Product> vp{ p1,p2,p3 };
	// TODO 4: vypiste podrobne informacie o kazdom prvku vektora 'products'
	// pre kazdy prvok vektora 'products' zavolajte metody 'getName' a 'getPrice'
	for (Product item : vp) {
		cout << item.getName() << " : " << item.getPrice() << "EUR" << endl;
	}

	// TODO 1: definujte prazdnu mnozinu celych cisel 's'
	set<int> s{};
	// TODO 2: do mnoziny 's' vlozte cisla 1,2,3,....10
	// pouzite na to jej funkciu 'insert'
	for (int i = 1; i <= 10; i++)
		s.insert(i);
	// TODO 3: pomocou iteratora vypiste vsetky prvky mnoziny 's'
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
		cout << *it << " ";
	cout << endl;
	// TODO 4: do mnoziny 's' vlozte pomocou 'insert' nejaky prvok, 
	// ktory sa uz v nej nachadza
	// Otazka: co sa stane? co vracia funkcia 'insert'?
	std::pair<set<int>::iterator, bool> ret;
	ret = s.insert(13);
	if (ret.second) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}

	// TODO 1: vytvorte prazdnu mapu 'm', ktora bude obsahovat pary typu <int, std::string>
	map<int, string> m{};
	// TODO 2: do mapy 'm' vlozte pary <0,"Monday"> a <1,"Tuesday">
	// pouzite na to jej funkciu 'insert'
	m.insert(pair<int, string>(0, "Monday"));
	m.insert(pair<int, string>(1, "Tuesday"));
	// TODO 3: ziskajte z mapy 'm' hodnotu, ktora 
	// je namapovana na kluc s hodnotou 1
	// pouzite na to operator []
	cout << m[1] << endl;
	// TODO 4: ziskajte z mapy 'm' hodnotu, ktora 
	// je namapovana na kluc s hodnotou 999
	// pouzite na to jej funkciu 'at'
	// ... odchytavajte vynimku typu 'out_of_range'
	try {
		m.at(999);
	}
	catch (out_of_range e) {
		cout << e.what();
	}
	return 0;
}