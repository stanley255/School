#include <iostream>
#include <string>
#include <functional>
using namespace std;

// Tema: Binarny vyhladavaci strom (BST)

// BST je datova struktura umoznujuca rychle vyhladavanie uzlov.
//
// Vlastnost BST:
//  * pre lubovolny uzol U v BST plati:
//      a) uzly v lavom podstrome su mensie ako U
//      b) uzly v pravom podstrome su vacsie ako U
//  * vsetky uzly v BST su unikatne

// Struktura 'Node' sluzi na reprezentaciu jedneho uzla v BST
struct Node
{
	// datova cast
	int data;       // hodnota uzla
	// navigacna cast
	Node* parent;   // smernik na rodica
	Node* left;     // smernik na laveho nasledovnika
	Node* right;    // smernik na praveho nasledovnika

	// konstruktor
	Node(int data, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr) :
		data(data),
		parent(parent),
		left(left),
		right(right)
	{
	}
};

// TODO: Doprogramujte vyznacene metody

// Trieda 'BST' sluzi na reprezentaciu BST a jeho operacii.
class BST
{
public:
	// default konstruktor BST, ak nezadame root, nastavi sa na nullptr
	BST(Node* root = nullptr) :
		root(root)
	{
	}

	// destruktor
	~BST() { }

	// TODO 1: dokoncite funkciu na vlozenie uzla s hodnotou 'data' do BST
	bool insert(int data) {
		return insert(this->root, data);
	}

	// TODO 2: dokoncite kopirovaci konstruktor, ktory vytvori BST ako 
	// kopiu ineho BST
	BST(const BST& otherBST) {
		copyTree(otherBST.root);
	}

	// TODO 3: dokoncite funkciu na vyhladanie uzla s hodnotou 'data'
	Node* search(int data) {
		return search(this->root, data);
	}

	// TODO 4: dokoncite funkciu na vymazanie uzla s hodnotou 'data'
	bool remove(int data) {
		/*...*/
		return false;
	}

	// TODO 5: dokoncite funkciu na vymazanie celeho BST
	void removeTree() {
		removeTree(this->root);
		this->root = nullptr;
	}

	// TODO 6: dokoncite funkciu na vypis stromu stylom pre-order
	void printPreOrder() {
		printPreOrder(this->root);
	}

	// TODO 7: dokoncite funkciu na vypis stromu stylom in-order
	void printInOrder() {
		printInOrder(this->root);
	}

	// TODO 8: dokoncite funkciu na vypis stromu stylom post-order
	void printPostOrder() {
		printPostOrder(this->root);
	}

	// TODO 9: dokoncite funkciu na vypis stromu stylom level-order (do sirky)
	void printLevelOrder() {
		int i = 0;
		while (printLevel(this->root, ++i));
	}

	// TODO 10: dokoncite funkciu na zistenie hlbky uzla s hodnotou 'data'
	int depth(int data) {
		return depth(this->root, data, 0);
	}

	// TODO 11: dokoncite funkciu na zistenie maximalnej hlbky stromu
	// Poznamka: koren ma hlbku 0.
	int treeDepth() {
		/*...*/
		return -1;
	}

	// TODO 12: dokoncite funkciu na zistenie poctu prvkov v strome
	int count() {
		/*...*/
		return -1;
	}

	// TODO 13: dokoncite funkciu 'applyFunction', ktora aplikuje
	//
	// vami definovanu funkciu 'fn' na kazdy uzol v BST.
	//
	// Funkcia 'fn' musi byt typu void fn(Node*), kde parametrom je povodny uzol.
	// Definujte si lubovolnu funkciu 'fn', ktora splna hore uvedene kriteria.
	//
	// Priklad definicie funkcie 'fn', ktora vypise potomkov zadaneho uzla:
	//
	// void fn(Node* node){
	//    if(node){
	//      cout << "Node: [" << node->data << "]" << endl;
	//      cout << " ---> Left child: " << ((node->left) ? to_string(node->left->data) : "n/a") << endl;
	//      cout << " ---> Right child: " << ((node->right) ? to_string(node->right->data) : "n/a") << endl;
	//    }
	// }
	// 
	// Namiesto definicie funkcie 'fn' mozete pouzit lambda vyraz.

	void applyFunctionToEachNode(const function<void(Node*)>& fn) {
		apply(this->root, fn);
	}

private:
	Node* root; // koren stromu 

	void apply(Node* node, const function<void(Node*)>& fn) {
		if (node) {
			fn(node);
			apply(node->left, fn);
			apply(node->right, fn);
		}
	}

	bool insert(Node* current, int data) {
		if (!current) {
			this->root = new Node(data);
			return true;
		}
		if (current->data == data) {
			return false;
		}
		else if (data < current->data) {
			if (current->left) {
				return insert(current->left, data);
			}
			else {
				current->left = new Node(data, current);
			}
		}
		else {
			if (current->right) {
				return insert(current->right, data);
			}
			else {
				current->right = new Node(data, current);
			}
		}
		return true;
	}

	void copyTree(Node* otherCurrent) {
		// Typ Pre-order
		if (otherCurrent) {
			this->insert(otherCurrent->data);
			copyTree(otherCurrent->left);
			copyTree(otherCurrent->right);
		}
	}

	Node* search(Node* current, int data) {
		if (!current) {
			return nullptr;
		}
		if (data == current->data) {
			return current;
		}
		else if (data < current->data) {
			return search(current->left, data);
		}
		else {
			return search(current->right, data);
		}
	}

	void removeTree(Node* current) {
		// Post Order
		if (current) {
			removeTree(current->left);
			removeTree(current->right);
			delete current;
		}
	}

	void printPreOrder(Node* current) {
		if (current) {
			std::cout << current->data << " ";
			printPreOrder(current->left);
			printPreOrder(current->right);
		}
	}
	void printInOrder(Node* current) {
		if (current) {
			printInOrder(current->left);
			std::cout << current->data << " ";
			printInOrder(current->right);
		}
	}
	void printPostOrder(Node* current) {
		if (current) {
			printPostOrder(current->left);
			printPostOrder(current->right);
			std::cout << current->data << " ";
		}
	}
	bool printLevel(Node* current, int targetLevel) {
		if (current) {
			if (targetLevel == 0){
				cout << current->data << " ";
				return true;
			}
			bool isLevelLeft, isLevelRight;
			isLevelLeft = printLevel(current->left, targetLevel - 1);
			isLevelRight = printLevel(current->right, targetLevel - 1);
			if (isLevelLeft || isLevelRight) {
				return true;
			}
			else {
				return false;
			}
		}
		return false;
	}

	int depth(Node* current, int data, int currentDepth) {
		if (!current) {
			return -1;
		}
		if (data == current->data) {
			return currentDepth;
		}
		else if (data < current->data) {
			return depth(current->left, data, currentDepth + 1);
		}
		else {
			return depth(current->right, data, currentDepth + 1);
		}
	}
};

void fn(Node* node) {
	if (node) {
		node->data++;
	}
}

int main() {
	BST tree;

	// TODO: riadne otestujte vsetky operacie v triede BST

	// TODO 1 - pridavanie
	int pole[]{5,1,2,8,9,10};
	for (int item : pole)
		tree.insert(item);

	// TODO 2 - testovanie kopirovacieho konstruktoru
	BST tree2(tree);

	// TODO 3 - hladanie uzla
	for (int item : pole) {
		Node* tmp = tree.search(item);
		if (tmp) {
			std::cout << item << " IN" << std::endl;
		}
		else {
			std::cout << item << " OUT" << std::endl;
		}
	}
	tree.search(100);

	// TODO 6 - preOrderPrint

	tree.printPreOrder();
	std::cout << std::endl;

	// TODO 7 - inOrderPrint

	tree.printInOrder();
	std::cout << std::endl;

	// TODO 8 - inOrderPrint

	tree.printInOrder();
	std::cout << std::endl;

	// TODO 9 - printLevelOrder

	tree.printLevelOrder();
	std::cout << std::endl;

	// TODO 10 - depth

	for (int i : pole) {
		std::cout << i << " : " << tree.depth(i) << std::endl;
	}

	// TODO

	tree.applyFunctionToEachNode(fn);

	// TODO 5 - vymazanie stromu
	tree.removeTree();
	tree2.removeTree();
	return 0;
}