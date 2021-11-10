#include <stdio.h>

int main(void) {
	int fee = 1000;
	int nAge = 0;
	double nRate = 0.0;

	scanf_s("%d", &nAge);

	if (nAge < 4) {
		nRate = 0.0;
	}
	else if (nAge < 14) {
		nRate = 0.5;
	}
	else if (nAge < 20) {
		nRate = 0.75;
	}
	else if (nAge < 65) {
		nRate = 1.0;
	}
	else {
		nRate = 0.0;
	}

	printf("�������: %d��\n", (int)(fee * nRate));
	return 0;
}