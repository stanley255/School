#include <iostream>
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
	Node *left;     // smernik na laveho nasledovnika
	Node *right;    // smernik na praveho nasledovnika

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
		if (!this->root) {
			this->root = new Node(data);
			return true;
		}
		return insert(this->root, data);
		return false;
	}

	// TODO 2: dokoncite funkciu na vyhladanie uzla s hodnotou 'data'
	Node* search(int data) {
		/*...*/
		return nullptr;
	}

	// TODO 3: dokoncite funkciu na vymazanie uzla s hodnotou 'data'
	bool remove(int data) {
		/*...*/
		return false;
	}

	// TODO 4: dokoncite funkciu na vymazanie celeho BST
	void removeTree() {
		/*...*/
	}

	// TODO 5: dokoncite funkciu na vypis stromu stylom pre-order
	void printPreOrder() {
		/*...*/
	}

	// TODO 6: dokoncite funkciu na vypis stromu stylom in-order
	void printInOrder() {
		/*...*/
	}

	// TODO 7: dokoncite funkciu na vypis stromu stylom post-order
	void printPostOrder() {
		/*...*/
	}

	// TODO 8: dokoncite funkciu na vypis stromu stylom level-order (do sirky)
	void printLevelOrder() {
		/*...*/
	}

	// TODO 9: dokoncite funkciu na zistenie hlbky uzla s hodnotou 'data'
	int depth(int data) {
		/*...*/
		return -1;
	}

private:
	Node* root; // koren stromu 

	bool insert(Node* current, int data) {
		if (current->data == data) {
			return false;
		}
		else if (current->data > data) {
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
};

int main() {
	BST tree;
	tree.insert(8);
	tree.insert(3);
	tree.insert(10);
	// TODO: riadne otestujte triedu BST
	return 0;
}