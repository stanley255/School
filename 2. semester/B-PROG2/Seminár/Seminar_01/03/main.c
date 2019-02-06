#include <stdio.h>
//Napíšte program v jazyku C, ktorý načíta zlomok v tvare a/b
//a upraví ho na tvar: x+y/z, kde y < z, gcd(y,z)=1. Využite funkciu gcd.

int gcd(int a, int b)
{
    int c;
    while (b!=0)
    {
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    int a, b;
    int x, y, z;
    int t;
    scanf("%i",&a);
    scanf("%i",&b);

    t = gcd(a,b);
    x = a/b;
    y = a%b;
    y = y/t;
    z = b/t;

    printf("%i/%i = %i + %i/%i",a,b,x,y,z);

    return 0;
}