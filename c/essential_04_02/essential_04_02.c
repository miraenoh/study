#include <stdio.h>

int main(void) {

	int input;
	int s, m, h;
	scanf_s("%d", &input);
	
	s = input;
	m = s / 60;
	s %= 60;
	h = m / 60;
	m %= 60;

	printf("%d�ʴ� %02d�ð� %02d�� %02d�� �Դϴ�.", input, h, m, s);
	return 0;
}