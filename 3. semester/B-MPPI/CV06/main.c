//******************************************************************************
// MPP cvicenie c. 6
//******************************************************************************

#include <msp430.h>
#include "evb1.h"

void main(void)
{
	int i = 0;
	
	evb1_io_init();

	while(1){
//		for(i=0; i<7; i++)
//		{
//			send_data_to_led(~(1<<i));
//			delay(20000);
//		}
//		for(i=0; i<7; i++)
//		{
//			send_data_to_led(~(128>>i));
//			delay(20000);
//		}

			send_data_to_led(0x09);
			delay(300000); //pauza medzi motivmi

			send_data_to_led(0x70);
			delay(300000); //pauza medzi motivmi

	}
}
