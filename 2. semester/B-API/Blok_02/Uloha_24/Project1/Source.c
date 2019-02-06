#include <stdio.h>
#define _CRT_SECURE_NO_DEPRECATE
int main() {
	int c;
	FILE *fo, *fr;
	fo = fopen("poviedka.htm", "r");
	fr = fopen("poviedka_opravena.htm", "w");
	while ((c = getc(fo)) != EOF) {
		switch (c) {
		case 165:
			c = 188;
			break;
		case 169:
			c = 138;
			break;
		case 171:
			c = 141;
			break;
		case 174:
			c = 1142;
			break;
		case 181:
			c = 190;
			break;
		case 185:
			c = 154;
			break;
		case 187:
			c = 157;
			break;
		case 190:
			c = 158;
			break;
		}
		putc(c, fr);
	}
	fclose(fo);
	fclose(fr);
	getchar();
	return 0;
}