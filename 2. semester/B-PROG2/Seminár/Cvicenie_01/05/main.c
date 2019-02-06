#include <stdio.h>

void parne(int stop_number)
{
    int cislo = 0;
    while (cislo<stop_number)
    {
        printf("%i\n",cislo);
        cislo = cislo + 2;
    }
}

int main() {
    int stop_number;
    scanf("%i",&stop_number);
    parne(stop_number);
    return 0;
}