#include <stdio.h>

// 지그재그로 2차원 배열 채우기 1
int main(void)
{
	int aList[5][5] = { 0 };
	int i = 0, j = 0, nCounter = 0;

	// 구현부
	for (i = 0; i < 5; ++i) {
		if (i % 2 == 0)
			// 정방향
			for (j = 0; j < 5; ++j)
				aList[i][j] = ++nCounter;
		else
			// 역방향
			for (j = 4; j >= 0; --j)
				aList[i][j] = ++nCounter;

	}

	for (i = 0; i < 5; ++i)
	{
		for (j = 0; j < 5; ++j)
			printf("%d\t", aList[i][j]);
		putchar('\n');
	}
	return 0;
}