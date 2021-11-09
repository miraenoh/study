#include <stdio.h>

int main(void) {
	int aList[3][4] = { {10, 20, 30}, {40, 50, 60} };
	int i = 0, j = 0;

	for (i = 0; i < 2; ++i) {
		for (j = 0; j < 3; ++j) {
			aList[i][3] += aList[i][j];
			aList[2][j] += aList[i][j];
		}
	}

	for (i = 0; i < 2; ++i)
		aList[2][3] += aList[i][3];

	// 결과 출력
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; ++j)
			printf("%d\t", aList[i][j]);
		putchar('\n');
	}
	return 0;
}