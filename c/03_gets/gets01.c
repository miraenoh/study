#include <stdio.h>

int main(void) {

	// ���ڿ� �迭 ����
	char szName[32] = { 0 };

	printf("�̸��� �Է��ϼ���: ");
	// gets(szName);
	gets_s(szName, sizeof(szName));

	printf("����� �̸��� ");
	puts(szName);
	printf("�Դϴ�.\n");
	return 0;
}