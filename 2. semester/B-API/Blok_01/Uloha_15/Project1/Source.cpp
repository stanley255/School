#include <stdio.h>

int main()
{
	int cislo_1, cislo_2, pocitadlo, vysledok;

	cislo_1 = 5;
	cislo_2 = 4;
	pocitadlo = 0;
	vysledok = 0;

	__asm {
		MOV EAX, cislo_1
		MOV EBX, cislo_2
		MOV ECX, pocitadlo
		MOV EDX, 0

		CMP EBX, ECX
		JG L1
		JMP END
		L1:
		ADD EDX, EAX
		INC ECX
		CMP EBX, ECX
		JG L1
 
		END:
		MOV vysledok, EDX
	}

	printf("%i*%i=%i",cislo_1,cislo_2, vysledok);
	getchar();
	return 0;
}
