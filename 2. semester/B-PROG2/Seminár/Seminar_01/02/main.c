#include <stdio.h>
//Napíšte funkciu v jazyku C, ktorý vypočíta najväčší spoločný deliteľ dvoch čísel (gcd). Otestujte ju v krátkom programe.

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

int main()
{
    int a, b, c;
    printf("Zadaj a:\n");
    scanf("%i",&a);
    printf("Zadaj b:\n");
    scanf("%i",&b);
    c = gcd(a,b);
    printf("%i",c);
    return 0;
}