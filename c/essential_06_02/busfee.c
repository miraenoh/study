#include <stdio.h>

int main(void) {
	double fee = 1000.0;
	int nAge = 0;
	scanf_s("%d", &nAge);

	if (nAge < 20)
		fee *= 0.75;

	printf("�������: %d��\n", (int)fee);
	return 0;
}