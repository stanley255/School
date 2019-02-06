#include <msp430.h>

void main(void)
{
	WDTCTL = WDTPW + WDTHOLD;				// deaktivacia watchdog-u
	P1DIR |=BIT0|BIT6;
	//P1DIR = ~BIT6;										// vsetky P1.x nastavene ako vystupy, P1.3 nastaveny ako vstup
	P1OUT = 0x00;							// nulovanie portu P1
	P1IES = BIT3;							// ext. prerusenie od P1.3 aktivne pri zostupnej hrane, t.j.
											// zmena z log.1 do log.0
	P1IE = BIT3;							// povolenie prerusenia od P1.3
	_BIS_SR(GIE + LPM0_bits);				// povolenie vsetkych maskovatelnych preruseni a sucasne
											// vstup do nizkoprikonoveho rezimu LPM0
	while(1);								//dostane sa sem program?
}
//#pragma vector = 2 //da sa aj takto zapisat
					// pozri v projekte subor .../ccsv5/ccs_base/msp430/include/msp430g2231.h
#pragma vector = PORT1_VECTOR
__interrupt void port1 (void)
{
	//P1IFG &= ~BIT3;					// zmazanie, nulovanie priznaku prerusenia od P1.3

	volatile unsigned int i, j; //po skonceni  ISR su premenne i,j stale v pamati
	P1OUT = 0x40;						//zasviet zelenu LED
	for (j=16; j > 0; j--){
		P1OUT ^= 0x41;					// zmena stavu oboch LED
		for (i = 20000; i > 0; i--);	// oneskorenie
		}
	P1OUT = 0x00;						// zhasnutie oboch LED
	P1IFG &= ~BIT3;						// zmazanie, nulovanie priznaku prerusenia od P1.3
}
