#include <stdio.h>

int main(void) {
	char ch = 0;

	while ((ch = getchar()) != '\n') {
		putchar(ch);
	}

	return 0;
}