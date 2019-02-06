#include <stdio.h>
//Napíšte program v jazyku C, ktorý načíta 2 zlomky
// v tvare a/b a c/d a dá ich na spoločný menovateľ:
// vypíše x/y a z/y. Využite funkciu gcd.

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

int main() {
    int a,b,c,d;
    int x,y,z;
    int sm, t_1, t_2, res;
    scanf("%i",&a);
    scanf("%i",&b);
    scanf("%i",&c);
    scanf("%i",&d);
    printf("%i/%i, %i/%i\n",a,b,c,d);
    sm = b*d;
    t_1 = a*d;
    t_2 = c*b;
    res = gcd(t_1,sm);
    printf("%i\n",res);
    a = t_1/res;
    b = sm/res;
    res = gcd(t_2,sm);
    printf("%i\n",res);
    c = t_2/res;
    d = sm/res;
    printf("%i/%i, %i/%i",a,b,c,d);

    return 0;
}