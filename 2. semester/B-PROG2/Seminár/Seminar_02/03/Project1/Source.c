#include <stdio.h>
#define _CRT_SECURE_NO_DEPRECATE
#include <math.h>
double splatka(double urokova_miera, int mesiace, double istina)
{
	double vysledok;
	if (urokova_miera == 0)
	{
		vysledok = istina / mesiace;
	}
	else
	{
		vysledok = (urokova_miera*istina) / (1-pow(1+urokova_miera,-mesiace));
	}
	return vysledok;
}

int main(void)
{
	//printf("%0.2lf EUR",splatka(0.03,360,100000));
	double miera = 0.0;
	while (miera < 1.0)
	{ 
		printf("%5.1lf %% %10.2lf EUR\n", miera, splatka(miera, 30*12, 100000));
		miera += .1;
	}

	getchar();
	return 0;
}