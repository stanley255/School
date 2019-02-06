#include <stdio.h>
void nazov_mesiaca(int mesiac);
void nazov_dna(int den);
//funckia, ktora vrati hodnotu vstupu, iba pokial je to cislo z intervalu <a;b>
int spravny_vstup(a,b) {
	int x;
	while (printf("Zadaj hodnotu: ") &&
		(scanf_s("%i", &x) == 0 || x < a || x > b) &&
		printf("Chyba vstupu\n"))
	{
		while (getchar() != '\n')
			;
	}
	return x;
}
//funkcia, ktora vrati jednotku, ak sa jedna o priestupny a nulu, ak o nepriestupny rok
int priestupny_rok(int rok) {
	int result;
	if ((rok % 4) == 0) {
		result = 1;
		if ((rok % 100) == 0) {
			result = 0;
			if ((rok % 400) == 0) {
				result = 1;
			}
		}
	}
	else { result = 0; }
	return result;
}
//funkcia, ktora vrati pocet dni v zadanom mesiaci
int pocet_dni_v_mesiaci(int mesiac, int rok) {
	if (mesiac == 2) {
		return priestupny_rok(rok) ? 29 : 28;
	}
	if (mesiac > 7) {
		mesiac -= 7;
	}
	return ((mesiac % 2) == 0) ? 30 : 31;
}

int den_v_mesiaci(int den, int mesiac, int rok) {
	int a, y, m, d;
	a = (14 - mesiac)/12;
	y = rok - a;
	m = mesiac + 12 * a - 2;
	d = (den + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	if (d == 0) { d = 7; }
	return d;
}
//funkcia, ktora vykresli kalendar na zadany mesiac
void kalendar_na_dany_mesiac(int mesiac, int rok) {
	int prvy_den = den_v_mesiaci(1, mesiac, rok);
	int counter = 1;
	//ZAHLAVIE
		//MESIAC + ROK
	printf("\n       ");
	nazov_mesiaca(mesiac);
	printf("  ");
	printf("%i\n",rok);
		//SKRATKY DNI
	for (int i = 1; i <= 7; i++) {
		nazov_dna(i);
		printf("  ");
	}
	printf("\n");
	//VYPLNENIE PRAZDNYCH DNI Z MINULEHO MESIACA
	for (int i = 1; i < prvy_den; i++) {
		printf("    ");
	}
	//VYPISOVANIE DNI MESIACA
	for (int i = 1; i <= 5; i++) {
		int j = i == 1? prvy_den: 1;
		while (j <= 7) {
			if (counter > pocet_dni_v_mesiaci(mesiac, rok)) { break; }
			printf("%2.i", counter);
			printf("  ");
			counter++;
			j++;
		}
		printf("\n");
		if (i == 5) { break; }		
	}
	printf("\n");
}
//funkcia, ktora vykresli kalendar na zadany rok
void kalendar_na_dany_rok(int rok) {
	for (int i = 1; i <= 12; i++) {
		kalendar_na_dany_mesiac(i, rok);
	}
}
//funkcia, ktora vrati pocet dni medzi dvoma datumami
int pocet_dni_medzi(int d1, int m1, int y1, int d2, int m2, int y2) {
	int result = 0;
	while (y1 != y2) {
		result += (priestupny_rok(y1) && (m1<3)) == 0 ? 365 : 366;
		y1++;
	}
	while (m1 > m2) {
		result -= pocet_dni_v_mesiaci(m1, y2);
		m1--;
	}
	while (m1 < m2) {
		result += pocet_dni_v_mesiaci(m1, y2);
		m1++;
	}
	while (d1 > d2) {
		result -= 1;
		d1--;
	}
	while (d1 < d2) {
		result += 1;
		d1++;
	}
	return result;
}

int jdn(int d1, int m1, int y1, int d2, int m2, int y2) {
	int JDN1 = (1461 * (y1 + 4800 + (m1 - 14) / 12)) / 4 + (367 * (m1 - 2 - 12 * ((m1 - 14) / 12))) / 12 - (3 * ((y1 + 4900 + (m1 - 14) / 12) / 100)) / 4 + d1 - 32075;
	int JDN2 = (1461 * (y2 + 4800 + (m2 - 14) / 12)) / 4 + (367 * (m2 - 2 - 12 * ((m2 - 14) / 12))) / 12 - (3 * ((y2 + 4900 + (m2 - 14) / 12) / 100)) / 4 + d2 - 32075;
	return JDN2 - JDN1;
}
//funkcia, ktora na zaklade cisla mesiaca vypise na obrazovku nazov mesiaca (bez medzier)
void nazov_mesiaca(int mesiac) {
	switch (mesiac) {
	case 1:
		printf("Januar");
		break;
	case 2:
		printf("Februar");
		break;
	case 3:
		printf("Marec");
		break;
	case 4:
		printf("April");
		break;
	case 5:
		printf("Maj");
		break;
	case 6:
		printf("Jun");
		break;
	case 7:
		printf("Jul");
		break;
	case 8:
		printf("August");
		break;
	case 9:
		printf("September");
		break;
	case 10:
		printf("Oktober");
		break;
	case 11:
		printf("November");
		break;
	case 12:
		printf("December");
		break;
	}
}
//funkcia, ktora na zaklade cisla dna vypise na obrazovku skratku dna (bez medzier)
void nazov_dna(int den) {
	switch (den) {
	case 1:
		printf("MO");
		break;
	case 2:
		printf("TU");
		break;
	case 3:
		printf("WE");
		break;
	case 4:
		printf("TH");
		break;
	case 5:
		printf("FR");
		break;
	case 6:
		printf("SA");
		break;
	case 7:
		printf("SU");
		break;
	}
}

int menu() {
	int volba;
	int mesiac, rok;
	int den_1, den_2, mesiac_1, mesiac_2, rok_1, rok_2;
	//VYPIS TEXTU HLAVNEHO MENU
	printf("V ponuke si mozete vybrat jednu z moznosti tejto app/ky.\n");
	printf("1. Zobrazit kalendar na zadany mesiac a rok\n2. Zobrazit kalendar na cely zadany rok\n");
	printf("3. Zobrazit pocet dni medzi dvoma datumami\n4. Ukoncit app/ku\n");
	volba = spravny_vstup(1,4);
	getchar();
	switch (volba) {
	case 1:
		printf("Zacneme cislom mesiaca...\n");
		mesiac = spravny_vstup(1, 12);
		printf("Teraz tebou zvoleny rok...\n");
		rok = spravny_vstup(10, 3000);
		getchar();
		kalendar_na_dany_mesiac(mesiac, rok);
		return 1;
	case 2:
		printf("Zvol si rok, ktoreho kalendar chces vypisat...\n");
		rok = spravny_vstup(10, 3000);
		getchar();
		kalendar_na_dany_rok(rok);
		return 2;
	case 3:
		do {
			printf("Zacneme...\n");
			printf("Rok 1:\n");
			rok_1 = spravny_vstup(10, 3000);
			printf("Mesiac 1:\n");
			mesiac_1 = spravny_vstup(1, 12);
			printf("Den 1:\n");
			den_1 = spravny_vstup(1, pocet_dni_v_mesiaci(mesiac_1, rok_1));

			printf("Rok 2:\n");
			rok_2 = spravny_vstup(10, 3000);
			printf("Mesiac 2:\n");
			mesiac_2 = spravny_vstup(1, 12);
			printf("Den 2:\n");
			den_2 = spravny_vstup(1, pocet_dni_v_mesiaci(mesiac_2, rok_2));
			getchar();
		} while (jdn(den_1, mesiac_1, rok_1, den_2, mesiac_2, rok_2)<0);
		printf("\nPocet dni medzi Vami zadanymi dnami je: %i\n\n", pocet_dni_medzi(den_1, mesiac_1, rok_1, den_2, mesiac_2, rok_2));
		return 3;
	case 4:
		return 4;
	}
}

int main() {	
	printf("***************************\n");
	printf("***Moj prvy kalendar v C***\n");
	printf("***************************\n");
	printf("Dobry den!");
	do {
		;
	} while (menu() != 4);

	return 0;
}