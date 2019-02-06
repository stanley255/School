
//****************************************************************************************
// After a PUC (Power-Up Clear) reset, MCLK and SMCLK are sourced from DCOCLK at ~1.1MHz
// and ACLK is sourced from LFXT1CLK in LF mode with an internal load capacitance of 6pF.
//****************************************************************************************

#include <msp430.h>
#include "osc_config.h"

// Digital controlled oscillator settings
// DCO_FREQ = 1MHz (callibrated frequency)
void enable_DCO(void)
{
	BCSCTL1 = CALBC1_1MHZ;		// Set range
	DCOCTL = CALDCO_1MHZ;		// Set DCO step + modulation
	__bic_SR_register(SCG0);    // enable DCO oscillator
}

void enable_LFXT1OSC(void)
{
	__bic_SR_register(OSCOFF);                         // enable LFXT1 oscillator
	do {
	   IFG1 &= ~OFIFG;
	   __delay_cycles(50);
	   } while((IFG1&OFIFG));                          // wait for stable clock
}

// System clock settings
// LFXT_VLO_mode = LFXT1CLK or VLOCLK
// MCLK_src = DCOCLK or LFXT_VLO
// MCLK_div = div_1, div_2, div_4, div_8
// SMCLK_src = DCOCLK or LFXT_VLO
// SMCLK_div = div_1, div_2, div_4, div_8
// ACLK_div = div_1, div_2, div_4, div_8
void set_system_clk(unsigned char LFXT_VLO_mode, unsigned char MCLK_src, unsigned char MCLK_div, unsigned char SMCLK_src, unsigned char SMCLK_div, unsigned char ACLK_div)
{
	switch(LFXT_VLO_mode){
		case LFXT1CLK :
			enable_LFXT1OSC();
			BCSCTL3 &= ~(LFXT1S1|LFXT1S0);
		break;
		case VLOCLK :
			BCSCTL3 |= LFXT1S1;
		break;
		default :
			enable_LFXT1OSC();
			BCSCTL3 &= ~(LFXT1S1|LFXT1S0);
		break;
	}
	
	switch(MCLK_src){
		case DCOCLK :
			enable_DCO();
			BCSCTL2 &= ~(SELM1|SELM0);
		break;
		case LFXT_VLO :
			BCSCTL2 |= (SELM1|SELM0);
		break;
		default :
			enable_DCO();
			BCSCTL2 &= ~(SELM1|SELM0);
		break;
	}
	
	switch(MCLK_div){
		case div_1 :
			BCSCTL2 &= ~(DIVM1|DIVM0);
		break;
		case div_2 :
			BCSCTL2 |= DIVM0;
		break;
		case div_4 :
			BCSCTL2 |= DIVM1;
		break;
		case div_8 :
			BCSCTL2 |= (DIVM1|DIVM0);
		break;
		default:
			BCSCTL2 &= ~(DIVM1|DIVM0);
		break;
	}
	
	switch(SMCLK_src){
		case DCOCLK :
			enable_DCO();
			BCSCTL2 &= ~SELS;
		break;
		case LFXT_VLO :
			BCSCTL2 |= SELS;
		break;
		default :
			enable_DCO();
			BCSCTL2 &= ~SELS;
		break;
	}
	
	switch(SMCLK_div){
		case div_1 :
			BCSCTL2 &= ~(DIVS1|DIVS0);
		break;
		case div_2 :
			BCSCTL2 |= DIVS0;
		break;
		case div_4 :
			BCSCTL2 |= DIVS1;
		break;
		case div_8 :
			BCSCTL2 |= (DIVS1|DIVS0);
		break;
		default:
			BCSCTL2 &= ~(DIVS1|DIVS0);
		break;
	}
	
	switch(ACLK_div){
		case div_1 :
			BCSCTL1 &= ~(DIVA1|DIVA0);
		break;
		case div_2 :
			BCSCTL1 |= DIVA0;
		break;
		case div_4 :
			BCSCTL1 |= DIVA1;
		break;
		case div_8 :
			BCSCTL1 |= (DIVA1|DIVA0);
		break;
		default:
			BCSCTL1 &= ~(DIVA1|DIVA0);
		break;
	}
	
	/*if((MCLK_src != DCOCLK)&&(SMCLK_src != DCOCLK))
                  __bis_SR_register(SCG0);                 // disable DCO oscillator

  	if((MCLK_src != LFXT1CLK)&&(SMCLK_src != LFXT1CLK))
                  __bis_SR_register(OSCOFF);               // disable LFXT1 oscillator*/
}
