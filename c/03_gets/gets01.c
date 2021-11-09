#include <stdio.h>

int main(void) {

	// 문자열 배열 선언
	char szName[32] = { 0 };

	printf("이름을 입력하세요: ");
	// gets(szName);
	gets_s(szName, sizeof(szName));

	printf("당신의 이름은 ");
	puts(szName);
	printf("입니다.\n");
	return 0;
}