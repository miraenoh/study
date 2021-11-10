#include <stdio.h>

// ������ �迭 ä��� �� ���
int main(void)
{
	int aList[5][5] = { 0 };
	int i = 0, j = 0, nCounter = 0, nOffsetX = 0, nOffsetY = 1;

	// ������
	int iNext = 0, jNext = 0;
	for (nCounter = 1; nCounter <= 5 * 5; ++nCounter)
	{
		// ���� ��ǥ�� �� �Է�
		aList[i][j] = nCounter;

		// �̵��� ��ǥ ���
		iNext = i + nOffsetX;
		jNext = j + nOffsetY;

		// ���� ��ȯ ���� �˻�
		if (iNext > 4 || iNext < 0 || jNext > 4 || jNext < 0 || aList[iNext][jNext] != 0)
		{
			// ���� ��ȯ
			// ������ ��ȣ ��ȯ ���� ����
			if (nOffsetX != 0)
			{
				// ������ ��ȣ ��ȯ
				nOffsetY = -nOffsetX;
				nOffsetX = 0;
			}
			else {
				// ������ ��ȣ ����ȯ
				nOffsetX = nOffsetY;
				nOffsetY = 0;
			}

			iNext = i + nOffsetX;
			jNext = j + nOffsetY;
		}

		// ���� ��ǥ �Է�
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