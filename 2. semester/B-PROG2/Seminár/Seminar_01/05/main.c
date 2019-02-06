#include <stdio.h>
//Napíšte funkciu, ktorá nájde najbližší deliteľ čísla x väčší ako y. Otestujte ju v krátkom programe (načíta vstupy, vypíše výstupy).
int main() {
    int x,y,del;
    int i;
    scanf("%i",&x);
    scanf("%i",&y);

    for(i=y; i<x; i=i+1)
    {
        if (x%i==0)
        {
            del = i;
        }
    }
    printf("%i",del);

    return 0;
}