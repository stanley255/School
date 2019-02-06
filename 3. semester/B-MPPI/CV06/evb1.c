//******************************************************************************
// Routines for MSP-EXP430G2 Launchpad external evaluation board EVB1
//
// EVB1 pin connection:
// P1.2 => ST_CP (LED) - writing to output register
// P1.3 => OE (DISP) - display enable
// P1.4 => ST_CP (DISP) - writing to output register
// P1.5 => SH_CP (LED + DISP) - writing to shift register
// P1.6 => DS (LED + DISP) - serial data input
//******************************************************************************


#include <msp430.h>
#include "evb1.h"

void evb1_io_init(void)
{
	WDTCTL = WDTPW + WDTHOLD;                 	// Stop watchdog timer
	P1DIR |= 0x7C;								// Set P1.2-6 to output direction
	P1OUT = 0x00;								// P1 initialization
	OE_DISP_L;
}

void send_data_to_led(char num_to_led)
{
	short int i = 0;
	P1OUT = 0x00;
	for(i=0; i<8; i++)
	{
		if(((num_to_led << i) & BIT7) == BIT7) DS_H;  //evb1.h: #define DS_H  P1OUT |= BIT6 //(1 << 6)
		else DS_L; //#define DS_L P1OUT &= ~BIT6 //(1 << 6)
		asm("	nop");
		SH_CP_H;   // P1OUT |= BIT5 
		asm("	nop");
		SH_CP_L;   //P1OUT &= ~BIT5 
/*		asm("	nop"); //SPOMAL
		ST_CP_LED_H;   //SPOMAL
		asm("	nop"); //SPOMAL
		ST_CP_LED_L;   //SPOMAL
		delay(60000); //SPOMAL
*/
	}
	asm("	nop");
	ST_CP_LED_H;  //P1OUT |= BIT2 
	asm("	nop");
	ST_CP_LED_L;  //P1OUT &= ~BIT2 
}

void delay(long int i)
{
	do {(i--);
	asm("	nop");}
    while (i != 0);
}
