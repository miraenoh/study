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

	printf("%d초는 %02d시간 %02d분 %02d초 입니다.", input, h, m, s);
	return 0;
}