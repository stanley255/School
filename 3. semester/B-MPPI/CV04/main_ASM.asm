;-------------------------------------------------------------------------------
; MSP430 Assembler Code Template for use with TI Code Composer Studio
;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"       ; Include device header file
;-------------------------------------------------------------------------------
            .def    ReeSeeT                   ; Export program entry-point to
                                            ; make it known to linker.
;-------------------------------------------------------------------------------
            .text                           ; Assemble into program memory.
            .retain                         ; Override ELF conditional linking
                                            ; and retain current section.
            .retainrefs                     ; And retain any sections that have
                                            ; references to current section.
;-------------------------------------------------------------------------------
tlac	mov.w	#16,R14	;kolkokrat zmenia LED stav
		mov.w	#1,&P1OUT	;inic stav LED, svieti cervena, zelena zhasnut
blik	xor.b	#041h,&P1OUT	; softverovy prepinac P1.0 a P1.6 , cerv a zel LED sa striedaju

		mov.w	#65000,R15		; register R15 - pocitadlo - pauza medzi zmenou LED
L1		dec.w	R15		; dekrementacia R15
		jnz    L1		; test: R15 = 0?
		dec.w	R14		; kolkokrat prebliknut
		jnz	blik
		mov.w	#0,&P1OUT ;zhasni obe LED
		mov.b	#000h,&P1IFG
		reti		; navrat z ISR

ReeSeeT	mov.w   #__STACK_END,SP         ; Inic. ukazovatela, smernika na zasobnik, SP
		mov.w   #WDTPW|WDTHOLD,&WDTCTL  ; Zastavenie casovaca watchdog

; nastavenie registrov portu P1
	mov.b	#000h,&P1OUT	;zhasni LED, aj tak nebudu po resete svietit

	bis.b	#041h,&P1DIR	;bis - bit set, (nastavenie do log.1 toho bitu kde je v 0x41 log.1)
							;povol vystupnu funkciu na pinoch P1.0 a P1.6,
							;tam su pripojene LED. teraz uz LED mozu svietit

	bic.b	#BIT3,&P1DIR	;bis - bit clear (nulovanie toho bitu kde je v BIT3 log.1)
							;nemusi byt, lebo reset

;nastavenie registrov externeho prerusenia od pinu portu:
	bis.b	#BIT3,&P1IES	;volba zmeny vst. log. signalu pri ktorej dojde k nastaveniu priznaku
							;pri zmene z log.1 do log.0, to jest pri STLACENI TL

	mov.b	#000h,&P1IFG	;zmaz vsetky priznaky
	bis.b	#BIT3,&P1IE		;povol len od pinu P1.3, kde je pripojene tlacitko

	bis.w	#GIE,SR	;povol globalne, az teraz je to citlive na stlacenie

;prechod procesora do nizkoprikonoveho rezimu LPM0

	bis.w	#CPUOFF,SR		;to iste ako: bis.w	#LPM0,SR
;nekonecna slucka v hlavnom programe:
zac		jmp 	zac
;koniec hlavneho programu


			;mov.b	#000h,&P1IFG	;prerusenie od P1 je viazpriznakove, mazanie vsetkych priznakov
;----------zaciatok ISR od stlacenia tlacitka


;-------------------------------------------------------------------------------
; definicia ukazovatela, smernika na zasobnik
;-------------------------------------------------------------------------------
            .global __STACK_END
            .sect   .stack
;-------------------------------------------------------------------------------
; Interrupt Vectors
;-------------------------------------------------------------------------------
 			.sect	".int02"	;vektor startu ISR od portu P1
 			.short tlac

            .sect   ".reset"	; MSP430 RESET Vector
            .short  ReeSeeT
            
