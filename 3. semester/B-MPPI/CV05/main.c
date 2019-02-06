//******************************************************************************
// MPT cv.5
// Timer_A, Toggle P1.0, CCR0, Cont. mode ISR, DCO, ACLK/4
//******************************************************************************

#include <msp430.h>
#include "osc_config.h"

char i = 0;

void main(void)
{
	WDTCTL = WDTPW + WDTHOLD;		// zastav WDT
	
	// System clock settings
	// LFXT_VLO_mode = LFXT1CLK or VLOCLK
	// MCLK_src = DCOCLK or LFXT_VLO
	// MCLK_div = div_1, div_2, div_4, div_8
	// SMCLK_src = DCOCLK or LFXT_VLO
	// SMCLK_div = div_1, div_2, div_4, div_8
	// ACLK_div = div_1, div_2, div_4, div_8
	set_system_clk(LFXT1CLK, DCOCLK, div_1, LFXT_VLO, div_1, div_4);
	// potom budu hodinove signaly nastavene nasledovne:
	//DCOCLK -> /1 -> MCLK -> CPU,
	//VLOCLK -> /4 -> ACLK,
	//VLOCLK -> /1 -> SMCLK
	//nastavit podla zadania, skomentovat v zavere elab(zmena VCOCLK na LFXT1CLK)

	P1DIR |= 0x41;							// piny P1.0 a P1.6 nastav ako vystupy
	P1OUT = 0x00;							// vynuluj vsetky bity, piny portu P1
	P1IES = BIT3;

	P1IE = BIT3;
	//nastavenie registrov casovaca	 T_A
		// pocitadlo TAR po resete nepocita, je neaktivne

	CCR0 = 3000;							// komparacny register CCR0
											//startovacia hodnota, nezavisi od nej frekvencia
											// blikania LED
											// pocitadlo TAR bude pocitat do hodnoty 0xffff
											// potom opat od nuly
	CCR1 = 3000;


	CCTL0 = CCIE;							// povolenie prerusenia od priznaku nastatia rovnosti obsahu TAR a CCR0
	CCTL1 = CCIE;							// povolenie prerusenia od priznaku nastatia rovnosti obsahu TAR a CCR1

	TACTL = TASSEL_2 + MC_2;				// hodinovy signal SMCLK je zdrojom impulzov pre pocitadlo TAR,
											// start pocitania pocitadla je v mode kontinualneho pocitania (od  0 do 0xffff)
											// skontrolovat parametre podla zadania, skomentovat v zavere
	
	_BIS_SR(LPM0_bits + GIE);				// prechod do modu LPM0, vsetky maskovatelne prer. povolit
											// vypneme len MCLK, LFXT1CLK musi ostat bezat, lebo napaaja casovac

}

//cervena LED
// Obsluzny program casovaca T_A0 // priznak TACCTL0_CCIFG
#pragma vector = TIMERA0_VECTOR //zmena z TIMER_A0_VECTOR na TIMERA0_VECTOR
__interrupt void Timer_A_CCR0 (void)
{
	P1OUT ^= 0x01;							// zmen log. stav na P1.0
	CCR0 += 4915;							// pripocitaj hodnotu delta k obsahu CCR0
											// frekvencia zavisi od hodnoty delta
}

//zelena LED
// Obsluzny program casovaca T_A0 // priznak TACCTL0_CCIFG
#pragma vector = TIMERA1_VECTOR
__interrupt void Timer_A_CCR1 (void)
{
	CCTL1&=~CCIFG;							//mazanie priznakov
	P1OUT ^= 0x40;							// zmen log. stav na P1.6
	CCR1 += 6553;							// pripocitaj hodnotu delta k obsahu CCR1
											// frekvencia zavisi od hodnoty delta

}

#pragma vector = PORT1_VECTOR
__interrupt void Blikanie (void)
{
	P1OUT = 0x00;
	switch(i){
	case 0:
		CCTL0 = CCIE;
		CCTL1 =~ CCIE;
		i = 1;
		break;
	case 1:
		CCTL0 =~ CCIE;
		CCTL1 = CCIE;
		i = 2;
		break;
	case 2:
		CCTL0 = CCIE;
		CCTL1 = CCIE;
		i = 3;
		break;
	case 3:
		CCTL0 =~ CCIE;
		CCTL1 =~ CCIE;
		i = 0;
		break;
	}
	P1IFG&=~BIT3;

}
