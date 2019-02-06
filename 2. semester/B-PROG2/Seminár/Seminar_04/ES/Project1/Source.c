#include <stdio.h>

int main2() {
	int prvocisla[119];
	for (int i = 2; i <= 120; i++) {
		prvocisla[i - 2] = i;
		//printf("%i\n",prvocisla[i - 2]);
	}
	int i = 0;
	while (i < 119) {
		if (prvocisla[i] == -1) {
			i++;
			continue;
		}
		for (int j = i + 1; j < 119; j++) {
			if ((prvocisla[j]%prvocisla[i] == 0)&&(prvocisla[j]!=-1)) {
				prvocisla[j] = -1;
			}
		}
		i++;
	}
	for (int i = 0; i < 119; i++) {
		if (prvocisla[i] != -1) {
			printf("%i\n",prvocisla[i]);
		}
	}

	getchar();
	return 0;
}