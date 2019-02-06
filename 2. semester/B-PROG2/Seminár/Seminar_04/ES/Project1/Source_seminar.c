# include <stdio.h>
#define N 1000000000
char _pole[N] = { 0 };

void sieve(int n) {
	int p, mul;

	p = 2;
	while (p*p <= n) {
		for (mul = p * p; mul < n; mul += p) {
			_pole[mul] = 1;
		}
		do {
			p++;
		} while (_pole[p] == 1);
	}
	/*
	for (p = 2; p*p <= n; p++){
		if ()
	}
	*/
}

int count(int n) {
	int i, cnt = 0;
	for (i = 2; i < n; i++) {
		if (_pole[i] == 0)
			cnt++;
	}
	return cnt;
}

int main() {
	sieve(N);
	printf("%i", count(N));
	getchar();
	return 0;
}