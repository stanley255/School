//1. Napíšte funkciu, ktorá vráti poèet reálnych koreòov kvadratickej rovnice (vstupy a,b,c sú koeficienty rovnice).
#include <math.h>
int kvadraticka_funkcia(double a, double b, double c, double *x1, double *x2) {
	double result;
	result = b * b - 4 * a*c;
	if (result > 0) {
		*x1 = (-b + sqrt(result)) / (2 * a);
		*x2 = (-b - sqrt(result)) / (2 * a);
		return 2;
	}
	else if (result == 0) {
		*x1 = (-b + sqrt(result)) / (2 * a);
		*x2 = (-b + sqrt(result)) / (2 * a);
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	double a, b, c, x1 = 0, x2 = 0;
	int result;
	a = -2;
	b = 3;
	c = 2;
	printf("a:%.0lf\n, b:%.0lf\n, c:%lf\n, poc. korenov: %i,\n", a, b, c, kvadraticka_funkcia(a, b, c, &x1, &x2));
	printf("x1: %lf\nx2:%lf",x1,x2);

	getchar();
	return 0;
}