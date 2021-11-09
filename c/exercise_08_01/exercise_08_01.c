#include <stdio.h>

int main(void) {
	int aList[5] = { 0 };
	int i = 0, min = 0, max = 0;

	for (i = 0; i < 5; ++i) {
		scanf_s("%d", &aList[i]);
		if (i == 0) {
			min = max = aList[i];
		}
		else {
			if (aList[i] > max) {
				max = aList[i];
			}
			if (aList[i] < min) {
				min = aList[i];
			}
		}
	}

	printf("MIN: %d, MAX: %d\n", min, max);
	return 0;
}