#include <stdio.h>

int main(void) {
	char szBuffer[6] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	// szBuffer2처럼 '\0'을 생략해도 상관없다
	// 초깃값이 명시되지 않은 배열 요소는 모두 0으로 초기화되기 때문
	char szBuffer2[6] = { 'H', 'e', 'l', 'l', 'o'};
	char szData[8] = { "Hello" };
	char* pszBuffer = "Hello";

	puts(szBuffer);
	puts(szData);
	puts(pszBuffer);
	return 0;
}