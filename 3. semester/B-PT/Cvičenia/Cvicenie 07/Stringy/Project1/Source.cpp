#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// Tema: std::string
// Odporucany zdroj: 'http://www.cplusplus.com/reference/string/string/?kw=string'

int main()
{
	// V Ccku const char* word = "Ahoj";
	// TODO 1: otestujte si pouzivanie roznych konstruktorov triedy std::string
	string str{}; // default konstruktor
	string str2{ str }; // Alebo str2 = str| str2(str) <= kopirovacie konstruktory
	string str3 = "abcdefgh";
	string str4(str3,1,str3.length()-2); // <= substring konstruktor (bcdefg)
	cout << str4 << endl;
	// TODO 2: otestujte si pouzivanie funkcii size() a empty()
	cout << str4.size() << endl;
	if (str.empty()) {
		cout << "str je prazdny" << endl;
	}
	else {
		cout << "str nie je prazdny" << endl;
	}
	// TODO 3: otestujte si pouzivanie operatora [] na pristup k znaku
	cout << str4[str4.size() - 2] << endl;
	// TODO 4: otestujte si pouzivanie funkcie at() na pristup k znaku a skuste pristupit
	// k neexistujucemu znaku
	try {
		cout << str4.at(555) << endl;
	}
	catch(out_of_range& e){
		cout << e.what() << endl;
		/*if (e.what() == "invalid string position") {
			cout << "Zla pozicia" << endl;
		}*/
	}
	// TODO 5: otestujte si pouzivanie operatora '+=' na pripajanie obsahu na koniec stringu
	string str5 = "Word1";
	str5 += "Word2";
	cout << str5 << endl;
	// TODO 6: otestujte si pouzivanie funkcie push_back() na pripojenie znaku na koniec stringu
	string str6 = "123";
	str6.push_back('.');
	cout << str6 << endl;
	// TODO 7: otestujte si pouzivanie funkcie insert()
	string str7 = "BBB";
	string newString = "CCC";
	str7.insert(1, newString); // BCCCBB
	// TODO 8: otestujte si pouzivanie funkcie erase()
	string str8 = "Hello World";
	str8.erase(5,1);
	// TODO 9: otestujte si pouzivanie operatora '=='
	string str9 = "First";
	string str10 = "First";
	if (str9 == str10) {
		cout << "Su rovnake" << endl;
	}
	// TODO 10: otestujte si pouzivanie funkcie c_str()
	// TODO 11: otestujte si pouzivanie funkcie find()
	// TODO 12: otestujte si pouzivanie funkcie substr()

	return 0;
}