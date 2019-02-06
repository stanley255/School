#include <stdio.h>

typedef struct _bod{
	int x;
	int y;
} Bod;

typedef struct _triangle{
	Bod A;
	Bod B;
	Bod C;
} Triangle;

void nacitajBod(Bod *bod){
	scanf("%i",bod->x);
	scanf("%i",bod->y);
}


void zadajBodyTrojuholnika(Triangle *triangle){
	nacitajBod(&triangle->A);
	nacitajBod(&triangle->B);
	nacitajBod(&triangle->C);
}

void vypisBod(Bod bod){
	printf("\nX:%i\n",bod.x);
	printf("Y:%i\n\n",bod.y);
}

void vytlacTrojuholnik(Triangle triangle){
	vypisBod(triangle.A);
	vypisBod(triangle.B);
	vypisBod(triangle.C);
}

int main(){
	Triangle triangle;
	zadajBodyTrojuholnika(&triangle);
	return 0;
}
