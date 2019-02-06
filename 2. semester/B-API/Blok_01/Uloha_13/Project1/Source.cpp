#include <stdio.h>

int main() 
{
	int cislo,vysledok;

	cislo = 8;
	
	__asm {
		MOV EAX, cislo
		CMP EAX, 9   
		JG L1
		ADD EAX, 48
		JMP L2
		L1:
		ADD EAX, 55
		L2:
		MOV vysledok, EAX
	}

	printf("%c",vysledok);

	getchar();
	return 0;
}
