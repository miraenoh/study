#include <stdio.h>

// 1~100까지의 숫자 중에서 4의 배수가 몇 개이며, 이들의 총합이 얼마인지 계산해 출력하는 프로그램을 작성하세요.
int main(void) {
	int i = 0, n = 0, sum = 0;

	for (i = 1; i <= 100; ++i) {
		if (i % 4 == 0) {
			++n;
			sum += i;
		}
	}

	printf("4의 배수는 %d개이고, 이들의 총합은 %d입니다.\n", n, sum);
	return 0;
}