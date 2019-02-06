#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct _bod {
	int x;
	int y;
} Bod;

typedef struct _triangle {
	Bod A;
	Bod B;
	Bod C;
} Triangle;

void nacitajBod(Bod *bod) {
	scanf("%i", &bod->x);
	getchar();
	scanf("%i", &bod->y);
	getchar();
}

void zadajBodyTrojuholnika(Triangle *triangle) {
	nacitajBod(&triangle->A);
	nacitajBod(&triangle->B);
	nacitajBod(&triangle->C);
}

void vypisBod(Bod bod) {
	printf("\nX:%i\n", bod.x);
	printf("Y:%i\n\n", bod.y);
}

void vypisTrojuholnik(Triangle triangle) {
	vypisBod(triangle.A);
	vypisBod(triangle.B);
	vypisBod(triangle.C);
}

int main() {
	Triangle triangle = { {1,2},{3,4},{4,5} };
	/*zadajBodyTrojuholnika(&triangle);
	vypisTrojuholnik(triangle);*/
	Triangle *ptr = &triangle;
	printf("%i",(*ptr).B.x);
	printf("%i", ptr->B.x);
	getchar();
	return 0;
}