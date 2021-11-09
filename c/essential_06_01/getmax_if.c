#include <stdio.h>

int main(void) {
	int nMax;
	int nInput;

	scanf_s("%d", &nInput);
	nMax = nInput;

	scanf_s("%d", &nInput);
	if (nInput > nMax)
		nMax = nInput;

	scanf_s("%d", &nInput);
	if (nInput > nMax)
		nMax = nInput;

	printf("MAX : %d\n", nMax);

	return 0;
}