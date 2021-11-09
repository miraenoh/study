#include <stdio.h>

int main(void) {

	double dData = 123.456;
	printf("%f, %f\n", dData, -123.456);

	printf("%.1f\n", dData);		// 소수점 2번째 자리에서 반올림하고 1자리까지 출력
	printf("%.2f\n", dData);
	printf("%.3f\n", dData);

	printf("%8d\n", 123);			// 총 길이 8로 출력
	printf("%12.3f\n", dData);		// 소수점 포함 12자리로 출력. 소수점은 3자리까지 출력
	printf("%012.3f\n", dData);		// 소수점 포함 12자리로 출력. 소수점은 3자리까지 출력. 빈자리는 0으로 채움

	return 0;
}