//******************************************************************************
// Priklad nastavenia modulu generovania hodinovych signalov
//******************************************************************************

#include <msp430.h>
#include "osc_config.h"

short int i;

void blink(int n, long int time);
void delay(long int j);

void main(void)
{
	WDTCTL = WDTPW + WDTHOLD; // zastavenie casovaca watchdog

	P1DIR |= 0x41;           //nastav piny portu P1.0 and P1.6 ako vystupne,
							//funkcia ostatnych pinov portu sa nemeni

	P1OUT = 0x01;			// log.1 na P1.0 a log.0 na vsetky ostatne piny, teda aj na P1.6
	

	while(1){
		set_system_clk(LFXT1CLK, DCOCLK, div_1, DCOCLK, div_1, div_1);
		//povolene hodnoty parametrov funkcie su v subore "osc_config_c, riadok 28"
		//vstupne hodnoty funkcie mozu byt zapisane aj ako (vid definicie v osc_config.h):
		//v tomto pripade: set_system_clk(1,0,0,0,0,0,0);


		//__bis_SR_register(OSCOFF); //intrizicka funkcia - v registri SR nastav bit OSCOFF do log.1 (len tento jeden bit)
		// informacia pre buducnost
				
			blink(5, 20000); // 5-krat preblikni LED - zel-cerv-zel-cerv-zel-cerv-zel-cerv-zel-cerv-
							//cislo 20000 nevyjadruje cas ale pocet vykonani funkcie "void delay(long int j);"
			delay(20000);	// svit LED sa chvilu nemeni, (ostava svietit cervena)
		
			// druhe nastavenie zdroja hodinoveho signalu
  		set_system_clk(LFXT1CLK, DCOCLK, div_2, DCOCLK, div_1, div_1);


				
			blink(4, 10000);
			delay(10000);
		//sem vlozite dalsie dve nastavenia zdroja hodinoveho signalu podla zadania

		set_system_clk(LFXT1CLK, LFXT_VLO, div_1, LFXT_VLO, div_1, div_1);

			blink(5, 625); //625=20000/(1000000/32768)
			delay(625);



		set_system_clk(VLOCLK, LFXT_VLO, div_1, LFXT_VLO, div_1, div_1);



			blink(6, 225);
			delay(225);


			P1OUT = 0x00; // zhasni obe LED
			delay(50000); //@ fMCLK = 500kHz
						  // a nechaj chvilu zhasnute (aby sme videli, ze program sa nachadza prave tu)
			P1OUT = 0x01; // zapni cervenu LED
	}
}

void blink(int n, long int time)
{
	for(i=0;i<n;i++){
		P1OUT ^= 0x41; //bitova operacia exclusive OR.
						//0x41=0b01000001, instrukcia precita stav vsetkych pinov portu P1
						//nacitane hodnoty bit po bite X-OR -uje s 0x41, vysledok zapise na vsetky piny portu
						//co svietilo - zhasne, co bolo zhasnute zasvieti. Ale len na bitovej pozicii .0 a .6
						//teda tam, kde operand 0x41 obsahuje log. 1
		delay(time);
		P1OUT ^= 0x41;
		delay(time);
	}
}

/*void delay(long int j)
{
	do (j--);
	while (j != 0);
}
*/
void delay(long int j)
{
	do {(j--);
	asm("nop");	//funkcia musi obsahovat nejaku zmysluplnu instrukciu - staci aj assemblerovska "nop"
				//inak prekladac funkciu "void delay(long int j)" vobec neprelozi a program ju nebude
				//nikdy volat
	}
	while (j != 0);
}
