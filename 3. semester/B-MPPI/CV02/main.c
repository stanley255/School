/*
 * Mikroprocesorova technika
 * cvicenie c. 2
*/

#include  <msp430.h>

void delay(long int i);

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  P1DIR |= 0x41;                            // Set P1.0 and P1.6 to output direction
  P1DIR &= 0xF7;							// Set P1.3 to input direction
	short int j = 0;
  for (;;)
  {
  	do{
  		P1OUT = 0x00;
  	}while(P1IN & BIT3); //test pustene tl
  	P1OUT = 0x01;	//stlacil som
  	delay(2);

  	do{
  		P1OUT = 0x01;
  	}while(~P1IN & BIT3); //test stlacene tl
  	delay(2); //pustil som

  	do{
  		P1OUT = 0x01;
  	}while(P1IN & BIT3); //test pustene tl
  	P1OUT = 0x00; //stlacil som
  	delay(2);
    	
	do{
  		P1OUT = 0x00;
  	}while(~P1IN & BIT3);//test stlacene tl
  	delay(2); //pustil som
  	
	do{
  		P1OUT = 0x00;
  	}while(P1IN & BIT3); //test pustene tl
	P1OUT = 0x40;
  	delay(2); // stlacil som


  	do{
  		P1OUT = 0x40;
  	}while(~P1IN & BIT3); //test stlacene tl
  	delay(2);

  	do{
  		P1OUT = 0x40;
  	}while(P1IN & BIT3); //test pustene tl
  	P1OUT = 0x00;
  	delay(2);
  	
  	do{
  		P1OUT=0x00;
  	}while(~P1IN & BIT3);
  	delay(2);

  	do{
  		P1OUT=0x00;
  	}while(P1IN & BIT3);
  	delay(2);

  	for(j=0;j<5;j++)
  	{
  		P1OUT = 0x41;
  		delay(50000);
  		P1OUT = 0x00;
  		delay(50000);
  	}
  	do{
  		P1OUT = 0x00;
  	}while(~P1IN & BIT3); // test pustene
  }
}

// Cakacia funkcia
void delay(long int i)
{
	do {(i--);
	asm("nop");
	}
    while (i != 0);
}
