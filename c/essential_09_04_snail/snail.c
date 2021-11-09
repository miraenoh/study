#include <stdio.h>

// 달팽이 배열 채우기 내 답안
int main(void)
{
	int aList[5][5] = { 0 };
	int i = 0, j = 0, nCounter = 0, nOffsetX = 0, nOffsetY = 1;

	// 구현부
	int iNext = 0, jNext = 0;
	for (nCounter = 1; nCounter <= 5 * 5; ++nCounter)
	{
		// 현재 좌표에 값 입력
		aList[i][j] = nCounter;

		// 이동할 좌표 계산
		iNext = i + nOffsetX;
		jNext = j + nOffsetY;

		// 방향 전환 여부 검사
		if (iNext > 4 || iNext < 0 || jNext > 4 || jNext < 0 || aList[iNext][jNext] != 0)
		{
			// 방향 전환
			// 오프셋 부호 전환 여부 결정
			if (nOffsetX != 0)
			{
				// 오프셋 부호 전환
				nOffsetY = -nOffsetX;
				nOffsetX = 0;
			}
			else {
				// 오프셋 부호 미전환
				nOffsetX = nOffsetY;
				nOffsetY = 0;
			}

			iNext = i + nOffsetX;
			jNext = j + nOffsetY;
		}

		// 다음 좌표 입력
		i = iNext;
		j = jNext;
	}

	for (i = 0; i < 5; ++i)
	{
		for (j = 0; j < 5; ++j)
			printf("%d\t", aList[i][j]);
		putchar('\n');
	}
	return 0;
}