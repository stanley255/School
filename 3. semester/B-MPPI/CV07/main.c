//******************************************************************************
// MPP cv. 7
// Hodiny s LED displejom
//******************************************************************************

#include <msp430.h>
#include "evb1.h"
#include "osc_config.h"

//unsigned char display[4] = {15,10,10,10};
unsigned char display[4] = {0,0,0,0};
unsigned char des_bod = 0, jm, dm, js, ds;
unsigned int time = 0;
unsigned int pos=0;

void main(void)
{
	evb1_io_init();
	
	set_system_clk(LFXT1CLK, DCOCLK, div_1, LFXT_VLO, div_1, div_8); // SMCLK div_4 pre 1 segment "a"

	CCR0 = 200;
	TACTL = TASSEL_2 + MC_2;				// zdroj hodin pre citac je SMCLK, kontinualne pocitanie nahor
	CCTL0 = CCIE;							// povolenie prerusenia od CCR0
	
	_BIS_SR(LPM0_bits + GIE);				// vstup do LPM0, povolenie vsetkych maskovatelnych preruseni
}

// obsluzna rutina od casovaca Timer A0   //CCS V6.2.0: 2231: TIMERA0_VECTOR, 2553: TIMER0_A0_VECTOR
#pragma vector = TIMERA0_VECTOR           // CCS V5.5.0: 2231: TIMERA0_VECTOR, 2553: TIMER0_A0_VECTOR
__interrupt void Timer_A_CCR0 (void)
{
	// aktualizacia casovych registrov
	send_data_to_disp(display,des_bod);
	display[0]++;


	if (display[0]==10){
		display[0]=0;
		display[1]++;
		if (display[1]==10){
			display[1]=0;
			display[2]++;
			if (display[2]==10){
				display[2]=0;
				display[3]++;
				if (display[3]==10){
					display[3]=0;
				}
			}
		}
	}



	CCR0 += 32768;						// zvacsi CCR0 o deltu
}										// perioda bude presne 1 sekunda
