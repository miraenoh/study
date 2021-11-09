#include <stdio.h>

int main(void) {
	char inpString[100];
	int len = 0;
	scanf_s("%s", inpString, sizeof(inpString));

	while (inpString[len] != '\0')
		len++;
	len /= 2;

	printf("한글 문자의 개수는 %d자 입니다.\n", len);
	return 0;
}