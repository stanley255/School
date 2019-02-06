#include <stdio.h>

//Nap�te funkciu, ktorej vstupom s� 2 adresy typu (void*) a size - ve�kos� �daju v bajtoch. Funkcia prehod� obsah pam�te na t�chto adres�ch.
//N�vod: pretypujte smern�ky na char*, opakujte size - kr�t : prehaho�te bajt na danom mieste(napr.pomocou extra premennej), 
//zv��te hodnotu ka�d�ho smern�ku o 1.

void swap(void *p1, void *p2, int size) {
	char *s1, *s2;
	char temp;
	s1 = p1; s2 = p2;
	for (int i = 0; i < size; i++) {
		temp = *s1;
		*s1 = *s2;
		*s2 = temp;
		s1++; s2++;
	}
}

int main() {
	double a = 5.456789, b = 4.652;
	printf("%lf %lf\n",a,b);
	swap(&a,&b,sizeof(a));
	printf("%lf %lf\n", a, b);
	getchar();
	return 0;
}