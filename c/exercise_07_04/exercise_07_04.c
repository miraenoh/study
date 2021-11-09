#include <stdio.h>

int main(void) {
	int nInput = 0;
	do {
		printf("Input number : ");
		scanf_s("%d", &nInput);
	} while (nInput < 0 || nInput > 10);

	puts("End");
	return 0;
}