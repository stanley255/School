#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>

int x = 5;

namespace n1 {
	int x = 10;
}

namespace n2 {
	int x = 20;
}

int main()
{
	int x = 30;

	// TODO 1: Odkomentujte nasledujuci riadok, co sa vypise?
	std::cout << x << std::endl; // 30

	// TODO 2: Vypiste premennu 'x' z menneho priestoru 'n1' ... 10
	std::cout << n1::x << std::endl;
	// TODO 3: Vypiste premennu 'x' z menneho priestoru 'n2' ... 20
	std::cout << n2::x << std::endl;
	// TODO 4: Vypiste globalnu premennu 'x' ... 5
	std::cout << ::x << std::endl;

	return 0;
}