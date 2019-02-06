#include <stdio.h>
//Napíšte program v jazyku C, ktorý načíta zlomok v tvare a/b a upraví ho na tvar:
// x+y/z, kde y < z, gcd(y,z)=1. Využite funkciu gcd.

int gcd(int a, int b)
{
    int d;
    while (b != 0)
    {
        d = a % b;
        a = b;
        b = d;
    }
    return a;
}

void bad_fun()
{
    int a,b; //vstupne premenne
    int t; //temporary premenna
    int x,y,z; //vystupne premenne
    int e, w;
    //1. Nacitaj
    printf("Zadaj a:\n");
    scanf("%i",&a);
    printf("Zadaj b:\n");
    scanf("%i",&b);
    while (b == 0)
    {
        printf("Zadaj b:\n");
        scanf("%i",&b);
    }

    //2. Vypocitaj
    x = a/b;
    y = a%b;
    z = b;
    t = gcd(y,z);
    y = y/t;
    z = z/t;

    //3. Vypis
    printf("Vysledok: %i + %i/%i\n",x,y,z);

}

int main() {
    bad_fun();
    return 0;
}