#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void aritmetika(int c1, int c2)
{
    int plus,minus,krat,deleno,zvysok;
    plus = c1+c2;
    minus = c1-c2;
    krat = c1*c2;
    deleno = c1/c2;
    zvysok = c1%c2;
    printf("%i+%i=%i\n",c1,c2,plus);
    printf("%i-%i=%i\n",c1,c2,minus);
    printf("%i*%i=%i\n",c1,c2,krat);
    printf("%i/%i=%i, zvysok %i\n",c1,c2,deleno,zvysok);
}

int generujCislo(int a, int b)
{
    int nahodne_cislo;
    srand(time(NULL));
    nahodne_cislo = rand()%(b-a+1)+a;
    return nahodne_cislo;
}

int main() {
/*
    //CAST A
    int c1,c2;
    scanf("%i",&c1);
    printf("%i\n",c1);
    scanf("%i",&c2);
    printf("%i\n",c2);
    aritmetika(c1,c2);
*/
    //CAST B
    int a,b,nc;
    scanf("%i",&a);
    scanf("%i",&b);
    nc = generujCislo(a,b);
    printf("%i",nc);
    return 0;
}
