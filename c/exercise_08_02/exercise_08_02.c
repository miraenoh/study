#include <stdio.h>

int main(void) {
	char inpString[100];
	int len = 0;
	scanf_s("%s", inpString, sizeof(inpString));

	while (inpString[len] != '\0')
		len++;
	len /= 2;

	printf("�ѱ� ������ ������ %d�� �Դϴ�.\n", len);
	return 0;
}