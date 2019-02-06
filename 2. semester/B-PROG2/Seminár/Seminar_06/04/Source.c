#include <stdio.h>

void vypisPole(int pole[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%i ", pole[i]);
	}
	printf("\n");
}

void absPola(int pole[], int n) {
	for (int i = 0; i < n; i++) {
		if (pole[i] < 0) {
			pole[i] = pole[i] * (-1);
		}
	}
	vypisPole(pole, n);
}

//Zapíše prvky po¾a v opaènom poradí, t.j. prehodí prvý s posledným, druhý s predposledným,...
void prehodPole(int pole[], int n) {
	int temp;
	for (int i = 0; i < (n/2); i++) {
		temp = pole[i];
		pole[i] = pole[n - i - 1];
		pole[n - i - 1] = temp;
	}
	vypisPole(pole, n);
}
//Odstráni z po¾a všetky hodnoty väèšie ako x. 
//Zvyšné hodnoty poposúva tak, aby boli prvky v pôvodnom poradí bez medzier spôsobených predošlým krokom. 
//Vráti nový poèet prvkov.
void zmazZadaneVacsieCislaAkoX(int pole[], int *pN, int x) {
	printf("Zmazane cisla vacsie ako %i: ",x);
	for (int i = 0; i < *pN; i++) {
		if (pole[i] > x) {
			for (int j = i; j < (*pN-1); j++) {
				pole[j] = pole[j + 1];
			}
			*pN = *pN-1;
			i--;
		}
	}
	vypisPole(pole, *pN);
}

void usporiadajPole(int pole[], int n) {
	int j, temp;
	for (int i = 1; i < n; i++) {
		j = i;
		while (pole[j] < pole[j-1]) {
			temp = pole[j];
			pole[j] = pole[j - 1];
			pole[j - 1] = temp;
			j--;
		}
	}
	vypisPole(pole, n);
}

//Funkcia pridá do po¾a na koniec prvok x. Vráti nový poèet prvkov.
void pridajNaKoniecPrvok(int pole[], int *pN, int x) {
	pole[*pN] = x;	
	*pN+=1;
}
//Funkcia pridá do po¾a na zaèiatok prvok x (ostatné prvky teda treba poposúva!
//skúste si poposúva po jednej bunke v tabu¾kovom procesore). Vráti nový poèet prvkov.
void pridajPrvokNaZaciatok(int pole[], int *pN, int x) {
	int temp;
	for (int i = (*pN-1); i > 1; i--) {
		pole[i + 1] = pole[i];
	}
	pole[0] = x;
	*pN += 1;
}
//Funkcia pridá do po¾a na koniec prvok x, ak také èíslo už v poli nie je (ak je, tak sa s po¾om niè nerobí). Vráti nový poèet prvkov.
void pridajPrvokAkSaNenachadza(int pole[], int *pN, int x) {
	//skontroluj, ci sa nenachadza x v poli
	for (int i = 0; i < *pN; i++) {
		if (pole[i] == x) {
			return;
		}
	}
	//pridaj x do listu
	pole[*pN] = x;
	*pN += 1;
}
//Funkcia pridá do usporiadaného po¾a prvok x tak, aby pole zostalo usporiadané 
//(t.j. nájde prvý väèší prvok, vloží x a ostatné prvky poposúva). 
//Vráti nový poèet prvkov.
void pridajDoUsporiadanehoPolaX(int pole[], int *pN, int x) {
	int temp;
	usporiadajPole(pole, *pN);
	for (int i = 0; i< *pN; i++) {
		if (x <= pole[i]) {
			for (int j = (*pN); j >= i; j--) {
				pole[j+1] = pole[j];
			}
			pole[i] = x;
			*pN += 1;
			return;
		}
	}
}

int main() {
	int pole[10], neusporiadanePole[] = {1,5,3,7,4,9,2,6,8,0};
	int newPole[10];
	int n = 10;
	for (int i = 0; i < n; i++) {
		pole[i] = -i;
	}
	for (int i = 0; i < (n - 1); i++) {
		newPole[i] = 0;
	}
	vypisPole(pole, n);
	absPola(pole, n);
	prehodPole(pole,n);
	//zmazZadaneVacsieCislaAkoX(pole,&n,4);
	n = 10;
	printf("Neusporiadane pole: ");
	vypisPole(neusporiadanePole,n);
	usporiadajPole(neusporiadanePole, n);
	printf("Pole s pridanym prvkom: ");
	n = 9;
	vypisPole(newPole, n);
	pridajNaKoniecPrvok(newPole, &n, 9);
	vypisPole(newPole, n);
	n = 9;
	vypisPole(newPole, n);
	printf("Pridaj prvok na ziaciatok:");
	pridajPrvokNaZaciatok(newPole, &n, 5);
	vypisPole(newPole, n);
	printf("Pole: ");
	n = 9;
	vypisPole(pole,n);
	pridajPrvokAkSaNenachadza(pole, &n, 22);
	n = 9;
	vypisPole(pole, n);
	pridajDoUsporiadanehoPolaX(pole, &n, 5);
	vypisPole(pole, n);
	getchar();
	return 0;
}