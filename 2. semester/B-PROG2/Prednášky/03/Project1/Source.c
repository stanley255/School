#include <stdio.h>
/*
switch(m){
	case 1:
	case 3:
	case 5:
		d = 31;
		break;
	case 4:
	case 6:
		d = 30;
		break;
	case 2:
		d = 28;
		break;
	default:
		d = 0;
		break;
}

//approach 3
return m==2 ? 28 : 30 + (m>7 ? m+1 : m)%2);
//aproach 4
return 30 + (m+(m>7))%2 - 2*(m==2));
*/
int dni_v_mesiaci(int mesiac) {
	if (mesiac > 12 || mesiac<1) {
		return 0;
	}
	else {
		if (mesiac == 2) {
			return 28;
		}
		if (mesiac > 7) { mesiac -= 5; }
		if (mesiac % 2 == 0) {
			return 30;
		}
		else { return 31; }
	}
}

int main() {
	for (int i = 1; i <= 12; i++) {
		printf("%i\n", dni_v_mesiaci(i));
}
	getchar();
	return 0;
}
