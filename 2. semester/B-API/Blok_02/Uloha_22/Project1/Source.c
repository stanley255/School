#include <stdio.h>
#include <windows.h>
#include <time.h>

int main(int argc, char* argv[]) {
	int i = 0;
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//POMOCNA FUNKCIA PRE VYPIS VSETKYCH TEXTATTRIBUTOV OD 0 PO 255
	for (int i = 0; i < 255; i++) {
		SetConsoleTextAttribute(hConsole, i);
		printf("%i: ABC\n",i);
	}
	/*SetConsoleTextAttribute(hConsole, 10);
	for (i; i < 10; i++) {
		if (i == 3) {
			SetConsoleTextAttribute(hConsole, 12);
		}
		else if (i == 8) {
			SetConsoleTextAttribute(hConsole, 11);
		}
		printf("00%i\n",i);
		Sleep(1000);
	}
	printf("0%i",i);*/


	getchar();
	return 0;
}
