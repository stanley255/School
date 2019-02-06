#pragma comment( lib, "winmm" )
#include <stdio.h>
#include <windows.h>
#include <string.h>
#define _CRT_SECURE_NO_DEPRECATE

int main() {
	char subor[20], prikaz[20] = {""};
	int volba;

	do {
		printf("\nC Prehravac\nVyber si z nasledujucej ponuky\n1.Volba suboru\n2.Play\n3.Pause\n4.Close\nNapis volbu: ");
		scanf("%i",&volba);
		getchar();
		switch (volba) {
		case 1:
			memset(subor, 0, strlen(subor));
			memset(prikaz, 0, strlen(prikaz));
			printf("\nZadaj nazov subora: ");
			fgets(subor, sizeof(subor), stdin);
			strtok(subor, "\n");
			strcat(prikaz, "open ");
			strcat(prikaz, subor);
			strcat(prikaz, " alias file1");
			mciSendString(prikaz, NULL, 0, NULL);
			break;
		case 2:
			mciSendString("play file1", NULL, 0, NULL);
			break;
		case 3:
			mciSendString("pause file1", NULL, 0, NULL);
			break;
		case 4:
			mciSendString("close file1", NULL, 0, NULL);
			break;
		default:
			break;
		}
	} while (1);

	return 0;
}