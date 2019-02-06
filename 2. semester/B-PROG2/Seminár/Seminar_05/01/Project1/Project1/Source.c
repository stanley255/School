#include <stdio.h>

//Nap�te funkciu, ktorej vstupom je adresa typu (void*) a size - ve�kos� �daju v bajtoch. 
//Funkcia vyp�e postupne bajty na danej adrese v hexadecim�lnom tvare. 
//Pou�ite t�to funkciu na v�pis premenn�ch r�zneho typu (napr. unsigned int i = 0xdeadbeef; double pi = 3.14), 
//pr�padne vysk��ajte aj so smern�kom na funkciu/pole.

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