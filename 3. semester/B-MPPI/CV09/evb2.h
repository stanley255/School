#ifndef EVB2_H_
#define EVB2_H_

#define FS_H		P1OUT |= (1 << 4)
#define FS_L		P1OUT &= ~(1 << 4)

#define tlv5636_cntrl	0x9001			// slow mode, reference 1.024V

void evb2_io_init(void);
void evb2_spi_init(void);
void fs_strobe(void);

#endif /*EVB2_H_*/
