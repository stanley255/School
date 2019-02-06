#include <stdio.h>
#define MAX_POLE 100
//Vyp�e prv�ch n prvkov po�a.
void vypisPola(const int pole[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%i ", pole[i]);
	}
	printf("\n");
}
//Vypo��ta (tzn. n�jde hodnotu a vr�ti ju cez return) minimum z n ��sel v poli.
int minimumPola(const int pole[], int n) {
	int min = 0;
	for (int i = 1; i < n; i++) {
		if (pole[min] > pole[i]) {
			min = i;
		}
	}
	return pole[min];
}
//Vypo��ta maximum z n ��sel v poli.
int maximumPola(const int pole[], int n) {
	int max = 0;
	for (int i = 1; i < n; i++) {
		if (pole[max] < pole[i]) {
			max = i;
		}
	}
	return pole[max];
}
//Vypo��ta priemer z n ��sel v poli.
double priemerPola(const int pole[], int n) {
	int priemer = 0;
	for (int i = 0; i < n; i++) {
		priemer += pole[i];
	}
	return priemer / n;
}
//Vypo��ta s��in v�etk�ch n ��sel v poli.
int sucetPola(const int pole[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += pole[i];
	}
	return sum;
}
//Vypo��ta po�et ��sel v poli, ktor� patria do nejak�ho intervalu [a,b].
int pocetCiselIntervalu(const int pole[], int n, int a, int b) {
	int poc = 0;
	for (int i = 0; i < n; i++) {
		if ((pole[i] >= a) && (pole[i] <= b)) {
			poc++;
		}
	}
	return poc;
}
//N�jde druh� najv���/najmen�� prvok po�a.
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
//Zist� po�et ��sel v poli, ktor� s� men�ie ako dan� ��slo x.
int PocetCiselMensichAkoX(const int pole[], int n, int x) {
	int counter = 0;
	for (int i = 0; i < n; i++) {
		counter += pole[i] < x ? 1 : 0;
	}
	return counter;
}
//Zist� po�et v�skytov ��sla x v poli.
//Zaroven uloha 11: Zist�, �i sa ��slo x v poli nach�dza.
int vyskytCislaX(const int pole[], int n, int x) {
	int counter = 0;
	for (int i = 0; i < n; i++) {
		counter += pole[i] == x ? 1 : 0;
	}
	return counter;
}
//Zist�, �i pole je usporiadan� 
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