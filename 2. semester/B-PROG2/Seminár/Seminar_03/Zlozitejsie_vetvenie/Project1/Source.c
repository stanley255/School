#include <stdio.h>
int overenie(int c1, int c2)
{
	int den, mesiac, rok;
	den = c1 % 100;
	mesiac = ((c1/100)%100)<=12? ((c1 / 100) % 100) : ((c1 / 100) % 100) -50;
		if (mesiac > 12) { return -1; }
	rok = c1/10000;
		if (c2 > 9999) { return -1; }
	if (c2 < 1000) { rok += 1900; }
	else if (rok <= 18) { rok += 2000; }
	else { rok += 1900; }

}

int main()
{
	int c1, c2;
	c1 = 986220;
	c2 = 3752;
	overenie(c1, c2);

	getchar();
	return 0;
}