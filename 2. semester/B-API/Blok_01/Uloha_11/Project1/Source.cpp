#include<stdio.h>

static int cislo1,cislo2, iVysledok;// Niektore verzie potrebujuglobalne premenne

int  main(int argc, char*argv[])
{
	cislo1 = 27;
	cislo2 = 13;
	iVysledok = 0;

#ifdef __GNUC__                      // Tato cast sa preklada len v Dev-C++ (gcc)

	asm(".intel_syntaxnoprefix \n"// Prepneme z AT&T syntaxe na na Intel 

		"moveax,_iCislo        \n"// iCislo -> EAX
		"inceax                \n"// EAX ++ 
		"mov _iVysledok,eax     \n"// EAX  ->iVysledok

		".att_syntax            \n");// Damevsetko do povodneho stavu      

#elif _MSC_VER                       // Tato cast sa preklada iba v MS Visual C++

	__asm {// zaciatok bloku asm
		MOV EAX, cislo1
		MOV ECX, cislo2
		ADD EAX, ECX          // pripocitaj 1
		MOV iVysledok, EAX// do premennej iVysledokvlozvysledok z registra EAX
	}// koniec bloku asm

#endif

	printf("\nCislo 1:%i, Cislo 2:%i, Vysledok:%i",cislo1,cislo2,iVysledok );
	getchar();
	printf("\n\nStlac ENTER a skoncime...");
	return(0);
}
