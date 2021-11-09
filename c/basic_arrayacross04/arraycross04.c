#include <stdio.h>

// 지그재그로 2차원 배열 채우기 3(플래그 방식)
int main(void)
{
	int aList[5][5] = { 0 };
	int i = 0, j = 0, nCounter = 0, nFlag = 1;

	// 구현부
	for (i = 0; i < 5; ++i) {
		if (nFlag)
		{
			// 정방향
			for (j = 0; j < 5; ++j)
				aList[i][j] = ++nCounter;
		}
		else
		{
			// 역방향
			for (j = 0; j < 5; ++j)
				aList[i][4 - j] = ++nCounter;
		}
	}

	for (i = 0; i < 5; ++i)
	{
		for (j = 0; j < 5; ++j)
			printf("%d\t", aList[i][j]);
		putchar('\n');
	}
	return 0;
}