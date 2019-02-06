#include <iostream>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

// Tema: N-arny strom 

// N-arny strom je strom, kde moze mat kazdy uzol 
// lubovolny pocet (n) potomkov. Medzi uzlami 
// neexistuje ziadne usporiadanie. 

// Struktura 'Node' sluzi na reprezentaciu jedneho uzla v strome
struct Node {
	string name; // hodnota uzla
	list<Node*> children; // potomkovia uzla
	Node(string name) : name(name)
	{
	}
};

// TODO: Doprogramujte vyznacene metody v triede 'Tree'

// Trieda 'Tree' sluzi na reprezentaciu n-arneho stromu a jeho operacii.
class Tree
{
public:
	// default konstruktor stromu, ak nezadame root, nastavi sa na nullptr
	Tree(Node* root = nullptr) :
		root(root)
	{
	}

	// destruktor
	~Tree() { }

	// TODO 1: dokoncite funkciu na pridanie uzla s menom 'nodeName' do stromu tak,
	// aby bol jeho rodicom uzol s menom 'parentName'.
	// V strome sa nesmu nachadzat duplikaty.
	// Ak je strom prazdny, tak 'nodeName' sa stane korenom.
	// Ak uzol s menom 'parentName' neexistuje, tak funkcia neprida novy uzol.

	bool insert(string nodeName, string parentName = "") {
		if (!this->root) {
			this->root = new Node(nodeName);
			return true;
		}
		Node* parent = findNode(this->root, parentName);
		if (!parent) {
			return false;
		}
		if (findNode(this->root, nodeName)) {
			return false;
		}
		parent->children.push_back(new Node(nodeName));
		return true;
	}

	// TODO 2: dokoncite kopirovaci konstruktor, ktory vytvori strom ako 
	// kopiu ineho stromu
	Tree(const Tree& otherTree) {
		/*...*/
	}

	// TODO 3: dokoncite funkciu na vyhladanie uzla s menom 'nodeName',
	// strom prechadzajte do hlbky (DFS: Depth First Search)
	// Ak je nastaveny aj parameter 'traverse_all' na 'true', vtedy funkcia nebude hladat
	// uzol 'nodeName', ale prejde cely strom.
	// Funkcia vrati zoznam prejdenych uzlov (ich mena) - musia byt v poradi DFS.
	list<string> searchDFS(string nodeName, bool traverse_all = false) {
		/*...*/
		return{};
	}

	// TODO 4: dokoncite funkciu na vyhladanie uzla s menom 'nodeName',
	// strom prechadzajte do sirky (BFS: Breadth First Search)
	// Ak je nastaveny aj parameter 'traverse_all' na 'true', vtedy funkcia nebude hladat
	// uzol 'nodeName', ale prejde cely strom.
	// Funkcia vrati zoznam prejdenych uzlov (ich mena) - musia byt v poradi BFS.
	list<string> searchBFS(string nodeName, bool traverse_all = false) {
		/*...*/
		return{};
	}

	// TODO 5: dokoncite funkciu na ziskanie mien vsetkych priamych potomkov uzla
	// s menom 'nodeName'
	list<string> successors(string nodeName) {
		/*...*/
		return{};
	}

private:
	Node* root; // koren n-arneho stromu 

	Node* findNode(Node* current, string nodeName) {
		if (current && nodeName != "") {
			if (nodeName == current->name) {
				return current;
			}
			for (Node* child : current->children) {
				Node* result = findNode(child, nodeName);
				if (result) {
					return result;
				}
			}
		}
		return nullptr;
	}
};

int main() {
	Tree tree;

	// TODO: riadne otestujte vsetky operacie v triede 'Tree'

	// TODO 1 - pridavanie
	// Vytvorte nasledujuci strom:
	//
	//
	//                          [A]
	//                           |
	//               ------------------------------
	//               |         |         |        |
	//              [C]       [R]       [H]      [V]
	//               |                   |        |
	//             -----                 |        |
	//             |   |                 |        |
	//            [B] [N]               [M]      [K]
	//                                            |
	//                                            |
	//                                            |
	//                                       -----------
	//                                       |    |    |
	//                                      [S]  [W]  [E]
	// lautgesetz.com/latrees
	vector<pair<string, string> >pairs{
		{"A",""},									// 0. LVL
		{"C","A"},{"R","A"},{"H","A"},{"V","A"},    // 1. LVL
		{"B","C"}, {"N","C"}, {"M","H"},{"K","V"},  // 2. LVL
		{"S","K"},{"W","K"},{"E","K"}				// 3. LVL
	};

	for (auto p : pairs) {
		tree.insert(p.first,p.second);
	}

	// TODO 2 - kopirovaci konstruktor
	// TODO 3 - DFS
	// TODO 4 - BFS
	// TODO 5 - successors

	cout << endl;
	return 0;
}