#include <stdio.h>

// 달팽이 배열 채우기 책 답안
int main(void)
{
	int aList[5][5] = { 0 };
	int x = -1, y = 0, nCounter = 0;
	int i = 0, j = 0, nLength = 9, nDirection = 1;

	for (nLength = 9; nLength > 0; nLength -= 2)
	{
		for (i = 0; i < nLength; ++i)
		{
			// 이동 값 결정
			if (i < nLength / 2 + 1)
				// x값 이동
				x += nDirection;
			else
				// y값 이동
				y += nDirection;

			// 계산된 좌표에 값 입력
			aList[y][x] = ++nCounter;
		}

		// 이동 방향 전환
		nDirection *= -1;
	}

	for (i = 0; i < 5; ++i)
	{
		for (j = 0; j < 5; ++j)
			printf("%d\t", aList[i][j]);
		putchar('\n');
	}
	return 0;
}