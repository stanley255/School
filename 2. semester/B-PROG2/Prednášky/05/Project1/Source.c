#include <stdio.h>
#define MAXPOLE 100

//int pole[MAXPOLE];
//void vypisPole(int *pole, int n)
//CONST zabezpeci, ze pole je read-only
void vypisPole(const int pole[], int n) {  //ODKAZ NA PRVY PRVOK POLA, NIE POLE SAMOTNE
	for (int i = 0; i < n; i++) {
		printf("%i ",i,pole[i]);
	}
	printf("\n");
}

void nacitajPole(int pole[], int n) {
	printf("Zadaj n prvkov:");
	for (int i = 0; i < n; i++) {
		scanf_s("%i", &pole[i]);
		getchar();
	}
	printf("\n");
}

int main() {
	int n;
	int field[] = {1,2,3,4,5};
	int k = 3;
	n = sizeof(field) / sizeof(field[0]);
	printf("Velkost: %i\n",n);	
	vypisPole(field, n);
	vypisPole(&field[1], n-1);
	//vypisPole(field+1, n-1);
	vypisPole(field+n-k, k);
	for (k = 0; k <= n; k++) {
		vypisPole(field, k);
	}
	nacitajPole(field,5);
	vypisPole(field, 5);
	getchar();
	return 0;
}