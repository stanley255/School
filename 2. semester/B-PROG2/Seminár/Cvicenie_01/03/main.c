#include <stdio.h>

int main() {
    int c1,c2;
    int plus,minus,krat,deleno,zvysok;
    scanf("%i",&c1);
    printf("%i\n",c1);
    scanf("%i",&c2);
    printf("%i\n",c2);
    plus = c1+c2;
    minus = c1-c2;
    krat = c1*c2;
    deleno = c1/c2;
    zvysok = c1%c2;
    printf("%i+%i=%i\n",c1,c2,plus);
    printf("%i-%i=%i\n",c1,c2,minus);
    printf("%i*%i=%i\n",c1,c2,krat);
    printf("%i/%i=%i, zvysok %i\n",c1,c2,deleno,zvysok);
    return 0;
}