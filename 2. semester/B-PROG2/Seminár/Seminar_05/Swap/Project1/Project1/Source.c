#include <stdio.h>

//Napíšte funkciu, ktorej vstupom sú 2 adresy typu (void*) a size - ve¾kos údaju v bajtoch. Funkcia prehodí obsah pamäte na tıchto adresách.
//Návod: pretypujte smerníky na char*, opakujte size - krát : prehahoïte bajt na danom mieste(napr.pomocou extra premennej), 
//zvıšte hodnotu kadého smerníku o 1.

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