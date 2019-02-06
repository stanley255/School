#include<stdio.h>

static int iCislo, iVysledok;// Niektore verzie potrebujuglobalne premenne

int  main(int argc, char*argv[])
{
	iCislo = 27;
	iVysledok = 0;
	printf("\nCislo: %d  Vysledok: %d", iCislo, iVysledok);

#ifdef __GNUC__                      // Tato cast sa preklada len v Dev-C++ (gcc)

	asm(".intel_syntaxnoprefix \n"// Prepneme z AT&T syntaxe na na Intel 

		"moveax,_iCislo        \n"// iCislo -> EAX
		"inceax                \n"// EAX ++ 
		"mov _iVysledok,eax     \n"// EAX  ->iVysledok

		".att_syntax            \n");// Damevsetko do povodneho stavu      

#elif _MSC_VER                       // Tato cast sa preklada iba v MS Visual C++

	__asm {
		MOV EAX, iCislo
		SHL EAX, 1
		MOV iVysledok, EAX
	}

#endif

	printf("\nCislo: %i * 2 \n Vysledok: %d", iCislo, iVysledok);

	printf("\n\nStlac ENTER a skoncime...");
	getchar();
}
