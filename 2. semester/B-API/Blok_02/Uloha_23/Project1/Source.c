#include <stdio.h>
#include <windows.h>
#define HORIZONTALNA 205
#define ZVISLA 186

void horna_ciara(int x, int y, int dlzka) {
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = x; i < dlzka; i++) {
		COORD point = { i,y };
		SetConsoleCursorPosition(hConsole, point);
		putchar(HORIZONTALNA);
	}
}

int main(int argc, char* argv[]) {
	char meno[] = { "Stano" };
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	

	//LAVA CAST CIARY
	horna_ciara(5,5,10);
	//ROZDELOVANIE
	COORD point = { 10,5 };
	SetConsoleCursorPosition(hConsole, point);
	putchar(203);
	point.X = 10; point.Y = 11;
	putchar("");
	printf("\nMeno:");
	//printf("Vyska:");
	//printf("Hmotnost:");
	//printf("Tel:");


	getchar();
	return 0;
}