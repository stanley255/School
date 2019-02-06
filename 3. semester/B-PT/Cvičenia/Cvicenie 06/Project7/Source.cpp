#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>

// funkcia s celociselnym parametrom 
void fun(int n) {
	std::cout << "fun(int)" << std::endl;
}

// pretazena funkcia s pointrovym parametrom 
void fun(char* s) {
	std::cout << "fun(char *)" << std::endl;
}

// Pred spustenim programu sa zamyslite nad bodmi TODO 1 a 2
int main()
{
	// TODO 1: Ktora z dvoch vyssie uvedenych verzii funkcie 'fun' sa zavola?
	fun(NULL); // fun(int)

	// TODO 2: Ktora z dvoch vyssie uvedenych verzii funkcie 'fun' sa zavola?
	fun(nullptr); // fun(char *)

	return 0;
}