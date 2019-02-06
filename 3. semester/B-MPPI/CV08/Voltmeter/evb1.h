#ifndef EVB1_H_
#define EVB1_H_

#define ST_CP_LED_H		P1OUT |= (1 << 2)
#define ST_CP_LED_L		P1OUT &= ~(1 << 2)
#define OE_DISP_H		P1OUT |= (1 << 3)
#define OE_DISP_L		P1OUT &= ~(1 << 3)
#define ST_CP_DISP_H	P1OUT |= (1 << 4)
#define ST_CP_DISP_L	P1OUT &= ~(1 << 4)
#define SH_CP_H			P1OUT |= (1 << 5)
#define SH_CP_L			P1OUT &= ~(1 << 5)
#define DS_H			P1OUT |= (1 << 6)
#define DS_L			P1OUT &= ~(1 << 6)
	
void evb1_io_init(void);
void send_data_to_led(unsigned char num_to_led);
void send_data_to_disp(unsigned char *disp, unsigned char point);
void int_to_bcd(unsigned char *dispin, unsigned int num);
void delay(long int i);

#endif /*EVB1_H_*/
