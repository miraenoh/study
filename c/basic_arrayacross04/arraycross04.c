#include <stdio.h>

// ������׷� 2���� �迭 ä��� 3(�÷��� ���)
int main(void)
{
	int aList[5][5] = { 0 };
	int i = 0, j = 0, nCounter = 0, nFlag = 1;

	// ������
	for (i = 0; i < 5; ++i) {
		if (nFlag)
		{
			// ������
			for (j = 0; j < 5; ++j)
				aList[i][j] = ++nCounter;
		}
		else
		{
			// ������
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