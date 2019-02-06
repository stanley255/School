#include<stdio.h>
char *ret1[4];
char *ret2[4];
char *ret3[4];
int  main(int argc, char*argv[])
{
#if _MSC_VER                    

	__asm {
		MOV EAX, 0;
		CPUID;
		MOV ret1, EBX;
		MOV ret2, EDX;
		MOV ret3, ECX;
	}

#endif
	int i;
	printf("%s%s%s", ret1, ret2, ret3);
	getchar();
	return(0);
}
