//********************************************************************
// Routines for MSP-EXP430G2 Launchpad external evaluation board EVB2
// Library for LCD display
//
// LCD display pins connections:
// P1.0 => LCD_RS - LCD display register select input
// P1.1 => LCD_EN - LCD display enable input
// P1.4 => DB4 - LCD display data bus pin 4
// P1.5 => DB5 - LCD display data bus pin 5
// P1.6 => DB6 - LCD display data bus pin 6
// P1.7 => DB7 - LCD display data bus pin 7
//********************************************************************

#include <msp430g2231.h>
#include "evb2.h"

void evb2_io_init(void)
{
	WDTCTL = WDTPW + WDTHOLD;              	// Stop watchdog timer
	P1DIR |= 0xF3;							// Set P1.0, P1.1 and P1.4-7 to output direction
	P1OUT = 0x00;							// P1 initialization
}

void lcd_strobe(void)
{
	LCD_EN_H;
	asm("	nop");
	LCD_EN_L;
}

/* write a byte to the LCD in 4 bit mode */
void lcd_write(unsigned char byte)
{
	P1OUT = (P1OUT & 0x03) | (byte & 0xF0);
	lcd_strobe();
	__delay_cycles(3000);
	P1OUT = (P1OUT & 0x03) | ((byte << 4) & 0xF0);
	lcd_strobe();
	__delay_cycles(3000);
}

/* clear and home the LCD */
void lcd_clear(void)
{
	LCD_RS_L;
	lcd_write(0x1);
	__delay_cycles(5000);
}

/* write one character to the LCD */
void lcd_putch(char c)
{
	LCD_RS_H;
	lcd_write(c);
}

/* write a string of chars to the LCD */
void lcd_puts(const unsigned char *s)
{
	LCD_RS_H;
	while(*s)
		lcd_write(*s++);
}

/* Go to the specified position */
void lcd_goto(unsigned char pos)
{
	LCD_RS_L;
	lcd_write(0x80+pos);
}
	
/* initialization of LCD - put into 4 bit mode */
void lcd_init(void)
{
	LCD_RS_L;							// write control bytes
	__delay_cycles(50000);				// power on delay
	P1OUT = 0x30;						// attention!
	lcd_strobe();
	__delay_cycles(15000);
	lcd_strobe();
	__delay_cycles(500);
	lcd_strobe();
	__delay_cycles(500);
	P1OUT = 0x20;						// set 4 bit mode
	lcd_strobe();
	__delay_cycles(500);
	lcd_write(0x28);					// 4 bit mode, 2 lines, 5x7 font
	lcd_write(0x08);					// display off
	lcd_write(0x0F);					// display on, cursor on, blink cursor on
	lcd_write(0x01);					// clear display
	lcd_write(0x06);					// entry mode set
}
