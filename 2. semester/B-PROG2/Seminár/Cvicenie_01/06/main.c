#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int my_number,nahodne_cislo,rozdiel,max;
    scanf("%i",&my_number);
    if (my_number>0){
        printf("%i",my_number);
    }
    else{
        max = 100;
        rozdiel = -1*my_number;
        srand(time(NULL)); // inicializacia generatora
        nahodne_cislo = rand()%(rozdiel-max+1)+max;
        my_number = my_number + nahodne_cislo;
        printf("%i",my_number);
    }

    return 0;
}