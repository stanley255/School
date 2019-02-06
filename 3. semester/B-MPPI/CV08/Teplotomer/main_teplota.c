//******************************************************************************
// MPT CV. 8
// Meranie teploty cipu procesora MSP430
//******************************************************************************

#include <msp430.h>
#include "evb1.h"

void main(void)
{
	float temperature = 0;
	long int temp=0;
	unsigned char display[4] = {0,0,0,0};
	
	evb1_io_init();

	ADC10CTL1 = INCH_10 + ADC10DIV_3;         	// pripoj vstup c.10 - interny senzor teploty,
												// hodinovy signal bude ADC10CLK/4
	ADC10CTL0 = SREF_1 + ADC10SHT_3 + REFON + ADC10ON + ADC10IE; //je tu = (vsetky bity su ovplyvnenee)
												//Vref+ = vnutorny zdroj ref.U, Vref- = 0V
												// cas "sample" = 64/(ADC10CLK/4)
												// zapni vnutorny zdroj referncneho napatia (ref.U)
												// zapni modul ADC, povol ISR
							//bit REF2_5V = 0 -> ref.U=1.5V


	__delay_cycles(1000);           // cakanie na ustalenie zdroja ref.U po zapnuti ADC modulu

	while(1)
	{
		ADC10CTL0 |= ENC + ADC10SC;				// povolenie prevodu, start prevodu,

		__bis_SR_register(CPUOFF + GIE);		// uvedenie do LPM0, celkove povolenie ISR
												// v ISR ale dojde ku modifikacii kopie bitov SR v zasobniku
												// program preto bude pokracovat dalej

		//temperature = 10*(ADC10MEM * 0.00146 - 0.986)/0.0035;

		temp=ADC10MEM;
		temp*=41;
		temp-=27775;


/*		temperature = ADC10MEM;
		temperature *= 15;
		temperature /= 1023;
		temperature /= 10;
		temperature *= 100000;
		temperature -= 98600;
		temperature /= 355;
		temperature *= 100;
*/
		int_to_bcd(display, (int) temp);

		send_data_to_disp(display, 3);
		delay(15000);
	}
}

// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
	__bic_SR_register_on_exit(CPUOFF);			// Clear CPUOFF bit from 0(SR)
											// Nastav bit CPUOFF nulu v odloženej kópii SR
											// kópia je odložená v zásobníku
}
