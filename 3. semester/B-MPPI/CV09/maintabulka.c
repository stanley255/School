//***********************************************************
// skusobna doska 2, rozhranie SPI periferie USI, test pomocou externeho DA prevodnika
//***********************************************************

#include <msp430.h>
#include "evb2.h"
#include "osc_config.h"

void main(void)
{
	unsigned int sample[50] = {2048,2305,2557,2802,3035,3252,3450,3626,3777,3901,3996,4060,4092,4092,4060
			,3996,3901,3777,3626,3450,3252,3035,2802,2557,2305,2048,1791,1539,1294,1061,844,646,470,319,195,
			100,36,4,4,36,100,195,319,470,646,844,1061,1294,1539,1791};
	unsigned char i;
	
	set_system_clk(VLOCLK, DCOCLK, div_1, DCOCLK, div_1, div_1); //pre SPI signal SMCLK

	evb2_io_init();
	//evb2_spi_init();
	USICTL0 |= USIPE7|USIPE6|USIPE5|USIMST|USIGE|USIOE;		// nastavenia periferie USI,
						//pripojenie SDI na P1.7, SDO na P1.6 a SCLK na P1.5, SPI master,
							//USIGE=1-vystup USISR priamo na SDO, output enabled
		USICTL1 = 0x00; 	//I2C disab.,interrupt disabled, oba priznaky zmazat
		USICKCTL |= USIDIV_0|USISSEL_2|USICKPL;						// SMCLK/1, polarita hodin
		USICTL0 &= ~USISWRST;										// USI released for operation
					// uvolnenie ser. portu z resetu, (po spusteni CPU bol USISWRST=1)
	
	USISR = tlv5636_cntrl;	// naplnenie USISR (shift register) riadiacim slovom pre prevodnik
	USICTL1 &= ~USIIFG;		// mazanie priznaku
	fs_strobe();				// sw emulacia signalu FS prevodnika
	USICNT |= USI16B|USICNT4;	// registre Hi a Lo spojene,
								//naplnenie pocitadla bitov hodnotou 16 -> START prenosu
	_delay_cycles(10);		// vysielanie bezi a paralelne program caka, aby sa dalsie data
							//nezapisali priskoro, este pocas vysielania starych
				//je to intrizicka funkcia,  "_delay_cycles(N);" vykona sa N instrukcnych cyklov
				// N je konstanta pocas behu programu.
	
	while(1)
	{
		for(i=0; i<50; i++)
		{
			USISR = sample[i];	//naplnenie USISR datami z pola (už musí byt predosle
								//vysielanie ukoncenee)
			USICTL1 &= ~USIIFG;	//mazanie priznaku....
			fs_strobe();		//ako vyssie
			USICNT |= USI16B|USICNT4;	//ako vyssie
			_delay_cycles(10);
		}
	}
}
