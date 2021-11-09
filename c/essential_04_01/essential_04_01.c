#include <stdio.h>

int main(void) {

	int input1, input2;
	printf("두 정수를 입력하세요.: ");
	scanf_s("%d%d", &input1, &input2);

	printf("AVG : %.2f", (input1 + input2) / 2.0);
	return 0;
}