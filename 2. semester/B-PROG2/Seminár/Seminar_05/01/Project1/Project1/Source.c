#include <stdio.h>

//Napíšte funkciu, ktorej vstupom je adresa typu (void*) a size - ve¾kos údaju v bajtoch. 
//Funkcia vypíše postupne bajty na danej adrese v hexadecimálnom tvare. 
//Pouite túto funkciu na vıpis premennıch rôzneho typu (napr. unsigned int i = 0xdeadbeef; double pi = 3.14), 
//prípadne vyskúšajte aj so smerníkom na funkciu/pole.

void fun(void *p1, int size) {
	char * s1 = p1;
	size++;
	for (int i = 1; i < size; i++) {
		printf("%i. bajt: %x\n",i,*s1 & 0xff);
		s1++;
	}
}

int main() {
	double pi = 3.14;
	unsigned int i = 0xdeadbeef;
	fun(&i,sizeof(i));

	getchar();
	return 0;
}