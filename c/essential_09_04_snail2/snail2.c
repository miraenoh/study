#include <stdio.h>

// ������ �迭 ä��� å ���
int main(void)
{
	int aList[5][5] = { 0 };
	int x = -1, y = 0, nCounter = 0;
	int i = 0, j = 0, nLength = 9, nDirection = 1;

	for (nLength = 9; nLength > 0; nLength -= 2)
	{
		for (i = 0; i < nLength; ++i)
		{
			// �̵� �� ����
			if (i < nLength / 2 + 1)
				// x�� �̵�
				x += nDirection;
			else
				// y�� �̵�
				y += nDirection;

			// ���� ��ǥ�� �� �Է�
			aList[y][x] = ++nCounter;
		}

		// �̵� ���� ��ȯ
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