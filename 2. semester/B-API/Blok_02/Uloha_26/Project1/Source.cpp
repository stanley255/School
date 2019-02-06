#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h> 
#include <windows.h>

bool IsKeyPressed(int virtualKey) {
	return((GetAsyncKeyState(virtualKey) & 0x8000) != 0 ? true : false);
}

void start() {
	printf("3  ");
	Sleep(1000);
	printf("2  ");
	Sleep(1000);
	printf("1  ");
	Sleep(1000);
	printf("GO!");
	Sleep(1000);
	system("cls");
}

int nahodne_cislo(int a, int b) {
	int nc= rand() % (b - a + 1) + a;
	return nc;
}

int main(int argc, char* argv[]) {
	srand(time(NULL));
	int znak;
	clock_t Start, Koniec;// premenne typu clock_t
	float  Trvanie;// tu bude vysledok merania

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD point = { 0,0 };
	while (true)
	{
		//ZOBRAZENIE TUTORIALU
		if (IsKeyPressed(VK_F1)) {
			point = {0,0};
			SetConsoleCursorPosition(hConsole, point);
			printf("Aplikacia sluzi na otestovanie rychlosti pisania zadanych znakov,\nstlacenim klavesi F2 spustite program a Vasou ulohou je zadat na klavesnici dany znak co najrychlejsie.");
			Sleep(1000);
		}
		//SAMOTNA HRA
		if (IsKeyPressed(VK_F2)) {
			znak = nahodne_cislo(65,90);
			system("cls");
			point = { 50,12 };
			SetConsoleCursorPosition(hConsole, point);
			start();
			point = { (short)nahodne_cislo(10,50),(short)nahodne_cislo(10,50) };
			SetConsoleCursorPosition(hConsole, point);
			printf("%c",znak);
			Start = clock();
			while (!IsKeyPressed(nahodne_cislo(65,90))) { ; }
			Koniec = clock();
			Trvanie = (float)(Koniec - Start) / CLOCKS_PER_SEC;
			point = { 30,14 };
			SetConsoleCursorPosition(hConsole, point);
			printf("Zadanie spravneho znaku ti trvalo: %.3lfs",Trvanie);
		}
		//UKONCENIE PROGRAMU
		if (IsKeyPressed(VK_ESCAPE)||(IsKeyPressed(VK_F10)))
		{
			system("cls");
			point = { 50,12 };
			SetConsoleCursorPosition(hConsole, point);
			printf("Koniec programu\n");
			break;
		}
	}

	getchar();
	return 0;
}