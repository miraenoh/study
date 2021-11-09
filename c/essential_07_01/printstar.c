#include <stdio.h>

int main(void) {
	int n = 0;
	scanf_s("%d", &n);
	if (n < 1)
		n = 1;
	else if (n > 9)
		n = 9;

	while (n > 0) {
		printf("*");
		--n;
	}
	printf("\n");

	return 0;
}