//********************************************************************
// Routines for MSP-EXP430G2 Launchpad external evaluation board EVB2
// Library for SPI and DAC TLV5636
//
// TLV5636 pins connections:
//
// P1.4 => FS - Frame Sync Input
// P1.5 => SCLK - Serial Clock
// P1.6 => DIN - Serial Data Input
// P1.7 (SDI) => connected to GND
//********************************************************************

#include <msp430.h>
#include "evb2.h"

void evb2_io_init(void)
{
	WDTCTL = WDTPW + WDTHOLD;              	// Stop watchdog timer
	P1OUT = 0x00;							// P1 initialization
	P1DIR |= 0x70;							// Set P1.4-6 to output and any others to input direction
}

void evb2_spi_init(void)
{
	USICTL0 |= USIPE7|USIPE6|USIPE5|USIMST|USIGE|USIOE;			// USI port settings, SPI master, output enabled
	USICTL1 = 0x00;
	USICKCTL |= USIDIV_0|USISSEL_2|USICKPL;						// SMCLK/1
	USICTL0 &= ~USISWRST;										// USI released for operation
}

void fs_strobe(void)
{
	FS_H; //P1OUT |= BIT4
	asm("	nop");
	FS_L; //P1OUT &= ~BIT4
}
