//******************************************************************************
// Routines for MSP-EXP430G2 Launchpad external evaluation board 1
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
	WDTCTL = WDTPW + WDTHOLD;              	// Stop watchdog timer
	P1DIR |= 0x7C;							// Set P1.2-6 to output direction
	P1OUT = 0x00;							// P1 initialization
	OE_DISP_L;
}

void send_data_to_led(unsigned char num_to_led)
{
	short int i = 0;
	P1OUT = 0x00;
	for(i=0; i<8; i++)
	{
		if(((num_to_led << i) & BIT7) == BIT7) DS_H;
		else DS_L;
		asm("	nop");
		SH_CP_H;
		asm("	nop");
		SH_CP_L;
	}
	asm("	nop");
	ST_CP_LED_H;
	asm("	nop");
	ST_CP_LED_L;
}

void send_data_to_disp(unsigned char *disp, unsigned char point)
{
	char i = 0, j = 0;
//	char disp[4];
	for(i=0; i<4; i++)
	{
		switch(*(disp+i))
		{
		case 0:
	        *(disp+i) = ~0x3F;
	        break;
	    case 1 :
	        *(disp+i) = ~0x06;
	        break;
	    case 2 :
	        *(disp+i) = ~0x5B;
	        break;
		case 3 :
	        *(disp+i) = ~0x4F;
	        break;
	    case 4:
	        *(disp+i) = ~0x66;
	        break;
	    case 5 :
	        *(disp+i) = ~0x6D;
	        break;
	    case 6 :
	        *(disp+i) = ~0x7D;
	        break;
		case 7 :
	        *(disp+i) = ~0x07;
	        break;
	    case 8 :
	        *(disp+i) = ~0x7F;
	        break;
	    case 9 :
	        *(disp+i) = ~0x6F;
	        break;
	    default :
	    	*(disp+i) = ~0x00;
		}
	}
	
	switch(point)
		{
		case 1:
	        *(disp+0) &= ~BIT7;
	        break;
	    case 2 :
	        *(disp+1) &= ~BIT7;
	        break;
	    case 3 :
	        *(disp+2) &= ~BIT7;
	        break;
		case 4 :
	        *(disp+3) &= ~BIT7;
	        break;
	    default :
	    	*(disp+0) |= BIT7;
	    	*(disp+1) |= BIT7;
	    	*(disp+2) |= BIT7;
	    	*(disp+3) |= BIT7;
		}

	P1OUT = 0;
	for(i=0; i<4; i++)
	{
		for(j=0; j<8; j++)
		{
			if (((*(disp+i) << j) & BIT7) == BIT7) DS_H;
			else DS_L;
			asm("	nop");
			SH_CP_H;
			asm("	nop");
			SH_CP_L;
		}
	}
	asm("	nop");
	ST_CP_DISP_H;
	asm("	nop");
	ST_CP_DISP_L;
}

void int_to_bcd(unsigned char *disp, unsigned int num)
{
	*(disp+3) = num/1000;
	*(disp+2) = (num - *(disp+3)*1000)/100;
	*(disp+1) = (num - *(disp+3)*1000 - *(disp+2)*100)/10;
	*disp = num - *(disp+3)*1000 - *(disp+2)*100 - *(disp+1)*10;
}

void delay(long int i)
{
	do {i--;
        asm("nop");}
    while (i != 0);
}
