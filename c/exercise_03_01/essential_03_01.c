#include <stdio.h>

int main(void) {

	int age = 0;
	char name[10] = { 0 };

	printf("���̸� �Է��ϼ���. : ");
	scanf_s("%d%*c", &age);
	printf("�̸��� �Է��ϼ���. : ");
	gets(name);

	printf("����� ���̴� %d���̰� �̸��� \'%s\'�Դϴ�.", age, name);
	return 0;
}