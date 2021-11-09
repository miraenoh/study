#include <stdio.h>

// 시계 반대방향 지그재그로 2차원 배열 채우기
int main(void)
{
	int aList[5][5] = { 0 };
	int i = 0, j = 0, nCounter = 0, nFlag = 1;

	for (j = 0; j < 5; ++j)
	{
		if (nFlag)
		{
			// 정방향
			for (i = 0; i < 5; ++i)
				aList[i][j] = ++nCounter;

			nFlag = 0;
		}
		else
		{
			// 역방향
			for (i = 0; i < 5; ++i)
				aList[4-i][j] = ++nCounter;

			nFlag = 1;
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