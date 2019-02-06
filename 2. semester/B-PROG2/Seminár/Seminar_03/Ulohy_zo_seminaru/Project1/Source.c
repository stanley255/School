#include <stdio.h>

int is_prime(int n) {
	int x;
	if (n < 2) {
		return 2;
	}
	for (x = n % 2 == 0 ? n + 1 : n + 2; !is_prime(x); x += 2)
		{
		}
	
	return x;
}

int count_primes(int from, int to, int i) {
	int counter = 0;
	for (i = next_prime(from); i <= to; i = next_prime(i)) {
		counter++;
	}
	return counter;
}

int next_prime(int n) {
	int x;
	for (x = n + 1; !is_prime(x); x++) {
	}
	return x;
}

int main() {
	int i, n;
	n = 8;
	i = next_prime(n);
	printf("Najblizsie vacsie prvocislo cisla %i je cislo %i\n", n, i);
	printf("%i",count_primes(1,2,100));
	getchar();
	return 0;
}