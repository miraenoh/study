#include <stdio.h>

int main(void) {

	double dData = 123.456;
	printf("%f, %f\n", dData, -123.456);

	printf("%.1f\n", dData);		// �Ҽ��� 2��° �ڸ����� �ݿø��ϰ� 1�ڸ����� ���
	printf("%.2f\n", dData);
	printf("%.3f\n", dData);

	printf("%8d\n", 123);			// �� ���� 8�� ���
	printf("%12.3f\n", dData);		// �Ҽ��� ���� 12�ڸ��� ���. �Ҽ����� 3�ڸ����� ���
	printf("%012.3f\n", dData);		// �Ҽ��� ���� 12�ڸ��� ���. �Ҽ����� 3�ڸ����� ���. ���ڸ��� 0���� ä��

	return 0;
}