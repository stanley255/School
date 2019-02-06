#include <stdio.h>
//Napíšte program v jazyku C, ktorý načíta dve celočíselné premenné a vypíše ich súčet, rozdiel, súčin a podiel.
int main() {
    //Nacitanie premennych
    int a, b, c, d, e;
    printf("Zadaj a: \n");
    scanf("%i",&a);
    printf("Zadaj b: \n");
    scanf("%i",&b);
    //Vypisanie suctu
    c = a + b;
    printf("%i + %i = %i\n",a,b,c);
    //Vypisanie rozdielu
    c = a - b;
    printf("%i - %i = %i\n",a,b,c);
    //Vypisanie podielu
    d = a/b;
    e = a%b;
    printf("%i/%i = %i zv. %i", a, b, d, e);

    return 0;
}