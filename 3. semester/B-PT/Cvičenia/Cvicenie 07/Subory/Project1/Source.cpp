#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <time.h>
using namespace std;

// Tema: std::fstream ... citanie zo suboru
// Odporucany zdroj: 'http://www.cplusplus.com/reference/fstream/fstream/?kw=fstream'

// TODO 1: Definujte funkciu 'genWord' s dvoma parametrami:
//
//  * std::string& word 
//  * int n
//
// Funkcia do parametra 'word' vygeneruje nahodny string 
// pozostavajuci z 'n' alfabetickych znakov.

void genWord(string& word, int n) {
	word = "";
	for (int i = 0; i < n; i++) {
		word += rand() % 25 + 65;
	}
}

int main() {

	// TODO 1: definujte objekt typu 'fstream' s nazvom 'file'
	fstream file;
	// TODO 2: pomocou objektu 'file' otvorte existujuci textovy subor 'data.txt' 
	// v rezime citania pomocou funkcie 'open'
	file.open("data.txt",fstream::in);
	// TODO 3: pomocou objektu 'file' overte, ci je subor otvoreny, pouzite na
	// to funkciu 'is_open'
	if (!file.is_open()) {
		cout << "" << "Nepodaril sa otvorit subor" << endl;
		return 1;
	}
	// TODO 4: preskocte prve dva riadky v textovom subore a zacnite citat az od 3. riadku
	// pouzite na to funkciu 'getline'
	string str;
	getline(file, str);
	//cout << str << endl;
	getline(file, str);
	//cout << str << endl;
	// TODO 5: precitajte zvysny obsah suboru formatovanym sposobom a vypiste ho do konzoly
	// pouzite na to operator '>>'
	string name;
	int age;
	double weight;
	double avg_age{};
	int n{};
	while (!file.eof()) {
		file >> name >> age >> weight;
		cout << name << "\t" << age << "\t" << weight << endl;
		avg_age += age;
		n++;
	}
	// TODO 6: Vypocitajte a vypiste do konzoly priemerny vek osob v subore
	cout << "Priemerny vek:\t" << avg_age / n << endl;
	// TODO 7: subor zatvorte
	file.close();


	srand(time(0));
	string randStr{};
	// TODO 2: definujte objekt typu 'fstream' s nazvom 'file2'
	fstream file2;
	// TODO 3: otvorte novy subor s nazvom 'words.txt' v rezime na zapis
	// pouzite na to funkciu 'open'
	file2.open("words.txt", fstream::app);
	// TODO 4: otestujte, ci sa subor podarilo otvorit
	if (!file2.is_open()) {
		return 1;
	}
	// TODO 5: vygenerujte 50 nahodnych slov s nahodnou dlzkou v intervale <1,10>
	// a zapiste ich do suboru 'words.txt'
	// pouzite funkciu 'genWord'
	for (int i = 0; i < 10; i++) {
		genWord(randStr, rand()%10+1);
		file2 << randStr << " ";
	}
	// TODO 6: subor zatvorte
	file2.close();
	return 0;
}