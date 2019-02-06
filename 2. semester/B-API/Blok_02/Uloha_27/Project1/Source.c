#include <stdio.h>
#include <float.h>


int main() {
	double epsilon = 0.5;
	double prev_epsilon;
	float fepsilon = 0.5;
	float fprev_epsilon;
	while ((1 + epsilon) != 1) {
		prev_epsilon = epsilon;
		epsilon /= 2;
	}
	while ((1 + fepsilon) != 1) {
		fprev_epsilon = fepsilon;
		fepsilon /= 2;
	}
	printf("FLT_EPSILON: %.32lf\n", FLT_EPSILON);
	printf("DBL_EPSILON: %.32lf\n", DBL_EPSILON);
	printf("Moj FLT_EPSILON: %.32lf\n", fprev_epsilon);
	printf("Moj DBL_EPSILON: %.32lf", prev_epsilon);

	getchar();
	return 0;
}