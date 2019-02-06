#include <stdio.h>
#define MAX_POLE 100
//Vypíše prvých n prvkov po¾a.
void vypisPola(const int pole[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%i ", pole[i]);
	}
	printf("\n");
}
//Vypoèíta (tzn. nájde hodnotu a vráti ju cez return) minimum z n èísel v poli.
int minimumPola(const int pole[], int n) {
	int min = 0;
	for (int i = 1; i < n; i++) {
		if (pole[min] > pole[i]) {
			min = i;
		}
	}
	return pole[min];
}
//Vypoèíta maximum z n èísel v poli.
int maximumPola(const int pole[], int n) {
	int max = 0;
	for (int i = 1; i < n; i++) {
		if (pole[max] < pole[i]) {
			max = i;
		}
	}
	return pole[max];
}
//Vypoèíta priemer z n èísel v poli.
double priemerPola(const int pole[], int n) {
	int priemer = 0;
	for (int i = 0; i < n; i++) {
		priemer += pole[i];
	}
	return priemer / n;
}
//Vypoèíta súèin všetkých n èísel v poli.
int sucetPola(const int pole[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += pole[i];
	}
	return sum;
}
//Vypoèíta poèet èísel v poli, ktoré patria do nejakého intervalu [a,b].
int pocetCiselIntervalu(const int pole[], int n, int a, int b) {
	int poc = 0;
	for (int i = 0; i < n; i++) {
		if ((pole[i] >= a) && (pole[i] <= b)) {
			poc++;
		}
	}
	return poc;
}
//Nájde druhý najväèší/najmenší prvok po¾a.
int druhyNajvacsiPrvokPola(const int pole[], int n) {
	int first_max = 0, second_max = 0;
	for (int i = 0; i < n; i++) {
		if (pole[first_max] < pole[i]) {
			second_max = first_max;
			first_max = i;
		}
	}
	return second_max;
}

void vypisCislePolaVacsichAkoX(const int pole[], int n, int x) {
	for (int i = 0; i < n; i++) {
		if (pole[i] > x) {
			printf("%i ",pole[i]);
		}
	}
	printf("\n");
}
//Zistí poèet èísel v poli, ktoré sú menšie ako dané èíslo x.
int PocetCiselMensichAkoX(const int pole[], int n, int x) {
	int counter = 0;
	for (int i = 0; i < n; i++) {
		counter += pole[i] < x ? 1 : 0;
	}
	return counter;
}
//Zistí poèet výskytov èísla x v poli.
//Zaroven uloha 11: Zistí, èi sa èíslo x v poli nachádza.
int vyskytCislaX(const int pole[], int n, int x) {
	int counter = 0;
	for (int i = 0; i < n; i++) {
		counter += pole[i] == x ? 1 : 0;
	}
	return counter;
}
//Zistí, èi pole je usporiadané 
int usporiadanostPola(const int pole[], int n) {
	for (int i = 0; i < (n-1); i++) {
		if (pole[i] > pole[i + 1]) {
			return 0;
		}
	}
	return 1;
}

int jePoleMnozinou(const int pole[], int n) {
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (pole[i] == pole[j]) {
				return 0;
			}
		}
	}
	return 1;
}
int main() {
	int n = 10;
	int a = 3, b = 6;
	int pole[MAX_POLE] = {0};
	for (int i = 0; i < n; i++) {
		pole[i] = i;
	}
	vypisPola(pole, 10);
	printf("Minimum pola: %i\n",minimumPola(pole,n));
	printf("Maximum pola: %i\n", maximumPola(pole, n));
	printf("Priemer pola: %.2lf\n", priemerPola(pole, n));
	printf("Suma pola: %i\n", sucetPola(pole, n));
	printf("Pocet cisel z intervalu <%i,%i> pola: %i\n", a, b, pocetCiselIntervalu(pole, n, a, b));
	printf("Druhy najvacsi prvok pola: %i\n",druhyNajvacsiPrvokPola(pole,n));
	printf("Cisla vacsie ako %i: ", b);
	vypisCislePolaVacsichAkoX(pole, n, b);
	printf("Pocet cisel <%i: %i",a, PocetCiselMensichAkoX(pole,n,a));
	printf("Pocet vyskytov cisla %i v poli: %i\n",a,vyskytCislaX(pole,n,a));
	vyskytCislaX(pole, n, a) != 0? printf("Cislo %i sa nachadza v poli\n", a): printf("Cislo %i sa nenachadza v poli\n", a);
	usporiadanostPola(pole,n) ? printf("Pole je usporiadane\n") : printf("Pole nie je usporiadane\n");
	jePoleMnozinou(pole, n) ? printf("Pole je mnozinou\n") : printf("Pole nie je mnozinou\n");
	getchar();
	return 0;
}