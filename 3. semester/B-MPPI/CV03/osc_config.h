
#ifndef OSC_CONFIG_H_
#define OSC_CONFIG_H_

// oscillators types
#define DCOCLK     	0
#define LFXT1CLK   	1
#define VLOCLK		2
#define LFXT_VLO	3

// divide by value
#define div_1   0
#define div_2   1
#define div_4   2
#define div_8   3

void enable_DCO(void);
void enable_LFXT1OSC(void);
void set_system_clk(unsigned char LFXT_VLO_mode, unsigned char MCLK_src, unsigned char MCLK_div, unsigned char SMCLK_src, unsigned char SMCLK_div, unsigned char ACLK_div);

#endif /*OSC_CONFIG_H_*/
