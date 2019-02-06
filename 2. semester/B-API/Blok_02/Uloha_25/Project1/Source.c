#include <stdio.h>
#define _CRT_SECURE_NO_DEPRECATE
int main() {
	int c;
	FILE *fo, *fr;
	fo = fopen("koniec.htm", "rb");
	fr = fopen("koniec_opraveny.htm", "w");
	while ((c = getc(fo)) != EOF) {
		putc(c ^ 27, fr);
	}
	fclose(fo);
	fclose(fr);
	getchar();
	return 0;
}