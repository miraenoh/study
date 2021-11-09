#include <stdio.h>

// 버블정렬
int main(void)
{
	int aList[5] = { 30, 40, 10, 50, 20 };
	int i = 0, j = 0, nTmp = 0;

	// 구현부
	for (i = 4; i > 0; --i)
		for (j = 0; j < i; ++j)
			if (aList[j] > aList[j + 1]) {
				// swap
				nTmp = aList[j];
				aList[j] = aList[j+1]; 
				aList[j+1] = nTmp;
			}

	for (i = 0; i < 5; ++i)
		printf("%d\t", aList[i]);
	putchar('\n');
	return 0;
}