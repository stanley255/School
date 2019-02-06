//***********************************************************
// Mikroprocesorova technika
// Cvicenie c. 11
// Riadenie inteligentneho alfanumerickeho displeja DEM16217 - dvojriadkovy
// Evaluation board 2 for MSP-EXP430G2
//***********************************************************

#include <msp430g2231.h>
#include "evb2.h"

const unsigned char text1[] = " JEZIS JE CESTA "; //"Mikroprocesorov" "\x0A";
const unsigned char text2[] = " JEZIS JE LASKA ";

void main(void)
{
	char i = 0;
	
	evb2_io_init();
	
	lcd_init();
//	lcd_clear();
//	lcd_puts(&text1[0]);
//	lcd_goto(0x40);
//	lcd_puts(&text2[0]);
//	LCD_RS_L;
//	lcd_write(0x8);
//	while(1){
		lcd_clear();
		lcd_puts(&text1[0]);\
		lcd_write(0x8);

		__delay_cycles(500000);

		lcd_clear();
		lcd_goto(0x40);
		lcd_puts(&text2[0]);
		lcd_write(0x0C);
		__delay_cycles(500000);

		lcd_clear();
		lcd_puts(&text1[0]);
		lcd_goto(0x40);
		lcd_puts(&text2[0]);
		lcd_write(0x0C);
		__delay_cycles(500000);
	}
//	while(1)
//	{
//		for(i=0;i<16;i++)
//		{
//			__delay_cycles(250000);
//			lcd_write(0x1C);
//		}
//		for(i=0;i<33;i++)
//		{
//			__delay_cycles(250000);
//			lcd_write(0x18);
//		}
//		for(i=0;i<17;i++)
//		{
//			__delay_cycles(250000);
//			lcd_write(0x1C);
//		}
//	}
}
