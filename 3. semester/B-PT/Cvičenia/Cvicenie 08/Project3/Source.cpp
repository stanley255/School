#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <fstream>
#include <algorithm>
using namespace std;

// Tema: STL algoritmy a lambda vyrazy

// TODO: Doprogramujte vyznacene metody v triede 'TextAnalyzer'

// Trieda 'TextAnalyzer' sluzi na analyzu textu, ktory je reprezentovany
// ako vektor slov (atribut 'words').
class TextAnalyzer {
private:
	vector<string> words; // text, ktory sa bude analyzovat je vyjadreny ako vektor slov
public:

	// TODO 1:
	// Default konstruktor, ktory nacita jednotlive slova zo vstupneho textu 'input_text' do vektora 'words'.
	// Biele znaky a interpunkcia musia byt ignorovane.
	//
	// Priklad:
	//      input_text: "Prajem Vam pekny den."
	//      words:      "Prajem", "Vam", "pekny", "den"
	//
	TextAnalyzer(string input_text = "") {
		stringstream ss{ input_text };
		string word;
		while (ss >> word) {
			// vyfiltruj nealphabeticke znaky
			for (int i = 0; i < word.size(); i++) {
				if (!isalnum(word.at(i))) {
					word.erase(i--,1);
				}
			}
			this->words.push_back(word);
		}
	}

	// TODO 2:
	// Metoda, ktora do vektora 'words' nacita slova z textoveho suboru s nazvom 'filename'.
	// Metoda vrati true/false, podla toho, ci citanie prebehlo uspesne/neuspesne.
	//
	bool loadTextFromFile(string filename) {
		fstream file(filename);
		string word;
		if (!file.is_open()) {
			return false;
		}
		this->words.clear();
		while (file >> word) {
			// vyfiltruj nealphabeticke znaky
			for (int i = 0; i < word.size(); i++) {
				if (!isalnum(word.at(i))) {
					word.erase(i--, 1);
				}
			}
			this->words.push_back(word);
		}
		file.close();
		return true;
	}

	// TODO 3: precvicenie algoritmu 'all_of' 
	// Metoda, ktora zisti, ci su vsetky slova vo vektore 'words' dlhsie nez dlzka 'n'.
	//
	// Napoveda: pri pisani lambda vyrazu vyuzite jeho "zachytavaciu klauzulu" na 
	// zachytenie premennej 'n'.
	bool areLongerThan(int n) {
		return all_of(this->words.begin(), this->words.end(), [n](string w) {
			return w.length() > n;
		});
	}

	// TODO 4: precvicenie algoritmu 'count_if'
	// Metoda, ktora vypocita kolko palindromov sa nachadza vo vektore 'words'.
	// Pozn. palindrom je taky retazec, ktory sa cita rovnako spredu aj odzadu, napr. "level".
	int countPalindromes() {
		return count_if(this->words.begin(), this->words.end(), [](string w) {
			string reverse_w = w;
			reverse(reverse_w.begin(), reverse_w.end());
			return reverse_w == w;
		});
	}

	// TODO 5: precvicenie algoritmu 'find_if'
	// Metoda, ktora najde prvy vyskyt slova konciaceho na znak 'start' a sucasne konciaceho na znak 'end'.
	// Najdene slovo funkcia vrati. Ak take slovo neexistuje, funkcia vrati prazdny retazec.
	string firstOccurence(char start, char end) {
		vector<string>::iterator it = find_if(this->words.begin(), this->words.end(), [=](string w) {
			return (w.front() == start && w.back() == end);
		});
		// kvoli tomu, ze end iterator nevieme dereferencovat
		if (it != this->words.end()) {
			return *it;
		}
		return "";
	}

	// TODO 6: precvicenie algoritmu 'transform'
	// Metoda, ktora transformuje vo vektore 'words' kazde slovo tak, ze sa na jeho koniec prida retazec 
	// v tvare "[x]", kde 'x' predstavuje pocet jeho znakov.
	void appendWordLength() {
		transform(this->words.begin(), this->words.end(), this->words.begin(), [](string w) {
			return w.append("["+to_string(w.length())+"]");
		});
	}

	// TODO 7: precvicenie algoritmu 'for_each'
	// Metoda, ktora najde vsetky slova vo vektore 'words', ktore obsahuju pismeno 'p'.
	// Vsetky vyhovujuce slova funkcia zapise do vstupneho vektora 'result'. 
	//
	// Napoveda: pri pisani lambda vyrazu vyuzite jeho "zachytavaciu klauzulu", v ktorej
	// budete "zachytavat" parameter 'result', aby ste ho mohli vo vnutri lambda vyrazu modifikovat
	void findWordsContaining(char p, vector<string>& result) {
		/*...*/
	}

	// TODO 8: precvicenie algoritmu 'remove_if'
	// Metoda, ktora odstrani z vektora 'words' tie slova, ktore sa nachadzaju vo vstupnom vektore slov 'wordlist'.
	// Funkcia vrati pocet odstranenych slov z vektora 'words'.
	int removeWords(const vector<string>& wordlist) {
		/*...*/
		return -1;
	}

	// getter
	vector<string> getWords() const { return this->words; }
};

int main() {
	// TODO: triedu 'TextAnalyzer' riadne otestujte

	TextAnalyzer t{"Prve oko. Druhy level."};
	//cout << (t.loadTextFromFile("book.txt") ? "true" : "false");
	cout << t.areLongerThan(5) << endl;
	cout << t.countPalindromes() << endl;
	cout << t.firstOccurence('P', 'e') << endl;
	t.appendWordLength();
	for (string item : t.getWords()) {
		cout << item << endl;
	}
	getchar();
	return 0;
}