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

//Zap�e prvky po�a v opa�nom porad�, t.j. prehod� prv� s posledn�m, druh� s predposledn�m,...
void prehodPole(int pole[], int n) {
	int temp;
	for (int i = 0; i < (n/2); i++) {
		temp = pole[i];
		pole[i] = pole[n - i - 1];
		pole[n - i - 1] = temp;
	}
	vypisPole(pole, n);
}
//Odstr�ni z po�a v�etky hodnoty v��ie ako x. 
//Zvy�n� hodnoty popos�va tak, aby boli prvky v p�vodnom porad� bez medzier sp�soben�ch predo�l�m krokom. 
//Vr�ti nov� po�et prvkov.
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

//Funkcia prid� do po�a na koniec prvok x. Vr�ti nov� po�et prvkov.
void pridajNaKoniecPrvok(int pole[], int *pN, int x) {
	pole[*pN] = x;	
	*pN+=1;
}
//Funkcia prid� do po�a na za�iatok prvok x (ostatn� prvky teda treba popos�va�!
//sk�ste si popos�va� po jednej bunke v tabu�kovom procesore). Vr�ti nov� po�et prvkov.
void pridajPrvokNaZaciatok(int pole[], int *pN, int x) {
	int temp;
	for (int i = (*pN-1); i > 1; i--) {
		pole[i + 1] = pole[i];
	}
	pole[0] = x;
	*pN += 1;
}
//Funkcia prid� do po�a na koniec prvok x, ak tak� ��slo u� v poli nie je (ak je, tak sa s po�om ni� nerob�). Vr�ti nov� po�et prvkov.
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
//Funkcia prid� do usporiadan�ho po�a prvok x tak, aby pole zostalo usporiadan� 
//(t.j. n�jde prv� v��� prvok, vlo�� x a ostatn� prvky popos�va). 
//Vr�ti nov� po�et prvkov.
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