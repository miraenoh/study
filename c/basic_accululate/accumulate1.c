#include <stdio.h>

int main(void) {

	int nInput, nTotal = 0;

	scanf_s("%d", &nInput);
	nTotal += nInput;
	scanf_s("%d", &nInput);
	nTotal += nInput;
	scanf_s("%d", &nInput);
	nTotal += nInput;

	printf("Total: %d\n", nTotal);
	return 0;
}