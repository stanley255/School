#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int beh()       //funkcia, ktora vracia nahodne cislo z <0;25>, ktore sa v tele programu pripisuje bezcom
{
    int a = 0, b = 25;
    int randint;
    randint = rand()%(b-a+1)+a;
    return randint;
}

int zhodenie_prekazky(int bezec_1, int bezec_2)     //funkcia, ktora vyhodnocuje, ci niekto/obaja zhodil/li prekazku
{
    if ((bezec_1%50==0 && bezec_1!=400 && bezec_1!=0)&&(bezec_2%50==0 && bezec_2!=400 && bezec_2!=0))
    {
        printf("Obaja bezci su vyradeni z preteku!");
        return 1;
    }
    if (bezec_1%50==0 && bezec_1!=400 && bezec_1!=0)
    {
        printf("Bezec 1 zhodil prekazku a je vyradeny!\n");
        printf("Bezec 2 vyhral pretek!!!\n");
        return 1;
    }
    if (bezec_2%50==0 && bezec_2!=400 && bezec_2!=0) {
        printf("Bezec 2 zhodil prekazku a je vyradeny!\n");
        printf("Bezec 1 vyhral pretek!!!\n");
        return 1;
    }
    return 0;
}

void vyhodnotenie(int bezec_1, int bezec_2)  //procedura, ktora vybera vitaza
{                                            //aby bol beh fer, tak pokial obaja prekrocia v jednom "tahu" 400m
    if (bezec_1>bezec_2)                     //tak za vitaza sa pocita bezec, ktory dobehol dalej
    {
        printf("Vyhral bezec 1!!!");
    }
    else
    {
        printf("Vyhral bezec 2!!!");
    }
}

int finish(int bezec_1, int bezec_2)                //funkcia, ktora ukoncuje while cyklus
{                                                   //za predpokladu, ze bezec/i zhodil/i prekazku
    if (zhodenie_prekazky(bezec_1,bezec_2)==1)      //alebo sa niekto dostal do ciela
    {
        return 1;
    }
    if (bezec_1>=400)
    {
        vyhodnotenie(bezec_1,bezec_2);
        return 1;
    }
    if (bezec_2>=400){
        vyhodnotenie(bezec_1,bezec_2);
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    //1. Inicializacia
    int bezec_1,bezec_2,zaver;
    bezec_1 = 0;
    bezec_2 = 0;
    zaver = 0;
    printf("3! 2! 1!START!\n");
    //2.,3.,4. Beh, Prekazky, Vitazstvo
    while (zaver==0) {
        bezec_1 += beh();
        bezec_2 += beh();
        printf("Bezec 1: %i m\n", bezec_1);
        printf("Bezec 2: %i m\n", bezec_2);
        zaver = finish(bezec_1, bezec_2);
    }

    return 0;
}