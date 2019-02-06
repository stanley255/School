//******************************************************************************
// Mikroprocesorova technika
// EVB2 I2C Master Transmitter
//******************************************************************************

#include  <msp430g2231.h>

char MST_Data = 1;                     // data na poslanie
char SLV_Addr = 0x70;                  // addresa obvodu PCF8574a (aj s R/*W bitom)

int I2C_State = 0;                     // stavova premenna, ktora cast prenosu sa vykona

char direction = 0;	// pri generovani novych dat
//PCF8574AP 01111100
void main(void)
{
  volatile unsigned int i;             // pouzi volatile aby nedoslo ku odstraneniu premennej

  WDTCTL = WDTPW + WDTHOLD;            // zastav watchdog
  if (CALBC1_1MHZ ==0xFF || CALDCO_1MHZ == 0xFF)                                     
  {  
    while(1);                          // ak su kalibracne konstanty oscilatora DCOCLK zmazane
                                       // nenacitavaj ich,zacykli sa tu a nepokracuj
  }   
  BCSCTL1 = CALBC1_1MHZ;               // nastav frekvenciu DCO na 1MHz
  DCOCTL = CALDCO_1MHZ;

  P1OUT = 0xC0;                        // piny P1.6 a P1.7 nastav do 1
  P1DIR = 0xC0;                        // piny P1.6 a P1.7 nastav ako vystupne

  USICTL0 = USIPE6+USIPE7+USIMST+USISWRST; // nastavenie periferie USI k portu a nastvenie jej modu
  USICTL1 = USII2C+USIIE;              // Nastav USI do modu I2C a povol prerusenie od USI
  USICKCTL = USIDIV_3+USISSEL_2+USICKPL; // nastevenie hodinoveho signalu USI: SCL = SMCLK/8 (~125kHz)
  USICNT |= USIIFGCC;                  // zakaz automaticke mazanie priznaku
  USICTL0 &= ~USISWRST;                // povol dekrementaciu pocitadla a posun dat
  USICTL1 &= ~USIIFG;                  // zmaz priznak prerusenia. Aby sa ISR nespustila hned po nasledovnej instrukcii
  _EINT();			// iny zapis globalneho povolenia prerusenia

  while(1)
  {
    USICTL1 |= USIIFG;                 // nastav softwerovo priznak a vyvolaj spustenie ISR
    							// tu procesor nestihne vykonat LPM0 a este predtym spusti ISR
    LPM0;                              // zaspanie CPU, cakanie na priznak, dalsi

    for (i = 0; i < 10000; i++);        // cakaj medzi jednotlivymi celymi komunikaciami
  }
}

/******************************************************
// USI interrupt service routine
******************************************************/
#pragma vector = USI_VECTOR
__interrupt void USI_TXRX (void)
{
  switch(I2C_State)
    {
      case 0: // Generuj podmienku start a posli adresu do expandera
              USISRL = 0x00;           // generovanie podmienky start
              USICTL0 |= USIGE+USIOE;	// tu sa zmeni SDA z 1 na 0, bez toho aby sa
              USICTL0 &= ~USIGE;		// zmenili hodiny. konfigurujeme USI za behu
              USISRL = SLV_Addr;       // vlozenie adresy a R/W = 0
              USICNT = (USICNT & 0xE0) + 0x08; // Bit counter = 8, TX Address, spustenie vysielania adresy
              I2C_State = 2;           // nastav dalsi stav prenosu: bude sa prijimat ACK, potvrdenie adresy
              break;

      case 2: // citanie bitu ACk, ktory potvrdil existenciu zariadenia s rovnakou ako vyslanou adresou
              USICTL0 &= ~USIOE;       // nastav SDA ako vstup (odpojenim vystupu)
              USICNT |= 0x01;          // bude sa prijimat len jeden bit, pocitadlo bitov = 1, start prijatia bitu ACK
              I2C_State = 4;           // nastav dalsi stav prenosu: test prijateho bitu ACK
              break;

      case 4: // test ACK bitu a vyslanie dat, ak bol ACK =0, inak koniec prenosu
              USICTL0 |= USIOE;        // pin SDA nastav ako vystupny
              if (USISRL & 0x01)       // citanie posuvneho registra a testovanie najnizsieho bitu, kde je prijaty ACK
              { // ak bol ACK =1, zariadenie neodpovedalo, priprav zbernicu na stop stav
                USISRL = 0x00;
                USICNT |=  0x01;       // vyslanie jedneho bitu, nastavi SCL do 1, a SDA do 0
                I2C_State = 10;        // nastav dalsi stav prenosu: generovanie stavu stop
              }
              else
              { // ak bolo ACk = 0 ma zmysel vysielat data
                USISRL = ~MST_Data;     // nacitaj data (8bitov) do posuvneho registra
                USICNT |=  0x08;       // pocitadlo odpocita 8 pulzov hodin, start vysielnia 8-mich bitov dat
                I2C_State = 6;         // nastav dalsi stav prenosu: prijem dalsieho ACK, potvrdenie prijatia dat
              }
              break;

      case 6: // Receive Data Ack/Nack bit
              USICTL0 &= ~USIOE;       // SDA ako vstup, ako vyssie
              USICNT |= 0x01;          // to iste ako vyssie
              I2C_State = 8;           // nastav dalsi stav prenosu:
              break;

      case 8: // uz bit ACK netreba testovat, vygeneruj nove data na buduce poslanie a priprav zbernicu na stop stav
              USICTL0 |= USIOE;
              
              if (direction == 0 & MST_Data <= 0x7F)
              {
              	MST_Data = MST_Data << 1;
              }
              else
              {
              	direction = 1;
              }
              
              if (direction == 1 & MST_Data > 0x01)
              {
              	MST_Data = MST_Data >> 1;
              }
              else
              {
              	direction = 0;
              }
              
              // priprav zbernicu na stop stav
              USISRL = 0x00;
              USICNT |=  0x01;         // pocitadlo = 1, start, vyslanie jedneho bitu, nastavi SCL do 1, a SDA do 0
              I2C_State = 10;          // nasledujuci stav prenosu: generuj stav stop
              break;

      case 10:// generovanie stavu stop
              USISRL = 0x0FF;          // najnizsi bit USISRL je 1 co sposobi ze SDA sa uvolni do log.1
              USICTL0 |= USIGE;        // ale az teraz
              USICTL0 &= ~(USIGE+USIOE);// nastav SDA ako vstup
              I2C_State = 0;           // novy stav bude stav opetovneho zaciatku komunikacie
              LPM0_EXIT;               // po navrate z ISR nezaspi ale bud active
              break;
    }

  USICTL1 &= ~USIIFG;                  // Clear pending flag
}
